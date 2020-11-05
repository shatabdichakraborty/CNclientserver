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
       	int listenfd, connfd, len, n;
	 char buff[200];
	 struct sockaddr_in servaddr, cliaddr;
	 len = sizeof(servaddr);
	 servaddr.sin_family = AF_INET;

	 servaddr.sin_addr.s_addr = htons(INADDR_ANY);

	 servaddr.sin_port = htons(0);
	 listenfd = socket(AF_INET, SOCK_STREAM, 0);
	 bind(listenfd, (struct sockaddr *)&servaddr, len);
	 getsockname(listenfd, (struct sockaddr *)&servaddr, &len);
	 printf("Port for client=%ld\n", (long)ntohs(servaddr.sin_port));
	 listen(listenfd, 5);
	 connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);
	 n = read(connfd, buff, sizeof(buff));

	 buff[n] = 0;
	 int num = atoi(buff);

	 printf("Server received the number= %d\n", num);
	 int numdata[1];
	 numdata[0] = num * num;
	  strcpy(buff, "");
	 for (int i = 0; i < 2; i++)
	  {
		 char temp[50];
		 sprintf(temp, "%d", numdata[i]);
		 strcat(buff, temp);															 strcat(buff, " ");
	 }
	 write(connfd, buff, sizeof(buff));

 return 0;
}
