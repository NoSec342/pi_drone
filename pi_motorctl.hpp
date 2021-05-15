#ifndef _PI_MOTOR_CTL_
#define _PI_MOTOR_CTL_

#include <iostream>
#include <termios.h>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
class motorctl
{
private:
    
    int8_t m_serial_fd;
    const uint16_t m_baud;
    std::string m_serial_dev;
    char m_buffer[4096];
        
public: 
    
    motorctl(const std::string& __serial_dev, const uint16_t& __baud); 
    ~motorctl();
    void Move(const std::string& __move_what) const;
    struct termios serial_port;
};

std::ostream& operator<<(std::ostream& __stream, motorctl __motor);

#endif
