#include "pi_sock.hpp"

//AICI VOI INITIALIZA UN SOCKET PE BAZA UNUI DESCRIPTOR DE FISIER, VOI INITIALIZA ON STRUCTURA 
// HINT CARE VA RETINE INFORMATII PRECUM VERSIUNEA IP-ULUI FOLOSIT (IN ACEST CAZ IPv4), PORT-UL
// PE CARE DRONA VA ASCULTA INSTRUCTIUNILE SI INTERFATA DE RETEA PE CARE VA ASCULTA (IN ACEST CAZ
// ORICE INTERFATA DE RETEA)

pi_sock::pi_sock(const uint16_t& fa_port)
{
    m_server_fd = socket(AF_INET, SOCK_STREAM, 0);
    m_port = fa_port;
    m_server.sin_port = htons(m_port);
    m_server.sin_family = AF_INET;
    m_server.sin_addr.s_addr = INADDR_ANY;
    m_server_len = sizeof(m_server);
    is_client_connected = true;
    if(bind(m_server_fd, (sockaddr *)&m_server, m_server_len ) < 0)
    {
        m_error_msg =  "Could not bind to address!\n";
        is_client_connected = false;
    }
    if(m_server_fd < 0)
    {
        m_error_msg = "Could not open socket!\n";
        is_client_connected = false;
    }
}

// AICI VOI INCHIDE DESCRIPTORII DE FISIER

pi_sock::~pi_sock()
{
    close(m_server_fd);
    close(m_client_fd);
}

// AICI VOI PORNI ASCULTAREA PE UN PORTUL DEFINIT MAI SUS


void pi_sock::pi_listen() 
{
    
        
    if(listen(m_server_fd, SOMAXCONN) < 0)
    {
        m_error_msg = "Can not listen! \n";
        is_client_connected = false;
    }
    
    m_client_fd = accept(m_server_fd, (sockaddr *)&m_server, &m_server_len);
    if(m_client_fd < 0)
    {
        m_error_msg = "Can not connect to client! \n";
        is_client_connected = false;
    }
    
    
}


// FUNCTIE DE CITIRE DE LA UN CLIENT CONECTAT

const std::string pi_sock::ReadFromClient()
{
    memset(m_buffer, 0, sizeof(m_buffer));
    m_rw_status = recv(m_client_fd, m_buffer, sizeof(m_buffer), 0);
    if(m_rw_status < 0)
    {
        m_error_msg =  "Can't read form client! Check connection! \n";
    }
    return std::string(m_buffer);

}

// FUNCTIE DE SCRIERE CATRE UN CLIENT CONECTAT

void pi_sock::WriteToClient(const std::string& fa_msg)
{
    memset(&m_buffer, 0, 4096);
    strcpy(m_buffer, fa_msg.c_str());
    m_rw_status = send(m_client_fd, m_buffer, sizeof(m_buffer), 0);
    if(m_rw_status < 0)
    {
        m_error_msg = "Can't WriteToClient client! Check connection! \n";
    }
    
}

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





