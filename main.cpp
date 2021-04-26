#include <iostream>
#include <stdio.h>
#include "pi_sock.hpp"
#include <thread> 



int main(int argc, char **argv) 
{
    
    uint16_t port = argc > 1 ? std::stoi(argv[1]) : 54000;
    pi_sock Sock(port);
    Sock.pi_listen();
//DUMMY
    while(true)
    {
        std::cout << Sock;
        if(!Sock.is_client_connected)
        {
            fprintf(stderr, "Client Disconnected!\n");
            return 0;
        }
    }
    return 0;
}
