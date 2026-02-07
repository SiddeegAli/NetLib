#include<socket.h>

Siddeeg::Net::Socket::Socket(socket_t socket):m_socket(socket){
    if(socket == invalid_socket){
        init();
    }
}

bool Siddeeg::Net::Socket::init(){
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    return m_socket != invalid_socket;
}

bool Siddeeg::Net::Socket::valid() const{
    return m_socket != invalid_socket;
}

void Siddeeg::Net::Socket::close(){
    if(valid()){
        ::closesocket(m_socket);
        m_socket = invalid_socket;
    }
}

Siddeeg::Net::Socket::~Socket(){
    close();
}