#include <stdio.h>
#include <stdlib.h>
#define Stack_Size 50
#define NUM 50

typedef struct BiTNode
{
    struct BiTNode*LChild;
    struct BiTNode*RChild;
    char data;
}BiTNode,*BiTree;

typedef struct 
{
    BiTree data[Stack_Size];
    int top;
}SeqStack;

//初始化栈
SeqStack* InitStack()
{
    SeqStack* S = (SeqStack*)malloc(sizeof(SeqStack));
    if(S == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    S->top = -1;
    return S;
}
//判断是否为空
int is_empty(SeqStack*S)
{
    return S->top == -1;
}
//入栈
int Push(SeqStack*S,BiTree p)
{
    if(S == NULL)
    {
        printf("failure\n");
        return 0;
    }
    if(S->top == Stack_Size -1 )
    {
        printf("full\n");
        return 0;
    }
    S->data[++(S->top)] = p;
    return 1;
}
//出栈
int Pop(SeqStack*S,BiTree*p)
{
    if((S == NULL)||(p == NULL))
    {
        printf("wrong\n");
        return 0;
    }
    if(is_empty(S))
    {
        printf("empty\n");
        return 0;
    }
    *p = S->data[S->top];
    S->top--;
    return 1;
}
//打印一个节点数据
void Visit(char ch)
{
    printf("%c  ",ch);
}
//中序遍历算法1
void inorder(BiTree root)
{
    int top = -1;
    BiTree p;
    BiTree s[Stack_Size];
    if(root == NULL)
    {
        return;
    }
    p = root;
    do
    {
        while(p != NULL)
        {
            top++;
            if(top >= Stack_Size)
            {
                printf("full\n");
                return;
            }
            s[top] = p;
            p = p->LChild;
        }
        if(top != -1)
        {
            p = s[top--];
            Visit(p->data);
            p = p->RChild;
        }
    }
    while((top != -1)||(p != NULL));
}
//后序遍历算法1
void postorder(BiTree root)
{
    int top = -1;
    BiTree p,q;
    BiTree s[Stack_Size];
    p = root;
    q = NULL;
    do
    {
        while( p!= NULL)
        { 
            top++;
            if(top >= Stack_Size)
            {
                printf("full\n");
                return;
            }
           
            s[top] = p;
            p = p->LChild;
        }
        if(top != -1)
        {
            p = s[top]; 
            if(p->RChild == NULL||p->RChild == q)
            {
                Visit(p->data);
                q = p;
                top--;
                p = NULL;
            }
            else
            {
                p = p->RChild;
            }
           
        }
    } while ((top != -1)||(p != NULL));
}
//前序遍历算法1
void frontorder(BiTree root)
{
    int top = -1;
    BiTree p;
    BiTree s[Stack_Size];
    p = root;
    do
    {
        while(p != NULL)
        {
            
            top++;
            if(top>=Stack_Size)
            {
                printf("full\n");
                return;
            }
            Visit(p->data);
            s[top] = p;
            p = p->LChild;
        }
        if(top != -1)
        {
            p = s[top--];
            p = p->RChild;
        }
    } while ((top != -1)||(p !=NULL));
}
//中序遍历算法2
void InOrder(BiTree root)
{
    if(root == NULL)
    {
        printf("empty\n");
        return ;
    }
    BiTree p = root;
    SeqStack*S = InitStack();
    while((!is_empty(S))||(p != NULL))
    {
        if(p!= NULL)
        {
            Push(S,p);
            p = p->LChild;
        }
        else
        {
            Pop(S,&p);
            Visit(p->data);
            p = p->RChild;
        }
    }
    free(S);
}
//后序遍历算法2
void PostOrder(BiTree root)
{
    if(root == NULL)
    {
        printf("empty\n");
        return ;
    }
    BiTree p = root;
    BiTree pp = NULL; 
    SeqStack*S = InitStack();
    while((!is_empty(S))||(p!= NULL))
    {
        if(p != NULL)
        {
            Push(S,p);
            p = p->LChild;
        }
        else
        {
           BiTree topNode = S->data[S->top];
           if((topNode->RChild == NULL)||(topNode->RChild == pp))
           {
                Pop(S,&p);
                Visit(p->data);
                pp = p;
                p = NULL;
           }
           else
           {
            p = topNode->RChild;
           }
        }
    }
    free(S);
}
//前序遍历算法2
void PreOrder(BiTree root)
{
    if(root == NULL)
    {
        printf("empty\n");
        return;
    }
    BiTree p = root;
    SeqStack*S = InitStack();
    while((!is_empty(S))||(p != NULL))
    {
        if(p != NULL)
        {
            Visit(p->data);
            Push(S,p);
            p = p->LChild;
        }
        else
        {
            Pop(S,&p);
            p = p->RChild;
        }
    }
    free(S);
}
//创建二叉树
void CreateBiTree(BiTree *bt)
{
   char ch;
  
    while ((ch = getchar()) == ' ' || ch == '\n' || ch == '\t');
    
    if (ch == '.') 
    {
        *bt = NULL;
    }
    else
    {
        *bt = (BiTree)malloc(sizeof(BiTNode));
        if(!*bt)
        {
            fprintf(stderr,"Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        (*bt)->data = ch;
        CreateBiTree(&(*bt)->LChild);
        CreateBiTree(&(*bt)->RChild);
    }
}

int main()
{
	BiTree T;
	printf("Build binary tree by extended pre-order traversal sequence, please enter the sequence:\n");
	CreateBiTree(&T);
	printf("6.11 In-order traversal output leaf nodes 1:");
	inorder(T);
	printf("\n");
	printf("6.11 In-order traversal output leaf nodes 1:");
	InOrder(T);
	printf("\n");
	printf("6.11 In-order traversal output leaf nodes 1:");
	PostOrder(T);
	printf("\n");

	return 0;
}