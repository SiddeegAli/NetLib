#pragma once
#ifdef _WIN32
    #include<WinSock2.h>
	#include<WS2tcpip.h>
	#define s_addr S_un.S_addr
	using socket_t = SOCKET;
	const socket_t invalid_socket = INVALID_SOCKET;
#else
    #include<sys/socket.h>
	#include<netinet/in.h>
	#include<arpa/inet.h>
	#include<errno.h>
	#include<unistd.h>	
	#include<string.h>
	using socket_t = int;
	const socket_t invalid_socket = -1;
	#define closesocket close
#endif

extern int error_code;

void platform_init();

int get_error_code(); 

void print_error();

void platform_terminate();