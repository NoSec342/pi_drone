#include <iostream>
#include <stdio.h>
#include "pi_sock.hpp"
#include "pi_motorctl.hpp"
#include <thread>


int main(int argc, char **argv) 
{
    
    uint16_t port = argc > 1 ? std::atoi(argv[1]) : 54000; // PRIMUL ARGUMENT VA REPREZENTA PORTUL PE CARE VA ASCULTA DRONA
    pi_sock Sock(port); 
    Sock.pi_listen();
    motorctl Motor; 

    std::thread send_err_to_client([&]
    {
        while(true)                     // VOI INITIALIZA UN THREAD CARE VA VERFICA DACA SUNT 
        {                               // PROBLEME , DACA APAR PROBLEME LA CONEXIUNI , LE VA 
            if(Sock.m_error_msg != "")  // TRIMITE CATRE CLIENT
            {
               Sock.m_error_msg >> Sock;
               Sock.m_error_msg = "";  // VOI GOLI MESAJUL DE EROARE PENTRU A NU FI TRIMIS IN
            }                          // CONTINUU
        }
    });
    send_err_to_client.detach();        // VOI DETASA THREAD-UL DEOARECE TREBUIE SA RULEZE 
                                        // SEPARAT FATA DE COD
    while(true)
    {
        
        std::string buffer;             // AICI VOI APELA FUNCTIA DE MISCARE CU PARAMETRU PRIMIT
        buffer << Sock;                 // DIRECT DE PE RETEA
        fprintf(stdout , "Received : %s" , buffer.c_str());
        Motor.Move(std::atoi(buffer.c_str())); 
        buffer = "";
    }                                      
    return 0;
}

