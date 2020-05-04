#ifndef SUN_COLOUR_H
#define SUN_COLOUR_H

#include <QTime>
#include <QColor>

class SunColour
{
public:
    SunColour();

    static QColor GetColourForDayTime(const QTime &time, int brightness=100);

private:
    unsigned int _temperature;
    int _brightness;
    static uint8_t calculateRed(int temp);
    static uint8_t calculateGreen(int temp);
    static uint8_t calculateBlue(int temp);

    static QColor KelvinToQColor(int kelvin_temp, int brightness);
    static long map(long x, long in_min, long in_max, long out_min, long out_max);


    static int constrain(int value, int min, int max);
};

#endif // SUN_COLOUR_H
