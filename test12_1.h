#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*typedef struct linknode
{
    int data;
    struct linknode* next;
}linknode;
void listprint()
{
    linknode node1;
    linknode node2 = {20,NULL};
    linknode node3 = {30,NULL};
    linknode node4 = {40,NULL};
    linknode node5 = {50,NULL};

    node1.data = 15;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    //遍历链表
    linknode* pcurrent = &node1;
    printf("%d\n",pcurrent->data);
    while(pcurrent->next != NULL)
    {
        pcurrent = pcurrent->next;
        printf("%d\n",pcurrent->data);
    }

} 
int main()
{
    listprint();
    return 0;
}*/

//链表节点
struct LinkNode
{
    int data;
    struct LinkNode* next;
};

//初始化链表
struct LinkNode* Init_LinkNode()
{
    //创建头节点
    struct LinkNode*header = (struct LinkNode*) malloc(sizeof(struct LinkNode));
    header->data = 0;
    header->next = NULL;

    //尾部指针
    struct LinkNode*prear = header;

    int val = -1;
    while(true)
    {
        printf("请输入数据：");
        scanf(" %d",&val);
        if(val == -1)
        break;

        //创建新节点
        struct LinkNode*newnode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
        newnode->data = val;
        newnode->next = NULL;
        prear->next = newnode;
        prear = newnode;
    }
    return  header;
}

//遍历
void forlistnode(struct LinkNode*header)
{
    if(NULL == header->next)
    {
        return ;
    }
    struct LinkNode*pcurrent = header->next;
   
    while(NULL!=pcurrent)
    {
        printf("%d\n",pcurrent->data);
        pcurrent = pcurrent->next;
    }
}

//插入
 void InsertByValue(struct LinkNode*header,int oldvalue,int newvalue)
 {
    if(NULL == header)
    {
        return ;
    }
    struct LinkNode*ppre = header;
    struct LinkNode*pcurrent = ppre->next;

    while(pcurrent != NULL)
    {
        if(pcurrent->data == oldvalue)
        {
            struct LinkNode*newnode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
            if (newnode == NULL) {
                printf("内存分配失败，无法插入\n");
                return;
            }
            newnode->data = newvalue;

            ppre->next = newnode;
            newnode->next = pcurrent;
           printf("插入成功：在%d后面插入%d\n", oldvalue, newvalue);
            return;
        }
        else{
        ppre = pcurrent;
        pcurrent = pcurrent->next;}
    }
    if(pcurrent == NULL)
    {
        printf("没有这个数据\n");
        return ;
    }
   
 }

 //清空
 void Clear(struct LinkNode*header)
 {
    if(NULL == header)
    return ;
   
    struct LinkNode*pcurrent = header;
    while(pcurrent != NULL)
    {
        struct LinkNode*pnext = pcurrent->next;
        free(pcurrent);
        pcurrent = pnext;
    }
    header =NULL;
 }

 //删除
 void DeletByValue(struct LinkNode*header,int delval)
 {
    if(NULL == header->next)
    {
        return ;
    }
    //找到数据
    struct LinkNode*ppre = header;
    struct LinkNode*pcurrent = header->next;
    while(NULL != pcurrent)
    {
        if(pcurrent->data == delval)
        {
            ppre->next = pcurrent->next;
            free(pcurrent);
            pcurrent = NULL;
            return ;
        }
        else
        {
            pcurrent = pcurrent->next;
             ppre = ppre->next;
            
        }
    }
    if(NULL == pcurrent)
    {
        printf("没有这个数据\n");
        return ;
    }
 }


 //销毁
 void Destroy(struct LinkNode*header)
 {
    if(NULL == header->next)
    {
        return ;
    }
    struct LinkNode*pcurrent = header->next;
    while(pcurrent != NULL)
    {
        struct LinkNode*pnext = pcurrent->next;
        free(pcurrent);
        pcurrent = pnext;
    }
 }