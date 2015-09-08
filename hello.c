/*************************************************************************
	> File Name: hello.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月04日 星期六 13时15分43秒
 ************************************************************************/

#include <stdio.h>

#define N 2
#define NTI(n) N*n+n

struct node_st{
    int c;
    char a;
    short b;
};

int main()
{
    int i;

    printf("%d\n", N*NTI(N));
    printf("hello world!\n");

    for(i =1; i < 1001; i++){
        if((i/16*16) == i)
            printf("%d ", i);
        if((i % 16) == 0)
            printf("%d ", i);
        if((i & 0x0F) == 0)
            printf("%d ", i);
        if(((i >> 4) << 4) == i)
            printf("%d \n", i);
    }

    return 0;
}
