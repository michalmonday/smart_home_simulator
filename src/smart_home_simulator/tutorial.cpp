#include "tutorial.h"
#include "ui_tutorial.h"

#include <QLabel>
#include <QMovie>
#include <QDebug>
#include "mainwindow.h"

Tutorial *tutorial = nullptr;


Tutorial::Tutorial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tutorial)
{
    ui->setupUi(this);
}

Tutorial::~Tutorial()
{
    delete ui;
}


static QList<QPair<QString, QString>> slides = {
    {"test.gif", "Testing description"},            // test.gif is located in: resources/tutorial/
    {"resizable_window.gif", "Another description"},
    {"book pic.jpg", "test"}
};

void Tutorial::on_pushButton_next_clicked()
{
    static int current_slide = 0;
    if (++current_slide >= slides.size()) {
        qDebug() << "Provided slide number is higher than the number of prepared slides. (slide number = " << current_slide << ")";
        current_slide %= slides.size();
    }
    SetSlide(current_slide);

}

void Tutorial::SetSlide(int num) {
    QString gif_name = slides[num].first;
    QString description = slides[num].second;

    // set gif
    QMovie *movie = new QMovie("resources/tutorial/" + gif_name);
    movie->setScaledSize(ui->label_gifholder->size());
    if (!movie->isValid()) { qDebug() << gif_name << " gif couldn't be loaded"; return; }

    // cleanup old gif
    if (QMovie *old_movie = ui->label_gifholder->movie()) delete old_movie;
    ui->label_gifholder->setMovie(movie);
    movie->start();

    // set description
    ui->label_textholder->setText(description);

    // set "Next" button text
    ui->pushButton_next->setText(QString().sprintf("Next %d/%d", num+1, slides.size()));
}

void Tutorial::on_pushButton_close_clicked()
{
    delete this;
}

void Tutorial::on_checkBox_dont_show_again_toggled(bool checked)
{
    settings->setValue("dont_show_tutorial_again", checked);
}
