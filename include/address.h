#include "platform.h"

namespace Siddeeg{
    namespace Net{
        class Address{
            private:
                const char* m_ip;
                uint16_t m_port;
                sockaddr_in m_sockaddr;
                bool m_vaild;
            public:
                Address(const char* ip, uint16_t port);
                const char* get_ip() const;
                uint16_t get_port() const;
                sockaddr_in raw() const;
                bool vaild() const;
        };
    }
}