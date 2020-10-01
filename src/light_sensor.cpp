#include "light_sensor.h"

LightSensor::LightSensor() {}
LightSensor::~LightSensor() {}

void LightSensor::set_pin_mode()
{
    pinMode(digital, INPUT);
    pinMode(analog, INPUT);
}

bool LightSensor::is_bright()
{
    if (analogRead(analog) > 300)
        return false;
    return true;
}

light_sensor_signal LightSensor::status()
{
    if (is_bright())
        return light_sensor_signal::bright;
    if (!is_bright())
        return light_sensor_signal::dark;
}