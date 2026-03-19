/*#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct stack
{
    ElemType data;
    struct stack* next;
}Stack;
//初始化
Stack* Intistack()
{
    Stack*s = (Stack*)malloc(sizeof(Stack));
    if(s == NULL)
    {
        printf("初始化失败\n");
        return NULL;
    }
    s->next = NULL;
    s->data = 0;
    return s;
}
//判断栈是否为空
int is_empty(Stack*s)
{
    if(s->next == NULL)
    {
        return 0;//栈为空
    }
    return 1;//栈非空
}
//压栈
int push(Stack*s,ElemType e)
{
    Stack*new_s = (Stack*)malloc(sizeof(Stack));
    if(new_s == NULL)
    {
        printf("压栈失败\n");
        return 0;
    }
    new_s->next = s->next;
    s->next = new_s;
    new_s->data = e;
    return 1;
}
//出栈
int pop(Stack*s,ElemType*e)
{
    if(s->next == NULL)
    {
        printf("栈为空\n");
        return 0;
    }
    else
    {
        Stack*del = s->next;
        *e = del->data;
        s->next = del->next;
        free(del);
        del = NULL;
    }
    return 1;
}
//获取栈顶元素
int gettop(Stack*s,ElemType*e)
{
    if(s->next == NULL)
    {
        printf("栈为空\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
}
int main()
{
    Stack*s = Intistack();
    if(s == NULL)
    {
        printf("初始化失败，程序退出\n");
        return 0;
    }
    if(is_empty(s) == 0)
    {
        printf("栈为空\n");
    }
    for(int i = 0;i<8;i++)
    {
        push(s,i+1);
    }
    for(int j = 0;j<5;j++)
    {
        ElemType n;
        if(pop(s,&n))
        {
            printf("%d  ",n);
        }
    }
    ElemType top  = 0;
    gettop(s,&top);
    printf("栈顶元素为%d\n",top);
    return 0;
}*/
//队列
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct 
{
    ElemType data[MAXSIZE];
    int front ;
    int rear;
}Queue;

//初始化
Queue* Initqueue()
{
    Queue*q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL)
    {
        printf("初始化失败\n");
        return NULL;
    }
    memset(q->data , 0,sizeof(q->data));
    q->front = 0;
    q->rear = 0;
    return q;
}

//判断队列是否为空
int is_empty(Queue*q)
{
    if(q == NULL)
    {
        printf("队列指针无效\n");
        return 0;
    }
    if(q->front == q->rear)
    {
        return 1;//队列空
    }
    return 0;//队列非空
}

//出队
int dequeue(Queue*q,ElemType*e)
{
    if(q == NULL)
    {
        printf("队列指针无效\n");
        return 0;
    }
    if(q->rear == q->front)
    {
        printf("队为空\n");
        return 0;//出队失败
    }
    *e = q->data[q->front];
    (q->front) = (q->front +1)%MAXSIZE;
    return 1;
}

//入队
int equeue(Queue*q,ElemType e)
{
    if(q == NULL)
    {
        printf("队列指针无效\n");
        return 0;
    }
    if((q->rear+1)&MAXSIZE == q->front) 
    {
        if(q->rear -q->front == MAXSIZE)
        {
            return 0;
        }
            for(int i = 0;i<(q->rear)-(q->front);i++)
            {
                q->data[i] = q->data[i+(q->front)];
            }
            q->rear = (q->rear+1)&MAXSIZE;
            q->front = 0;
    }
    q->data[q->rear] = e;
    (q->rear)++;
    return 1;
}

int main()
{
    Queue*q = Initqueue();
    if(is_empty(q))
    {
        printf("队列为空\n");
    }
    for(int i = 0;i<13;i++)
    {
        equeue(q,i+1);
    }
    ElemType n = 0;
    for(int j = 0;j<7;j++)
    {
        if(dequeue(q,&n))
        {
            printf("%d  ",n);
        }
    }
    return 0;


}


