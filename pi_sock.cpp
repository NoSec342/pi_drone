#include "pi_sock.hpp"

pi_sock::pi_sock(const uint16_t& fa_port)
{
    m_error_exit = false;
    is_client_connected = false;
    m_server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(m_server_fd < 0)
    {
        fprintf(stderr, "Could not open socket!\n");
        m_error_exit = true;
        is_client_connected = false;
    }
    m_port = fa_port;
    m_server.sin_port = htons(m_port);
    m_server.sin_family = AF_INET;
    m_server.sin_addr.s_addr = INADDR_ANY;
    m_server_len = sizeof(m_server);
    if(bind(m_server_fd, (sockaddr *)&m_server, m_server_len ) < 0)
    {
        fprintf(stderr, "Could not bind to address!\n");
        m_error_exit = true;

    }
}

pi_sock::~pi_sock()
{
    close(m_server_fd);
    close(m_client_fd);
}


void pi_sock::pi_listen() 
{
    
        
    m_error_exit = listen(m_server_fd, SOMAXCONN) < 0 ? true : false;
    
    m_client_fd = accept(m_server_fd, (sockaddr *)&m_server, &m_server_len);
    is_client_connected = true;
    m_error_exit = m_client_fd < 0 ? true : false;
    is_client_connected = m_client_fd < 0 ? false : true;
    
    
    
}

const std::string pi_sock::ReadFromClient()
{
    memset(m_buffer, 0, sizeof(m_buffer));
    m_rw_status = recv(m_client_fd, m_buffer, sizeof(m_buffer), 0);
    if(m_rw_status < 0)
    {
        
        return "Can't read form client! Check connection! \n";
    }
    return std::string(m_buffer);
}
void pi_sock::WriteToClient(const std::string& fa_msg)
{
    memset(&m_buffer, 0, 4096);
    strcpy(m_buffer, fa_msg.c_str());
    m_rw_status = send(m_client_fd, m_buffer, sizeof(m_buffer), 0);
    if(m_rw_status < 0)
    {
        fprintf(stderr, "Can't read form client! Check connection! \n");
    }
    
}








