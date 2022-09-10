#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	/* server information */
	const char *host = "google.com";
	const char *port = "80"; // HTTP
	int ret;
	struct addrinfo hints, *resources;

	/* prepare the hints structure */
	printf("Configuring host ...\n");
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;	 /* IPv4 */
	hints.ai_socktype = SOCK_STREAM; /* TCP */

	/* fill the resource structure */
	ret = getaddrinfo(host, port, &hints, &resources);
	if(ret)
	{
		perror("Failed to get addres info\n");
		exit(1);
	}

	printf("getaddrinfo() done!\n");
	/* free alocated memory */
	freeaddrinfo(resources);

	return 0;
}
