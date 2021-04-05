#ifndef __PI_SERIAL
#define __PI_SERIAL

class pi_serial
{
private:
    const serial_port;
    
    
public:
    pi_serial();
    ~pi_serial();
    virtual void WriteToPort(const std::string& msg) const;
};

#endif
