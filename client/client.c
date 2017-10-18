
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
#define IP "192.168.242.11"         //server IP
#define PORT 1234                   //server Port Nr.

int main (int argc, char **argv)
{

  int sockFd = socket (AF_INET, SOCK_DGRAM, 0);
  if (sockFd == -1)
  {
    printf ("Error creating socket\n");
    return EXIT_FAILURE;
  }

  struct sockaddr_in serverAddress;
  memset (&serverAddress, 0, sizeof (serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons (PORT);
  int DestAddrResult = inet_aton (IP,
                                  &serverAddress.sin_addr);    //inet_ntoa or inet_aton  network to ASCII vice versa
  if (DestAddrResult == 0)
  {
    printf ("The address is invalid\n");
  }

  socklen_t length = sizeof (serverAddress);
  int connectResult = connect (sockFd, (struct sockaddr *) &serverAddress,
                               length);          //serveradresse & port
  if (connectResult != 0)
  {
    printf ("Building the connection failed\n");
  }
  //Verbindung hergestellt, Zeit zum senden! sendto & recvfrom nicht noetig
  //weil die Verbindung zum server mit connect aufgebaut wurde

  int counter = 0;
  while(counter <3)
  {
    char buffer[100] = "Hello server";
    ssize_t sendResult = send (sockFd, &buffer, sizeof (char) * 100, 0);
    if (sendResult == -1)
    {
      printf ("Error sending data\n");
    }
    char receiveBuffer[100] = {};


    char *bigBuffer = malloc (10000);
    char *current = bigBuffer;

    memcpy (current, receiveBuffer, 100);
    current = current + 100;

    ssize_t receiveResult = recv(sockFd, receiveBuffer, 100, 0);
    if(receiveResult < 0)
    {
      printf("Error receiving message\n");
    }
    printf("Message from server: %s\n",receiveBuffer);
    counter++;
  }


  //Verbinndung beenden
  close (sockFd);

  return (EXIT_SUCCESS);
}


