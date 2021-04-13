#include <iostream>
#include <stdio.h>
#include "pi_sock.hpp"
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include "pi_serial.hpp"
int main(int argc, char **argv) {

    
    uint16_t port = argc > 1 ? atoi(argv[1]) : 54000;
    std::cout << port << std::endl;
    
    //MOMENTAN NU E GATA, IL VOI LASA SA RULEZE DREPT SERVER TCP RAW
    pi_sock Socket(port);
    Socket.pi_listen();
    
    while(true)
    
    return 0;
}
