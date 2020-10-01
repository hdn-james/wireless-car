#ifndef _LIGHT_SENSOR_H_
#define _LIGHT_SENSOR_H_

#include "initialize.h"

class LightSensor
{
private:
    int digital = 13;
    int analog = A0;

    bool is_bright();

public:
    LightSensor();
    ~LightSensor();

    void set_pin_mode();

    light_sensor_signal status();
};

#endif /* _LIGHT_SENSOR_H_ */