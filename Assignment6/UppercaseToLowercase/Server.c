// Problem Statement: Write a program for wired network using UDP socket to the following operation:
// String Conversion from UpperCase to LowerCase 
// Server Side Code:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server, client;
    int len = sizeof(client);
    char str[100];
    int i, n;

    WSAStartup(MAKEWORD(2, 2), &wsa);

    s = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(s, (struct sockaddr *)&server, sizeof(server));

    printf("UDP Server Started\n");
    printf("Enter bye to exit.\n");

    while (1)
    {
        n = recvfrom(s, str, 99, 0,
                     (struct sockaddr *)&client, &len);
        if (n == SOCKET_ERROR)
            break;

        str[n] = '\0';

        if (strcmp(str, "bye") == 0)
        {
            sendto(s, "bye", 4, 0,
                   (struct sockaddr *)&client, len);
            break;
        }

        for (i = 0; str[i] != '\0'; i++)
            str[i] = tolower((unsigned char)str[i]);

        sendto(s, str, strlen(str) + 1, 0,
               (struct sockaddr *)&client, len);

        printf("Converted: %s\n", str);
    }

    closesocket(s);
    WSACleanup();
    return 0;
}
