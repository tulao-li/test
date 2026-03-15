#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Element int
typedef struct node
{
    Element data;
    struct node* next;
}Node;

Node*InitList()
{
    Node*head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}
//头插法
/*Node*AddHeadList(Node* list,Node* new)
{
    Node*cur = list->next;
    list->next = new;
    new->next = cur;
    return list;
}*/
int inserthead(Node *L,Element e)
{
    Node*new_code = (Node*)malloc(sizeof(Node));
    if(new_code == NULL)
    {
        return 0;
    }
    new_code->data = e;
    Node*ori = L->next;
    L->next = new_code;
    new_code->next = ori;
    return 1;
}
//尾插法
int insertend(Node*L,Element e)
{
    Node*p = L;
    while(p->next!= NULL)
    {
        p = p->next;
    }
    Node*new_code = (Node*)malloc(sizeof(Node));
    if(new_code == NULL)
    {
        return 0;
    }
    new_code->data = e;
    new_code->next = NULL;
    p->next = new_code;
}
//遍历
void listnode(Node*L)
{
    Node*p = L->next;
    while(p!= NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

//在某个数据后面插入
int Eleminsretlist(Node*L,Element e,Element bef)
{
    Node*p= L->next;
    if(p== NULL)
    {
        printf("该链表为空\n");
        return 0;
    }
    else
    {
        while(p!= NULL)
        {
            if(p->data == bef)
            {
                Node*aft = p->next;
                Node*newcode = (Node*)malloc(sizeof(Node));
                newcode->data = e;
                p->next = newcode;
                newcode->next = aft;
                return 1;
            }
            p = p->next;
        }
        printf("该链表里面没有此元素\n");
        return 0;
    }
}

//在某个节点后面插入
int insertlist(Node*L,int pos,Element e)
{
    if(L->next == NULL)
    {
        printf("该链表为空\n");
        return 0;
    }
    if(pos<=0)
    {
        printf("插入位置错误\n");
        return 0;
    }
    else
    {
        Node*bef = L->next;
        /*for(int i = 1;i<pos;i++)
        {
            if(bef== NULL)
            {
                printf("插入位置错误\n");
                return 0;
            }
            bef = bef->next;
        }*/
       int i = 0;
       while(i<pos-1)
       {
        bef  = bef->next;
        i++;
        if(bef == NULL)
        {
            printf("插入位置有误\n");
            return 0;
        }
       }
        Node*newcode = (Node*)malloc(sizeof(Node));
        newcode->data = e;
        newcode->next = bef->next;
        bef->next = newcode;
        return 1;
    }

}
//按位置删除节点
int dellist(Node*L,int pos)
{
    if(L->next == NULL)
    {
        printf("此链表为空\n");
        return 0;
    }
    Node*bef = L->next;
    int i = 0;
    if(pos == 1)
    {
        L->next = bef->next;
        free(bef);//释放空间
        return 1;
    }
    else
    {
        while(i<pos-2)
        {
            bef = bef->next;//要删除节点的前驱
            if(bef == NULL)
            {
                printf("删除位置错误\n");
                return 0;
            }
            i++;
        }
        Node*delcode = bef->next;//记录要删除的节点
        Node*aft = bef->next->next;
        bef->next = aft;
        free(delcode);//释放空间
        return 1;
    }
}

//获取链表长度(不含头节点)
int lengthlist(Node*L)
{
    Node*p = L;
    int i = 0;
    while(p->next!= NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

//释放链表
void freelist(Node*L)
{
    if(L == NULL)
    {
        printf("此链表为空\n");
    }
    Node*p = L->next;
    while(p!= NULL)
    {
        Node*del = p;
        p = p->next;
        free(del);
    }
    L->next = NULL;
    return ;
} 

int main()
{
    Node* list =InitList();
    for(int i = 0;i<10;i++)
    {
        if(insertend(list,10+i) == 0)
        {
            printf("插入有误\n");
            break;
        };
    }
    listnode(list);
    if(Eleminsretlist(list,100,15))
    {
        listnode(list);
    };
    if(insertlist(list,2,200))
    {
        listnode(list);
    }
    if(dellist(list,3))
    {
        listnode(list);
    }
    int len = lengthlist(list);
    printf("此链表有%d个节点(不含头节点)\n",len);
    freelist(list);
    len = lengthlist(list);
    printf("此链表有%d个节点(不含头节点)\n",len);
    return 0;
}
