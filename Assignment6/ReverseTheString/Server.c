// Problem Statement: Write a program for wired network using UDP socket to the following operation:
// Reverse the string
// Server Side Code:

#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET server;
    struct sockaddr_in serverAddr, clientAddr;
    int clientLen = sizeof(clientAddr);
    char str[1024], temp;
    int i, j;

    WSAStartup(MAKEWORD(2, 2), &wsa);

    server = socket(AF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(server, (struct sockaddr *)&serverAddr,
         sizeof(serverAddr));

    printf("UDP Server started. Waiting for client...\n");

    while (1)
    {
        int n = recvfrom(server, str, sizeof(str) - 1, 0,
                         (struct sockaddr *)&clientAddr,
                         &clientLen);

        if (n == SOCKET_ERROR)
            break;

        str[n] = '\0';

        if (strcmp(str, "bye") == 0)
        {
            printf("Client sent bye. Server exiting.\n");
            sendto(server, "bye", 3, 0,
                   (struct sockaddr *)&clientAddr, clientLen);
            break;
        }

        printf("Received: %s\n", str);

        i = 0;
        j = strlen(str) - 1;

        while (i < j)
        {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }

        sendto(server, str, strlen(str), 0,
               (struct sockaddr *)&clientAddr, clientLen);

        printf("Reversed: %s\n", str);
    }

    closesocket(server);
    WSACleanup();

    return 0;
}
