#include "pi_motorctl.hpp"

motorctl::motorctl(const uint8_t& fa_pin)
    : m_PIN(fa_pin)
{
//VOI INITIALIZA BIBLIOTECA PENTRU A FOLOSI PINII GPIO CU SCHEMA DE NUMARARE 1 - 16 SI VOI SETA PINUL DE IESIRE 
    wiringPiSetup();
    pinMode(m_PIN, OUTPUT);
    
}

motorctl::~motorctl()
{
//AICI NU-I GATA
}


void motorctl::write_to_pcb(const uint8_t& fa_val) const
{
//AICI VOI PRELUA ORICE VALOARE UNSIGNED INT DE 8 BITI SI O VOI STOCA INTR-UN SIR DE BITI
//AICI VOI TRIMITE BITII PE RAND CATRE PINUL GPIO DE IESIRE
//DELAY DE 10 MILISECUNDE PENTRU A SE SINCRONIZA CU PLACA DE DEZVOLTARE CE CONTROLEAZA MOTOARELE
    std::bitset<8> f_val_in_bits(fa_val);
    for(uint8_t i = 0; i < f_val_in_bits.size(); i++)
    {
        digitalWrite(this->m_PIN, f_val_in_bits[i]);
        delay(10);
    }
}


