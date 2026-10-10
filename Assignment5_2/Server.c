// Problem Statement: Write a C program for a wired network using TCP sockets to demonstrate mathematical operations.
// Server Side Code:

#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET server, client;
    struct sockaddr_in address;
    int size, a, b, result;
    char op[10];

    WSAStartup(MAKEWORD(2, 2), &wsa);

    server = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = INADDR_ANY;

    bind(server, (struct sockaddr *)&address, sizeof(address));
    listen(server, 1);

    printf("Server waiting for client...\n");

    size = sizeof(address);
    client = accept(server, (struct sockaddr *)&address, &size);

    while (1)
    {
        recv(client, op, sizeof(op), 0);

        if (strcmp(op, "exit") == 0)
        {
            printf("Client disconnected.\n");
            break;
        }

        recv(client, (char *)&a, sizeof(a), 0);
        recv(client, (char *)&b, sizeof(b), 0);

        switch (op[0])
        {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b != 0)
                    result = a / b;
                else
                    result = 0;
                break;
            default: result = 0;
        }

        send(client, (char *)&result, sizeof(result), 0);

        printf("Result = %d\n", result);
    }

    closesocket(client);
    closesocket(server);
    WSACleanup();

    return 0;
}
