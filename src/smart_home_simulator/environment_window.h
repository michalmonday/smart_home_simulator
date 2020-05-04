#ifndef ENVIRONMENT_WINDOW_H
#define ENVIRONMENT_WINDOW_H

#include <QDialog>
#include <QTime>
#include <QTimer>

namespace Ui {
class EnvironmentWindow;
}

class EnvironmentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnvironmentWindow(QWidget *parent = nullptr);
    ~EnvironmentWindow();

    QDateTime GetDateTime();
    QTime GetTime();
    QString GetDayOfTheWeek();

    void SetTemperature(int celcius);
    void SetWeatherType(int type);
    void SetWeatherName(QString name);

    void SetWeatherPixmap(const QPixmap &p);

    bool RandomizeWeatherAutomatically();

private slots:
    void on_dateTimeEdit_dateChanged(const QDate &date);

    void on_horizontalSlider_valueChanged(int value);

    void OnTimer();

    void on_comboBox_weather_type_currentTextChanged(const QString &arg1);

    void on_comboBox_weather_type_activated(const QString &arg1);

    void on_spinBox_temperature_valueChanged(int arg1);

    void on_checkBox_freeze_time_toggled(bool checked);

private:
    Ui::EnvironmentWindow *ui;

    QTimer *timer;

    void UpdateDayOfWeek(const QDate &date);

};

extern EnvironmentWindow *environment_window;

#endif // ENVIRONMENT_WINDOW_H
