#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "initialize.h"

class Motor
{
private:
    int m1_a = 5;
    int m1_b = 6;
    int m2_a = 9;
    int m2_b = 10;

private:
    void forward();
    void backward();
    void left();
    void right();
    void stop();

public:
    Motor();
    ~Motor();

    void set_pin_mode();
    void motor(motor_control);
};

#endif /* _MOTOR_H_ */