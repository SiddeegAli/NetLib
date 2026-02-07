#include<tcp_socket.h>

Siddeeg::Net::TCPSocket::TCPSocket(socket_t socket) : Socket(socket){}

bool Siddeeg::Net::TCPSocket::connect(Address address){
    if(!valid()) return false;
    sockaddr_in raw_addr = address.raw();
    error_code = ::connect(m_socket, (sockaddr*)&raw_addr, sizeof(raw_addr));
    return error_code < 0;
}

bool Siddeeg::Net::TCPSocket::bind(Address address){
    if(!valid()) return false;
    sockaddr_in raw_addr = address.raw();
    error_code = ::bind(m_socket, (sockaddr*)&raw_addr, sizeof(raw_addr));
    return error_code < 0;
}

bool Siddeeg::Net::TCPSocket::listen(int backlog){
    if(!valid()) return false;
    error_code = ::listen(m_socket, backlog);
    return error_code < 0;
}

Siddeeg::Net::TCPSocket Siddeeg::Net::TCPSocket::accept(){
    if(!valid()) {
        TCPSocket faild_socket(invalid_socket);
        faild_socket.close();
        return faild_socket;
    }

    socket_t client_socket = ::accept(m_socket, nullptr, nullptr);

    if(client_socket == invalid_socket){
        TCPSocket faild_socket(client_socket);
        faild_socket.close();
        return faild_socket;
    }

    return TCPSocket(client_socket);
}

bool Siddeeg::Net::TCPSocket::send(const void* data, size_t size, int flags){
    if(!valid()) return false;

    int bytes_sent = 0;

    while(bytes_sent < size){
        bytes_sent += ::send(m_socket, static_cast<const char*>(data) + bytes_sent, size - bytes_sent, flags);
        if(bytes_sent < 0) return false; // Error occurred
    }

    return true;
}

int Siddeeg::Net::TCPSocket::recv(void* buffer, size_t size, int flags){
    if(!valid()) return -1;
    return ::recv(m_socket, static_cast<char*>(buffer), size, flags);
}