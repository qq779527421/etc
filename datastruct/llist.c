/*************************************************************************
    > File Name: llist-abc-cba.c
    > Author: Mr.qiao
    > Mail: qiao_fw@163.com
    > Created Time: 2015年07月20日 星期一 14时23分27秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIR_FRONT	1
#define DIR_BACK	2


typedef char datatype;

struct node_st{
	datatype data;
	struct node_st *pre;
	struct node_st *next;
};

int llist_creat(struct node_st **list)
{
	struct node_st *new;

	new = malloc(sizeof(*new));
	if(NULL == new)
		return -1;

	new->next = new;
	new->pre = new;
	*list = new;

	return 0;
}

void llist_destroy(struct node_st *list)
{
	struct node_st *cur;

	for(cur = list->next; cur != list; cur = list->next){
		list->next = cur->next;
		list->next->pre = list;
		free(cur);
	}
	free(list);
}

int llist_insert(struct node_st *list, const void *data, int dir)
{
	struct node_st *new;

	new = malloc(sizeof(*new));
	if(NULL == new)
		return -1;
	memcpy(&new->data, data, sizeof(new->data));
	if(dir == DIR_FRONT){
		new->pre = list;
		new->next = list->next;
	}else{
		new->pre = list->pre;
		new->next = list;
	}
	new->pre->next = new;
	new->next->pre = new;

	return 0;
}

void llist_travel(struct node_st *list, void *arg)
{
    struct node_st *cur;

    for (cur = list->next; cur != list; cur = cur->next) {
        printf("%c ", cur->data);
    }
    printf("\n");
}

void llist_roll(struct node_st *list)
{
    struct node_st *p, *q, *r;

    for(p = list->next; p != list; p = q){
        q = p->next;
        
        r = p->pre;
        p->pre = p->next;
        p->next = r;
    }
    r = p->pre;
    p->pre = p->next;
    p->next = r;
}



int main(int argc, char *argv[])
{
    int i;
    struct node_st *list;

    if(argc != 2 )
    {
        printf("Usage: %s STRING\n", argv[0]);
        return -1;
    }
    
    if(-1 == llist_creat(&list))
        return -1;
    
    for(i = 0; i < strlen(argv[1]); i++){
        llist_insert(list, &argv[1][i], DIR_FRONT);
    }

    llist_travel(list, NULL);
    llist_roll(list);
    llist_travel(list, NULL);
    llist_destroy(list);

    return 0;
}
