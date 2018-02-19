#include <winsock2.h>

int send_with_newline(const SOCKET s, char *str, const int n);

_Thread_local SOCKET sock;  // Thread Local Storage

int main(int argc, char *argv[])
{
	WSADATA wsa_data;
	struct sockaddr_in server;

	server.sin_family           = AF_INET;
	server.sin_port             = htons(8889);
	server.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	WSAStartup(MAKEWORD(2, 0), &wsa_data);

	sock = socket(AF_INET, SOCK_STREAM, 0);

	connect(sock, (struct sockaddr *)&server, sizeof(server));

	char str[] = "hoge";
	send_with_newline(sock, str, sizeof str);

	closesocket(sock);

	WSACleanup();

	return 0;
}

int send_with_newline(const SOCKET s, char *str, const int n)
{
	str[n - 1] = '\n';

	return send(s, str, n, 0);
}
