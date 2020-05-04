/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGrid;
    QAction *actionCreate_doors_from_selected_rect;
    QAction *actionSet_color_of_selected_rooms;
    QAction *actionEnvironment;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_itemSelectorHolder;
    QGroupBox *groupBox_mode;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_Design;
    QRadioButton *radioButton_Simulation;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_shapes_rect;
    QPushButton *pushButton_shapes_ellipse;
    QPushButton *pushButton_shapes_polygon;
    QPushButton *pushButton_shapes_line;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_doorbell;
    QPushButton *pushButton_light_bulb;
    QPushButton *pushButton_power_socket;
    QPushButton *pushButton_speakers;
    QPushButton *pushButton_radiator;
    QPushButton *pushButton_fan;
    QPushButton *pushButton_thermometer;
    QPushButton *pushButton_infra_red_sensor;
    QPushButton *pushButton_toilet;
    QPushButton *pushButton_blinds;
    QPushButton *pushButton_control_screen;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuView;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 681);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QStringLiteral("resources/images/smart devices/house.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionGrid = new QAction(MainWindow);
        actionGrid->setObjectName(QStringLiteral("actionGrid"));
        actionGrid->setCheckable(true);
        actionCreate_doors_from_selected_rect = new QAction(MainWindow);
        actionCreate_doors_from_selected_rect->setObjectName(QStringLiteral("actionCreate_doors_from_selected_rect"));
        actionSet_color_of_selected_rooms = new QAction(MainWindow);
        actionSet_color_of_selected_rooms->setObjectName(QStringLiteral("actionSet_color_of_selected_rooms"));
        actionEnvironment = new QAction(MainWindow);
        actionEnvironment->setObjectName(QStringLiteral("actionEnvironment"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_itemSelectorHolder = new QVBoxLayout();
        verticalLayout_itemSelectorHolder->setSpacing(0);
        verticalLayout_itemSelectorHolder->setObjectName(QStringLiteral("verticalLayout_itemSelectorHolder"));
        verticalLayout_itemSelectorHolder->setContentsMargins(1, -1, -1, 0);
        groupBox_mode = new QGroupBox(centralWidget);
        groupBox_mode->setObjectName(QStringLiteral("groupBox_mode"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_mode->sizePolicy().hasHeightForWidth());
        groupBox_mode->setSizePolicy(sizePolicy1);
        groupBox_mode->setMinimumSize(QSize(191, 0));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        groupBox_mode->setFont(font);
        groupBox_mode->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout = new QVBoxLayout(groupBox_mode);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton_Design = new QRadioButton(groupBox_mode);
        radioButton_Design->setObjectName(QStringLiteral("radioButton_Design"));
        sizePolicy1.setHeightForWidth(radioButton_Design->sizePolicy().hasHeightForWidth());
        radioButton_Design->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        radioButton_Design->setFont(font1);
        radioButton_Design->setChecked(true);

        verticalLayout->addWidget(radioButton_Design);

        radioButton_Simulation = new QRadioButton(groupBox_mode);
        radioButton_Simulation->setObjectName(QStringLiteral("radioButton_Simulation"));
        radioButton_Simulation->setFont(font1);

        verticalLayout->addWidget(radioButton_Simulation);


        verticalLayout_itemSelectorHolder->addWidget(groupBox_mode);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        tabWidget->setFont(font2);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy3);
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton_shapes_rect = new QPushButton(tab);
        pushButton_shapes_rect->setObjectName(QStringLiteral("pushButton_shapes_rect"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_shapes_rect->sizePolicy().hasHeightForWidth());
        pushButton_shapes_rect->setSizePolicy(sizePolicy4);
        pushButton_shapes_rect->setFont(font1);
        QIcon icon1;
        icon1.addFile(QStringLiteral("resources/images/shapes/rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_shapes_rect->setIcon(icon1);
        pushButton_shapes_rect->setIconSize(QSize(25, 25));
        pushButton_shapes_rect->setCheckable(true);
        pushButton_shapes_rect->setFlat(true);

        verticalLayout_2->addWidget(pushButton_shapes_rect);

        pushButton_shapes_ellipse = new QPushButton(tab);
        pushButton_shapes_ellipse->setObjectName(QStringLiteral("pushButton_shapes_ellipse"));
        sizePolicy4.setHeightForWidth(pushButton_shapes_ellipse->sizePolicy().hasHeightForWidth());
        pushButton_shapes_ellipse->setSizePolicy(sizePolicy4);
        pushButton_shapes_ellipse->setFont(font1);
        QIcon icon2;
        icon2.addFile(QStringLiteral("resources/images/shapes/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_shapes_ellipse->setIcon(icon2);
        pushButton_shapes_ellipse->setIconSize(QSize(25, 25));
        pushButton_shapes_ellipse->setCheckable(true);
        pushButton_shapes_ellipse->setFlat(true);

        verticalLayout_2->addWidget(pushButton_shapes_ellipse);

        pushButton_shapes_polygon = new QPushButton(tab);
        pushButton_shapes_polygon->setObjectName(QStringLiteral("pushButton_shapes_polygon"));
        sizePolicy4.setHeightForWidth(pushButton_shapes_polygon->sizePolicy().hasHeightForWidth());
        pushButton_shapes_polygon->setSizePolicy(sizePolicy4);
        pushButton_shapes_polygon->setFont(font1);
        QIcon icon3;
        icon3.addFile(QStringLiteral("resources/images/shapes/polygon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_shapes_polygon->setIcon(icon3);
        pushButton_shapes_polygon->setIconSize(QSize(25, 25));
        pushButton_shapes_polygon->setCheckable(true);
        pushButton_shapes_polygon->setFlat(true);

        verticalLayout_2->addWidget(pushButton_shapes_polygon);

        pushButton_shapes_line = new QPushButton(tab);
        pushButton_shapes_line->setObjectName(QStringLiteral("pushButton_shapes_line"));
        sizePolicy4.setHeightForWidth(pushButton_shapes_line->sizePolicy().hasHeightForWidth());
        pushButton_shapes_line->setSizePolicy(sizePolicy4);
        pushButton_shapes_line->setFont(font1);
        QIcon icon4;
        icon4.addFile(QStringLiteral("resources/images/shapes/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_shapes_line->setIcon(icon4);
        pushButton_shapes_line->setIconSize(QSize(25, 25));
        pushButton_shapes_line->setCheckable(true);
        pushButton_shapes_line->setFlat(true);

        verticalLayout_2->addWidget(pushButton_shapes_line);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sizePolicy3.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy3);
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton_doorbell = new QPushButton(tab_2);
        pushButton_doorbell->setObjectName(QStringLiteral("pushButton_doorbell"));
        sizePolicy4.setHeightForWidth(pushButton_doorbell->sizePolicy().hasHeightForWidth());
        pushButton_doorbell->setSizePolicy(sizePolicy4);
        pushButton_doorbell->setFont(font1);
        pushButton_doorbell->setLayoutDirection(Qt::LeftToRight);
        QIcon icon5;
        icon5.addFile(QStringLiteral("resources/images/smart devices/doorbell.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_doorbell->setIcon(icon5);
        pushButton_doorbell->setIconSize(QSize(30, 30));
        pushButton_doorbell->setCheckable(true);
        pushButton_doorbell->setAutoExclusive(false);
        pushButton_doorbell->setFlat(true);

        verticalLayout_3->addWidget(pushButton_doorbell);

        pushButton_light_bulb = new QPushButton(tab_2);
        pushButton_light_bulb->setObjectName(QStringLiteral("pushButton_light_bulb"));
        sizePolicy4.setHeightForWidth(pushButton_light_bulb->sizePolicy().hasHeightForWidth());
        pushButton_light_bulb->setSizePolicy(sizePolicy4);
        pushButton_light_bulb->setFont(font1);
        QIcon icon6;
        icon6.addFile(QStringLiteral("resources/images/smart devices/smart-light.png"), QSize(), QIcon::Selected, QIcon::Off);
        pushButton_light_bulb->setIcon(icon6);
        pushButton_light_bulb->setIconSize(QSize(30, 30));
        pushButton_light_bulb->setCheckable(true);
        pushButton_light_bulb->setChecked(false);
        pushButton_light_bulb->setFlat(true);

        verticalLayout_3->addWidget(pushButton_light_bulb);

        pushButton_power_socket = new QPushButton(tab_2);
        pushButton_power_socket->setObjectName(QStringLiteral("pushButton_power_socket"));
        sizePolicy4.setHeightForWidth(pushButton_power_socket->sizePolicy().hasHeightForWidth());
        pushButton_power_socket->setSizePolicy(sizePolicy4);
        pushButton_power_socket->setFont(font1);
        QIcon icon7;
        icon7.addFile(QStringLiteral("resources/images/smart devices/socket.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_power_socket->setIcon(icon7);
        pushButton_power_socket->setIconSize(QSize(30, 30));
        pushButton_power_socket->setCheckable(true);
        pushButton_power_socket->setFlat(true);

        verticalLayout_3->addWidget(pushButton_power_socket);

        pushButton_speakers = new QPushButton(tab_2);
        pushButton_speakers->setObjectName(QStringLiteral("pushButton_speakers"));
        sizePolicy4.setHeightForWidth(pushButton_speakers->sizePolicy().hasHeightForWidth());
        pushButton_speakers->setSizePolicy(sizePolicy4);
        pushButton_speakers->setFont(font1);
        QIcon icon8;
        icon8.addFile(QStringLiteral("resources/images/smart devices/speakers.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_speakers->setIcon(icon8);
        pushButton_speakers->setIconSize(QSize(30, 30));
        pushButton_speakers->setCheckable(true);
        pushButton_speakers->setFlat(true);

        verticalLayout_3->addWidget(pushButton_speakers);

        pushButton_radiator = new QPushButton(tab_2);
        pushButton_radiator->setObjectName(QStringLiteral("pushButton_radiator"));
        sizePolicy4.setHeightForWidth(pushButton_radiator->sizePolicy().hasHeightForWidth());
        pushButton_radiator->setSizePolicy(sizePolicy4);
        pushButton_radiator->setFont(font1);
        QIcon icon9;
        icon9.addFile(QStringLiteral("resources/images/smart devices/radiator.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_radiator->setIcon(icon9);
        pushButton_radiator->setIconSize(QSize(30, 30));
        pushButton_radiator->setCheckable(true);
        pushButton_radiator->setFlat(true);

        verticalLayout_3->addWidget(pushButton_radiator);

        pushButton_fan = new QPushButton(tab_2);
        pushButton_fan->setObjectName(QStringLiteral("pushButton_fan"));
        sizePolicy4.setHeightForWidth(pushButton_fan->sizePolicy().hasHeightForWidth());
        pushButton_fan->setSizePolicy(sizePolicy4);
        pushButton_fan->setFont(font1);
        QIcon icon10;
        icon10.addFile(QStringLiteral("resources/images/smart devices/fan.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_fan->setIcon(icon10);
        pushButton_fan->setIconSize(QSize(30, 30));
        pushButton_fan->setCheckable(true);
        pushButton_fan->setFlat(true);

        verticalLayout_3->addWidget(pushButton_fan);

        pushButton_thermometer = new QPushButton(tab_2);
        pushButton_thermometer->setObjectName(QStringLiteral("pushButton_thermometer"));
        sizePolicy4.setHeightForWidth(pushButton_thermometer->sizePolicy().hasHeightForWidth());
        pushButton_thermometer->setSizePolicy(sizePolicy4);
        pushButton_thermometer->setFont(font1);
        QIcon icon11;
        icon11.addFile(QStringLiteral("resources/images/smart devices/thermometer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_thermometer->setIcon(icon11);
        pushButton_thermometer->setIconSize(QSize(30, 30));
        pushButton_thermometer->setCheckable(true);
        pushButton_thermometer->setFlat(true);

        verticalLayout_3->addWidget(pushButton_thermometer);

        pushButton_infra_red_sensor = new QPushButton(tab_2);
        pushButton_infra_red_sensor->setObjectName(QStringLiteral("pushButton_infra_red_sensor"));
        sizePolicy4.setHeightForWidth(pushButton_infra_red_sensor->sizePolicy().hasHeightForWidth());
        pushButton_infra_red_sensor->setSizePolicy(sizePolicy4);
        pushButton_infra_red_sensor->setFont(font1);
        QIcon icon12;
        icon12.addFile(QStringLiteral("resources/images/smart devices/infra red sensor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_infra_red_sensor->setIcon(icon12);
        pushButton_infra_red_sensor->setIconSize(QSize(30, 30));
        pushButton_infra_red_sensor->setCheckable(true);
        pushButton_infra_red_sensor->setFlat(true);

        verticalLayout_3->addWidget(pushButton_infra_red_sensor);

        pushButton_toilet = new QPushButton(tab_2);
        pushButton_toilet->setObjectName(QStringLiteral("pushButton_toilet"));
        sizePolicy4.setHeightForWidth(pushButton_toilet->sizePolicy().hasHeightForWidth());
        pushButton_toilet->setSizePolicy(sizePolicy4);
        pushButton_toilet->setFont(font1);
        QIcon icon13;
        icon13.addFile(QStringLiteral("resources/images/smart devices/toilet.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_toilet->setIcon(icon13);
        pushButton_toilet->setIconSize(QSize(30, 30));
        pushButton_toilet->setCheckable(true);
        pushButton_toilet->setFlat(true);

        verticalLayout_3->addWidget(pushButton_toilet);

        pushButton_blinds = new QPushButton(tab_2);
        pushButton_blinds->setObjectName(QStringLiteral("pushButton_blinds"));
        pushButton_blinds->setFont(font1);
        QIcon icon14;
        icon14.addFile(QStringLiteral("resources/images/smart devices/curtains.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_blinds->setIcon(icon14);
        pushButton_blinds->setIconSize(QSize(30, 30));
        pushButton_blinds->setCheckable(true);
        pushButton_blinds->setFlat(true);

        verticalLayout_3->addWidget(pushButton_blinds);

        pushButton_control_screen = new QPushButton(tab_2);
        pushButton_control_screen->setObjectName(QStringLiteral("pushButton_control_screen"));
        sizePolicy4.setHeightForWidth(pushButton_control_screen->sizePolicy().hasHeightForWidth());
        pushButton_control_screen->setSizePolicy(sizePolicy4);
        pushButton_control_screen->setFont(font1);
        QIcon icon15;
        icon15.addFile(QStringLiteral("resources/images/smart devices/control screen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_control_screen->setIcon(icon15);
        pushButton_control_screen->setIconSize(QSize(30, 30));
        pushButton_control_screen->setCheckable(true);
        pushButton_control_screen->setFlat(true);

        verticalLayout_3->addWidget(pushButton_control_screen);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_itemSelectorHolder->addWidget(tabWidget);


        horizontalLayout->addLayout(verticalLayout_itemSelectorHolder);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setAutoFillBackground(false);

        horizontalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuView->addAction(actionGrid);
        menuView->addAction(actionEnvironment);
        menuEdit->addAction(actionCreate_doors_from_selected_rect);
        menuEdit->addAction(actionSet_color_of_selected_rooms);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        pushButton_doorbell->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Smart home simulator", Q_NULLPTR));
        actionGrid->setText(QApplication::translate("MainWindow", "Grid", Q_NULLPTR));
        actionCreate_doors_from_selected_rect->setText(QApplication::translate("MainWindow", "Create doors from selected shape", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCreate_doors_from_selected_rect->setShortcut(QApplication::translate("MainWindow", "D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSet_color_of_selected_rooms->setText(QApplication::translate("MainWindow", "Set color of selected rooms", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSet_color_of_selected_rooms->setShortcut(QApplication::translate("MainWindow", "C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionEnvironment->setText(QApplication::translate("MainWindow", "Environment", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        groupBox_mode->setToolTip(QApplication::translate("MainWindow", "Pick between design and simulation mode.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_mode->setTitle(QApplication::translate("MainWindow", "Mode", Q_NULLPTR));
        radioButton_Design->setText(QApplication::translate("MainWindow", "Design", Q_NULLPTR));
        radioButton_Simulation->setText(QApplication::translate("MainWindow", "Simulation", Q_NULLPTR));
        pushButton_shapes_rect->setText(QApplication::translate("MainWindow", "        Rectangle", Q_NULLPTR));
        pushButton_shapes_ellipse->setText(QApplication::translate("MainWindow", "             Ellipse", Q_NULLPTR));
        pushButton_shapes_polygon->setText(QApplication::translate("MainWindow", "            Polygon", Q_NULLPTR));
        pushButton_shapes_line->setText(QApplication::translate("MainWindow", "               Line", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Shapes", Q_NULLPTR));
        pushButton_doorbell->setText(QApplication::translate("MainWindow", "          Doorbell", Q_NULLPTR));
        pushButton_light_bulb->setText(QApplication::translate("MainWindow", "               Light", Q_NULLPTR));
        pushButton_power_socket->setText(QApplication::translate("MainWindow", "  Power sockets", Q_NULLPTR));
        pushButton_speakers->setText(QApplication::translate("MainWindow", "         Speakers", Q_NULLPTR));
        pushButton_radiator->setText(QApplication::translate("MainWindow", "          Radiator", Q_NULLPTR));
        pushButton_fan->setText(QApplication::translate("MainWindow", "                Fan", Q_NULLPTR));
        pushButton_thermometer->setText(QApplication::translate("MainWindow", "  Thermometer", Q_NULLPTR));
        pushButton_infra_red_sensor->setText(QApplication::translate("MainWindow", "Infra red sensor", Q_NULLPTR));
        pushButton_toilet->setText(QApplication::translate("MainWindow", "              Toilet", Q_NULLPTR));
        pushButton_blinds->setText(QApplication::translate("MainWindow", "              Blinds", Q_NULLPTR));
        pushButton_control_screen->setText(QApplication::translate("MainWindow", "  Control screen", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Smart devices", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
