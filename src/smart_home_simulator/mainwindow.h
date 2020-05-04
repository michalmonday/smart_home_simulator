#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#include "creator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QApplication *app;

    static MainWindow * getMainWinPtr(); // https://stackoverflow.com/a/50205573/4620679

    Ui::MainWindow *ui;
    //QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rect;

    QSpacerItem *spacer;

    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void on_pushButton_clear_all_clicked();

    void on_actionGrid_toggled(bool arg1);

    void on_SmartDeviceButtons_clicked(QAbstractButton * button_ptr);
    void on_ShapeButtons_clicked(QAbstractButton * button);

    void on_actionCreate_doors_from_selected_rect_triggered();

    void on_actionDesign_triggered();
    void on_radioButton_Design_toggled(bool checked);
    void on_actionSet_color_of_selected_rooms_triggered();
    void on_actionEnvironment_triggered();
};

extern MainWindow * pMainWindow;
extern void StatusBarMsg(const char * msg);
extern QSettings *settings;

extern QButtonGroup *smart_device_buttons, *shapes_buttons;

#endif // MAINWINDOW_H
