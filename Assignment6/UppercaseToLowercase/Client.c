// Problem Statement: Write a program for wired network using UDP socket to the following operation:
// String Conversion from UpperCase to LowerCase 
// Client Side Code:

#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    int len = sizeof(server);
    int n;
    char str[100];

    WSAStartup(MAKEWORD(2, 2), &wsa);

    s = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter uppercase string (type bye to exit):\n");

    while (1)
    {
        printf("Enter string: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        sendto(s, str, strlen(str) + 1, 0,
               (struct sockaddr *)&server, len);

        n = recvfrom(s, str, 99, 0,
                     (struct sockaddr *)&server, &len);
        if (n == SOCKET_ERROR)
            break;

        str[n] = '\0';
        printf("Server reply: %s\n", str);

        if (strcmp(str, "bye") == 0)
        {
            printf("Exiting...\n");
            break;
        }
    }

    closesocket(s);
    WSACleanup();
    return 0;
}
