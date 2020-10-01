#ifndef CONTROL_H
#define CONTROL_H

#include "initialize.h"
#include "led.h"
#include "light_sensor.h"
#include "motor.h"
#include "wireless.h"
#include "asynchronous.h"

Wireless wireless;
LightSensor light_sensor;
Motor motor;
Led led;

Task *wireless_task;
Task *light_task;
Task *motor_task;

int temp = -1;

void initialize()
{
    wireless.set_pin_mode();
    light_sensor.set_pin_mode();
    motor.set_pin_mode();
    led.set_pin_mode();
}

void wireless_controller()
{

    if (wireless.status() == wireless_signal::A_button)
        temp = 0;
    else if (wireless.status() == wireless_signal::B_button)
        temp = 1;
    else if (wireless.status() == wireless_signal::C_button)
        temp = 2;
    else if (wireless.status() == wireless_signal::D_button)
        temp = 3;
    else
        temp = -1;
}

void led_controller()
{
    if (light_sensor.status() == light_sensor_signal::dark)
        led.set_led(led_mode::front);
    else
        led.set_led(led_mode::off_front);
    if (temp == 2)
        led.set_led(led_mode::left);
    else if (temp == 3)
        led.set_led(led_mode::right);
    else if (temp == 1)
        led.set_led(led_mode::backward_led);
    else
        led.set_led(led_mode::off);

    //led.test();
}

void motor_controller()
{
    if (temp == 0)
        motor.motor(motor_control::forward);
    else if (temp == 1)
        motor.motor(motor_control::backward);
    else if (temp == 2)
        motor.motor(motor_control::left);
    else if (temp == 3)
        motor.motor(motor_control::right);
    else
        motor.motor(motor_control::stop);
}

#endif /* _CONTROL_H_ */