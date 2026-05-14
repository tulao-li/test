#include <stdio.h>
#include <stdlib.h>
typedef char DataType;

typedef struct Node
{
    DataType data;
    int Ltag;//0 = 左孩子；1 = 中序前驱
    int Rtag;//0 = 有孩子；1 = 中序后继
    struct Node*LChild;
    struct Node*RChild;
}BiTNode,*BiTree;
BiTree pre = NULL;
void CreateBiTree(BiTree *bt)
{
    char ch = getchar();
    if(ch == '.' || ch == '\n')
    {
        *bt = NULL;
    }
    else
    {
        *bt = (BiTree)malloc(sizeof(BiTNode));
        if(*bt == NULL)
        {
            return ;
        }
        (*bt)->data = ch;
        (*bt)->Ltag = 0;
        (*bt)->Rtag = 0;
        CreateBiTree(&((*bt)->LChild));
        CreateBiTree(&((*bt)->RChild));
    }
}
void InThread(BiTree root)
{
    if(root == NULL)
    {
        return;
    }
    InThread(root->LChild);
    if(root->LChild == NULL)
    {
        root->Ltag = 1;
        root->LChild = pre;
    }
    if(pre!= NULL &&pre->RChild == NULL)
    {
        pre->Rtag = 1;
        pre->RChild = root;
    }
    pre = root;
    InThread(root->RChild);
}
//中序遍历第一个节点
void my_TinFirst(BiTree root,BiTree*p)
{
    if(root == NULL)
    {
        *p = NULL;
        return;
    }
    if(root->Ltag ==1  &&root->LChild == NULL)
    {
       *p = root;
       return;
    }
    my_TinFirst(root->LChild,p);
}
BiTree TinFirst(BiTree root)
{
    while(root != NULL && root->Ltag == 0)
    {
        root = root->LChild;
    }
    return root;
}