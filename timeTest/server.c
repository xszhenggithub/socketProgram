#include<stdio.h>
#include<memory.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<time.h>

#define BUFFSIZE 1024
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
	int listenfd,connfd;
	char buffer[BUFFSIZE+1];
	struct sockaddr_in servaddr;
	time_t ticks;

	listenfd=socket(AF_INET,SOCK_STREAM,0);

	memset(&seraddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=13;
	servaddr.sin_addr.sa_family=AF_INET;
	servaddr.sin_addr.sa_data="255.255.255.255";

	bind(listenfd,&servadd,sizeof(servaddr));
	listen(listenfd, );

	while(true){
		connfd=accept(listenfd,NULL,NULL);
		ticks=time(NULL);
		snprintf(buffer,BUFFSIZE,"%.24s\r\n",ctime(&ticks));
		write(connfd,buffer,strlen(buffer));
	}
	
	return 0;
}

