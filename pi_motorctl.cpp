#include "pi_motorctl.hpp"

motorctl::motorctl(const std::string& __serial_dev, const uint16_t& __baud) 
    : m_baud(__baud), m_serial_dev(__serial_dev)
{
    m_serial_fd = open(m_serial_dev.c_str(), O_RDWR);
    if(m_serial_fd < 0)
    {
        fprintf(stderr, "On file descriptor %s: ", m_serial_dev.c_str());
        throw "Can not open descriptor\n";
    }
    if(tcgetattr(m_serial_fd, &serial_port)) 
    {
        throw "Can not set the serial port for writing to arduino!\n";
    }
    serial_port.c_cflag &= ~PARENB;
    serial_port.c_cflag &= ~CSTOPB;
    serial_port.c_cflag |= CS8;
    serial_port.c_cflag &= ~CRTSCTS;
    serial_port.c_cflag |= CREAD | CLOCAL;
    serial_port.c_lflag &= ~ICANON;
    serial_port.c_lflag &= ~ECHO; 
    serial_port.c_lflag &= ~ECHOE; 
    serial_port.c_lflag &= ~ECHONL; 
    serial_port.c_cflag &= ~ISIG;
    serial_port.c_iflag &= ~(IXON | IXOFF | IXANY);
    serial_port.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
    serial_port.c_oflag &= ~OPOST;
    serial_port.c_oflag &= ~ONLCR;
    serial_port.c_cc[VTIME] = 0;
    serial_port.c_cc[VMIN] = 0;
    cfsetspeed(&serial_port, m_baud);
    if(tcsetattr(m_serial_fd, TCSANOW, &serial_port))
    {
        throw "Can not set serial file descriptor settings!\n";
    }
    
}

motorctl::~motorctl()
{
    close(m_serial_fd);
}


void motorctl::Move(const std::string& __move_what) const
{
    write(m_serial_fd, __move_what.c_str(), sizeof(char));
}





