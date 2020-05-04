# Product Demonstration Report

# List of contents:  
* [Overview](#overview)
* [Features implemented so far](#features-implemented-so-far)
    * [Resizable window image](#resizable-window-image)
    * [Basic menu](#basic-menu)
    * [Grid](#grid)
    * [Shapes creation](#shapes-creation)
    * [Snap to grid while moving shapes](#snap-to-grid-while-moving-shapes)
    * [Select move and delete multiple shapes](#select-move-and-delete-multiple-shapes)
    * [Opaque area detection](#opaque-area-detection)
    * [Detect the smallest shape under cursor](#detect-the-smallest-shape-under-cursor)
    * [Status info bar](#status-info-bar)
    * [Zoom](#zoom)
    * [Placing smart devices](#placing-smart-devices)
    * [Actor selection and movement](#actor-selection-and-movement)
    * [Control screen usage](#control-screen-usage)
* [Implementation details](#implementation-details)


# Overview
So far a significant number of design mode features was accomplished, with few elements of simulation as well. We believe that the minimal requirements for the project can be met by us in the future, possibly with few additional features.  


# Features implemented so far


### Resizable window image

The "QGraphicsView" element inside the window scales nicely as the window is resized.  

![resizble_window_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/resizable_window.gif)  


### Basic menu

It's a very basic menu at this point but more options will be added after the minimum requirements for the assignment will be met.  

![menu_image](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/menu.png)


### Grid

The grid can be toggled from the menu. Graphical items snap to grid when they're created or moved, which can be seen on the few gifs below.  
The size, granularity and colour of the grid can be easily changed, which can be seen in the code responsible for creating/clearing it.  
Giving the user control over these 3 variables may possibly be added as an additional feature in the future (these type of improvements have low priority though).  

It is possible that the implementation of grid will change in future, in the current state it crates a large number of graphic items, which makes looping over all items inefficient. A few different resources were accessed trying to find an optimal solution, however no choice has been made yet to pick an alternative to the current one.   
[qtcentre - Drawing grids efficiently in QGraphicsScene](https://www.qtcentre.org/threads/5609-Drawing-grids-efficiently-in-QGraphicsScene)   
[stackoverflow - Efficient Grid in Qt](https://stackoverflow.com/questions/12569578/efficient-grid-in-qt)  
[Draw Grid on QGraphicsScene](http://tufangorel.blogspot.com/2011/08/draw-grid-on-qgraphicsscene.html)  

```cpp
// grid.h file

#define GRID_SIZE 500
#define GRID_GRANULARITY 20
#define GRID_COLOR QColor(230,230,230)
```

```cpp
// grid.cpp file

void Grid::Set(int granularity_, int size, QColor color) {
/*
 ... contents of the Set method
*/
}

void Grid::Clear(){
    is_set = false;
    if (lines_group) delete lines_group;
    lines_group = new QGraphicsItemGroup();
}

```

![grid_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/grid_set_clear.gif)


### Shapes creation

So far the 3 main shapes can be selected:  
* rectangle  
* ellipse  
* polygon  

Once the shape is selected from the panel on the left the program enters either:  
* **press_and_drag_creator** mode (for rectangle and ellipse)  
* **polygon_creator** mode   

Both of these modes allow the convenient creation of the desired shape.  
When any of these modes is entered, the background changes colour to plain white.  
When any of these modes is exited (by pressing the escape key or RMB), the background changes colour to slightly gray.  

![shapes_cretion_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/shapes_creation.gif)


### Snapping to the grid while moving shapes

When a graphic item is moved it automatically snaps to the grid.  
The code below shows how it's implemented (by overriding "itemChange" method of QGraphicsItem). Modular design allows the code to be relatively simple. The "GetClosestPoint" method is contained by the Grid class, and can be used wherever it's needed in the project.  

```cpp
// graphics_item.cpp file

QVariant GraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionChange && scene()) {
        return grid->GetClosestPoint(value.toPointF());
    }
    return QGraphicsItem::itemChange(change, value);
}
```


```cpp
// grid.cpp file

QPointF Grid::GetClosestPoint(QPointF pos) {
    int g = (int)granularity;
    int x = (((int)pos.x() + g / 2) / g) * g;
    int y = (((int)pos.y() + g / 2) / g) * g;

    return QPointF(x, y);
    // https://stackoverflow.com/questions/29557459/round-to-nearest-multiple-of-a-number
}
```

![snap_to_grid_while_moving_shapes_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/snap_to_grid_on_move.gif)


### Select move and delete multiple shapes

Multiple items can be selected and can be moved at the same time or deleted them by pressing the "del" key. It can be noticed that different effects are applied to the shapes when they're selected, or hovered over.  

The ability to select and move items is achieved by setting flags of the QGraphicsItem object.

```cpp
// graphics_item.h file

#define ITEM_FLAGS QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges
```

```cpp
// graphics_item.cpp file

GraphicsItem::GraphicsItem(int type) {
/* ... */
    setFlags(ITEM_FLAGS);
/* ... */
}
```

Effects on hover/select are accomplished by overriding the "paint" method of QGraphicsItem.  

```cpp
// graphics_item.h file

#define SELECTED_PEN QPen(Qt::black, 1)
#define SELECTED_COLOR QColor(0, 74, 194, 50)
#define HOVER_PEN QPen(Qt::black, 2)
```

```cpp
// graphics_item.cpp file

void GraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
/* ... */
    bool is_selected = option->state & QStyle::State_Selected;
    if (is_selected && creator == base_idle_creator) {
        pen_ = SELECTED_PEN;
        brush_ = SELECTED_COLOR;
    } else {
        pen_ = DEFAULT_ITEM_PEN;
        brush_ = DEFAULT_ITEM_COLOR;
    }

    if (hovered && creator == base_idle_creator) {
        pen_ = HOVER_PEN;
        PaintSelectionDashedBoundingRect(painter); // could be replaced with QRubberBand (but it's alright)
    }

    pen_.setCosmetic(true); // makes it consistent regardless of zoom (otherwise it would be barely visible when zoomed-out)
    painter->setPen(pen_);
    painter->setBrush(brush_);
/* ... */
```

![select_move_and_delete_multiple_shapes_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/select_move_delete_multiple_items.gif)


### Opaque area detection

The program recognizes when the user moves the mouse over the opaque area of a shape (instead of relying on the bounding rectangle of the shape).
It's accomplished by overriding the "shape" method of QGraphicsItem

```cpp
// graphics_item.cpp file

QPainterPath GraphicsItem::shape() const
{
    if (item_type == ITEM_POLYGON) {
        QPainterPath path;
        path.addPolygon(polygon);
        return path;
    }

    if (item_type == ITEM_ELLIPSE) {
        QPainterPath path;
        path.addEllipse(boundingRect());
        return path;
    }
    return QGraphicsItem::shape();
}
```

![opaque_area_detection_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/response_on_opaque_area.gif)


### Detect the smallest shape under the cursor

During program operation and design process, it may happen that there are multiple items on top of each other. In order to make the usage comfortable, the program detects the smallest item under the cursor and automatically adjusts its "Z value" (which gives it priority to be selected when LMB is clicked). The "on hover" effect allows you to see it, as shown on the gif below.  
It's implemented in the "GraphicsScene::mouseMoveEvent" callback where the smallest item under the cursor is assigned higher than the normal "Z Value". That value is getting reset to normal once the new smallest item is found.

```cpp
// graphics_scene.cpp file

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{ 
    if (creator->mouseMoveEvent(event)) return;
    QGraphicsItem *smallest_item = nullptr;
    int smallest_shape_length = INT_MAX;
    for (auto & item : items()) {
        if (
            item->isUnderMouse() &&
            item->type() != 6 &&
            !qgraphicsitem_cast<QGraphicsEllipseItem*>(item) &&
            !qgraphicsitem_cast<QGraphicsItemGroup*>(item)
            )
        {
            int shape_length = item->shape().length();
            if (shape_length < smallest_shape_length) {
                smallest_shape_length = shape_length;
                smallest_item = item;
            }
        }
    }

    if (smallest_item) {
        smallest_item->setZValue(1.0);
        smallest_item->update();
        if (smallest_item != hovered_item) {
            if (hovered_item && hovered_item) hovered_item->setZValue(0.1);
            hovered_item = smallest_item;
        }
    }

    QGraphicsScene::mouseMoveEvent(event);
}
```

![detect_smallest_shape_under_cursor_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/smallest_element_under_cursor_detection.gif)


### Status info bar

The status info bar at the bottom of the window informs the user about the current state of the app and the behaviour of keys/buttons.  
At this point of development it displays the current "creator" state.  

```cpp
// mainwindow.cpp file

/* Auxliary function to avoid using long chain of pointers */
void StatusBarMsg(const char * msg) {
    if (pMainWindow)
        pMainWindow->ui->statusBar->showMessage(msg);
}
```

```cpp
// mainwindow.h file

extern void StatusBarMsg(const char * msg);
```

```cpp
// creator.cpp file

void SetCreator(Creator * c) {
/* ... */
    if      (c == polygon_creator)        { StatusBarMsg("Polygon creator - LMB to create point, RMB to erase last point (or exit mode if it's 1st point)"); }
    else if (c == press_and_drag_creator) { StatusBarMsg("Press and drag creator - LMB to draw the shape, RMB to exit the mode."); }
    else if (c == smart_device_creator)   { StatusBarMsg("Smart device creator - LMB to create, RMB to exit the mode."); }
    else {
        StatusBarMsg("IDLE - no creator selected");
        scene_->setBackgroundBrush(QColor(245, 245, 245));
    }
/* ... */
}
``` 

![status_info_bar_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/status_info_bar.gif)


### Zoom

As mentioned in the comments at the top of Zoom.h and Zoom.cpp files, the code responsible for zooming functionality was copied from the [example](https://stackoverflow.com/a/19114517/4620679) posted by [Pavel Strakhov](https://stackoverflow.com/users/344347/pavel-strakhov).

```cpp
// mainwindow.cpp file

#include "zoom.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
/* ... */
    Zoom* z = new Zoom(ui->graphicsView);
    z->set_modifiers(Qt::ControlModifier);
/* ... */
}
```

```cpp
// zoom.h and zoom.cpp files

/*
Copied from https://stackoverflow.com/a/19114517/4620679
Author: Pavel Strakhov - https://stackoverflow.com/users/344347/pavel-strakhov
*/
```

![zoom_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/zoom.gif)


### Placing smart devices

The buttons on the left panel are inconsistent with the list of shapes in the "Shapes" tab. This may change in the final version of the program.  

![placing_smart_devices](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/placing_smart_devices.gif)


### Actor selection and movement

When the user moves the mouse over the actor, a marker with decreased opacity is displayed under the actor, creating a sense of responsiveness (hoverEnter / hoverExit events).
When the actor is clicked, the opacity is set to a higher value and the actor can be moved (focusIn / focustOut events). 

```cpp
// actor.cpp file

void Actor::focusInEvent(QFocusEvent *event)
{
    qDebug() << "Actor::focusInEvent";
    if (marker) {
        marker->setOpacity(1);
        marker->setVisible(true);
    }
    QGraphicsPixmapItem::focusInEvent(event);
}

void Actor::focusOutEvent(QFocusEvent *event)
{
    qDebug() << "Actor::focusOutEvent";
    if (marker) {
        marker->setVisible(false);
    }
    QGraphicsPixmapItem::focusOutEvent(event);
}

/* ... */

void Actor::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if (marker && !hasFocus()) {
        marker->setOpacity(MARKER_OPACITY_ON_HOVER);
        marker->setVisible(true);
    }
}

void Actor::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (marker) {
        if (!hasFocus())
            marker->setVisible(false);
        else marker->setOpacity(1);
    }
}
```

The movement method mimics the methods used in most of the 2D games (e.g. old pokemon games). The actor can move to a certain point in the screen without changing the position of the viewport. The code below shows where it is implemented.

```cpp
// actor.cpp file

void Actor::UpdateViewport() {
/* Lots of nasty lines to get the right coordinates */
    if (d_l < l) h_diff = d_l - l;
    if (d_r > r) h_diff = d_r - r;
    if (d_t < t) v_diff = d_t - t;
    if (d_b > b) v_diff = d_b - b;

    if (h_diff || v_diff)
        v->centerOn(screen_center_scene_pos + QPointF(h_diff, v_diff));
}
```

An animation based on switching pixmap (still, left_leg_up, right_leg_up) is used to create an illusion of the actor walking. Pressing shift makes the actor move 2x faster.  

```cpp
// actor.cpp file

/* Loading pixmaps from files */
Actor::Actor(QGraphicsItem *parent)
/* ... */
    anim_pixmaps.still = QPixmap("resources/images/actor/dude.png").scaledToHeight(GRID_GRANULARITY*5);
    anim_pixmaps.left_up = QPixmap("resources/images/actor/dude_left_leg_up.png").scaledToHeight(GRID_GRANULARITY*5);
    anim_pixmaps.right_up = QPixmap("resources/images/actor/dude_right_leg_up.png").scaledToHeight(GRID_GRANULARITY*5);
    pixmap = &anim_pixmaps.still;
    setPixmap(*pixmap);
/* ... */
}

/* Animation and shift to speed-up mechanism */
void Actor::Move() {
/* ... */
    // Shift to speed-up mechanism
    qreal speed_mult = GetKeyState(VK_SHIFT) & ~1 ? SHIFT_SPEED_INCREASE : 1;
    qreal x = scenePos().x();
    qreal y = scenePos().y();
    if (mov_h)
        x += mov_h * speed * speed_mult;
    if (mov_v)
        y += mov_v * speed * speed_mult;
/* ... */
        // Animation mechanism
        if (GetTickCount() > last_leg_switch + LEG_SWITCH_INTERVAL / speed_mult) {
            last_leg_switch = GetTickCount();
            if (pixmap == &anim_pixmaps.left_up) pixmap = &anim_pixmaps.right_up;
            else pixmap = &anim_pixmaps.left_up;
            setPixmap(*pixmap);
        }
/* ... */
```

/

![actor_movement_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/player_selection_and_movement.gif)


### Control screen usage

At this stage of development a simple collision detection is used to check that the player is near the controller screen. It is planned to improve it by using threshold and checking the distance between the actor and the control screen. For the sake of responsiveness when the user moves the cursor over the control screen, the label "Click to open" changes its colour.  

The code below shows how collision detection is done in order to make the "Control Screen" smart device clickable (and to display "Click to open" text).  
```cpp
// actor_player.cpp

void Player::Move() {
    if (IsNearControlScreen()) near_controlscreen->SetVisibleToUser(true);
    else if (near_controlscreen) {
        near_controlscreen->SetVisibleToUser(false);
        near_controlscreen = nullptr;
    }
    Actor::Move();
}

bool Player::IsNearControlScreen() {
    for (auto &item : collidingItems()) {
        if (ControlScreen *sd_controlscreen = dynamic_cast<ControlScreen*>(item)) {
            if (near_controlscreen) near_controlscreen->SetVisibleToUser(false);
            near_controlscreen = sd_controlscreen;
            return true;
        }
    }

    return false;
}
```

The code below shows actually setting the text item to visible/invisible + colour change on hover (program responsiveness).  
```cpp
// sd_controlscreen.cpp

// Setting the "click to open" text visible/invisible
void ControlScreen::SetVisibleToUser(bool is_visible) {
    state.visible_to_user = is_visible;
    click_me_text->setVisible(is_visible);
}
/* ... */

// Changing color (program responsiveness)
void ControlScreen::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    if (state.visible_to_user) {
        click_me_text->setBrush(Qt::darkGreen);
/* ... */

void ControlScreen::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    click_me_text->setBrush(CLICK_ME_BRUSH);
/* ... */
```

The dialog that appears after clicking on the control screen is in early stage of development but allows the user to change the states of lights :heavy_check_mark: (on/off, brightness, colour) and power sockets :heavy_check_mark: (on/off).  

The change of light brightness is accomplished in the following code using in-built Qt objects such as "QGraphicsOpacityEffect" and "QRadialGradient":  

```cpp
// sd_light.cpp

void Light::InitGlowItem() {
/* ... */

    // Adjusting at which point the effect should be transparent (using "QRadialGradient" object)
    opacity_gradient = new QRadialGradient(QPointF(state_sz, state_sz), state_sz);
    opacity_gradient->setColorAt(0.6, Qt::transparent);
    opacity_gradient->setColorAt(1.0, Qt::transparent);
/* ... */

    // Initializing the effect object
    glow_opacity_effect = new QGraphicsOpacityEffect;
/* ... */
}

// setting the opacity mask of the object (which represents the brightness)
void Light::SetGlowOpacity(int opacity) {
    opacity_gradient->setColorAt(0.75, QColor(0,0,0, opacity % 256));
    glow_opacity_effect->setOpacityMask(*opacity_gradient);
}
```

The change of light brightness is triggered by the change of the horizontal slider position:

```cpp
// controller_screen.cpp

void ControllerScreen::on_horizontalSlider_selectedLightsOpacity_sliderMoved(int position)
{
    for (auto &item : scene_->selectedItems()) {
        if (Light* light = dynamic_cast<Light*>(item)) {
            light->SetGlowOpacity(position);
        }
    }
}
```

The change of light colour is accomplished in the following code using in-built "QColorDialog" object that make colour-picking very concise (1-line solution):  

```cpp
// controller_screen.cpp

void ControllerScreen::on_pushButton_setSelectedLightsColor_clicked()
{
    // boolean used to avoid the color-picker popup appearing 
    bool color_picked = false;
    
    QColor clr;
    
    // for all selected graphical items
    for (auto &item : scene_->selectedItems()) {
    
        // check if it's a light item
        if (Light* light = dynamic_cast<Light*>(item)) {
        
            // create color-picker dialog only if it wasn't previously picked (to avoid multiple popup for each selected items)
            if (!color_picked) {
            
                // create popup that allows selecting colour
                clr = QColorDialog::getColor(light->GetColor(), this, "Set light color"); // consider adding last param with options to make it nicer
                color_picked = true;
            }
            
            light->SetGlowColor(clr);
        }
    }
}
```

```cpp
// sd_light.cpp

void Light::SetGlowColor(QColor clr)
{
    state.color = clr;
/* ... */
    gradient.setColorAt(1, clr);
    
    glow_item->setBrush(gradient);
}
```

![control_screen_states_control_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/control_screen_states_control.gif)  

In the future, the control screen dialog might dynamically generate and hide options/buttons/widgets based on the selected items by the user. It may also contain the log of the events and a set of indicators for in-built sensors (e.g. temperature, humidity, weather forecast based on online API that fetches current weather in the city recognized by another API).  



# Implementation details
A lot of effort was put to avoid writing code that is unclear and over-complicated. For that reason polymorphism was used to simplify the implementation by removing "type" containing variables and conditional checks for these. 3 examples of using this technique are:
* "Creator" class - which allows creating different shapes in different ways (without polluting the code) and contains the following set of virtual methods (that can be implemented in sub-classes where needed):
    * mousePressEvent
    * mouseMoveEvent
    * mouseReleaseEvent
    * keyPressEvent
    * keyReleaseEvent
* Set of smart device sub-classes derived from the QGraphicsItem class provided by Qt containing the following set of virtual methods:
    * paint
    * hoverEnterEvent
    * hoverLeaveEvent
    * keyPressEvent
    * keyReleaseEvent
    * mousePressEvent
    * mouseMoveEvent
    * mouseReleaseEvent
    * itemChange
* Player being a subclass of Actor. Where Actor class implements movement/selection/drawing mechanisms, and Player class implements only the interaction with the ControlScreen (without being polluted with anything else).  

### Creator and its' sub-classes
<img alt="creators_polymorphism_diagram_image"  src="https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/Team%20project%20-%20Creators.png" width="800" border="5" />

### QGraphicsItem and its' sub-classes
<img alt="qgraphicsitem_polymorphism_diagram_image"  src="https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/Team%20project%20-%20QGraphicsItem%20derived%20tree%20.png" width="800" />