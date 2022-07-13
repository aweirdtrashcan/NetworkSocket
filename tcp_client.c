#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {

    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);

    int server_response = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    if (server_response == -1) 
    {
        printf("An error has occurred\n");
    }
    else if (server_response == 0) {
        printf("Connection stablished successfully");
    }

    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);
    
    printf("Server message is: %s\n", server_response);

    close(network_socket);

    return 0;
}