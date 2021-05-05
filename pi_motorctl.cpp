#include "pi_motorctl.hpp"

motorctl::motorctl() 
{

    wiringPiSetup(); //VOI INITIALIZA BIBLIOTECA PENTRU A FOLOSI PINII GPIO CU SCHEMA DE NUMARARE       
                     //1 - 16 SI VOI SETA PINUL DE IESIRE 
    pinMode(FORWARD, OUTPUT);       //VOI INITIALIZA PINII
    pinMode(BACKWARDS, OUTPUT);
    pinMode(LEFT, OUTPUT);
    pinMode(RIGHT, OUTPUT);
    pinMode(ROTATE_LEFT, OUTPUT);
    pinMode(ROTATE_RIGHT, OUTPUT);
    pinMode(MOTOR_POWER1, OUTPUT);
    pinMode(MOTOR_POWER2, OUTPUT);
    pinMode(MOTOR_POWER3, OUTPUT);
    pinMode(POWER_DOWN, OUTPUT);
    
    
    
}

motorctl::~motorctl()
{
// MOMENTAN NIMIC AICI
}

// FUNCTIE CE VA TRIMITE SEMNAL PE PINUL PRIMIT CA PARAMETRU

void motorctl::Move(const uint8_t& fa_what_to_move) const
{
    digitalWrite(fa_what_to_move, HIGH);
}





