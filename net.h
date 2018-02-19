#include <winsock2.h>

#define IP_ADDRESS "127.0.0.1"
#define PORT 8889

void p_connect();                // connects to the server
void p(char *str, const int n);  // sends a message to the server
void p_disconnect();             // disconnect from the server
