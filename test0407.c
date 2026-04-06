#include <stdio.h>
#include <stdlib.h>
#define ElemType int
#define MAXROW 10
#define MAXCOL 10
typedef struct OLNode
{
    int row;
    int col;
    ElemType e;
    struct OLNode*down;
    struct OLNode*right;
}OLNode,*OLink;//十字链表的每个节点
typedef struct
{
    OLink *row_head;//数组指针
    OLink *col_head;
    int m;
    int n;
    int len;
}CrossList;//十字链表整体结构
//初始化
CrossList* InitCrossList()
{
    CrossList *M = (CrossList*)malloc(sizeof(CrossList));
    if(M == NULL)
    {
        return NULL;
    }
    M->m = MAXROW;
    M->n = MAXCOL;
    M->len = 0;
    M->row_head = (OLink*)malloc(sizeof(OLink)*MAXROW);
    M->col_head = (OLink*)malloc(sizeof(OLink)*MAXCOL);
    if((M->col_head == NULL)||(M->row_head == NULL))
    {
        free(M);
        return NULL;
    }
    for(int i = 0;i<M->m;i++)
    {
        *(M->row_head + i) = NULL;
    }
    for(int j = 0;j<M->n;j++)
    {
        *(M->col_head + j) = NULL;
    }
    return M;
}
//插入元素
int InsertCrossList(CrossList *M,int m,int n,ElemType e)
{
    if((M == NULL)||(m<0)||(n<0)||(m>M->m)||(n>M->n))
    {
        printf("参数有误\n");
        return 0;
    }
    if(M->len == MAXROW*MAXCOL)
    {
        printf("链表已满\n");
        return 0;
    }
    //创建新节点
    OLink newnode  = (OLink)malloc(sizeof(OLNode));
    if(newnode == NULL )
    {
        return 0;
    }
    newnode->e = e;
    newnode->row = m;
    newnode->col = n;
    newnode->right = NULL;
    newnode->down = NULL;
    //插行
    OLink row = M->row_head[m];
    //插在表头
    if((row == NULL)||(row->col > n))
    {
        M->row_head[m] = newnode;
        newnode->right = row;
    }
    //插中间
    else
    {
        while((row->right != NULL)&&(row->right->col <n))
        {
            row = row->right;
        }
        newnode->right = row->right;
        row->right = newnode;
    }
    //插列
    OLink col = M->col_head[n];
    if((col == NULL)||(col->row > m))
    {
        M->col_head[n] = newnode;
        newnode->down = col;
        
    }
    else
    {
        while((col->down != NULL)&&(col->down->row < m))
        {
            col = col->down;
        }
        newnode->down = col->down;
        col->down = newnode;
        
    }
    M->len++;
    return 1;

}
//打印矩阵
void PrintCrossList(const CrossList M)
{
    printf("矩阵大小： %d行*%d列,非零元素个数：%d\n",M.m,M.n,M.len);
    for(int i = 0;i<M.m;i++)
    {
        OLink p = M.row_head[i];
        for(int j = 0;j<M.n;j++)
        {
            if((p!= NULL)&&(p->col == j))
            {
                printf("%-4d",p->e);
                p = p->right;
            }
            else
            {
                printf("%-4d",0);
            }
        }
        printf("\n");
    }
    return ;
}
//销毁
void DestroyCrossList(CrossList *M)
{
    if(M == NULL)
    {
        return ;
    }
    for(int i = 0;i<M->m;i++)
    {
        OLink p = M->row_head[i];
        while(p!= NULL)
        {
            OLink des = p;
            p = p->right;
            free(des);
        }
    }
    free(M->row_head);
    free(M->col_head);
    free(M);
    return ;
}

int main()
{
    CrossList*M = InitCrossList();
    if(M == NULL)
    {
        printf("初始化失败");
        return 1;
    }
    InsertCrossList(M,0,1,3);
    InsertCrossList(M,1,0,5);
    InsertCrossList(M,1,2,7);
    InsertCrossList(M,2,2,9);
    PrintCrossList(*M);
    DestroyCrossList(M);
    return 0;

}