#include "motor.h"

Motor::Motor(){};
Motor::~Motor(){};

void Motor::set_pin_mode()
{
    pinMode(m1_a, OUTPUT);
    pinMode(m1_b, OUTPUT);
    pinMode(m2_a, OUTPUT);
    pinMode(m2_b, OUTPUT);
}

void Motor::forward()
{
    digitalWrite(m1_a, HIGH);
    digitalWrite(m1_b, LOW);
    analogWrite(m2_a, 230);
    digitalWrite(m2_b, LOW);
}

void Motor::backward()
{
    digitalWrite(m1_a, LOW);
    analogWrite(m1_b, 150);
    digitalWrite(m2_a, LOW);
    analogWrite(m2_b, 130);
}

void Motor::right()
{
    analogWrite(m1_a, 0);
    analogWrite(m1_b, 100);
    analogWrite(m2_a, 100);
    analogWrite(m2_b, 0);
}

void Motor::left()
{
    analogWrite(m1_a, 100);
    analogWrite(m1_b, 0);
    analogWrite(m2_a, 0);
    analogWrite(m2_b, 100 );
}

void Motor::stop()
{
    digitalWrite(m1_a, LOW);
    digitalWrite(m1_b, LOW);
    digitalWrite(m2_a, LOW);
    digitalWrite(m2_b, LOW);
}

void Motor::motor(motor_control action)
{
    switch (action)
    {
    case motor_control::forward:
        forward();
        break;
    case motor_control::backward:
        backward();
        break;
    case motor_control::left:
        left();
        break;
    case motor_control::right:
        right();
        break;
    case motor_control::stop:
        stop();
        break;
    default:
        break;
    }
}