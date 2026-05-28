#include <stdio.h>
#include <stdlib.h>

typedef int keytype;
typedef struct node
{
    keytype key;
    struct node*lchild;
    struct node*rchild;
}BSTNode,*BSTree;
void InOrder(BSTree T)
{
    if(T == NULL)
    {
        return;
    }
    
    InOrder(T->lchild);
    printf("%d  ",T->key);
    InOrder(T->rchild);
}
BSTree DelBST(BSTree T,keytype k)
{
    if(T == NULL)
    {
        return NULL;
    }
    BSTree p = T;
    BSTree f = NULL;
    while(p != NULL)
    {
        if(p->key == k)
        {
            break;
        }
        f = p;
        if(p->key > k)
        {
            p = p->lchild;
        }
        else if(p->key < k)
        {
            p = p->rchild;
        }
    }
    if(p == NULL)
    {
        return T;
    }
    if(p->lchild == NULL)
    {
        if(f == NULL)
        {
            T = p->rchild;
        }
        else
        {
            if(f->lchild == p)
            {
                f->lchild = p->rchild;
            }
            else if(f->rchild == p)
            {
                f->rchild = p->rchild;
            }
        }
        free(p);
    }
    else if(p->rchild == NULL)
    {
        if(f == NULL)
        {
            T = p->lchild;
        }
        else
        {
            if(f->lchild == p)
            {
                f->lchild = p->lchild;
            }
            else if(f->rchild == p)
            {
                f->rchild = p->lchild;
            }
        }
        free(p);
    }
    else
    {
        BSTree s = p->lchild;
        BSTree q = p;
        while(s->rchild != NULL)//得到左子树里面的最大值(q 为其父节点)
        {
            q = s;
            s = s->rchild;
        }
        if(q == p)
        {
            p->key = s->key;
            q->lchild = s->lchild;
            free(s);
        }
        else
        {
            p->key = s->key;
            q->rchild = s->lchild;
            free(s);
        }
       
    }
    return T;
}
int main()
{
    BSTree root = (BSTree)malloc(sizeof(BSTNode));
    root->key = 50;
    root->lchild =(BSTree)malloc(sizeof(BSTNode));
    root->rchild = (BSTree)malloc(sizeof(BSTNode));

    root->lchild->key = 30;
    root->lchild->lchild = (BSTree)malloc(sizeof(BSTNode));
    root->lchild->rchild = (BSTree)malloc(sizeof(BSTNode));
    root->lchild->lchild->key = 20;
    root->lchild->lchild->lchild = root->lchild->lchild->rchild = NULL;
    root->lchild->rchild->key = 40;
    root->lchild->rchild->lchild = root->lchild->rchild->rchild = NULL;

    root->rchild->key = 70;
    root->rchild->lchild = (BSTree)malloc(sizeof(BSTNode));
    root->rchild->rchild = (BSTree)malloc(sizeof(BSTNode));
    root->rchild->lchild->key = 60;
    root->rchild->lchild->lchild = root->rchild->lchild->rchild = NULL;
    root->rchild->rchild->key = 80;
    root->rchild->rchild->lchild = root->rchild->rchild->rchild = NULL;

    printf("In-order traversal of the original binary sort tree.\n");
    InOrder(root);
    printf("\n");

    int delkey;
    printf("Please enter the key to delete.\n");
    scanf(" %d",&delkey);
    root = DelBST(root,delkey);

    printf("In-order traversal of the binary sort tree after removing the tree.\n");
    InOrder(root);
    printf("\n");
    return 0;
}