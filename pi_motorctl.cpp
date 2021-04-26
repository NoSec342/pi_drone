#include "pi_motorctl.hpp"

motorctl::motorctl(const uint8_t& fa_pin1 , const uint8_t& fa_pin2)
{
//init
    wiringPiSetup();
    pinMode(fa_pin1, OUTPUT);
    pinMode(fa_pin2, OUTPUT);
    
}

motorctl::~motorctl()
{
    
}

void motorctl::self_move(const char& fa_direction) const
{
    
}

