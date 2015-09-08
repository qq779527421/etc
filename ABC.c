/*************************************************************************
	> File Name: ABC.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月24日 星期五 08时43分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

    unsigned int uiA = (0xAA & 0xBB)^(0xCC | 0xDD);
    unsigned int uiB = (0xAA << 24)|(0xBB << 16)|(0xCC << 8)|0xDD;
    
    printf("A = %x\nB = %x\n", uiA, uiB);

    return 0;
}
