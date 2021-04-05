#include <iostream>
#include <stdlib.h>
#include "pi_serial.hpp"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

pi_serial::pi_serial()
{
    serial_port = open("DEVICE", 0); //NOT DONE HERE
}

pi_serial::~pi_serial()
{
    
}
void pi_serial::WriteToPort ( const std::string& msg ) const
{
    
}


