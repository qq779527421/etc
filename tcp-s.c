#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

#define BUF_SIZE 2048
char gc_rcv_buf[BUF_SIZE] = {0};


void print_buf(char buf[], int len)
{
    int i;

    printf("*********len = %d", len);
    for(i = 0;i < len; i++)
    {
        if(!(i%16))
            printf("\n");
        printf(" %c(%02x)", buf[i], buf[i])
    }
}

int main(int argc, char **argv)
{
    int sockfd, connfd;
    struct sockaddr_in my_addr, his_addr;
    socklen_t his_addr_len;
    int sport;
    char *ip;
    int blog;
    int ret;

    if(argc != 4)
    {
        printf("Usage: %s IP PORT BAKLOG\n", argv[0]);
        return -1;
    }

    ip = argv[1];
    sport = atoi(argv[2]);
    blog = atoi(argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("socket");
        return -1;
    }

    memset(&my_addr, 0, sizeof(server_sockaddr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(sport);
    inet_pton(AF_INET, ip, &my_addr.sin_addr.s_addr);

    ret = bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr));
    if(ret < 0)
    {
        perror("bind");
        return -1;
    }

    ret = listen(sockfd, blog);
    if(ret < 0)
    {
        perror("listen");
        return -1;
    }

start_accept:
    his_addr_len = sizeof(his_addr);
    connfd = accept(sockfd, (struct sockaddr *)&his_addr, &his_addr_len);
    if(connfd < 0)
    {
        perror("accept");
        return -1;
    }
    
    
    while(1)
    {
        memset(gc_rcv_buf, 0, sizeof(gc_rcv_buf));
        getchar();
        ret = recv(connfd, gc_rcv_buf, sizeof(gc_rcv_buf)-1, 0);
        if(ret < 0)
            goto start_accept;
        print_buf(gc_rcv_buf, ret);
    }

    
    return 0;
}

