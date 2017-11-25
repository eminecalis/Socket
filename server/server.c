
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

#define TEXT "\n" \
"\n"\
"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur rhoncus vitae dolor vitae convallis. Vestibulum tincidunt orci sollicitudin lacus venenatis commodo. Nam vel arcu diam. Sed suscipit tortor in tincidunt dapibus. Mauris id dui tortor. Maecenas tristique, libero nec suscipit elementum, orci sem imperdiet purus, consectetur pretium purus diam at dolor. Donec ac elementum risus. Integer viverra sed orci vitae ullamcorper. Cras vulputate convallis congue. Maecenas tellus mauris, suscipit vel augue eget, dapibus ultrices mauris. Interdum et malesuada fames ac ante ipsum primis in faucibus. Nullam tortor nibh, accumsan mollis dui fermentum, mattis mollis justo.\n"\
"\n"\
"Aliquam vehicula lacinia massa id eleifend. Nullam sit amet viverra dui. Sed ante turpis, semper et viverra vitae, tempor id justo. Sed et dui vulputate, varius justo sed, fermentum est. Integer odio quam, efficitur nec nunc in, consequat maximus lectus. Aenean et justo erat. In eu arcu risus. Duis lectus lacus, sodales ut sapien nec, interdum elementum elit. Nullam eleifend risus in aliquet porttitor. Donec vulputate vulputate ultricies. Praesent volutpat porta augue, ut dictum mi dignissim eget. Nunc vulputate pharetra nunc vel accumsan. Mauris semper nisi augue, eu fermentum nisl tempor ut. Phasellus eleifend dolor vitae mauris consequat, a faucibus nisl dignissim. Ut nisi neque, semper id eleifend eu, venenatis ac justo.\n"\
"\n"\
"Sed varius purus non elit malesuada, sed lobortis sem commodo. Nunc iaculis pulvinar posuere. Sed id ornare orci, non commodo justo. In sit amet nisl accumsan, aliquet velit nec, tincidunt libero. Morbi non urna interdum, tincidunt elit suscipit, lobortis sapien. Cras sit amet dui pulvinar, fringilla nulla vitae, porta ligula. Mauris sem risus, ornare non arcu non, fringilla fermentum est.\n"\
"\n"\
"Nam condimentum quam et felis condimentum, quis feugiat felis aliquet. Maecenas a odio bibendum, porta arcu at, sodales ex. Aliquam erat volutpat. Mauris luctus suscipit risus. Sed fringilla orci vel tortor auctor malesuada. Vivamus commodo enim velit, hendrerit faucibus neque commodo a. Cras dolor justo, viverra in rutrum nec, imperdiet et lectus.\n"\
"\n"\
"Suspendisse ullamcorper, erat eu auctor interdum, odio mauris varius ligula, a porttitor ipsum odio hendrerit nunc. Suspendisse augue libero, aliquam a pulvinar vel, tempus sit amet tortor. Suspendisse rhoncus non purus et dapibus. Nulla sit amet ligula luctus lorem luctus placerat eu hendrerit libero. Suspendisse sit amet erat sed sem tincidunt hendrerit in sit amet diam. Morbi cursus pharetra tortor vel interdum. Cras sed tortor ante. Curabitur convallis a leo non feugiat. Vivamus a aliquam diam, id tincidunt elit. Sed non pharetra ipsum. Proin tempor finibus velit sit amet finibus.\n"\
"\n"\
"Sed bibendum consectetur semper. Pellentesque vitae elit vel magna convallis lacinia. Nam euismod, mi vitae laoreet ornare, ipsum risus semper massa, id lobortis lacus risus eget velit. Integer bibendum nec lacus sed fermentum. Sed eu tortor non tortor euismod posuere. Curabitur interdum erat vel erat vulputate, sit amet fringilla velit feugiat. Nullam sit amet ex blandit, commodo elit tincidunt, porttitor risus. Donec at turpis eleifend, scelerisque urna eget, tristique arcu. Phasellus varius placerat massa, quis suscipit nulla. Nulla molestie volutpat tristique. Integer lacinia augue turpis, non bibendum metus accumsan sit amet.\n"\
"\n"\
"Aenean nec mollis velit. Aliquam vitae felis lacinia, consectetur enim id, maximus libero. Suspendisse potenti. Phasellus lobortis pretium scelerisque. Vivamus varius neque ante, sit amet malesuada urna sollicitudin ut. Morbi posuere urna non nunc ullamcorper faucibus. Etiam efficitur purus a tellus vulputate, eget tincidunt risus imperdiet. Sed facilisis urna non aliquam pharetra. Etiam quis hendrerit odio. Nunc aliquet gravida viverra. Nunc a magna faucibus, ultrices ex id, lacinia sem.\n"\
"\n"\
"In efficitur maximus pellentesque. Etiam eu ultricies lectus, at porta augue. Integer ullamcorper leo nisl, quis porta risus accumsan ac. Suspendisse ac diam enim. Phasellus a tempus urna. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Sed id leo sit amet purus commodo ultrices eu et nisi. Maecenas auctor, augue nec tempus gravida, mauris metus sagittis ligula, et dapibus sem orci a lacus. Sed ipsum mauris, sodales eget cursus quis, aliquam nec nibh. Ut condimentum augue a nulla dignissim facilisis. Pellentesque congue vehicula eleifend. Aenean consequat, mi eget commodo tempus, ante diam finibus justo, id porttitor sapien purus in urna. Cras sed turpis nec eros tempor viverra. Nam eget ante sollicitudin, euismod magna non, viverra libero. Fusce iaculis et urna eget venenatis. Duis venenatis orci ac tempus fermentum.\n"\
"\n"\
"Nullam efficitur rhoncus eros, id elementum ex posuere sed. Mauris elementum magna ex, nec aliquam ante ultricies sed. Curabitur pretium risus porttitor urna dictum, vel placerat sapien pulvinar. Morbi velit purus, suscipit nec felis sit amet, tincidunt dignissim nunc. Fusce fermentum efficitur fringilla. Donec tincidunt vitae dui a maximus. Duis ullamcorper quis nibh efficitur vehicula. Suspendisse sed placerat ex. Fusce egestas lorem a bibendum semper. Proin mattis lorem nec ultrices mollis.\n"\
"\n"\
"Donec porttitor mi at pharetra hendrerit. Ut semper felis maximus felis pretium dignissim. Mauris efficitur eu nulla ut blandit. Curabitur laoreet nisi elementum porttitor ullamcorper. Vivamus in mauris pulvinar, cursus augue a, tempus augue. Ut lacinia arcu sit amet velit iaculis consequat. Proin vehicula nibh at mi pharetra dignissim consectetur quis lorem. "
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
  while (counter < 3)
  {

    int receiveResult = recvfrom (sockFd, buffer, 1500, 0,
                                  (struct sockaddr *) &clientaddress,
                                  &clientAddressLength);
    if (receiveResult < 0)
    {
      printf ("Nothing received\n");
    }
    char *clientIp = inet_ntoa (clientaddress.sin_addr);
    printf ("IP address of client sending the message: %s\n", clientIp);
    int clientPort = ntohs (clientaddress.sin_port);
    printf ("Portnumber of client sending the message: %d\n", clientPort);
    printf ("Nachricht from client:%s\n", buffer);
    counter++;
    printf ("Number of received messages: %d\n", counter);

    char *sendBuffer = malloc (1400);
    char *sendBufferCursor = sendBuffer;

    /*int printResult = snprintf (sendBuffer, 1500, "IP: %s, Port: %d, Nr.of messages: %d", clientIp,clientPort,counter);
    if(printResult < 0)
    {
      printf("String could not be written\n");
    }
     size_t sendMessageLength = strlen (sendBuffer);
     */
    socklen_t lengthOfClientAddress = sizeof (clientaddress);
    size_t lengthOfText = strlen (TEXT);
    memcpy (sendBufferCursor, &lengthOfText, 4);
    sendBufferCursor = sendBufferCursor + 4;
    char *current = TEXT;
    int sendBufferSize = 1400;
    size_t sendSize;
    size_t totalSendSize = 0;
    int firstIteration = 1;        //1 is true
    size_t placeHolder =4;
    do
    {
      if(firstIteration == 0)
      {
        placeHolder = 0;
      }

      if (lengthOfText < (sendBufferSize - placeHolder))
      {
        memcpy (sendBufferCursor, current, lengthOfText);
        sendSize = lengthOfText + placeHolder;
      } else
      {
        memcpy (sendBufferCursor, current, 1400 - placeHolder);
        sendSize = 1400;
      }
      totalSendSize = totalSendSize+sendSize;
      ssize_t sendtoResult = sendto (sockFd, sendBuffer, sendSize, 0,
                                     (struct sockaddr *) &clientaddress,
                                     lengthOfClientAddress);
      firstIteration = 0;
      sendBufferCursor =sendBuffer;
      current =current+sendSize-placeHolder;

    } while (totalSendSize < lengthOfText);


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

