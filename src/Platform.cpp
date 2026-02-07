#include<platform.h>
#include<iostream>

int error_code = 0;

void platform_init() {
#ifdef _WIN32
    WSAData wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
}


int get_error_code() {
#ifdef _WIN32
	return WSAGetLastError();
#else
	return errno;
#endif

}

void print_error() {
    error_code = get_error_code();
#ifdef _WIN32
    LPVOID lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        error_code,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );
    std::cerr << "Error: " << (char*)lpMsgBuf << std::endl;
    LocalFree(lpMsgBuf);
#else
    std::cerr << "Error(" << error_code << "): " << strerror(error_code) << std::endl;
#endif
}


void platform_cleanup() {
#ifdef _WIN32
    WSACleanup();
#endif
}