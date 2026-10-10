// Problem Statement: Write a program for wired network using UDP socket to the following operation:
// Reverse the string 
// Client Side Code:

#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET client;
    struct sockaddr_in serverAddr;
    int serverLen = sizeof(serverAddr);
    char str[1024], result[1024];
    int n;

    WSAStartup(MAKEWORD(2, 2), &wsa);

    client = socket(AF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("UDP String Reversal Client\n");
    printf("Enter bye to exit both client and server.\n");

    while (1)
    {
        printf("\nEnter a string: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        sendto(client, str, strlen(str), 0,
               (struct sockaddr *)&serverAddr,
               sizeof(serverAddr));

        n = recvfrom(client, result, sizeof(result) - 1, 0,
                     (struct sockaddr *)&serverAddr,
                     &serverLen);

        if (n == SOCKET_ERROR)
            break;

        result[n] = '\0';

        if (strcmp(result, "bye") == 0)
        {
            printf("Exiting client and server...\n");
            break;
        }

        printf("Reversed string: %s\n", result);
    }

    closesocket(client);
    WSACleanup();

    return 0;
}
