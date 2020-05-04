#ifndef CONTROLLER_SCREEN_H
#define CONTROLLER_SCREEN_H

#include <QDialog>
#include <QTableWidget>
#include <QTime>

namespace Ui {
class ControllerScreen;
}

class ControllerScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ControllerScreen(QWidget *parent = nullptr);
    ~ControllerScreen();

    // QDialog interface

    bool auto_lights, auto_heating, auto_blinds_close, auto_blinds_open;
    bool lights_mimic_sun;

    QTableWidget * GetSongAlarmsTable();
    QTime GetBlindsAutoOpenTime();
    QTime GetBlindsAutoCloseTime();
public slots:
    virtual void reject() override;

private slots:

    void on_pushButton_setSelectedLightsColor_clicked();

    void on_pushButton_toggleSelectedLights_clicked();

    void on_horizontalSlider_selectedLightsOpacity_sliderMoved(int position);

    void on_pushButton_toggleSelectedPowerSockets_clicked();

    void on_checkBox_AutoLights_toggled(bool checked);

    void on_checkBox_mimic_sun_color_temperature_toggled(bool checked);

    void on_pushButton_add_new_song_alarm_clicked();

    void on_tableWidget_song_alarms_itemClicked(QTableWidgetItem *item);

    void on_pushButton_toggle_selected_radiators_clicked();

    void on_horizontalSlider_selected_radiators_power_level_valueChanged(int value);

    void on_checkBox_heating_auto_on_off_toggled(bool checked);

    void on_checkBox_blinds_auto_close_toggled(bool checked);

    void on_checkBox_blinds_auto_open_toggled(bool checked);

private:
    Ui::ControllerScreen *ui;
};

extern ControllerScreen *controller_screen;

#endif // CONTROLLER_SCREEN_H
