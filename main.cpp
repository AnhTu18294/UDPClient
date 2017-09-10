#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<sys/types.h>
#include <netinet/in.h>
#include <string.h>

using namespace std;

int main()
{
    cout << "Client!" << endl;
    int sockFD, port = 3000;
    char *message = "I wanna connect and send you a message";
    char buffer[256];

    sockFD = socket(AF_INET, SOCK_DGRAM, 0);\
    if(sockFD < 0){
        printf("ERROR: Cannot opening a socket file descriptor");
        return -1;
    }

    struct sockaddr_in serv_addr, cli_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(port);
    socklen_t client = sizeof(cli_addr);
    socklen_t server = sizeof(serv_addr);

    sendto(sockFD, message, strlen(message), 0, (struct sockaddr *) &serv_addr, server);
    recvfrom(sockFD, buffer, 256, 0, (struct sockaddr *)&cli_addr, &client);
    cout <<"Received message: " << buffer << endl;
    return 0;
}
