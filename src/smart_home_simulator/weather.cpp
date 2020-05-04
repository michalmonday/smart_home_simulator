#include "weather.h"
#include "environment_window.h"
#include "controller_screen.h"
#include "sd_radiator.h"
#include <QDir>
#include <QTextStream>
#include <QPixmap>

#include <QDebug>

Weather *weather = nullptr;

Weather::Weather()
    :
      temp(15),
      temp_range(temperature_range::NEUTRAL),
      is_night(false)
{ 
    weather_types.push_back({"Clear",  "sun.png",    "moon.png"});
    weather_types.push_back({"Cloudy", "cloudy.png", "cloudy-night.png"});
    weather_types.push_back({"Rainy",  "rain.png",   ""});
    type = &weather_types[0];
}

void Weather::Update(const QTime &time)
{
    int hr = time.hour();
    int min = time.minute();

    // if the is_night is about to change, then update the image
    if ((hr >= 20 || hr < 8) != is_night) {
        is_night = !is_night;
        UpdateEnvironmentWidnowWeather(*type);
    }

    if (!environment_window->RandomizeWeatherAutomatically()) return;

    if (hr % 4 == 0 && min == 0) {
        WeatherType &wt = weather_types[ rand() % weather_types.size() ];
        UpdateEnvironmentWidnowWeather(wt);
    }

    if (min % 20 == 0) {
        int last_temp = temp;
        temp += (rand() % 2) * (rand() % 2 == 1 ? 1 : -1);
        if (temp > 32) temp = 32;
        if (temp < 2) temp = 2;

        environment_window->SetTemperature(temp);

        if (controller_screen->auto_heating) {
            if (last_temp > 9 && temp < 10)
                Radiator::TurnOnAll();
            else if (last_temp < 10 && temp > 9)
                Radiator::TurnOffAll();
        }
    }
}

void Weather::SetTypeByName(QString name)
{
    for (auto &wt : weather_types) {
        if (name == wt.name) {
            type = &wt;
            UpdateEnvironmentWidnowWeather(wt);
            return;
        }
    }
    qDebug() << name << " weather was not found.";
}

void Weather::UpdateEnvironmentWidnowWeather(WeatherType &wt)
{
    QString &f_name = is_night && !wt.night_alternative_file_name.isEmpty() ? wt.night_alternative_file_name : wt.file_name;
    environment_window->SetWeatherPixmap( QPixmap("resources/images/weather/" + f_name) );
    environment_window->SetWeatherName(wt.name);
}


