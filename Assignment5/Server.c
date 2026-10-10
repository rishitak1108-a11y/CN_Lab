// Problem Statement:  Write a C program for wired network using TCP socket to demonstrate a Chat application
// Server Side Code
#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in server, client;
    int clientSize;
    char buffer[BUFFER_SIZE];

    WSAStartup(MAKEWORD(2, 2), &wsa);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    bind(serverSocket, (struct sockaddr *)&server,
         sizeof(server));

    listen(serverSocket, 1);

    printf("Server waiting for client...\n");

    clientSize = sizeof(client);
    clientSocket = accept(serverSocket,
        (struct sockaddr *)&client, &clientSize);

    printf("Client connected!\n");

    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);

        int n = recv(clientSocket, buffer,
                     BUFFER_SIZE - 1, 0);

        if (n <= 0)
            break;

        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        if (strcmp(buffer, "bye") == 0)
            break;

        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        send(clientSocket, buffer,
             (int)strlen(buffer), 0);

        if (strcmp(buffer, "bye") == 0)
            break;
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
