#include<tcp_socket.h>
#include<iostream>

using namespace Siddeeg::Net;

int main(){
    platform_init();
    TCPSocket server;

    if(!server.bind({"", 8080})){
        std::cerr << "Failed to bind socket" << std::endl;
        print_error();
        return -1;
    }

    if(!server.listen()){
        std::cerr << "Failed to listen on socket" << std::endl;
        print_error();
        return -2;
    }

    std::cout << "Server Listening on port 8080 ..." << std::endl;

    TCPSocket client = server.accept();

    if(!client.valid()){
        std::cerr << "Failed to accept client connection" << std::endl;
        print_error();
        return -3;
    }

    const char message[] = "Hello from the server!";
    if(!client.send(message, sizeof(message))){
        std::cerr << "Failed to send message to client" << std::endl;
        print_error();
        return -4;
    }
    platform_terminate();
}