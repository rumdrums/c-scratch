#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
	/* display binary equivalents of given ip address */
	char *address = "10.0.8.2";
	struct in_addr addr;
	int success = 0;
	
	success = inet_pton(AF_INET, address, &addr);
	printf("Address: %s\n",address);
	printf("Success: %d\n",success);
	printf("Binary address, network order: %d\n",addr.s_addr);
	printf("Binary address, host-byte order: %d\n",ntohl(addr.s_addr));
	return 0;
}
