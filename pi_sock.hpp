#ifndef __PI_SOCK__
#define __PI_SOCK__
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <memory>
#include <unistd.h>
#include <string>
#include <cstring>

// PENTRU SCOPURILE FUNCTIILOR VERIFICATI pi_sock.cpp
// O CLASA CU DEFINITIILE FUNCTIILOR DE CARE VA FI NEVOIE PENTRU COMUNICAREA PE RETEA

class pi_sock 
{
private:
    int8_t m_server_fd, m_client_fd, m_rw_status;
    sockaddr_in m_server;
    socklen_t m_server_len;
    uint16_t m_port;
    char m_buffer[8192];
    
    
public:
    bool m_error_exit, is_client_connected;
    
    pi_sock(const uint16_t& fa_port);
    ~pi_sock();
    virtual void pi_listen();
    virtual const std::string ReadFromClient();
    virtual void WriteToClient(const std::string& msg);
    
};

// AICI AM REINCARCAT OPERATORII << (bitshift left) SI >> (bitshift right) PENTRU A FACE 
// MAI USOARA CITIREA SI SCRIEREA PE ACEASTA CLASA

std::istream& operator>>(std::istream& stream, pi_sock& fa_sock)
{
    std::string f_message_to_send;
    stream >> f_message_to_send;
    fa_sock.WriteToClient(f_message_to_send);
    return stream;
}
std::ostream& operator<<(std::ostream& stream, pi_sock& fa_sock)
{
    stream << fa_sock.ReadFromClient();
    return stream;
}


std::string& operator<<( std::string& fa_msg, pi_sock& fa_sock)
{
    fa_msg = fa_sock.ReadFromClient();
    return fa_msg;
}
const std::string& operator>>(const std::string& fa_msg, pi_sock& fa_sock)
{
    fa_sock.WriteToClient(fa_msg);
    return fa_msg;
}

#endif
