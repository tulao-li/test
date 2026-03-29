/* #include <stdio.h>
int add(int n)
{
   if(n>=100)
   {
    return 100;
   }

   return n+add(n+1);
}
int fun(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return fun(n-1) +n;
    }
}
int fib(int n)
{
    if(n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 1;
    }
    return fib(n-1) +fib(n-2);
}
int main()
{
    int total = 0;
    total = add(total);
    printf("%d\n",total);
    int n = fun(100);
    printf("%d\n",n);
    int r = fib(9);
    printf("%d\n",r);
    return 0;
}*/
/*#include <stdio.h>
#include <stdbool.h>
typedef enum weekday
{
    mon = 1,tue,wed,thu,fri,sat,sun
}weekday;

int main()
{
   weekday a;
    a = mon;
    weekday b;
    b = tue;
    printf("%d\n",a);
    printf("%d\n",b);
    bool flag = false;
    printf("%d\n",flag);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
//定义运算符号
typedef enum
{
    LEFT_PARE/*左括号*/ = 0,RIGHT_PARE/*右括号*/,
    ADD,SUB/*减*/,MUL,DIV,MOD/*取余*/,
    EOS/*结束符*/,NUM
}contentType;

char expr[] = "56+7*";

typedef struct
{
    ElemType *data;
    int top;
}stack;

//初始化
stack* InitStack()
{
    stack*s = (stack*)malloc(sizeof(stack));
    s->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = -1;
}

//出栈
int pop(stack*s,ElemType *x)
{
    if(s->top == -1)
    {
        printf("The stack is empty\n");
        return 0;
    }
    *x = s->data[s->top];
    s->top = (s->top)-1;
    return 1;
}

//入栈
int push(stack*s,ElemType n)
{
    if(s->top+1 == MAXSIZE)
    {
        printf("The stack is full\n");
        return 0;
    }
    s->top = (s->top)+1;
    *((s->data)+(s->top)) = n;
    return 1;
}

//计算后缀表达式
int eval(stack*s)
{
    int i = 0;
    while(expr[i] != '\0')
    {
        if((expr[i]>='0')&&(expr[i]<='9'))
        {
            int n = expr[i] - '0';
            push(s,n);
        }
        else
        {
            int x = 0;
            int y = 0;
            int total = 0;
            if((pop(s,&y))&&(pop(s,&x)))
            {
                switch(expr[i])
                {
                    case '+':
                    total = x+y;
                    break;
                    case '-':
                    total = x-y;
                    break;
                    case '*':
                    total = x*y;
                    break;
                    case '/':
                    total = x/y;
                    break;
                }
                push(s,total);
            }
        }
        i++;
    }
    int total = 0;
    if(pop(s,&total))
    {
        return total;
    }
    return -1;
}

int main()
{
    stack*s =InitStack();
    printf("%d\n",eval(s));
    return 0;
}
