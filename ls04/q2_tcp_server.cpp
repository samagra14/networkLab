  #include     <time.h>
  #include <iostream>
  #include <stdio.h>
  #include <sys/socket.h>
  #include <stdlib.h>
  #include <netinet/in.h>
  #include <string.h>
  #include <arpa/inet.h>
  #include <unistd.h>

  int
  main(int argc, char **argv)
  {
      int     listenfd, connfd;
      struct sockaddr_in servaddr;
      char    buff[MAXLINE];
      time_t ticks;

     listenfd = Socket(AF_INET, SOCK_STREAM, 0);

     bzeros(&servaddr, sizeof(servaddr));
     servaddr.sin_family = AF_INET;
     servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
     servaddr.sin_port = htons(13); /* daytime server */

     Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

     Listen(listenfd, LISTENQ);

     for ( ; ; ) {
         connfd = Accept(listenfd, (SA *) NULL, NULL);

         ticks = time(NULL);
         snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
         Write(connfd, buff, strlen(buff));

         Close(connfd);
     }
 }
