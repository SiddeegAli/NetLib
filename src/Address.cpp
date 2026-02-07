#include<address.h>

Siddeeg::Net::Address::Address(const char* ip, uint16_t port): m_ip(ip), m_port(port), m_vaild(false){
    memset(&m_sockaddr, 0, sizeof(m_sockaddr));
    m_sockaddr.sin_family = AF_INET;
    m_sockaddr.sin_port = htons(port);
    if (ip != '\0'){
        if (inet_pton(AF_INET, ip, &m_sockaddr.sin_addr) <= 0){
            m_vaild = false;
        }else{
            m_vaild = true;
        }
    }else{
        m_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        m_vaild = true;
    }
}

const char* Siddeeg::Net::Address::get_ip() const{
    return m_ip;
}

uint16_t Siddeeg::Net::Address::get_port() const{
    return m_port;
}

sockaddr_in Siddeeg::Net::Address::raw() const{
    return m_sockaddr;
}

bool Siddeeg::Net::Address::vaild() const{
    return m_vaild;
}