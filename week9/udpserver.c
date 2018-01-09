
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>


int main()
{
     int udpSocket, newsockfd, portno, clilen,nBytes,addr_size;
    
     struct sockaddr_in serv_addr, cli_addr;
       struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
     int n,i;
     
    udpSocket = socket(PF_INET, SOCK_DGRAM, 0);
     
     serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    char buffer[]="message successfully recieved";
     
     bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
      addr_size = sizeof serverStorage;
       while(1){
    
    nBytes = recvfrom(udpSocket,buffer,1024,0,(struct sockaddr *)&serverStorage, &addr_size);



   
    sendto(udpSocket,buffer,nBytes,0,(struct sockaddr *)&serverStorage,addr_size);
  }
     
     return 0; 
}
