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
    motorctl Motor(10); // TREBUIE SA GASESC UN PIN BUN

    while(true)
    {
        
        std::string buffer;
        buffer << Sock;
        uint8_t rotation = buffer.find("ROTATE_LEFT") != std::string::npos ? buffer.find("ROTATE_RIGHT") != std::string::npos ? 101 : 100 : 0;
        Motor.write_to_pcb(255);
        Motor.write_to_pcb(200);
        Motor.write_to_pcb(rotation);
        if(buffer.find("FRONT") != std::string::npos)
        {
            
            Motor.write_to_pcb(0);
        }
        if(buffer.find("BACK") != std::string::npos)
        {
         
            Motor.write_to_pcb(30);
        }
        if(buffer.find("LEFT") != std::string::npos)
        {
            
            Motor.write_to_pcb(45);
        }
        if(buffer.find("RIGHT") != std::string::npos)
        {
            
            Motor.write_to_pcb(15);
        }
        
        Motor.write_to_pcb(255);
    }
    return 0;
}
