#ifndef _INITIALIZE_H_
#define _INITIALIZE_H_

#include <Arduino.h>

enum class motor_control
{
    forward,
    backward,
    left,
    right,
    stop
};

enum class wireless_signal
{
    A_button,
    B_button,
    C_button,
    D_button,
    wait
};

enum class light_sensor_signal
{
    bright,
    dark
};

enum class led_mode {
    front,
    left,
    right,
    off,
    off_front,
    backward_led,
    blink
};

#endif // !_INITIALIZE_H_