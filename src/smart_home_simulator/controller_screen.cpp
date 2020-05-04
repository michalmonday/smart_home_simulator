#include "controller_screen.h"
#include "ui_controller_screen.h"
#include "graphics_scene.h"

#include "sd_controlscreen.h"
#include "sd_doorbell.h"
#include "sd_light.h"
#include "sd_powersocket.h"
#include "sd_radiator.h"
#include "weather.h"

#include "actor_player.h"
#include "audio.h"
#include "sd_fan.h"

#include "environment_window.h"

#include <QColorDialog>
#include <QLayout>

#include <QMessageBox>

ControllerScreen *controller_screen;

ControllerScreen::ControllerScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControllerScreen),
    auto_lights(false),
    auto_heating(false),
    lights_mimic_sun(false),
    auto_blinds_close(false),
    auto_blinds_open(false)
{
    ui->setupUi(this);
    ui->horizontalSlider_selectedLightsOpacity->setValue(150);

    ui->comboBox_songs->addItems(audio->GetSongNames());

    ui->tableWidget_song_alarms->setColumnWidth(0, 160);
    ui->tableWidget_song_alarms->setColumnWidth(1, 58);
}

ControllerScreen::~ControllerScreen()
{
    delete ui;
}


// on close
void ControllerScreen::reject()
{
    if (player)
        player->OnControllerScreenClose();
    QDialog::reject();

    /* //https://stackoverflow.com/a/17482796/4620679
    QMessageBox::StandardButton resBtn = QMessageBox::Yes;
    if (changes) {
        resBtn = QMessageBox::question( this, "APP_NAME",
                                        tr("Are you sure?\n"),
                                        QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                        QMessageBox::Yes);
    }
    if (resBtn == QMessageBox::Yes) {
        QDialog::reject();
    }*/
}

void ControllerScreen::on_pushButton_toggleSelectedLights_clicked()
{
    for (auto &item : scene_->selectedItems()) {
        if (Light* light = dynamic_cast<Light*>(item)) {
            light->Toggle();
        }
    }
}

void ControllerScreen::on_pushButton_setSelectedLightsColor_clicked()
{
    bool color_picked = false;
    QColor clr;
    for (auto &item : scene_->selectedItems()) {
        if (Light* light = dynamic_cast<Light*>(item)) {
            if (!color_picked) {
                clr = QColorDialog::getColor(light->GetColor(), this, "Set light color"); // consider adding last param with options to make it nicer
                color_picked = true;
            }
            light->SetGlowColor(clr);
        }
    }
}



void ControllerScreen::on_horizontalSlider_selectedLightsOpacity_sliderMoved(int position)
{
    for (auto &item : scene_->selectedItems()) {
        if (Light* light = dynamic_cast<Light*>(item)) {
            light->SetGlowOpacity(position);
        }
    }
}

void ControllerScreen::on_pushButton_toggleSelectedPowerSockets_clicked()
{
    for (auto &item : scene_->selectedItems()) {
        if (PowerSocket* power_socket = dynamic_cast<PowerSocket*>(item)) {
            power_socket->Toggle();
        }
    }
}


void ControllerScreen::on_checkBox_AutoLights_toggled(bool checked)
{
    auto_lights = checked;
}

void ControllerScreen::on_checkBox_mimic_sun_color_temperature_toggled(bool checked)
{
    lights_mimic_sun = checked;
}


void ControllerScreen::on_pushButton_add_new_song_alarm_clicked()
{
    QString file_name = ui->comboBox_songs->currentText();
    if (file_name.isEmpty()) return;

    int i = ui->tableWidget_song_alarms->rowCount();
    ui->tableWidget_song_alarms->insertRow(i);

    QTableWidgetItem *pCellName = ui->tableWidget_song_alarms->item(i, 0);
    QTableWidgetItem *pCellTime = ui->tableWidget_song_alarms->item(i, 1);
    if(!pCellName) {
        pCellName = new QTableWidgetItem;
        ui->tableWidget_song_alarms->setItem(i, 0, pCellName);
    }
    if(!pCellTime) {
        pCellTime = new QTableWidgetItem;
        ui->tableWidget_song_alarms->setItem(i, 1, pCellTime);
    }


    pCellName->setText(file_name);
    pCellTime->setText(ui->timeEdit->time().toString());
}

QTableWidget * ControllerScreen::GetSongAlarmsTable()
{
    return ui->tableWidget_song_alarms;
}

QTime ControllerScreen::GetBlindsAutoOpenTime()
{
    return ui->timeEdit_blinds_auto_open->time();
}

QTime ControllerScreen::GetBlindsAutoCloseTime()
{
    return ui->timeEdit_blinds_auto_close->time();
}


void ControllerScreen::on_tableWidget_song_alarms_itemClicked(QTableWidgetItem *item)
{
    ui->tableWidget_song_alarms->removeRow(item->row());
}

void ControllerScreen::on_pushButton_toggle_selected_radiators_clicked()
{
    for (auto &item : scene_->selectedItems()) {
        if (Radiator* rad = dynamic_cast<Radiator *>(item)) {
            rad->Toggle();
        }
    }
}

void ControllerScreen::on_horizontalSlider_selected_radiators_power_level_valueChanged(int value)
{
    for (auto &item : scene_->selectedItems()) {
        if (Radiator* rad = dynamic_cast<Radiator *>(item)) {
            rad->SetPowerLevel(value/100.0f);
        }
    }
}

void ControllerScreen::on_checkBox_heating_auto_on_off_toggled(bool checked)
{
    auto_heating = checked;
    if (auto_heating) {
        int temp = weather->GetTemperature();
        if (temp >= 20) {
            Fan::TurnOnAll();
        } else {
            Fan::TurnOffAll();
        }

        if (temp < 10) {
            Radiator::TurnOnAll();
        } else {
            Radiator::TurnOffAll();
        }
    }
}

void ControllerScreen::on_checkBox_blinds_auto_close_toggled(bool checked)
{
    auto_blinds_close = checked;
}

void ControllerScreen::on_checkBox_blinds_auto_open_toggled(bool checked)
{
    auto_blinds_open = checked;
}
