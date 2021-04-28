#include <iostream>
#include <stdio.h>
#include "pi_sock.hpp"
#include "pi_motorctl.hpp"


int main(int argc, char **argv) 
{
    
    uint16_t port = argc > 1 ? std::stoi(argv[1]) : 54000;
    pi_sock Sock(port);
    Sock.pi_listen();
    motorctl Motor; 

    while(true)
    {
        
        std::string buffer;             // AICI VOI APELA FUNCTIA DE MISCARE CU PARAMETRU PRIMIT
        buffer << Sock;                 // DIRECT DE PE RETEA
        fprintf(stdout , "Received : %s" , buffer.c_str());
        Motor.Move(std::stoi(buffer.c_str())); 
    }
    return 0;
}
