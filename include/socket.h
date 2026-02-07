#pragma once
#include "platform.h"

namespace Siddeeg{
    namespace Net{
        class Socket{
        public:
            Socket(socket_t socket=invalid_socket);
            virtual ~Socket();
            bool init();
            void close();
            bool valid() const;

            // DELETE Copying
            Socket(const Socket&) = delete;
            Socket& operator=(const Socket&) = delete;

            // ENABLE Moving
            Socket(Socket&& other) noexcept : m_socket(other.m_socket) {
                other.m_socket = invalid_socket; // Steal the handle, leave other empty
            }
            Socket& operator=(Socket&& other) noexcept {
                if (this != &other) {
                    if (m_socket != invalid_socket) ::closesocket(m_socket); // Clean up current
                    m_socket = other.m_socket; // Steal handle
                    other.m_socket = invalid_socket; // Nullify source
                }
                return *this;
            }
        protected:
            socket_t m_socket;
        };
    }
}