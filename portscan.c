#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>


int main(int argc, char *argv[]) {

    if(argc <=1) {
        printf("None arguments are given\nRun example: ./portscan IP\n");
    }else {
        int sock;
        int conn;

        int port;
        int start = 0;
        int end = 65535;
        char *dst;
        dst = argv[1];

        struct sockaddr_in host;

        for(port=start;port<end;port++) {
            sock = socket(AF_INET,SOCK_STREAM,0);
            host.sin_family = AF_INET;
            host.sin_port = htons(port);
            host.sin_addr.s_addr = inet_addr(dst);

            conn = connect(sock, (struct sockaddr *)&host, sizeof host);

            if(conn == 0) {
                printf("Port %d - status [ABERTA]\n", port);
                close(sock);
                close(conn);
            }else {
                close(sock);
                close(conn);
            }
        }   

    }
}