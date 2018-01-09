#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include<string.h>
int main(int argc, char *argv[])
{
int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
 char buffer[256];
 portno=4043;
 
 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 server = gethostbyname(argv[1]);
 if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(portno);
printf("not connected");
connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
printf("connection established\n");
printf("Please enter the message: ");
fgets(buffer,255,stdin);
n = write(sockfd,buffer,strlen(buffer));
 n = read(sockfd,buffer,18);
 printf("%s\n",buffer);
 close("sockfd");
 return 0;



}
