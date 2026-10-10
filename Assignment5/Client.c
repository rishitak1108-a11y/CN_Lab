//Problem Statement:  Write a C program for wired network using TCP socket to demonstrate a Chat application
// Client Side Code
#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    WSADATA wsa;
    SOCKET clientSocket;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    WSAStartup(MAKEWORD(2, 2), &wsa);

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(clientSocket, (struct sockaddr *)&server,
            sizeof(server));

    printf("Connected to server!\n");

    while (1)
    {
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        send(clientSocket, buffer,
             (int)strlen(buffer), 0);

        if (strcmp(buffer, "bye") == 0)
            break;

        memset(buffer, 0, BUFFER_SIZE);

        int n = recv(clientSocket, buffer,
                     BUFFER_SIZE - 1, 0);

        if (n <= 0)
            break;

        buffer[n] = '\0';
        printf("Server: %s\n", buffer);

        if (strcmp(buffer, "bye") == 0)
            break;
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
