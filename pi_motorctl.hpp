
#ifndef _PI_MOTOR_CTL_
#define _PI_MOTOR_CTL_

#include <iostream>
#include <wiringPi.h>
#include <string>
#include <bitset>


class motorctl
{
private:
    
public:
    motorctl(const uint8_t& fa_pin);
    ~motorctl();
    virtual void write_to_pcb(const uint8_t& fa_val, const uint8_t& fa_pin) const;

};

#endif
