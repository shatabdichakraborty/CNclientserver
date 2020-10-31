#include<stdio.h> 
#include<netinet/in.h> 
#include<netdb.h>
#include<fcntl.h>
#include<unistd.h>
#define SERV_TCP_PORT 5035 
int main(int argc,char**argv) 
{ 
	int sockfd,newsockfd,clength; 
	struct sockaddr_in serv_addr,cli_addr; 
	char buffer[4096]; 
	sockfd=socket(AF_INET,SOCK_STREAM,0); 
	serv_addr.sin_family=AF_INET; 
	serv_addr.sin_addr.s_addr=INADDR_ANY; 
	serv_addr.sin_port=htons(SERV_TCP_PORT); 
	bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)); 
	printf("\nServer is Listening.."); 
	printf("\n"); listen(sockfd,5); 
	clength=sizeof(cli_addr); 
	newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
	printf("\nClient accepted"); 
	printf("\n"); read(newsockfd,buffer,4096); 
	printf("\nClient message:%s",buffer); 
	write(newsockfd,buffer,4096); 
	printf("\n"); 
	close(sockfd); 
	return 0;
}

