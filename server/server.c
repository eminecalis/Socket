
/* 
 * File:   main.c
 * Author: socket_test
 *
 * Created on October 11, 2017, 10:53 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

/*
 * 
 */

#define IP "192.168.242.11"   //server IP
#define PORT 1234            //server port number

int main (int argc, char **argv)
{

  int sockFd = socket (AF_INET, SOCK_DGRAM, 0);
  if (sockFd == -1)
  {
    printf ("Error creating socket\n");
    return EXIT_FAILURE;
  }

  //bind: um OS mitzuteilen zu welchem Port das Socket gehört
  //INADDR_ANY Verbindungen für jede IP-Adresse annehmen
  struct sockaddr_in serveraddress;
  memset (&serveraddress, 0, sizeof (serveraddress));
  serveraddress.sin_family = AF_INET;
  serveraddress.sin_port = htons (PORT);   //host to network
  int serverAddressResult = inet_aton (IP, &serveraddress.sin_addr);
  socklen_t serverAddressLength = sizeof (serveraddress);
  int bindResult = bind (sockFd, (struct sockaddr *) &serveraddress,
                         serverAddressLength);
  if (bindResult != 0)
  {
    printf ("Error binding socket\n");
  }

  /* //listen for TCP/IP
   * int numberOfConnections = 10;
   * int listenResult = listen(sockFd,numberOfConnections);
   * if(listenResult != 0)
   * {
   *     printf("No connection attempts\n");
   * }  
    
   */
  struct sockaddr_in clientaddress;
  memset (&clientaddress, 0, sizeof (clientaddress));

  socklen_t clientAddressLength = sizeof (clientaddress);

  char *buffer = malloc (1500);   //groesse des udp pakets
  int counter = 0;
  while (counter <3)
  {

    int receiveResult = recvfrom (sockFd, buffer, 1500, 0,
                                  (struct sockaddr *) &clientaddress,
                                  &clientAddressLength);
    if (receiveResult < 0)
    {
      printf ("Nothing received\n");
    }
    char *clientIp = inet_ntoa (clientaddress.sin_addr);
    printf("IP address of client sending the message: %s\n",clientIp);
    int clientPort = ntohs (clientaddress.sin_port);
    printf("Portnumber of client sending the message: %d\n",clientPort);
    printf ("Nachricht from client:%s\n", buffer);
    counter++;
    printf ("Number of received messages: %d\n",counter);

    char *sendBuffer =malloc (1500);

    int printResult = snprintf (sendBuffer, 1500, "IP: %s, Port: %d, Nr.of messages: %d", clientIp,clientPort,counter);
    if(printResult < 0)
    {
      printf("String could not be written\n");
    }
    socklen_t lengthOfClientAddress = sizeof(clientaddress);
    size_t sendMessageLength = strlen (sendBuffer);
    ssize_t sendtoResult = sendto(sockFd,sendBuffer, sendMessageLength, 0,
                                  (struct sockaddr*)&clientaddress, lengthOfClientAddress);
  }
  /*  //For TCP/IP : Adressinformationen des Clients befinden sich im zweiten Parameter von accept().
   *  int newSockFd = accept(sockFd,(struct sockaddr *)&clientaddress,&clientAddressLength);
   *  if(newSockFd == -1)
   *  {
   *      printf("Connection to client not established\n");
   *  }
   */
  return (EXIT_SUCCESS);
}

