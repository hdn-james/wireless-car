#ifndef _LED_H_
#define _LED_H_

#include "initialize.h"

class Led
{
private:
    int latch_pin = 8;
    int data_pin = 11;
    int clock_pin = 12;
    int front_led = 13;

    byte led_status = 0B00000000;

    byte left_led_bit = 0b10111110;
    byte right_led_bit = 0b11010111;
    byte red_led_bit = 0b01101001;
    byte led_off_bit = 0b11111111;
    byte yellow_led_bit = 0b10010110;

private:
    void led_front();
    void led_left();
    void led_right();
    void led_off();
    void led_off_front();
    void red_led();
    void yellow_led();

public:
    Led();
    ~Led();

    void set_pin_mode();
    
    void set_led(led_mode);
};

#endif /* _LED_H_ */