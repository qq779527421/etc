/*************************************************************************
	> File Name: A-K.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月20日 星期一 18时50分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node_st{
    int data;
    struct node_st *next;
};

int main()
{
    struct node_st *head, *p, *q;
    int i, j;

    head = malloc(sizeof(*p));
    head->data = 1;
    q = head;

    for(i = 2; i <= 13; i++){
        p = malloc(sizeof(*p));
        if(NULL == p)
            break;
        p->data = i;
        q->next = p;
        q = p;
    }
    p = head;
    q->next = head;
    
    printf("A-K应该放的位置为：");
    for(i = 1; i <= 13; i++){
        for(j = 1; j < 2; j++){
            p = p->next; 
        }
        printf("%d ", p->data);
        q = p->next;
        memcpy(p, q, sizeof(*q));
        free(q);
    }
    printf("\n");

    return 0;
}
