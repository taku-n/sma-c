#include "net.h"

_Thread_local SOCKET s;  // Thread Local Storage

void p_connect()
{
	WSADATA wsa_data;
	struct sockaddr_in server;

	server.sin_family           = AF_INET;
	server.sin_addr.S_un.S_addr = inet_addr(IP_ADDRESS);
	server.sin_port             = htons(PORT);

	WSAStartup(MAKEWORD(2, 0), &wsa_data);

	s = socket(AF_INET, SOCK_STREAM, 0);

	connect(s, (struct sockaddr *)&server, sizeof(server));
}

void p(char *str, const int n)
{
	str[n - 1] = '\n';

	send(s, str, n, 0);
}

void p_disconnect()
{
	closesocket(s);

	WSACleanup();
}
