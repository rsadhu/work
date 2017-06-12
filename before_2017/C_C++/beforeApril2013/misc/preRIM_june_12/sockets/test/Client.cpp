#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>
#include<string.h>
#include<stdio.h>
#include <netdb.h>


int main(int argc,char *argv[])
{
	sockaddr_in serverAddr;


	struct hostent *server; // used to get servername 

	int sockFd  = socket(AF_INET,SOCK_STREAM,0);

	bzero(&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(13);

//	inet_pton(AF_INET,serverName,serverAddr.sin_addr);

	int ret=  connect(sockFd,(const sockaddr *)&serverAddr,sizeof(serverAddr));
	printf("\n connected  ret :: %d\n",ret);

	char buffer[256];
	fgets(buffer,255,stdin);
	printf("\n %s\n",buffer);


//	int  n = write(sockFd,buffer,strlen(buffer));
	//n = read(sockFd,buffer, strlen(buffer));
//	printf("data written to the socket   %d \n",n);

	//shutdown(sockFd,2);
//	close(sockFd);
	return 0;
}
