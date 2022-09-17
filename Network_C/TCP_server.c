/*
*	test writing address: http://127.0.0.1:2000/ on browser
*
*	author: jseroczy(serek90)
*
*/

#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*initialize the constants */
const int SOC_DOMAIN = AF_INET; /* IPv4 */
//const int SOC_DOMAIN = AF_INET6; /*IPv6 */
const int SOC_TYPE = SOCK_STREAM; /* TCP */
//const int SOC_TYPE = SOCK_DGRAM; /* UDP */

int main()
{
	/* server information */
	const char *host = "127.0.0.1"; /* your machine address */
	const char *port = "2000"; /* HTTP */
	//const char *port = "HTTP";
	int ret;
	struct addrinfo hints, *resources;

	/***********************************
	*getaddrinfo() prep
	***********************************/
	/* prepare the hints structure the same infor have to be late at *resources*/
	printf("Configuring host ...\n");
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = SOC_DOMAIN;
	hints.ai_socktype = SOC_TYPE;

	/* fill the resource structure */
	ret = getaddrinfo(host, port, &hints, &resources);
	if(ret)
	{
		perror("Failed to get addres info\n");
		exit(1);
	}

	printf("getaddrinfo() done!\n");
	printf("INFORMATION:\n");
	if(resources->ai_family == AF_INET)
		printf("\tIPv4\n");
	if(resources->ai_socktype == SOCK_STREAM)
		printf("\tTCP\n");

	/**************************************
	*socket() prep
	**************************************/
	int socketfd; // socket file descriptor
	printf("Assign a socket ...\n");
	socketfd = socket(
		resources->ai_family,	 /* domain */
		resources->ai_socktype,  /* type, stream */
		resources->ai_protocol   /* 0 = IP protocol, check /etc/protocols */
		);
	if( socketfd == -1)
	{
		perror("Failed to open a socket\n");
		exit(1);
	}
	printf("Socket is opened\n");

	/*************************************
	*bind (for client will be connect)
	*************************************/
	printf("Binding socket ...\n");
	ret = bind(socketfd,
		  resources->ai_addr,
		  resources->ai_addrlen
		  );
	if( ret == -1)
	{
		perror("Failed to bind addr to sockt\n");
		exit(1);
	}
	printf("Binding end correctly\n");

	/*************************************
	* Listen fo incoming connections
	*************************************/
	printf("Listening..\n");
	ret = listen(socketfd,1); //one connection
	if(ret == -1)
	{
		perror("failed\n");
		exit(1);
	}

	/*************************************
	*Accept a new connection
	*************************************/
	int client_fd;
	socklen_t client_len;
	struct sockaddr client_addr;
	printf("Accepting new connection\n");
	client_len = sizeof(client_addr);
	client_fd = accept(socketfd,
		&client_addr,
		&client_len
		);
	if(client_fd == -1)
	{
		perror("yFailed to accept connection fromclient");
		exit(1);
	}
	printf("Cleint file descriptor is: %d\n", client_fd);

	printf("\n\n");
	/* close the socket */
	close(socketfd);
	printf("Socket is closed\n");
	/* free alocated memory from getaddrinfo() */
	freeaddrinfo(resources);
	printf("Resources are cleared\n");

	return 0;
}
