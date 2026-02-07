#pragma once
#include "socket.h"
#include "address.h"

namespace Siddeeg{
    namespace Net{
        class TCPSocket : public Socket{
        public:
            TCPSocket(socket_t socket=invalid_socket);
            bool connect(Address address);
            bool bind(Address address);
            bool listen(int backlog=5);
            TCPSocket accept();
            bool send(const void* data, size_t size, int flags=0);
            int recv(void* buffer, size_t size, int flags=0);
        };
    }
}