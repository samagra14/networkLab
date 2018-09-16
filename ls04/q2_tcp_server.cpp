  #include     <time.h>
  #include <iostream>
  #include <stdio.h>
  #include <sys/socket.h>
  #include <stdlib.h>
  #include <netinet/in.h>
  #include <string.h>
  #include <arpa/inet.h>
  #include <unistd.h>
  using namespace std;

  #define	MAXLINE		4096

  int
  main(int argc, char **argv)
  {
      int     listenfd, connfd;
      struct sockaddr_in servaddr;
      char    buff[MAXLINE];
      time_t ticks;

     listenfd = socket(AF_INET, SOCK_STREAM, 0);
     int port ;
     printf("\n Enter the port no:");
     scanf("%d",&port);
     printf("The port no is:%d\n",port);

     bzero(&servaddr, sizeof(servaddr));
     servaddr.sin_family = AF_INET;
     servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
     servaddr.sin_port = htons(port); /* daytime server */

     bind(listenfd, (sockaddr *) &servaddr, sizeof(servaddr));

     listen(listenfd, 4);

     for ( ; ; ) {
         connfd = accept(listenfd, (sockaddr *) NULL, NULL);

         ticks = time(NULL);
         snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
         write(connfd, buff, strlen(buff));
         cout<<"Sent date info as "<< buff<<endl;

         close(connfd);
     }
 }
