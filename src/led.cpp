#include "led.h"

Led::Led(){};
Led::~Led(){};

void Led::set_pin_mode()
{
    pinMode(latch_pin, OUTPUT);
    pinMode(data_pin, OUTPUT);
    pinMode(clock_pin, OUTPUT);
    pinMode(front_led, OUTPUT);
}

void Led::led_front()
{
    if (digitalRead(front_led) == LOW)
        digitalWrite(front_led, HIGH);
}

void Led::led_right()
{
    digitalWrite(latch_pin, LOW);
    shiftOut(data_pin, clock_pin, MSBFIRST, right_led_bit);
    digitalWrite(latch_pin, HIGH);
}

void Led::led_left()
{
    digitalWrite(latch_pin, LOW);
    shiftOut(data_pin, clock_pin, MSBFIRST, left_led_bit);
    digitalWrite(latch_pin, HIGH);
}

void Led::led_off()
{
    digitalWrite(latch_pin, LOW);
    shiftOut(data_pin, clock_pin, MSBFIRST, led_off_bit);
    digitalWrite(latch_pin, HIGH);
}

void Led::led_off_front()
{
    digitalWrite(front_led, LOW);
}

void Led::red_led()
{
    digitalWrite(latch_pin, LOW);
    shiftOut(data_pin, clock_pin, MSBFIRST, red_led_bit);
    digitalWrite(latch_pin, HIGH);
}

void Led::yellow_led()
{
    digitalWrite(latch_pin, LOW);
    shiftOut(data_pin, clock_pin, MSBFIRST, yellow_led_bit);
    digitalWrite(latch_pin, HIGH);
}

void Led::set_led(led_mode mode)
{
    switch (mode)
    {
    case led_mode::front:
        led_front();
        break;
    case led_mode::left:
        led_left();
        break;
    case led_mode::right:
        led_right();
        break;
    case led_mode::off_front:
        led_off_front();
        break;
    case led_mode::backward_led:
        red_led();
        break;
    default:
        led_off();
        break;
    }
}