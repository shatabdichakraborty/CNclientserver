#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h> 
#include <time.h>
#define BACKLOG 10 
int main(int argc, char **argv)
{ 
	if(argc != 2)
	{ 
		printf("Enter the Port No \n"); 
		exit(0); 
	} 
	int port = atoi(argv[1]); 
	int n_client = 0; 
	int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	struct sockaddr_in serverAddress; 
	serverAddress.sin_family = AF_INET; 
	serverAddress.sin_addr.s_addr = INADDR_ANY; 
	serverAddress.sin_port = htons(port); 
	bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)); 
	listen(sockfd, BACKLOG); 
	printf("Listening on port %d\n",port); 
	int i = 1; 
	while(i)
	{ 
		int client_socket = accept(sockfd, NULL, NULL); 
		n_client++; 
		time_t currentTime; 
		time(&currentTime); 
		printf("Client %d requested at %s", n_client, ctime(&currentTime)); 
		send(client_socket, ctime(&currentTime), 30, 0); 
	} 
	return 0;
}
