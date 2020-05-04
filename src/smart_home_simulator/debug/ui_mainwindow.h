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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDesign;
    QAction *actionSimulation;
    QAction *actionGrid;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_itemSelectorHolder;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_doorbell;
    QPushButton *pushButton_light_bulb;
    QPushButton *pushButton_power_socket;
    QPushButton *pushButton_control_screen;
    QPushButton *pushButton_clear_all;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuSimulator;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 500);
        MainWindow->setMouseTracking(false);
        actionDesign = new QAction(MainWindow);
        actionDesign->setObjectName(QStringLiteral("actionDesign"));
        actionDesign->setCheckable(true);
        actionSimulation = new QAction(MainWindow);
        actionSimulation->setObjectName(QStringLiteral("actionSimulation"));
        actionSimulation->setCheckable(true);
        actionGrid = new QAction(MainWindow);
        actionGrid->setObjectName(QStringLiteral("actionGrid"));
        actionGrid->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_itemSelectorHolder = new QVBoxLayout();
        verticalLayout_itemSelectorHolder->setSpacing(6);
        verticalLayout_itemSelectorHolder->setObjectName(QStringLiteral("verticalLayout_itemSelectorHolder"));
        verticalLayout_itemSelectorHolder->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_itemSelectorHolder->setContentsMargins(1, -1, -1, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        listWidget = new QListWidget(tab);
        QIcon icon;
        icon.addFile(QStringLiteral("resources/images/shapes/rect.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QStringLiteral("resources/images/shapes/circle_clr.png"), QSize(), QIcon::Selected, QIcon::On);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QStringLiteral("resources/images/shapes/circle.png"), QSize(), QIcon::Selected, QIcon::On);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon1);
        __qlistwidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QIcon icon2;
        icon2.addFile(QStringLiteral("resources/images/shapes/polygon.png"), QSize(), QIcon::Selected, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 143, 297));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        listWidget->setFont(font);
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Sunken);
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listWidget->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        listWidget->setDefaultDropAction(Qt::MoveAction);
        listWidget->setAlternatingRowColors(false);
        listWidget->setIconSize(QSize(30, 30));
        listWidget->setTextElideMode(Qt::ElideRight);
        listWidget->setMovement(QListView::Free);
        listWidget->setFlow(QListView::TopToBottom);
        listWidget->setProperty("isWrapping", QVariant(false));
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setSpacing(10);
        listWidget->setViewMode(QListView::ListMode);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sizePolicy1.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_doorbell = new QPushButton(tab_2);
        pushButton_doorbell->setObjectName(QStringLiteral("pushButton_doorbell"));
        sizePolicy.setHeightForWidth(pushButton_doorbell->sizePolicy().hasHeightForWidth());
        pushButton_doorbell->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QStringLiteral("resources/images/smart devices/doorbell.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_doorbell->setIcon(icon3);
        pushButton_doorbell->setIconSize(QSize(30, 30));
        pushButton_doorbell->setCheckable(true);

        verticalLayout_3->addWidget(pushButton_doorbell);

        pushButton_light_bulb = new QPushButton(tab_2);
        pushButton_light_bulb->setObjectName(QStringLiteral("pushButton_light_bulb"));
        sizePolicy.setHeightForWidth(pushButton_light_bulb->sizePolicy().hasHeightForWidth());
        pushButton_light_bulb->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QStringLiteral("resources/images/smart devices/smart-light.png"), QSize(), QIcon::Selected, QIcon::Off);
        pushButton_light_bulb->setIcon(icon4);
        pushButton_light_bulb->setIconSize(QSize(30, 30));
        pushButton_light_bulb->setCheckable(true);
        pushButton_light_bulb->setChecked(false);

        verticalLayout_3->addWidget(pushButton_light_bulb);

        pushButton_power_socket = new QPushButton(tab_2);
        pushButton_power_socket->setObjectName(QStringLiteral("pushButton_power_socket"));
        sizePolicy.setHeightForWidth(pushButton_power_socket->sizePolicy().hasHeightForWidth());
        pushButton_power_socket->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QStringLiteral("resources/images/smart devices/socket.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_power_socket->setIcon(icon5);
        pushButton_power_socket->setIconSize(QSize(30, 30));
        pushButton_power_socket->setCheckable(true);

        verticalLayout_3->addWidget(pushButton_power_socket);

        pushButton_control_screen = new QPushButton(tab_2);
        pushButton_control_screen->setObjectName(QStringLiteral("pushButton_control_screen"));
        sizePolicy.setHeightForWidth(pushButton_control_screen->sizePolicy().hasHeightForWidth());
        pushButton_control_screen->setSizePolicy(sizePolicy);
        QIcon icon6;
        icon6.addFile(QStringLiteral("resources/images/smart devices/control screen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_control_screen->setIcon(icon6);
        pushButton_control_screen->setIconSize(QSize(30, 30));
        pushButton_control_screen->setCheckable(true);

        verticalLayout_3->addWidget(pushButton_control_screen);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_itemSelectorHolder->addWidget(tabWidget);

        pushButton_clear_all = new QPushButton(centralWidget);
        pushButton_clear_all->setObjectName(QStringLiteral("pushButton_clear_all"));

        verticalLayout_itemSelectorHolder->addWidget(pushButton_clear_all);


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
        menuSimulator = new QMenu(menuBar);
        menuSimulator->setObjectName(QStringLiteral("menuSimulator"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSimulator->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuSimulator->addAction(actionDesign);
        menuSimulator->addAction(actionSimulation);
        menuView->addAction(actionGrid);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionDesign->setText(QApplication::translate("MainWindow", "Design", Q_NULLPTR));
        actionSimulation->setText(QApplication::translate("MainWindow", "Simulation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSimulation->setToolTip(QApplication::translate("MainWindow", "Simulation", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionGrid->setText(QApplication::translate("MainWindow", "Grid", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Rectangle", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Ellipse", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Polygon", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Shapes", Q_NULLPTR));
        pushButton_doorbell->setText(QApplication::translate("MainWindow", "Doorbell", Q_NULLPTR));
        pushButton_light_bulb->setText(QApplication::translate("MainWindow", "Light", Q_NULLPTR));
        pushButton_power_socket->setText(QApplication::translate("MainWindow", "Power sockets", Q_NULLPTR));
        pushButton_control_screen->setText(QApplication::translate("MainWindow", "Control screen", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Smart devices", Q_NULLPTR));
        pushButton_clear_all->setText(QApplication::translate("MainWindow", "Clear all", Q_NULLPTR));
        menuSimulator->setTitle(QApplication::translate("MainWindow", "Mode", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
