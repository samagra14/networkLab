#include <stdio.h> 
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <linux/if.h>
#include <string.h>
#include <fcntl.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include<iostream>
using namespace std;


void getMacAddress(char * uc_Mac){

int fd;
struct ifreq ifr;
char *iface = "eno1";
char *mac;

fd = socket(AF_INET, SOCK_DGRAM,0);
ifr.ifr_addr.sa_family = AF_INET;
strncpy((char*)ifr.ifr_name,(const char*)iface,IFNAMSIZ-1);

ioctl(fd, SIOCGIFHWADDR,&ifr);

close(fd);

mac = (char*)ifr.ifr_hwaddr.sa_data;

sprintf((char *)uc_Mac,(const char *)"%.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n" , mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

}

int main(){
   struct hostent *he;
struct in_addr ipv4addr;
string stri;
cout<<"input IP "<<endl;
cin>>stri;

inet_pton(AF_INET, stri.c_str(), &ipv4addr);
he = gethostbyaddr(&ipv4addr, sizeof ipv4addr, AF_INET);
printf("Host name: %s\n", he->h_name); 

// To get mac address
struct ifreq s_two;
int fd_two = socket(PF_INET, SOCK_DGRAM,IPPROTO_IP);
strcpy(s_two.ifr_name,"eth0");
	int i;
	cout<<"MAC ADDRESS == "<<endl;
	for(i=0;i<6;i++)
		printf("%02x",(unsigned char) s_two.ifr_addr.sa_data[i]);
	puts("\n");




	char mac[32]={0};

	getMacAddress (mac);

	cout<<endl<<"Mac Address : "<<mac;
}
