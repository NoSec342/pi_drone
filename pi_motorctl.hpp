
#ifndef _PI_MOTOR_CTL_
#define _PI_MOTOR_CTL_

#include <iostream>
#include <wiringPi.h>
#include <string>


class motorctl
{
private:
    
    
public:
    motorctl(const uint8_t* fa_pin, const uint8_t& fa_pin2);
    ~motorctl();
    virtual void self_move(const char& fa_direction)const;
    
    
}

#endif
