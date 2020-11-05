#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int compare(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
	int listenfd,connfd,len,n;
	char buff[200], data[500];
	struct sockaddr_in servaddr,cliaddr;
	len=sizeof(servaddr);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htons( INADDR_ANY);
	servaddr.sin_port=htons(0);
	listenfd=socket(AF_INET,SOCK_STREAM,0);
	bind(listenfd, (struct sockaddr *)&servaddr,len);
	getsockname(listenfd,(struct sockaddr *)&servaddr ,&len);
	printf("Port for client=%ld\n",(long)ntohs(servaddr.sin_port));
	listen(listenfd,5);
	connfd=accept(listenfd,(struct sockaddr *)&cliaddr ,&len);
	n=read(connfd , buff ,sizeof(buff));
	buff[n]=0;
	int num = atoi(buff);
	n=read(connfd , data ,sizeof(data));
	data[n]=0;
	int arr[num], i = 0;
	char* temp = strtok(data, " ");
	while (temp != NULL)
	{
		arr[i++] = atoi(temp);
		temp = strtok(NULL, " ");
	}
	qsort(arr, num, sizeof(int), compare);
	strcpy(data, "");
	for(int i = 0; i < num; i++)
	{
		char temp[50];
		sprintf (temp, "%d", arr[i]);
		strcat(data, temp);
		strcat(data, " ");
	}
	write(connfd, data ,sizeof(data));
	return 0;
}
