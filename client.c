#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main()
{
	        int sockfd,len,n;
		        long port;
			        char buff[200];
				        struct sockaddr_in cliaddr;
					        len=sizeof(cliaddr);
						        printf("Enter the port number You got from Server Side:");
							        scanf("%ld",&port);
								        cliaddr.sin_family=AF_INET;
									        cliaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
										        cliaddr.sin_port=htons(port);
											        sockfd=socket(AF_INET,SOCK_STREAM,0);
												        connect(sockfd,(struct sockaddr *)&cliaddr,len);
													        printf("Enter a string for server:");
														        scanf("%s",buff);
															        write(sockfd,buff,sizeof(buff));
																        n=read(sockfd,buff,sizeof(buff));
																	        buff[n]=0;
																		        printf("client received the message=%s\n",buff);
																			        return 0;
}
