/*#include <stdio.h>
#include <stdlib.h>*/
/*void fun(int**p)
{
    *p = (int*)malloc(sizeof(int));
    **p = 100;
}

int main()
{
    int*p = NULL;
    fun(&p);
    printf("%d",*p);
    return 0;
}*/
/*typedef struct Complex
{
    float Realpart;
    float Imagepart;
}Complex;

void create(Complex *c,float x,float y)
{
    if(y>=10.0)
    {
        printf("Imagepart should be less\n");
    }
    c->Realpart = x;
    c->Imagepart = y;
};
int main()
{
    Complex *p = (Complex*)malloc(sizeof(Complex));
    float x = 10;
    float y = 9;
    create(p,x,y);
    printf("%f+%fi\n",p->Realpart,p->Imagepart);
    return 0;

}*/
#include <stdio.h>
#include <string.h>
#define MAXSIZE 15
typedef int ElemType;

typedef struct 
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;
//打印
void PriList(SeqList*p)
{
    for(int i = 0;i<p->length;i++)
        {
            printf("%d  ",p->data[i]);
        }
        printf("\n");
        printf("当前长度占用：%d\n",p->length);
}
//初始化
void initList(SeqList*p)
{
    for(int i = 0;i<MAXSIZE;i++)
    {
        p->data[i] = 0;
    }
    p->length = 0;
}
//从末端增加
int addendElem(SeqList*p,ElemType a)
{
    if(p->length == MAXSIZE)
    {
        printf("顺序表已满\n");
        return 0;
    }
    else
    {
        p->data[p->length] = a;
        (p->length)++;
    }
    return 1;
}
//任意位置插入
int insertElem(SeqList*p,int pos,ElemType e)
{
    if(p->length == MAXSIZE)
    {
        printf("表已满\n");
        return 0;
    }
    if(pos<=0||pos>p->length)
    {
        printf("插入位置错误\n");
        return 0;
    }
    else
    {
        /*ElemType new = e;
        p->length++;
        for(int i = 0;i<p->length;i++)
        {
            if(i>=pos-1)
            {
                ElemType ori = p->data[i];
                p->data[i] = new;
                new = ori;
            }
        }*/
       for(int i =p->length-1;i>=pos-1;i--)
       {
        p->data[i+1]= p->data[i];
       }
       p->data[pos-1] = e;
       (p->length)++;
    }
    return 1;
}
//删除
int DelList(SeqList*p,int pos)
{
    if(pos<1||pos>p->length)
    {
        printf("删除位置有误\n");
        return 0;
    }
    if(p->length == 0)
    {
        printf("表为空\n");
        return 0;
    }
    else
    {
        for(int i = pos-1;i<p->length-1;i++)
        {
            p->data[i] = p->data[i+1];
        }
        (p->length)--;
        return 1;
    }
}
//查找
int findElem(SeqList*p,ElemType e)
{
    int pos = 0;
    if(p->length == 0)
    {
        printf("表为空\n");
        return 0;
    }
    int i = 0;
    for(i = 0;i<(p->length);i++)
    {
        if(p->data[i] == e)
        {
            pos = i+1;
            return pos;
            break;
        }
    }
    if(i == p->length)
    {
        printf("表中没有此数据\n");
        return 0;
    }


}
int main()
{
    SeqList list ;
    initList(&list);
    printf("初始化成功，当前长度占用%d\n",list.length);
    printf("当前占用内存%zu字节\n",sizeof(list.data));
    int n = 10;
    //末端增加
    int flag = addendElem(&list,n);
    while(list.length<=11)
    {
        flag = addendElem(&list,++n);
    }
    PriList(&list);
    //插入
    if(insertElem(&list,2,100))
    {
        PriList(&list);
    }
    //删除
    if(DelList(&list,6))
    {
        PriList(&list);
    }
    //查找
    int pos = findElem(&list,10);
    if(pos)
    {
        printf("此数据在第%d位\n",pos);
    }
    return 0;
}