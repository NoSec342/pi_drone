#include <iostream>
#include <stdio.h>
#include "pi_sock.hpp"
#include "pi_motorctl.hpp"
#include <thread> 


int main(int argc, char **argv) 
{
    
    uint16_t port = argc > 1 ? std::stoi(argv[1]) : 54000;
    pi_sock Sock(port);
    Sock.pi_listen();
    motorctl Motor(5); // TREBUIE SA GASESC UN PIN BUN

    while(true)
    {
        
        std::string buffer;
        buffer << Sock;
        fprintf(stdout , "Received : %s" , buffer.c_str());
        uint8_t direction = 0;
        bool is_moving;
        uint8_t rotation = buffer.find("ROTATE_LEFT") != std::string::npos ? buffer.find("ROTATE_RIGHT") != std::string::npos ? 101 : 100 : 0;
        if(buffer.find("FRONT") != std::string::npos)
        {
            direction = 0;
            is_moving = true;
        }else if(buffer.find("BACK") != std::string::npos)
        {
            is_moving = true;            
            direction = 30;
        }else if(buffer.find("LEFT") != std::string::npos)
        {
            is_moving = true;
            direction = 45;
        }
        if(buffer.find("RIGHT") != std::string::npos)
        {
            is_moving = true;
            direction = 15;
        }
        Motor.write_to_pcb(255);
        Motor.write_to_pcb(100);
        Motor.write_to_pcb(rotation);
        Motor.write_to_pcb(direction);        
        Motor.write_to_pcb(255);
        is_moving = false;
        if(!Sock.is_client_connected)
        {
            fprintf(stderr, "Client disconnected!\n");
            return ENETRESET;
        }
    }
    return 0;
}
