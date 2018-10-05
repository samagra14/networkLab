#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
using namespace std;



int main(void){

int n;
int udp_send_size;
unsigned int m = sizeof(n);
int fdsocket;
fdsocket = socket(AF_INET, SOCK_DGRAM,0);
getsockopt(fdsocket, SOL_SOCKET,SO_RCVBUF,(void*) &n,&m);
cout<<"default udp receive buffer size = "<< n<<endl;
unsigned int size_2 = sizeof(udp_send_size);
getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void*)&udp_send_size,&size_2);
cout<<"Default udp send buffer size = "<<udp_send_size<<endl<<endl<<endl;







int def_tcp_val;
int fdsocket_two;
int n_two;
unsigned int size = sizeof(n_two);
fdsocket_two = socket(AF_INET,SOCK_STREAM,0);
getsockopt(fdsocket_two,SOL_SOCKET,SO_RCVBUF,(void*)&n_two,&size);
cout<<"default tcp receive buffer size = "<< n_two<<endl;
int tcp_send_size;
unsigned int size_4 = sizeof(tcp_send_size);
getsockopt(fdsocket_two,SOL_SOCKET,SO_SNDBUF,(void*)&tcp_send_size,&size_4);
cout<< "Default tcp send buffer size = "<< tcp_send_size<<endl<<endl<<endl;



cout<< "Changing buffer sizes we get"<<endl<<endl;
n--;
udp_send_size++;

n_two -=2;
tcp_send_size+=2;
setsockopt(fdsocket,SOL_SOCKET,SO_RCVBUF,(char*)&n,sizeof(n));
getsockopt(fdsocket, SOL_SOCKET,SO_RCVBUF,(void*) &n,&m);
cout<<"changed udp receive buffer size = "<< n<<endl;

setsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(char*)&udp_send_size,sizeof(udp_send_size));
getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void*)&udp_send_size,&size_2);
cout<<"Changed udp send buffer size = "<<udp_send_size<<endl<<endl<<endl;

setsockopt(fdsocket_two,SOL_SOCKET,SO_RCVBUF,(char*)&n_two,sizeof(n_two));
getsockopt(fdsocket_two,SOL_SOCKET,SO_RCVBUF,(void*)&n_two,&size);
cout<<"changed tcp receive buffer size = "<< n_two<<endl;



setsockopt(fdsocket_two,SOL_SOCKET,SO_SNDBUF,(char*)&tcp_send_size,sizeof(tcp_send_size));

getsockopt(fdsocket_two,SOL_SOCKET,SO_SNDBUF,(void*)&tcp_send_size,&size_4);
cout<< "Changed tcp send buffer size = "<< tcp_send_size<<endl<<endl<<endl;




}
