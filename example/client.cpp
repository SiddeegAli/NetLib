#include<tcp_socket.h>
#include<iostream>

using namespace Siddeeg::Net;

int main(){
    TCPSocket client;

    if(!client.connect({"127.0.0.1", 8080})){
        std::cerr << "Failed to connect to server" << std::endl;
        return -1;
    }

    char buffer[1024];
    int bytes_received = client.recv(buffer, sizeof(buffer));

    if(bytes_received < 0){
        std::cerr << "Failed to receive data from server" << std::endl;
        return -2;
    }

    buffer[bytes_received] = '\0';

    std::cout << "Received from server: " << buffer << std::endl;
}