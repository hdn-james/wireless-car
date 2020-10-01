#include "wireless.h"

Wireless::Wireless() {}
Wireless::~Wireless() {}

void Wireless::set_pin_mode()
{
    pinMode(rf_d0, INPUT);
    pinMode(rf_d1, INPUT);
    pinMode(rf_d2, INPUT);
    pinMode(rf_d3, INPUT);
}

bool Wireless::B_is_pressing()
{
    if (digitalRead(rf_d0) == HIGH)
        return true;
    else
        return false;
}

bool Wireless::D_is_pressing()
{
    if (digitalRead(rf_d1) == HIGH)
        return true;
    else
        return false;
}

bool Wireless::A_is_pressing()
{
    if (digitalRead(rf_d2) == HIGH)
        return true;
    else
        return false;
}

bool Wireless::C_is_pressing()
{
    if (digitalRead(rf_d3) == HIGH)
        return true;
    else
        return false;
}

wireless_signal Wireless::status()
{
    if (A_is_pressing())
        return wireless_signal::A_button;
    else if (B_is_pressing())
        return wireless_signal::B_button;
    else if (C_is_pressing())
        return wireless_signal::C_button;
    else if (D_is_pressing())
        return wireless_signal::D_button;
    else
        return wireless_signal::wait;
}
