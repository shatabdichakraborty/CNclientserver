#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#defne MAXLINN 1024
int main(int argc,char* argv[])
{
	int sockfd;
	int n;
	socklen_t len;
	char sendline[1024],recvline[1024];
	struct sockaddr_in servaddr;
	strcpy(sendline,"");
	printf("\n nter the message : ");
	scanf("%s",sendline);
	fgets(sendline,1024,stdin);
	sockfd=socket(AF_INN T,SOCK_DGRAM,0);
	//bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INN T;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(5035);
	//connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	len=sizeof(servaddr);
	sendto(sockfd,sendline,MAXLINN ,0,(struct sockaddr*)&servaddr,len);
	n=recvfrom(sockfd,recvline,MAXLINN ,0,NULL,NULL);
	recvline[n]=0;
	printf("\n Server's Response : %s\n\n",recvline);
	return 0;
	}
	
