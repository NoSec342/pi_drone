#include "pi_motorctl.hpp"

motorctl::motorctl(const uint8_t& fa_pin1)
{
//init
    wiringPiSetup();
    pinMode(fa_pin1, OUTPUT);
    
}

motorctl::~motorctl()
{
    
}


void motorctl::write_to_pcb(const uint8_t& fa_val, const uint8_t& fa_pin) const
{
    std::bitset<8> f_val_in_bits(fa_val);
    for(uint8_t i = 0; i < f_val_in_bits.size(); i++)
    {
        digitalWrite(fa_pin, f_val_in_bits[i]);
        delay(1);
    }
}


