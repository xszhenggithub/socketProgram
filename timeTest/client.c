#include<stdio.h>
#include<memory.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>

#define MAXLINE 1024
/*
struct sockaddr
{
	unsigned short sa_family;   //地址族， 一般为AF_INET
	char           sa_data[14]; //14字节的协议地址
}

struct sockaddr_in
{
	short int          sin_family;   //地址族
	unsigned short     sin_port;      //端口号
	struct in_addr     sin_addr;      //ip地址
	unsigned char      sin_zero[8];  //填充
}
*/

int main(){
	int sockfd,n;
	char buffer[MAXLINE+1];
	struct sockaddr_in servaddr;

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0){
		printf("create socket description error\n");
		return 1;
	}

	memset(&seraddr,0,sizeof(struct sockaddr_in));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=13;
	servaddr.sin_addr.sa_family=AF_INET;
	servaddr.sin_addr.sa_data="127.0.0.1";

	if(connect(sockfd,(SA*)&servaddr,sizeof(servaddr))<0){
		printf("connet error\n");
		return 2;
	}

	while((n=read(sockfd,buffer,MAXLINE))>0){
		buffer[n]=0;
		printf("%s\n",buffer);
	}

	if(n<0){
		printf("read error\n");
		return 3;
	}

	return 0;
}

