#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int sockfd, n = 0;
    char recvline[1000 + 1];
    struct sockaddr_in servaddr;
    int port;
    printf("\n Enter the port no:");
    scanf("%d",&port);
    printf("The port no is:%d\n",port);

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf( "Socket printfor");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
		printf( "Connect printfor");
    }

	while ((n = read(sockfd, recvline, 1000)) > 0) {
	    recvline[n] = 0;
	    fputs(recvline, stdout);
	}

	return 0;
}
