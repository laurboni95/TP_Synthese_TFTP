#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char**argv){
    printf("TFTP Client \n");

    if(argc != 4){
        printf("Usage: %s <host> <port> <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //Retrieve information about the command, the host used and the file name (gettftp)
    const char *command = argv[1];
    const char *host = argv[2];
    const char *file_name = argv[3];

    printf("Command: %s\n", command);
    printf("Host: %s\n", host);
    printf("File: %s\n", file_name);


    struct addrinfo hints;
    struct addrinfo * result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_protocol = IPPROTO_UDP;
    int status = getaddrinfo(argv[1], argv[2], &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    char ip_string[128] = {0};
    char port_string[128] = {0};
    getnameinfo(result->ai_addr, result->ai_addrlen,
                ip_string, sizeof(ip_string),
                port_string, sizeof(port_string),
                NI_NUMERICHOST | NI_NUMERICSERV);

    printf("%s is resolved at: %s:%s\n", argv[1], ip_string, port_string);

    freeaddrinfo(result);

    return 0;
}