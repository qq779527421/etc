/*************************************************************************
	> File Name: print.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月20日 星期一 17时58分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print(const char *a, const char *b, const char *c)
{
    int i, j, k;
    
    while(1){
        if(('0' == a[i]) && ('0' == b[j]) & ('0' == c[k]))
            break;
        if((' ' == a[i]) && (' ' == b[j]) & (' ' == c[k])){
            i++; 
            j++; 
            k++;
        }
        if(' ' != a[i])
            i++;
        if(' ' != a[i])
            i++;
        if(' ' != a[i])
            i++;
    }
}

int mian()
{
    char s1[] = "abcd cd eeeeeeeeeeee";
    char s2[] = "ad cdefgh cccc";
    char s3[] = "a c cde";

    print(s1, s2, s3);

    return 0;
}
