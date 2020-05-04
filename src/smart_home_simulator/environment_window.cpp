#include "environment_window.h"
#include "ui_environment_window.h"
#include "controller_screen.h"
#include "graphics_scene.h"
#include "sd_light.h"
#include "sun_colour.h"

#include "audio.h"
#include "sd_fan.h"
#include "sd_radiator.h"
#include "weather.h"
#include "sd_blinds.h"

#include <QLineEdit>

EnvironmentWindow *environment_window = nullptr;

static QString days_of_week[] = { "-", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

EnvironmentWindow::EnvironmentWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnvironmentWindow)
{
    ui->setupUi(this);
    QDateTime dt = QDateTime::currentDateTime();
    ui->dateTimeEdit->setDateTime(dt);
    UpdateDayOfWeek(dt.date());

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &EnvironmentWindow::OnTimer);
    timer->start(1000);

    for (auto &wt : weather->GetWeatherTypes())
        ui->comboBox_weather_type->addItem(wt.name);
}

void EnvironmentWindow::OnTimer() {
    QDateTime dt = ui->dateTimeEdit->dateTime();
    QTime time(dt.time().hour(), dt.time().minute());
    ui->dateTimeEdit->setDateTime(dt.addSecs(60));

    if (controller_screen->lights_mimic_sun) {
        for (auto &item : scene_->items()) {
            if (Light *light = dynamic_cast<Light *>(item)) {
                QColor clr = SunColour::GetColourForDayTime(time);
                //qDebug() << "New light colour = " << clr;
                light->SetGlowColor(clr);
            }
        }
    }

    QTableWidget *song_alarms_tbl = controller_screen->GetSongAlarmsTable();
    for (int i = 0; i < song_alarms_tbl->rowCount(); i++) {
        QString time_str = song_alarms_tbl->item(i, 1)->text();
        QTime time_ = QTime().fromString(time_str);
        if (time_.hour() == time.hour() && time.minute() == time.minute()) {
            QString song_file = song_alarms_tbl->item(i, 0)->text();

            audio->PlaySong(song_file);
        }
    }

    if (controller_screen->auto_blinds_open) {
        QTime auto_open_time = controller_screen->GetBlindsAutoOpenTime();
        if (auto_open_time == time)
            Blinds::OpenAll();
    }

    if (controller_screen->auto_blinds_close) {
        QTime auto_close_time = controller_screen->GetBlindsAutoCloseTime();
        if (auto_close_time == time)
            Blinds::CloseAll();
    }


    weather->Update(dt);
}

EnvironmentWindow::~EnvironmentWindow()
{
    delete ui;
}

QDateTime EnvironmentWindow::GetDateTime()   { return ui->dateTimeEdit->dateTime(); }
QTime EnvironmentWindow::GetTime()           { return GetDateTime().time(); }
QString EnvironmentWindow::GetDayOfTheWeek() { return ui->label_day_of_week->text(); }

void EnvironmentWindow::SetTemperature(int celcius)
{
    ui->spinBox_temperature->setValue(celcius);
}

void EnvironmentWindow::SetWeatherName(QString name)
{
    ui->comboBox_weather_type->setCurrentText(name);
}

void EnvironmentWindow::SetWeatherPixmap(const QPixmap &p)
{
    ui->label_weather_icon_holder->setScaledContents(true);
    ui->label_weather_icon_holder->setPixmap(p);
}

bool EnvironmentWindow::RandomizeWeatherAutomatically()
{
    return ui->checkBox_randomize_automatically->isChecked();
}


void EnvironmentWindow::on_dateTimeEdit_dateChanged(const QDate &date)
{
    UpdateDayOfWeek(date);
}

void EnvironmentWindow::UpdateDayOfWeek(const QDate &date)
{
    int i_dow = date.dayOfWeek();
    ui->label_day_of_week->setText(days_of_week[i_dow]);
}

void EnvironmentWindow::on_horizontalSlider_valueChanged(int value)
{
    if (!timer->isActive() && value)
        timer->start(1000 / value);

    if (timer->isActive()) {
        if (value)
            timer->setInterval(1000 / value);
        else
            timer->stop();
    }
}


void EnvironmentWindow::on_comboBox_weather_type_currentTextChanged(const QString &arg1)
{

}

void EnvironmentWindow::on_comboBox_weather_type_activated(const QString &arg1)
{
    weather->SetTypeByName(arg1);
}

void EnvironmentWindow::on_spinBox_temperature_valueChanged(int temp)
{
    static int last_temp = temp;
    if (temp >= 20) {
        ui->spinBox_temperature->setStyleSheet("QSpinBox { background-color: orange; }");
        if (last_temp < 20 && controller_screen->auto_heating)
            Fan::TurnOnAll();
    }
    else if (temp < 10) {
        ui->spinBox_temperature->setStyleSheet("QSpinBox { background-color: lightblue; }");
        if (last_temp >= 10 && controller_screen->auto_heating)
            Radiator::TurnOnAll();
    }
    else {
        ui->spinBox_temperature->setStyleSheet("QSpinBox { background-color: white; }");
        if (last_temp < 10 && controller_screen->auto_heating)
            Radiator::TurnOffAll();
    }

    if (controller_screen->auto_heating && last_temp >= 20 && temp < 20)
        Fan::TurnOffAll();

    last_temp = temp;
    weather->SetTemperature(temp);
}

void EnvironmentWindow::on_checkBox_freeze_time_toggled(bool checked)
{
    ui->horizontalSlider->setEnabled(!checked);

    if (checked)
        timer->stop();
    else
        timer->start(1000 / ui->horizontalSlider->value());
}
