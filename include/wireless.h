#ifndef _WIRELESS_H_
#define _WIRELESS_H_

#include "initialize.h"

class Wireless
{
private:
    int rf_d2 = 4; // A button
    int rf_d0 = 2; // B button
    int rf_d3 = 7; // C button
    int rf_d1 = 3; // D button

public:
    bool A_is_pressing();
    bool B_is_pressing();
    bool C_is_pressing();
    bool D_is_pressing();

public:
    Wireless();
    ~Wireless();

    void set_pin_mode();

    wireless_signal status();
};

#endif // !_WIRELESS_H_H