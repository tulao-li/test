#include <stdio.h>
#define ElemType int
//三元组表的类型定义
#define MAXSIZE 1000//非零元素最多个数
typedef struct
{
    int row;//行
    int col;//列
    ElemType e;
}Triple;
typedef struct 
{
    Triple data[MAXSIZE];
    int m;//矩阵行数
    int n;//矩阵列数
    int len;//非零元素个数
}TSMatrix;
//矩阵转置
void TransMatrix(TSMatrix *source,TSMatrix* dest)
{
    if((source == NULL)||(dest == NULL))
    {
        printf("矩阵指针为空\n");
        return ;
    }
    if(source->len == 0)
    {
        printf("矩阵为空\n");
        dest->m = source->n;
        dest->n = source->m;
        dest->len = 0;
        return;
    }
    dest->n = source->m;
    dest->m = source->n;
    dest->len = source->len;
    int k = 0;//转置矩阵的三元组下标
    for(int col = 0;col<source->n;col++)
    {
        for(int i = 0;i<source->len;i++)
        {
            if(source->data[i].col == col)
            {
                dest->data[k].row = source->data[i].col;
                dest->data[k].col = source->data[i].row;
                dest->data[k].e = source->data[i].e;
                k++;
            }
        }
    }
    return ;
}
//快速转置
void FastTransMatrix(TSMatrix *source,TSMatrix* dest)
{
    if((source == NULL)||(dest == NULL))
    {
        printf("指针为空\n");
        return ;
    }
    if(source->len == 0)
    {
        printf("矩阵为空\n");
        dest->m = source->n;
        dest->n = source->m;
        dest->len = 0;
        return ;
    }
    dest->m = source->n;
    dest->n = source->m;
    dest->len = source->len;
    int num[MAXSIZE] = {0};//num[col],原矩阵第col列的非零元素个数
    int copt[MAXSIZE] = {0};//copt[col]，原矩阵第col列第一个非零元素在新矩阵中的位置下标
    for(int i = 0;i<source->len;i++)
    {
        num[source->data[i].col]++;
    }//制作num数组
    copt[0] = 0;
    for(int i = 1;i<+source->n;i++)
    {
        copt[i] = copt[i-1] + num[i-1];
    }//制作copt 数组
    for(int i = 0;i<source->len;i++)
    {
        int col = source->data[i].col;
        dest->data[copt[col]].col = source->data[i].row;
        dest->data[copt[col]].row = source->data[i].col;
        dest->data[copt[col]].e = source->data[i].e;
        copt[col]++;
    }
    return ;
}