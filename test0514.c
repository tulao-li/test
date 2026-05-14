#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct BiTree
{
    DataType data;
    int Ltag;
    int Rtag;
    struct BiTree* LChild;//0 = 左孩子;1 = 线索
    struct BiTree* RChild;
}BiTNode,*BiTree;
BiTree pre = NULL;//全局变量
void CreateBiTree(BiTree*root)
{

    char ch = getchar();
    if((ch == '.')||(ch == '\n'))
    {
        *root = NULL;
    }
    else
    {
        *root = (BiTree)malloc(sizeof(BiTNode));
        if(*root == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
        (*root)->data = ch;
        (*root)->Ltag  = (*root)->Rtag = 0;
        CreateBiTree(&(*root)->LChild);
        CreateBiTree(&(*root)->RChild);
    }
}
void Threading(BiTree root)
{
    if(root != NULL)
    {
        Threading(root->LChild);
        if(root->LChild == NULL )
        {
            root->Ltag = 1;
            root->LChild = pre;
        }
        if(pre != NULL && pre->RChild == NULL)
        {
            pre->Rtag = 1;
            pre->RChild = root;
        }
        pre = root;
        Threading(root->RChild);
    }
}
BiTree TinFirst(BiTree root)//找到中序遍历里面最开头节点
{
    while((root != NULL)&&(root->Ltag == 0))
    {
        root = root->LChild;
    }
    return root;
}
BiTree InNext(BiTree root)//寻找后继节点
{
    if(root->Rtag == 1)
    {
        return root->RChild;
    }
    while((root != NULL)&&(root->Rtag == 0))
    {
        root = root->RChild;
    }
    return root;
}
BiTree Inpre(BiTree root)
{
    if(root->Ltag == 1)
    {
        return root->LChild;
    }
    while((root != NULL)&&(root->Ltag == 0))
    {
        root = root->LChild;
    }
    return root;
}
void TinOrder(BiTree root)
{
    BiTNode *p = TinFirst(root);
    while(p != NULL)
    {
        printf("%c  ",p->data);
        p = InNext(p);
    }
}
void InsNode(BiTree p,BiTree r)
{
    if((p == NULL)||(r == NULL))
    {
        return;
    }
    if(p->Rtag == 1)
    {
        r->RChild = p->RChild;
        r->Rtag = 1;
        p->RChild = r;
        p->Rtag = 0;
        r->LChild = p;
        r->Ltag = 1;
        return ;
    }
    if(p->Rtag == 0)
    {
        BiTree s = p->RChild;
        while((s != NULL)&&(s->Ltag == 0))
        {
            s = s->LChild;
        }
        r->RChild = p->RChild;
        r->Rtag = 0;
        r->LChild = p;
        r->Ltag = 1;
        p->RChild = r;
        s->LChild = r;
        s->Ltag = 1;
    }

}
int main()
{
    BiTree T;
    printf("Enter the preorder sequence of the binary tree:\n");
    CreateBiTree(&T);
    Threading(T);
    BiTree p = T->LChild->RChild;
    BiTree q;
    q = Inpre(p);
    printf("6.15 The successor of node %c is: %c\n",p->data, q ? q->data : '#');
    // 6.16: Find first node in in-order traversal
    q = TinFirst(T);
    printf("6.16 The first node in in-order traversal is: %c\n", q->data);

    // 6.17: In-order traversal of threaded binary tree
    printf("6.17 In-order traversal result:\n");
    TinOrder(T);

    return 0;
}