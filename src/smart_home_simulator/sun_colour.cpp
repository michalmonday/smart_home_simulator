#include "sun_colour.h"

#include <map>
#include <QDebug>
using namespace std;

#define MIN_TIME QTime(6,0)
#define MAX_TIME QTime(18,0)
static map<QTime, int> m = {
    { QTime(6,0), 1900 },
    { QTime(8,0), 3000 },
    { QTime(10,0), 4000 },
    { QTime(12,0), 6600 },
    { QTime(14,0), 4000 },
    { QTime(16,0), 3000 },
    { QTime(18,0), 1900 }
};

SunColour::SunColour() {

}

QColor SunColour::GetColourForDayTime(const QTime &time, int brightness)
{
    if (time < MIN_TIME || time > MAX_TIME)
        return KelvinToQColor(1900, brightness);



    QTime time_under, time_over;
    int temp_under, temp_over;
    for (auto &p : m) {
        if (p.first <= time) {
            time_under = p.first;
            temp_under = p.second;
        }

        if (p.first > time) {
            time_over = p.first;
            temp_over = p.second;
            break;
        }
    }

    /*qDebug() << "time_under = " << time_under << ", temp_under = " << temp_under;
    qDebug() << "time = " << time;
    qDebug() << "time_over = " << time_over << ", temp_over = " << temp_over;*/

    int interpolated_kelvin = map(
                time.msecsSinceStartOfDay()/1000,
                time_under.msecsSinceStartOfDay()/1000,
                time_over.msecsSinceStartOfDay()/1000,
                temp_under,
                temp_over);
    return KelvinToQColor(interpolated_kelvin, brightness);
}

/*  map function was copied from: https://stackoverflow.com/a/5735770
    It's just like it is in Arduino. Usage:
    int val = map(val, 0, 1023, 0, 255);
    */
long SunColour::map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int SunColour::constrain(int value, int min, int max)
{
    if (value > max) return max;
    if (value < min) return min;
    return value;
}


/* Functions below were copied/adapted from:
 https://github.com/timvw74/Kelvin2RGB/blob/master/Kelvin2RGB.h

*/
QColor SunColour::KelvinToQColor(int kelvin_temp, int brightness)
{
    //qDebug() << "kelvin_temp = " << kelvin_temp;

    unsigned int temp = constrain(kelvin_temp, 0, 65500);
    int Brightness = constrain(brightness, 0, 100);
    uint8_t Red = map(Brightness, 0, 100, 0, calculateRed(temp));
    uint8_t Green = map(Brightness, 0, 100, 0, calculateGreen(temp));
    uint8_t Blue = map(Brightness, 0, 100, 0, calculateBlue(temp));
    int Color;
    Color = Red;
    Color = Color<<8;
    Color = Color|Green;
    Color = Color<<8;
    Color = Color|Blue;

    return QColor(Color);
}


uint8_t SunColour::calculateRed(int temp){
    float red = 255;
    int temperature = temp/100;
    if(temperature>66) {
        red = temperature - 60;
        red = 329.698727466 * pow(red,-0.1332047592);
    }
    return (uint8_t)constrain(red, 0, 255);
}

uint8_t SunColour::calculateGreen(int temp){
    float green;
    int temperature = temp/100;
    if(temperature<= 66){
        green = temperature;
        green = (99.4708025861 * log(green)) - 161.1195681661;
    } else {
        green = temperature - 60;
        green = 288.1221695283 * pow(green, -0.0755148492);
    }
    return (uint8_t)constrain(green, 0, 255);
}

uint8_t SunColour::calculateBlue(int temp){
  float blue = 255;
  int temperature = temp/100;
  if(temperature<65){
    if(temperature <= 19){
      blue = 0;
    } else {
      blue = temperature - 10;
      blue = (138.5177312231 * log(blue)) - 305.0447927307;
    }
  }
  return (uint8_t)constrain(blue, 0, 255);
}
