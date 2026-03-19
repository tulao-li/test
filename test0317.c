#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE  100
typedef int ElemType;
typedef struct stack{
    ElemType *data;
    int top;
}Stack;
//初始化
Stack* InitStack()
{
    Stack*s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = -1;
    return s;
}
//判断是否为空栈
int isempty(Stack* s)
{
    if(s->top <= -1)
    {
        return 0;//是空栈
    }
    else
    {
        return 1;//不是空栈
    }
}
//判断栈是否满了
int isfull(Stack*s)
{
    if(s->top >= MAXSIZE-1)
    {
        return 1;//栈满
    }
    else
    {
        return 0;//栈非满
    }
}
//压栈
int push(Stack*s,ElemType e)
{
    if(isfull(s))
    {
        printf("栈已满\n");
        return 0;//压栈失败
    }
    (s->top)++;
    s->data[s->top] = e;
    return 1;//压栈成功
}
//出栈
int pop(Stack*s,ElemType *e)
{
    if(isempty(s) == 0)
    {
        printf("栈为空\n");
        return 0;//出栈失败
    }
    *e = s->data[s->top];
    (s->top)--;
    return 1;//出栈成功
}
//获取栈顶元素
int getTop(Stack*s,ElemType *e)
{
    if(isempty(s) == 0)
    {
        printf("栈是空的\n");
        return 0;//获取失败
    }
    *e = s->data[s->top];
    return 1;//获取成功
}
int main()
{
    Stack*s = InitStack();
    if(isempty(s) == 0)
    {
        printf("是空栈\n");
    }
    if(isfull(s))
    {
        printf("栈已满\n");
    }
    for(int i = 0;i<10;i++)
    {
        push(s,i+1);
    }
    int len = s->top+1;
    for(int i = 0;i<len;i++)
    {
        ElemType n = 0;
        if(getTop(s,&n))
        {
            printf("%d  ",n);
            pop(s,&n);
        }
    }
    return 0;
}