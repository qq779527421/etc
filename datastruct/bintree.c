#include <stdio.h>
#include <stdlib.h>

//eLink(0):表示指向左右孩子的指针
//eThread(1):指向前驱后继的线索
typedef enum{eLink, eThread} PointerTag;

typedef struct BinThrNode
{
    char data;
    struct BinThrNode *lchild, *rchild;
    PointerTag ltag, rtag;
} BinThrNode, *BinThrTree;

BinThrNode *pre;


//前序创建T
void creatBinTree(BinThrTree *T)
{
    char c;

    scanf("%c", &c);
    if('#' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BinThrNode *)malloc(sizeof(BinThrNode));
        (*T)->data = c;
        (*T)->ltag = eLink;
        (*T)->ltag = eLink;

        creatBinTree(&(*T)->lchild);        
        creatBinTree(&(*T)->rchild);
    }

}

//中序线索化
void inThreading(BinThrTree T)
{
    if(T)
    {
        inThreading(T->lchild);

        if(NULL == T->lchild)
        {
            T->ltag = eThread;
            T->lchild = pre;
        }
        if(NULL == pre->rchild)
        {
            pre->rtag = eThread;
            pre->rchild = T;
        }

        pre = T;
        
        inThreading(T->rchild);
    }

    
}


void inOrderThreading(BinThrTree *p, BinThrTree T)
{
    *p = (BinThrTree)malloc(sizeof(BinThrNode));
    (*p)->ltag = eLink;
    (*p)->rtag = eThread;
    (*p)->rchild = *p;
    if(NULL == T)
    {
        (*p)->lchild = *p;
    }
    else
    {
        (*p)->lchild = T;
        pre = *p;
        inThreading(T);
        pre->rchild = *p;
        pre->rtag = eThread;
        (*p)->rchild = pre;
    }
}

void visit( char c)
{
    printf("%c", c);
}

//中序遍历二叉树
void inorderTraverse(BinThrTree T)
{
    BinThrTree p;
    p = T->lchild;

    while(p != T)
    {
        while( p->ltag == eLink)
        {
            p=p->lchild;
        }
        visit(p->data);

        while(p->ltag == eThread && p->rchild != T)
        {
            p = p->rchild;
            visit(p->data);
        }

        p = p->rchild;
    }
}


int main()
{
    BinThrTree P, T;
    
    creatBinTree(&T);

    inOrderThreading( &P, T);

    printf("中序遍历线索二叉树：\n");

    inorderTraverse(P);
    
    printf("\n");

    return 0;
}


