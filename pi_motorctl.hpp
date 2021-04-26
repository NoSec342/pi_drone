
#ifndef _PI_MOTOR_CTL_
#define _PI_MOTOR_CTL_

#include <iostream>
#include <wiringPi.h>
#include <string>
#include <bitset>


//DEFINITIA CLASEI PENTRU ACCESAREA PLACII DE DEZVOLTARE PENTRU CONTROLUL MOTOARELOR
//PENTRU SCOPURILE FUNCTIILOR VEDETI pi_motorctl.cpp

class motorctl
{
private:
//VOI RETINE PIN-UL FOLOSIT
    const uint8_t m_PIN;
    
public:
    
    motorctl(const uint8_t& fa_pin);
    ~motorctl();
    virtual void write_to_pcb(const uint8_t& fa_val) const;

};

#endif
