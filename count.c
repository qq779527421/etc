

/*************************************************************************
	> File Name: count.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月21日 星期二 17时12分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 128

int main(int argc, char **argv)
{
    FILE *fp;
    int num = 1;
    char *ret;
    char buf[BUFSIZE];

    if(2 != argc){
        printf("Usage: ./a.out filename\n");
        return -1;
    }

    fp = fopen(argv[1], "r");
    if(NULL == fp)
        return -1;

    while(1){
        ret = fgets(buf, BUFSIZE, fp);
        if(NULL == ret)
            break;
        if('\n' == buf[0]){
            printf("%s", buf);
            continue;
        }
        printf("%03d %s", num++, buf);
    }

    return 0;
}
