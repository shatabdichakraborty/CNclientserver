#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main()
{
	int sockfd,len,n;
	long port;
	char buff[200], data[500] = { '\0' };
	struct sockaddr_in cliaddr;
	len=sizeof(cliaddr);
	printf("Enter the port number you got from Server side:");
	scanf("%ld" ,&port);
	cliaddr.sin_family=AF_INET;
	cliaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	cliaddr.sin_port=htons(port);
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	connect(sockfd,(struct sockaddr *)&cliaddr,len);
	printf("Enter the total number of elements: ");
	scanf("%s", buff);
	int num = atoi(buff);
	write(sockfd, buff ,sizeof(buff));
	printf("Enter %d number of elements: ", num);
	for(int i = 0; i < num; i++)
	{
		scanf("%s", buff);
		strcat(data, buff);
		strcat(data, " ");
	}
	write(sockfd, data ,sizeof(data));
	n=read(sockfd,data ,sizeof(data));
	data[n]=0;
	printf("\nClient received the sorted numbers= %s\n" , data);
	return 0;
}

