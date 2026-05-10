#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct TreeNode
{
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
    int Ltag;
    int Rtag;
}TreeNode,*Bitree;
char str[] = "ABDH#K###E##CFI###G#J#Kl###";
int idx = 0;

Bitree CreatBitree()
{
    Bitree T = (Bitree)malloc(sizeof(TreeNode));
    if(T == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    char p = str[idx];
    idx++;
    if(p == '#')
    {
        return NULL;
    }
    T->data = p;
    T->lchild = CreatBitree();
    T->rchild = CreatBitree();
    return T;

}
void preOrder(Bitree T)//前序遍历（递归
{
    if(T == NULL)
    {
        return ;
    }
    printf("%c  ",T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
    return;
}

void midOrder(Bitree T)//中序遍历（递归
{
    if(T == NULL)
    {
        return ;
    }
    midOrder(T->lchild);
    printf("%c  ",T->data);
    midOrder(T->rchild);
    return;
}

void behindOrder(Bitree T)//后序遍历（递归
{
    if(T == NULL)
    {
        return ;
    }
    behindOrder(T->lchild);
    behindOrder(T->rchild);
    printf("%c  ",T->data);
    return ;
}

void leaforder(Bitree T)// 输出叶子节点
{
    if(T != NULL)
    {
        if((T->lchild == NULL)&&(T->rchild == NULL ))
        {
            printf("%c  ",T->data);
        }
        leaforder(T->lchild);
        leaforder(T->rchild);
    }
}

int leaf(Bitree T)//输出二叉树里叶节点数目
{
    if(T == NULL)
    {
        return 0;
    }
    int leafcount = 0;
    if((T->lchild == NULL)&&(T->rchild == NULL))
    {
        return 1;
    }
    else
    {
        return leaf(T->lchild) + leaf(T->rchild); 
    }
}

int heightorder(Bitree T)//计算高度
{
    if(T == NULL)
    {
        return 0;
    }
    if((T->lchild == NULL)&&(T->rchild == NULL))
    {
        return 1;
    }
    else
    {
        if(heightorder(T->lchild) >=heightorder(T->rchild))
        {
            return 1+heightorder(T->lchild);
        }
        else
        {
            return 1+heightorder(T->rchild);
        }
    }
}

int PostTreeDepth(Bitree T)//后序遍历求深度
{
    int hl,hr,max = 0;
    if(T != NULL)
    {
        hl = PostTreeDepth(T->lchild);
        hr = PostTreeDepth(T->rchild);
        max = hl>hr?hl:hr;
        return 1+max;
    }
    return 0;
}

//前序遍历求高度（会有全局变量
/*int depth = 0;
void PreTreeDepth(Bitree T,int h)
{
    if(T != NULL)
    {
        if(h>depth)
        {
            depth = h;
            PreTreeDepth(T->lchild,h+1);
            PreTreeDepth(T->rchild,h+1);
        }
        return;
    }
    return;
}*/

int main()
{
    Bitree T = CreatBitree();
    behindOrder(T);
    printf("\n");
    leaforder(T);
    printf("\n");
    printf("%d\n",leaf(T));
    printf("%d\n",heightorder(T));
    return 0;
}