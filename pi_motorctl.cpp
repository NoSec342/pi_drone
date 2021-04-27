#include "pi_motorctl.hpp"

motorctl::motorctl()
{
//VOI INITIALIZA BIBLIOTECA PENTRU A FOLOSI PINII GPIO CU SCHEMA DE NUMARARE 1 - 16 SI VOI SETA PINUL DE IESIRE 
    wiringPiSetup();
//VOI INITIALIZA PINII
    pinMode(FORWARD, OUTPUT);
    pinMode(BACKWARDS, OUTPUT);
    pinMode(LEFT, OUTPUT);
    pinMode(RIGHT, OUTPUT);
    pinMode(ROTATE_LEFT, OUTPUT);
    pinMode(ROTATE_RIGHT, OUTPUT);
    pinMode(MOTOR_POWER1, OUTPUT);
    pinMode(MOTOR_POWER2, OUTPUT);
    pinMode(MOTOR_POWER3, OUTPUT);
    pinMode(MOTOR_POWER4, OUTPUT);
    
    
    
}

motorctl::~motorctl()
{
//AICI NU-I GATA
}

void motorctl::Move(const uint8_t& fa_what_to_move) const
{
    digitalWrite(fa_what_to_move, HIGH);
}





