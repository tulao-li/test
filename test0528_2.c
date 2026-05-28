#include <stdio.h>
#include <stdlib.h>
#define ENDKEY 0
typedef int keytype;

typedef struct node
{
    keytype key;
    struct node*lchild;
    struct node*rchild;
    int bf;//平衡因子
}AVLNode,*AVLTree;
void ins_AVLTree(AVLTree *T,keytype k)
{
    //创建新节点，把k放进去
    AVLTree newnode = (AVLTree)malloc(sizeof(AVLNode));
    if(newnode == NULL)
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newnode->key = k;
    newnode->bf = 0;
    newnode->lchild = newnode->rchild = NULL;
   //处理空树
    if(*T == NULL)
    {
        *T = newnode;
        return;
    }

    AVLTree p = *T;
    AVLTree pp = NULL;
    AVLTree A = NULL;
    AVLTree pA = NULL;
    while(p!= NULL)
    {
        if(p->bf != 0)
        {
            A = p;
            pA = pp;
        }
        pp = p;
        if(p->key < k)
        {
            p = p->rchild;
        }
        else if(p->key > k)
        {
            p = p->lchild;
        }
        else if(p->key == k)
        {
            return;
        }
    }
    //插入新节点(此时先不处理平衡因子，后续统一处理)
    if(pp->key > k)
    {
        pp->lchild = newnode;

    }
    else if(pp->key <k)
    {
        pp->rchild = newnode;

    }
    //不会出现不平衡时情况
    if(A == NULL)
    {
        p = *T;
        while(p->key != k)
        {
            if(p->key > k)
            {
                p->bf++;
                p = p->lchild;
            }
            else 
            {
                p->bf--;
                p = p->rchild;
            }
        }
        return;
    }
    //处理A的平衡因子
    AVLTree Anext;
    if(A->key > k)
    {
        A->bf++;
        Anext = A->lchild;
    }
    else
    {
        A->bf--;
        Anext = A->rchild;
    }
    //处理路径上所有平衡因子
    p = Anext;
    while(p != NULL)
    {
        if(p->key > k)
        {
            p->bf = 1;
            p = p->lchild;
        }
        else if(p->key < k)
        {
            p->bf = -1;
            p = p->rchild;
        }
        else if(p->key == k)
        {
            p->bf = 0;
            p = NULL;
        }
    }
    
    if((A->bf ==2)&&(1 == Anext->bf))
    {
        A->lchild = Anext->rchild;
        Anext->rchild = A;
        A->bf = Anext->bf = 0;
        if(pA == NULL)
        {
            *T = Anext;
            return;
        }
        else if(pA->lchild = A)
        {
            pA->lchild = Anext;
        }
        else
        {
            pA->rchild = Anext;
        }
    }
    if((A->bf == -2)&&(Anext->bf == -1))
    {
        A->rchild = Anext->lchild;
        Anext->lchild = A;
        A->bf = Anext->bf = 0;
        if(pA == NULL)
        {
            *T = Anext;
        }
        else if(pA->lchild = A)
        {
            pA->lchild = Anext;
        }
        else
        {
            pA->rchild = Anext;
        }
    }
    if((A->bf == 2)&&(Anext->bf == -1))
    {
        AVLTree C = Anext->rchild;
        A->lchild = C->rchild;
        Anext->rchild = C->lchild;
        C->lchild = Anext;
        C->rchild = A;
        if(C->key < k)
        {
            A->bf = 0;
            Anext->bf = 1;
        }
        else if(C->key > k)
        {
            Anext->bf = 0;
            A->bf = -1;
        }
        else
        {
            A->bf = Anext->bf = 0;
        }
        C->bf = 0;
        if(pA == NULL)
        {
            *T = C;
        }
        else if(pA->lchild == A)
        {
            pA->lchild = C;
        }
        else
        {
            pA->rchild = C;
        }
    }
    if((A->bf == -2)&&(Anext->bf == 1))
    {
        AVLTree C = Anext->lchild;
        A->rchild = C->lchild;
        Anext->lchild = C->rchild;
        C->lchild = A;
        C->rchild = Anext;
        if(C->key == k)
        {
            A->bf = Anext->bf = 0;
        }
        else if(C->key > k)
        {
            A->bf = 0;
            Anext->bf = -1;
        }
        else
        {
            A->bf = 1;
            Anext->bf = 0;
        }
        C->bf = 0;
        if(pA == NULL)
        {
            *T = C;
        }
        else if(pA->lchild == A)
        {
            pA->lchild = C;
        }
        else
        {
            pA->rchild = C;
        }
    }
    return;
}
void PreOrder(AVLTree T)
{
    if(T != NULL)
    {
        printf("%d  ",T->key);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void CreateAVLT(AVLTree*T)
{
    *T= NULL;
    keytype k;
    scanf("%d",&k);
    while(k!=ENDKEY )
    {
        ins_AVLTree(T, k);
        scanf("%d",&k);
    }
}
int main()
{
    AVLTree T;
    printf("Please enter the keywords of the AVL tree, ending with 0.\n");
    CreateAVLT(&T);
    printf("The result of pre_order is:\n");
    PreOrder(T);
    printf("\n");
    return 0;
}