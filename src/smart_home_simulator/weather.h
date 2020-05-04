#ifndef WEATHER_H
#define WEATHER_H

#include <QTime>


struct WeatherType {
    QString name, file_name, night_alternative_file_name;
};


enum temperature_range {
    COLD,
    NEUTRAL,
    HOT
};

class Weather
{
private:
    int temp, temp_range;
    bool is_night;

    WeatherType *type;
    QList<WeatherType> weather_types; // initialized in constructor

public:
    Weather();

    void Update(const QTime &t);
    void Update(const QDateTime &dt) { Update(dt.time()); }

    void SetTemperature(int t) { temp = t; }
    int GetTemperature()       { return temp; }
    int GetTemperatureRange()  { return temp_range; }
    bool IsNight()             { return is_night; }

    WeatherType & GetWeatherType() { return *type; }
    const QList<WeatherType> & GetWeatherTypes() { return weather_types; }
    void SetTypeByName(QString name);

    void UpdateEnvironmentWidnowWeather(WeatherType &wt);

};

extern Weather *weather;

#endif // WEATHER_H
