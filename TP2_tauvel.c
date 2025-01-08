#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char ** argv) {
    printf("TFTP Client \n");

    if (argc != 4){
        printf("Wrong command \n");
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints;
    struct addrinfo * result;
    memset(&hints,0,sizeof(struct addrinfo));

    hints.ai_family = AF_INET;
    hints.ai_protocol = IPPROTO_UDP;

    int status = getaddrinfo(argv[1],argv[2],&hints,&result);

    char ip_string[128]={0};
    char port_string[128]={0};

    getnameinfo(result->ai_addr,result->ai_addrlen,
                ip_string,128,port_string,128,
                NI_NUMERICHOST|NI_NUMERICSERV);

    printf("%s is resolved at : %s:%s \n",argv[1],ip_string,port_string);

    int sd = socket(result->ai_family,result->ai_socktype,
                    result->ai_protocol);

    char rrq[128]={0};
    rrq[1]=1;
    sprintf(rrq+2,"%s",argv[3]);
    sprintf(rrq+3+strlen(argv[3]),"octet");

    int status_test_sendto = sendto(sd,rrq,strlen(argv[3])+9,0,
           result->ai_addr,result->ai_addrlen);
   

    //There was a problem with sendto so I wrote the line below to find where was the problem
    //printf("Retour du sendTo : %d\n",status_test_sendto);

    freeaddrinfo(result);

    struct sockaddr_in sender_addr;
    socklen_t sender_addr_len = sizeof(sender_addr);

    char buffer[516]; // 512 bytes for data + 4 bytes header
    ssize_t received = recvfrom(sd, buffer, sizeof(buffer), 0, (struct sockaddr *)&sender_addr, &sender_addr_len);
    if (received <0 ) {
        perror("recvfrom failed");
        freeaddrinfo(result);
        close(sd);
        exit(EXIT_FAILURE);
    }

    char buf[4];

    printf("Envoie ACK : ");
    for (int i = 0; i < 4; i++) {
        printf("&d", buf[i]);}
    printf("\n");
    
    if ((n_bytes = sendto(sock, buf, 4, 0, res-›ai_addr, res-›ai_addrlen)) == -1){
        perror("Send ACK");
        exit (EXIT_FAILURE);
    }
    printf("ACK send &d bytes\n", n_bytes);
    exit (EXIT_SUCCESS);

    return 0;
}
