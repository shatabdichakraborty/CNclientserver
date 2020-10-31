#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<fcntl.h>
#include<unistd.h>
#include<arpa/inet.h>
#define SERV_TCP_PORT 5035
int main(int argc,char*argv[])
{
	int sockfd;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[4096];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(SERV_TCP_PORT);
	printf("\nConnected");
	connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)); 
	printf("\nEnter the message\n"); 
	printf("\nClient: "); 
	fgets(buffer,4096,stdin); 
	write(sockfd,buffer,4096); 
	printf("echo message by server: %s",buffer); 
	printf("\n"); 
	close(sockfd); 
	return 0; 
}

