/* Here we can define what happens when the app starts up,
 this is also the place where the behaviour of most UI elements like buttons
is defined. */


/*


TODO:
    - curtains (optional auto closing/opening from control_screen with QTimeEdit objects to set opening/closing)
    - state of radiators (optional auto turn on/off when temperature gets over/under threshold)


    - set variable heating power of radiators. Introduce infra-red sensors that will count how many hours person spends in which room, this will affect
        the power setting of radiator in each room.







    - add event log list to control screen

    - improve grid performance
        right now it adds 2000 items to the scene which makes it laggy when looping over all items
        this must be changed
        see: https://www.qtcentre.org/threads/5609-Drawing-grids-efficiently-in-QGraphicsScene


    - if weird movement is observed when using transforms on images then use setOffset instead of
      manually calculating position (when centering images), e.g:
            setOffset(-pixmap->width() / 2, -pixmap->height() / 2);

            only works for pixmap item,
            so use setTransformOriginPoint in that case

    - decide what method of animation to use (p.149, 174)

    - consider making Room/Door/Window classes because requirements say that:
        * control screen should be placed on the wall
        * windows should be placed on the wall
      Making room class (with room names/labels as members) will allow to enumerate them
      and list in the controller screen (e.g. by making few tabs, 1 per room, each tab
      could contain controls for the devices present in specific room)

   - dynamically create QDialog popups with combo-boxes having presets to pick suggested
     room names (e.g. kitchen, lounge, toilet etc.)

      On the other side, assignment specification says:
            "A single control screenwhich can be placed on a wall in the apartment,
            and which provides the simulator view to the residents."

      So maybe the graphicsView used in designer mode could be used to interact with simulation.
      Where control screen would represent only part of the actual control screen.
      Need to ask the client about it.

    - add built in sensors to ControllerScreen, for example
        * temperature
        * humidity
        * weather forecast (use networking and some free online API to fetch weather forecast - as an additional feature)

    - consider adding additional subclasses to GraphicsItem (just like the SmartDevice was made a sub-class of it, which simplified a lot)
         (e.g. creating separate polygon class would allow to remove QPolygon object from GraphicsItem)

    - merging separate shapes into rooms (QGraphicsItemsGroup + remove QPen)
            https://doc.qt.io/qt-5/qgraphicsitemgroup.html

            The operation of adding and removing items preserves the items'
            scene-relative position and transformation, as opposed to calling
            setParentItem(), where only the child item's parent-relative position
            and transformation are kept.

            OR:
            Painter paths
            If you want to create a graphics item that consists of multiple geometric primitives,
            creating multiple QGraphicsItem objects seems to be tedious. Fortunately, Qt provides
            a  QGraphicsPathItem class that allows you to specify a number of primitives in a
            QPainterPath object. QPainterPath allows you to "record" multiple painting instructions
            (including filling, outlining, and clipping), and then efficiently reuse them multiple times.

    - adding walls manually (not sure about this)
    - adding doors (using collision/coordinates detection to prevent actor going through the walls or closed doors)

    - consider using drop events of the rooms/building to use SmartDevice->setParentItem(room_or_building_obj_ptr), this way light clipping could be implemented
      and this way by deleting room all the smart devices inside it would get deleted too.
      Also it would be possible to get all the child objects of the room easily
      But first it has to be determined how exactly to setup rooms/walls/doors (e.g. merge all shapes into path item? Or carry on using separate shapes,
      and use small yellow rects as doors)

    - cleanup after removing items:
         "If you want to remove an item from a scene without setting it directly to another scene or
         without deleting it, you can call scene.removeItem(rectItem). Be aware, however, that now it
         is your responsibility to delete rectItem to free the allocated memory!"
         See "delete item" in: https://subscription.packtpub.com/book/game_development/9781788399999/4/ch04lvl1sec32/custom-items

    - add sound effects (doorbell, light switch click, power switch click)


Smart devices sticking to room positions (even when rooms are moving):
    QGraphicsItem::setParentItem()

Drawing any kind of partial ellipse:
    QGraphicsEllipseItem::startAngle()
    QGraphicsEllipseItem::spanAngle()

Good website with tutorials/examples about Qt:
    https://www.bogotobogo.com/Qt/Qt5_SignalsSlotsGui.php
    https://www.bogotobogo.com/Qt/Qt5_QGraphicsView_QGraphicsScene.php
    https://www.bogotobogo.com/Qt/Qt5_QGraphicsView_QGraphicsScene_QGraphicsItems.php
    https://www.bogotobogo.com/Qt/Qt5_QGraphicsView_animation.php
*/



/*
The following minimum set of smart home devices should be supported:
1.  Door bell
    – this should generate an event when the door bell is pressed

2.  Fixed ceiling lights
    – these should be positioned on the ceiling of a room and be able to respond to the following events:
        (1) turn on,
        (2) turn off
        (3) brightness change
        (4) color change
    Each light should have aID(extra marks if you use UUIDs) and a location.

3.  Smart power sockets
    – these should be positioned in a room and be able to respond to the following events:
        (1) turn on
        (2) turn off
    Each socket should have an ID (extra marks if you use UUIIDs) and a location.

4.  A single control screenwhich can be placed on a wall in the apartment,
    and which provides the simulator view to the residents. This allows the
    users to view events and interact with the devices in the apartment.

This means the simulation view must have smaller graphicsView and a panel displayed on the side of the screen.
*/



#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "grid.h"
#include "graphics_item.h"
#include "graphics_scene.h"
#include "polygon_creator.h"
#include "smart_device_creator.h"
#include "press_and_drag_creator.h"
#include "zoom.h"

#include "actor.h"
#include "actor_player.h"
#include "audio.h"
#include "weather.h"

#include "controller_screen.h"
#include "environment_window.h"
#include "tutorial.h"

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QColorDialog>

#include <QGraphicsItem>
#include <QMessageBox>
#include <QScrollBar>

MainWindow * pMainWindow = nullptr;
QSettings *settings = nullptr;

QButtonGroup * shapes_buttons = nullptr;
QButtonGroup * smart_device_buttons = nullptr;

void StatusBarMsg(const char * msg) {
    if (pMainWindow)
        pMainWindow->ui->statusBar->showMessage(msg);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    spacer(nullptr)
{
    // What happens when program starts:

    // loading audio effects takes some time, for that reason it's done before the window appears
    // to avoid misleading the user to think that the program loaded fully
    audio = new Audio();
    audio->LoadSongs(); // optional location can be supplied (default is "resources/audio")
    audio->LoadSoundEffects();

    weather = new Weather();

    // Initialises user interface
    ui->setupUi(this);

    // Makes a copy of pointer to main window (so it's accessible from other files when needed)
    // but it's not really needed
    pMainWindow = this;

    // Could be used at startup:
    //showMaximized();
    //showFullScreen();

    /* scene holds items
       items = rectangles, ellipses, polygons, pixmaps (images) etc.
       it has methods like: scene->items(); scene->addItem(); */
    scene_ = new GraphicsScene();

    /* Creator is a parent class, thanks to polymorphism it will be easy to implement
       custom behaviour to draw different kind of things (e.g. polygon is being drawn
       differently from rect/ellipse) */
    base_idle_creator = new Creator();
    SetCreator(base_idle_creator);

    // Creator subclasses:
    polygon_creator = new PolygonCreator();
    smart_device_creator = new SmartDeviceCreator();
    press_and_drag_creator = new PressAndDragCreator();

    /* Each of the sub-classes above implements its' own set of Creator methods like:
        - mousePressEvent
        - mouseMoveEvent
        - mouseReleaseEvent
        - keyPressEvent
        - keyReleaseEvent

       So we can implement different behaviour for drawing of polygon / rect, ellipse / smart devices,
       all in their own separate files.

       And then just switch between them when needed by using:
       creator = polygon_creator; // which is what happens in SetCreator();

       E.g. It's used like that in MainWindow::on_listWidget_itemClicked
    */

    ui->graphicsView->setMouseTracking(true);
    //ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    ui->graphicsView->cursor().setShape(Qt::ArrowCursor);

    ui->graphicsView->setScene(scene_);
    ui->actionGrid->setChecked(true); // "clicks" at "view - Grid" from the top menu when program is started

    double center = GRID_SIZE * GRID_GRANULARITY / 2.0;
    ui->graphicsView->centerOn(center, center);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    //ui->statusBar->showMessage("this is a status bar, useful for displaying info about current mode/creator");

    Zoom* z = new Zoom(ui->graphicsView);
    z->set_modifiers(Qt::ControlModifier);

    smart_device_buttons = new QButtonGroup(this);
    smart_device_buttons->addButton(ui->pushButton_doorbell);
    smart_device_buttons->addButton(ui->pushButton_light_bulb);
    smart_device_buttons->addButton(ui->pushButton_power_socket);
    smart_device_buttons->addButton(ui->pushButton_control_screen);
    smart_device_buttons->addButton(ui->pushButton_speakers);
    smart_device_buttons->addButton(ui->pushButton_radiator);
    smart_device_buttons->addButton(ui->pushButton_thermometer);
    smart_device_buttons->addButton(ui->pushButton_infra_red_sensor);
    smart_device_buttons->addButton(ui->pushButton_toilet);
    smart_device_buttons->addButton(ui->pushButton_fan);
    smart_device_buttons->addButton(ui->pushButton_blinds);


    // old SIGNAL(), SLOT() syntax, improve it with &
    connect(smart_device_buttons, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(on_SmartDeviceButtons_clicked(QAbstractButton *)));

    shapes_buttons = new QButtonGroup(this);
    shapes_buttons->addButton(ui->pushButton_shapes_rect);
    shapes_buttons->addButton(ui->pushButton_shapes_ellipse);
    shapes_buttons->addButton(ui->pushButton_shapes_polygon);
    shapes_buttons->addButton(ui->pushButton_shapes_line);



    // old SIGNAL(), SLOT() syntax, improve it with &
    connect(shapes_buttons, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(on_ShapeButtons_clicked(QAbstractButton *)));


    //Actor *actor = new Actor();
    controller_screen = new ControllerScreen(this);

    environment_window = new EnvironmentWindow(this);

    int top_frame_size = 31;
    int start_menu_estimated_height = 50;
    QSize resolution = app->screens()[0]->size();

    int x_offset = std::max(controller_screen->width(), environment_window->width()) + 1;
    setGeometry(
    /*   x    */  x_offset,
    /*   y    */  top_frame_size,
    /* width  */  resolution.width() - x_offset,
    /* height */  resolution.height() - start_menu_estimated_height
               );

    controller_screen->setGeometry(0, top_frame_size, x_offset - 1, controller_screen->height());
    environment_window->setGeometry(0, controller_screen->height() + top_frame_size*2, x_offset - 1, environment_window->height());

    tutorial = new Tutorial(this);

    settings = new QSettings("settings.ini", QSettings::IniFormat);

    if (settings->value("first_run", true).toBool()) {
        qDebug() << "First run detected";
        settings->setValue("first_run", false);
    } else {
        qDebug() << "It's not a first run.";
    }

    if (!settings->value("dont_show_tutorial_again", false).toBool()) {
        tutorial->show();
        tutorial->SetSlide(0);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow *MainWindow::getMainWinPtr()
{
    return pMainWindow;
}

void MainWindow::on_pushButton_clear_all_clicked()
{
    qDebug() << "clear all button was clicked";
}


void MainWindow::on_actionGrid_toggled(bool checked)
{
    if (checked){
        grid->Set(GRID_GRANULARITY, GRID_SIZE, GRID_COLOR);
    }
    else{
        grid->Clear();
    }
}


void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    int key = event->key();
}



void MainWindow::on_SmartDeviceButtons_clicked(QAbstractButton * button)
{
    qDebug() << "(QAbstractButton*)->text() = " << button->text();
    smart_device_creator->SetDeviceType(button);
    SetCreator(smart_device_creator);
}

void MainWindow::on_ShapeButtons_clicked(QAbstractButton * button)
{
    qDebug() << button;
    QString s(button->text().trimmed());

    if (s == "Rectangle" || s == "Ellipse" || s == "Line") {
        SetCreator(press_and_drag_creator);

        if (s == "Rectangle") {
            press_and_drag_creator->SetItemType(ITEM_RECT);
        } else if (s == "Ellipse") {
            press_and_drag_creator->SetItemType(ITEM_ELLIPSE);
        } else {
            press_and_drag_creator->SetItemType(ITEM_LINE);
        }

    }

    if (s == "Polygon") {
        SetCreator(polygon_creator);
    }
}



/* // piece of code I found online, some of it may be useful in future:
void MyGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    // Get the list of the views attached to this scene
    QList<QGraphicsView*> scene_views = views();

    for(int i = 0; i < scene_views.count(); i++)
    {
        // get the visible view port
        QWidget* viewport_widget = scene_views.at(i)->viewport();

        // ensure it is visible
        if(viewport_widget->isVisible())
        {
            // Update cursor position (text to be displayed)
            QString string = QString("%1, %2")
                                .arg(event->scenePos().x())
                                .arg(event->scenePos().y());

            cursor->setPlainText(string);

            // Set the new position of the cursor
            cursor->setPos(viewport_widget->width() - cursor->boundingRect().width()
                           ,viewport_widget->height() - cursor->boundingRect().height());
        }
    }
}
*/


void MainWindow::on_actionCreate_doors_from_selected_rect_triggered()
{
    QList<QGraphicsItem *> selected_items = scene_->selectedItems();
    for (auto &selected_item : selected_items) {
        if (GraphicsItem * item = dynamic_cast<GraphicsItem *>(selected_item)) {
            item->ToggleDoors();
        }
    }
}


void MainWindow::on_actionDesign_triggered()
{

}


void MainWindow::on_radioButton_Design_toggled(bool checked)
{
    if (checked) {
        ui->actionGrid->setChecked(true);
        ui->tabWidget->show();


        if (player) {
            delete player;
            player = nullptr;
        }

        if (spacer) {
            ui->verticalLayout_itemSelectorHolder->removeItem(spacer);
            delete spacer;
            spacer = nullptr;
        }
    }
    else {

        SetCreator(base_idle_creator);
        grid->Clear();

        ui->actionGrid->setChecked(false);
        //ui->tabWidget->clear();
        ui->tabWidget->hide();

        if (!spacer) spacer = new QSpacerItem(0,0, QSizePolicy::Minimum, QSizePolicy::Expanding);
        ui->verticalLayout_itemSelectorHolder->addItem(spacer);

        environment_window->show();


    /*
        QPushButton *button1 = new QPushButton("One");

        connect(button1, &QPushButton::clicked, this, &MainWindow::on_pushButton_test_clicked);

        ui->verticalLayout_itemSelectorHolder->addWidget(button1);
    */

        if (player) {
            delete player;
            player = nullptr;
        }
        player = new Player();
    }
}

void MainWindow::on_actionSet_color_of_selected_rooms_triggered()
{

    QColor clr;
    bool color_picked = false;
    QList<QGraphicsItem *> selected_items = scene_->selectedItems();
    for (auto &selected_item : selected_items) {
        if (GraphicsItem * item = dynamic_cast<GraphicsItem *>(selected_item)) {
            if (!color_picked) {
                clr = QColorDialog::getColor(DEFAULT_ITEM_COLOR, this, "Set selected rooms color");
                color_picked = true;
            }
            item->SetColor(clr);
        }
    }
    if (!color_picked) {
        QMessageBox msgBox;
        msgBox.setWindowTitle(":(");
        msgBox.setText("No shapes were selected");
        msgBox.setStandardButtons(QMessageBox::Yes);
        //msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        if(msgBox.exec() == QMessageBox::Yes){

        }else {

        }
    }
}

void MainWindow::on_actionEnvironment_triggered()
{
    if (!environment_window->isVisible())
        environment_window->show();
}
