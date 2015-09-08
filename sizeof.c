/*************************************************************************
	> File Name: sizeof.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月24日 星期五 09时06分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void func(char abc[10])
{
    char arr[10];

}
int main()
{
    unsigned int uiA = 100;
    char *p = "hello";
    printf("%d \n", sizeof(p));
    char arr[10] = "hello";
    char *p2;
    p2 = arr;
    printf("%d \n", sizeof(p2));
    char *p3 = malloc(10);
    printf("%d \n", sizeof(p3));
    func(arr);
    printf("%s\r\n", uiA);

    return 0;
}

