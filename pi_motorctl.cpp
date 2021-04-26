#include "pi_motorctl.hpp"

motorctl::motorctl(const uint8_t& fa_pin1 , const uint8_t& fa_pin2)
    : m_direction(NULL) 
{
//init
    wiringPiSetup();
    pinMode(fa_pin1, OUTPUT);
    pinMode(fa_pin2, OUTPUT);
    
}

motorctl::~motorctl()
{
    
}


void motorctl::write_to_pcb(const uint8_t& fa_val, const uint8_t& fa_len, const uint8_t& fa_pin) const
{
    std::bitset<fa_len> f_val_in_bits(fa_val);
    for(uint8_t i = 0; i < fa_len; i++)
    {
        digitalWrite(fa_pin, f_val_in_bits[i]);
        delay(1);
    }
}


