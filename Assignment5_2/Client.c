// Problem Statement: Write a C program for a wired network using TCP sockets to demonstrate mathematical operations.
// Server Side Code:

#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET client;
    struct sockaddr_in address;
    int a, b, result;
    char op[10];

    WSAStartup(MAKEWORD(2, 2), &wsa);

    client = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client, (struct sockaddr *)&address, sizeof(address));

    printf("TCP Mathematical Operations\n");
    printf("Enter +, -, *, or / to perform an operation.\n");
    printf("Type 'exit' to close the connection.\n\n");

    while (1)
    {
        printf("Enter operator (+, -, *, /) or exit: ");
        scanf("%9s", op);

        send(client, op, sizeof(op), 0);

        if (strcmp(op, "exit") == 0)
        {
            printf("Client disconnected.\n");
            break;
        }

        printf("Enter first number: ");
        scanf("%d", &a);

        printf("Enter second number: ");
        scanf("%d", &b);

        send(client, (char *)&a, sizeof(a), 0);
        send(client, (char *)&b, sizeof(b), 0);

        recv(client, (char *)&result, sizeof(result), 0);

        if (op[0] == '/' && b == 0)
            printf("Division by zero is not allowed.\n");
        else
            printf("Result = %d\n", result);

        printf("\n");
    }

    closesocket(client);
    WSACleanup();

    return 0;
}
