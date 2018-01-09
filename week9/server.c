#include<sys/types.h>
#include<stdio.h>
#include<sys/socket.h>
#include <netinet/in.h>
int main()
{
int sock=socket(AF_INET,SOCK_STREAM,0);
if (sock < 0) 
        error("ERROR opening socket");
socklen_t clilen;
struct sockaddr_in address, cli_addr;
char buffer[256];
int n,portno=4043;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = portno;
printf("not binded0");
bind(sock,(struct sockaddr *)&address,sizeof(address));
printf("binding done");
listen(sock,3);
printf("listening");
clilen = sizeof(cli_addr);
int newsockfd = accept(sock, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
  n = read(newsockfd,buffer,256);
  printf("message recieved\n");
  printf("Here is the message: %s\n",buffer);
  n = write(newsockfd,"I got your message",18);
  close(sock);
  return 0;
  

}
