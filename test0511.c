#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef char DataType;
typedef struct Node
{
    DataType data;
    struct Node*LChild;
    struct Node*RChild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree*bt)
{
    char ch = getchar();
    if((ch == '.')||(ch == '\n'))
    {
        *bt = NULL;
    }
    else
    {
        *bt = (BiTree)malloc(sizeof(BiTNode));
        if(*bt == NULL)
        {
            fprintf(stderr,"Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        (*bt)->data = ch;
        CreateBiTree(&((*bt)->LChild));
        CreateBiTree(&((*bt)->RChild));
    }
}
void PreOrder(BiTree T)
{
    if(T == NULL)
    {
        return;
    }
    printf("%c  ",T->data);
    PreOrder(T->LChild);
    PreOrder(T->RChild);
}
typedef BiTree QueueElementType;
typedef struct 
{
    QueueElementType element[MAXSIZE];
    int front;
    int rear;
}SeqQueue;

void InitQueue(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
}
int is_empty(SeqQueue*Q)
{
    return (Q->front == Q->rear);
}
int  EnterQueue(SeqQueue*Q,QueueElementType x)
{
    if(Q == NULL)
    {
        return 0;
    }
    if(((Q->rear)+1)%MAXSIZE == Q->front)
    {
        printf("This queue is full.\n");
        return 0;
    }
    Q->element[Q->rear] = x;
    Q->rear = ((Q->rear)+1)%MAXSIZE;
    return 1;
}
int DeleteQueue(SeqQueue*Q,QueueElementType*x)
{
    if((Q == NULL)||(x == NULL))
    {
        return 0;
    }
    if(is_empty(Q))
    {
        return 0;
    }
    *x = Q->element[Q->front];
    (Q->front) = (Q->front +1)%MAXSIZE;
    return 1;
}
int LayerOrder(BiTree bt)
{
    if(bt == NULL)
    {
        return 0;
    }
    SeqQueue*S = (SeqQueue*)malloc(sizeof(SeqQueue));
    if(S == NULL)
    {
        return 0;
    }
    InitQueue(S);
    EnterQueue(S,bt);
    printf("The result is:");
    while(!is_empty(S))
    {
        BiTree p;
        DeleteQueue(S,&p);
        printf("%c  ",p->data);
        if(p->LChild != NULL)
        {
            EnterQueue(S,p->LChild);
        }
        if(p->RChild != NULL)
        {
            EnterQueue(S,p->RChild);
        }
    }
    printf("\n");
    free(S);
    return 1;
}

int main()
{
    BiTree T;
    printf("Please enter the binary tree:");
    CreateBiTree(&T);
    PreOrder(T);
    printf("\n");
    LayerOrder(T);
    return 0;
}