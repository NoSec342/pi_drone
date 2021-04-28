#ifndef _PI_MOTOR_CTL_
#define _PI_MOTOR_CTL_

#include <iostream>
#include <wiringPi.h>
#include <string>
#include <bitset>
#include <array>




//DEFINITIA CLASEI PENTRU ACCESAREA PLACII DE DEZVOLTARE PENTRU CONTROLUL MOTOARELOR
//PENTRU SCOPURILE FUNCTIILOR VEDETI pi_motorctl.cpp

class motorctl
{
private:
//VOI RETINE PINII FOLOSITI
    const uint8_t FORWARD = 8, BACKWARDS = 9, LEFT = 7, RIGHT = 0, ROTATE_LEFT = 2, ROTATE_RIGHT = 3, MOTOR_POWER1 = 12, MOTOR_POWER2 = 13, MOTOR_POWER3 = 14,  MOTOR_POWER4 = 30; 
public: 
    
    motorctl();
    ~motorctl();
    virtual void Move(const uint8_t& fa_what_to_move)const;
    
};

#endif
