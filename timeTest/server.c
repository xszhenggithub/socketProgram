#include<stdio.h>
#include<memory.h>
#include<netinet/in.h>
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

	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=13;
	servaddr.sin_addr.s_addr=0;

	bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	listen(listenfd,5);

	while(1){
		connfd=accept(listenfd,NULL,NULL);
		ticks=time(NULL);
		snprintf(buffer,BUFFSIZE,"%.24s\r\n",ctime(&ticks));
		write(connfd,buffer,strlen(buffer));
	}
	
	return 0;
}

