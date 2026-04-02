/*#include <stdio.h>
int main()
{
    int a[][3] = {{3,2,3},{7,5,7}};
    for(int i = 0;i<2;i++)
    {
        for(int j = 0;j<3;j++)
        {
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/
/*#include <stdio.h>
#include <string.h>
int main()
{
    char a1[] = "asdfghjkl";
    char a2[] = "kl";
    printf("%p\n",strstr(a1,a2));
    for(int i = 0;i<(sizeof(a1)/sizeof(a1[0])-sizeof(a2)/sizeof(a2[0]));i++)
    {
        int flag = 0;
        for(int j = 0;j<(sizeof(a2)/sizeof(a2[0])-1);j++)
        {
            if(a1[i+j] == a2[j])
            {
                flag++;
            }
        }
        if(flag == sizeof(a2)/sizeof(a2[0])-1)
        {
            printf("%p\n",&a1[i]);
        }
    }
    return 0;
} */
/*#include <stdio.h>
#include <string.h>
int strMatch(char*str,char*patten)
{
    int n = strlen(str);
    int m = strlen(patten);
    for(int i = 0;i<(n-m)+1;i++)
    {
        int j = 0;;
        while(j<m)
        {
            if(str[i] == patten[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j;
                break;
            }
        }
        if (j == m)
        {
            return i-j;
        }
    }
    return -1;
}

int main()
{
    char s1[] = "wefgssrgsrhawfe";
    char s2[] = "fe";
    printf("%d\n",strMatch(s1,s2));
    return 0;
}*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 40
#define BLOCK_SIZE 4
//每个节点定义
typedef struct BLOCK
{
    char ch[BLOCK_SIZE];
    struct BLOCK*next;
}Block;
//块链整体定义
typedef struct 
{
    Block*head;
    Block*tail;
    int length;
}BLString;

//初始化
BLString* InitBLString()
{
    BLString* S = (BLString*)malloc(sizeof(BLString));
    if(S == NULL)
    {
        return NULL;
    }
    S->tail = NULL;
    S->head = NULL;
    S->length = 0;
    return S;
}

//创建块链串
int StrAssign(BLString *S,const char *chars)
{
    if(chars == NULL)
    {
        return 0;
    }
    int len = strlen(chars);
    if(len == 0)
    {
        printf("字符串为空\n");
        return 0;
    }
    int block_num = (len+BLOCK_SIZE-1)/BLOCK_SIZE;//计算所需块数并向上取整
    Block*prev = NULL;
    int k = 0;
    for(int i = 0;i<block_num;i++)
    {
        Block*newBlock = (Block*)malloc(sizeof(Block));
        if(newBlock == NULL)
        {
            Block *p = S->head;
            Block*q ;
            while(p != NULL)
            {
                q = p->next;
                free(p);//内存释放
                p = q;
            }
            S->head = S->tail = NULL;
            S->length = 0;
            return 0;
        }
        newBlock->next = NULL;
        for(int j = 0;j<BLOCK_SIZE;j++)
        {
            if(k<len)
            {
                newBlock->ch[j] = chars[k];
                k++;
            }
            else
            {
                newBlock->ch[j] = '#';
            }
        }
        if(S->head == NULL)
        {
            S->head = newBlock;
        }
        else
        {
            prev->next = newBlock;
        }
        prev = newBlock;
    }
    S->tail = prev;
    S->length = len;
    return 1;
}
//打印
int printBlock(const BLString*S)
{
    if(S == NULL)
    {
        printf("指针为空\n");
        return 0;
    }
    if(S->length == 0)
    {
        printf("空串\n");
        return 0;
    }

    Block*p = S->head;
    int n = 0;
    while((p != NULL)&&(n<(S->length)))
    {
        for(int i = 0;(i<BLOCK_SIZE)&&(n<(S->length));i++)
        {
                printf("%c ",p->ch[i]);
                n++;
        }
    }
    printf("\n");
    return 0;
}
//串拼接
//浅拷贝
/*int StrConcat(BLString *S,const BLString T)
{
    if(T.length == 0)
    {
        printf("添加字符串为空\n");
        return 0;
    }
    if(S == NULL)
    {
        return 0;
    }
    if(S->head == NULL)
    {
        S->head = T.head;
        S->tail = T.tail;
        S->length = T.length;
        return 1;
    }
    S->tail->next = T.head;
    S->tail = T.tail;
    S->length = S->length +T.length;
    return 1;
}*/
//深拷贝
int StrConcat(BLString *S, const BLString T)
{
    if(S == NULL) return 0;
    if(T.length == 0)
    {
        printf("添加字符串为空\n");
        return 1; 
    }

    Block *p = T.head;
    Block *prev_S = S->tail;

    while(p != NULL)
    {
        Block *newBlock = (Block*)malloc(sizeof(Block));
        if(newBlock == NULL)
        {
            printf("内存分配失败！\n");
            return 0;
        }
        memcpy(newBlock->ch, p->ch, BLOCK_SIZE);
        newBlock->next = NULL;
        if(S->head == NULL) 
        {
            S->head = newBlock;
        }
        else
        {
            prev_S->next = newBlock;
        }
        prev_S = newBlock;
        p = p->next;
    }
    S->tail = prev_S;
    S->length += T.length;
    return 1;
}
 
//释放内存
void DestroyBlock(BLString *S)
{
    if(S == NULL)
    {
        printf("传入指针为空\n");
        return ;
    }
    Block*p = S->head;
    Block*q;
    while(p!= NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    S->head = S->tail = NULL;
    S->length = 0;
    return;
}

int main()
{
    BLString *s1 = InitBLString();
    BLString *s2 = InitBLString();
    BLString *s3 = InitBLString();
    //赋值
    StrAssign(s1,"hello,world!");
    StrAssign(s2,"Tomorrow is an another day");
    //打印
    printf("串1:");
    printBlock(s1);
    printf("串2:");
    printBlock(s2);
    //拼接
    StrConcat(s1,*s2);
    printf("复合串:");
    printBlock(s1);
    StrConcat(s3,*s1);
    printf("串3:");
    printBlock(s3);
    printf("length:%d",s3->length);
    //销毁
    DestroyBlock(s1);
    DestroyBlock(s2);
    DestroyBlock(s3);
    return 0;
}
