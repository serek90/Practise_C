
/*
*	description:
*	Simple program that shows host name of the machine on Linux OS
*
*	@author: serek90(jseroczy)
*
*	created: 06.09.2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

int main()
{
	char hostName[BUFSIZ];
	struct hostent *hostData;
	char **addresses;

	/* get host name of this machine */
	int ret = gethostname(hostName,BUFSIZ);
	if(ret == -1)
	{
		fprintf(stderr, "Unable to get host name\n");
		exit(1);
	}

	printf("This host is: %s\n", hostName);


	/*get information about the host */
	hostData = gethostbyname(hostName);
	if(hostData == NULL)
	{
		fprintf(stderr, "Can't obtain host data\n");
		exit(1);
	}
	printf("Address(es): ");
	addresses = hostData->h_addr_list;
	while( *addresses)
	{
		printf("%s\n", inet_ntoa(*(struct in_addr *)*addresses));
		addresses++;
	}

	return 0;
}
