#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QDialog>

namespace Ui {
class Tutorial;
}

class Tutorial : public QDialog
{
    Q_OBJECT

public:
    explicit Tutorial(QWidget *parent = nullptr);
    ~Tutorial();

    void SetSlide(int num);

private slots:
    void on_pushButton_next_clicked();

    void on_pushButton_close_clicked();

    void on_checkBox_dont_show_again_toggled(bool checked);

private:
    Ui::Tutorial *ui;  
};

extern Tutorial *tutorial;

#endif // TUTORIAL_H
