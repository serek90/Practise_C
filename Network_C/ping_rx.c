/*
*       The program prints ping(ICMP) messages coming to the machine
*       
*       environment: Linux
*
*       author: jseroczy
*/

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <time.h>


#define BUF_LEN 10000
#define IP_LEN  16
#define ECHO_REQUEST 8

void printMessBythes(char *buffer, int len)
{
        for (int i = 0; i < len; i++)
                printf("%02X%s", (uint8_t)buffer[i], (i + 1)%16 ? " " : "\n");
        printf("\n");
}

int main(){
        struct sockaddr_in myAddr, sourceAddr;
        char buf[BUF_LEN];

        int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
        if (sockfd < 0)
        {
                perror("Socket open");
                exit(1);
        }

        socklen_t sockaddrLen = sizeof(struct sockaddr_in);
        char sourceIP[IP_LEN];

        printf("Start listening!\n");
        while(1)
        {
                int ret = recvfrom(sockfd, buf, BUF_LEN, 0, (struct sockaddr *)&myAddr, &sockaddrLen);
                if(ret == -1)
                {
                        perror("Problem with receiving message\n");
                        continue;
                }
                //printf(" rec'd %d bytes\n", ret);

                struct iphdr *ip_hdr = (struct iphdr *)buf;
                //printf("IP header is %d bytes.\n", ip_hdr->ihl*4);

                /*get source IP addres */
                memset(&sourceAddr, 0, sizeof(sourceAddr));
                sourceAddr.sin_addr.s_addr = ip_hdr ->saddr;
                strcpy(sourceIP, inet_ntoa(sourceAddr.sin_addr));

                /* if(ip_hdr->protocol == IPPROTO_ICMP) */
                struct icmphdr *icmp_hdr = (struct icmphdr *)((char *)ip_hdr + (4 * ip_hdr->ihl));

                //printf("ICMP msgtype=%d, code=%d", icmp_hdr->type, icmp_hdr->code);
                if(icmp_hdr->type == ECHO_REQUEST) /* ping type */
                {
                        time_t t = time(NULL);
                        struct tm tm = *localtime(&t);
                        printf("%d-%02d-%02d %02d:%02d:%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
                                                               tm.tm_hour, tm.tm_min, tm.tm_sec);
                        printf("Received a Ping from %s\n", sourceIP);
                }
        }
}
