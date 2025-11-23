#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_CON 100
//人的信息
typedef  struct PeoInfo
{
    char name[15];
    int age;
    char gender[10];
    char tele[13];
    char addr[30];
}PeoInfo;


//通讯录信息
//静态版本
/*typedef struct Contact
{
    PeoInfo data[100];
    int count;
}Contact;*/
//动态版本
typedef struct Contact
{
    PeoInfo* data;
    int count;
    int capacity;
}Contact;

//函数声明
void InitContact(Contact*p);
void AddContact(Contact*p);
void ShowContact(const Contact*p);
void DelContact(Contact*p);
void SearchContact(Contact*p);
void ModContact(Contact*p);
void SortContact(Contact*p);
void DestroyContact(Contact*p);

//初始化通讯录
//静态
/*void InitContact(Contact*p)
{
    assert(p);
    p->count = 0;
    memset(p->data,0,sizeof(p->data));
    return;
}*/
//动态
void InitContact(Contact*p)
{
    assert(p);
    p->count = 0;
    p->capacity = 3;
    p->data = (PeoInfo*)calloc(3,sizeof(PeoInfo));
    if(p->data == NULL)
    {
        printf("InitContact:%s\n",strerror(errno));
    }
    return;
}

//添加个人信息
//静态
/*void AddContact(Contact*p)
{
    assert(p);
    if(p->count == MAX_CON)
    {
        printf("已放满，不可增加\n");
        return;
    }
    else
    {
        printf("请输入姓名：");
        scanf(" %s",&p->data[p->count].name);
        printf("请输入年龄：");
        scanf(" %d",&p->data[p->count].age);
        printf("请输入性别：");
        scanf(" %s",&p->data[p->count].gender);
        printf("请输入电话号码：");
        scanf(" %s",&p->data[p->count].tele);
        printf("请输入地址：");
        scanf(" %s",&p->data[p->count].addr);
        (p->count)++;
    }
    return;
}*/
//动态
void AddContact(Contact*p)
{
    assert(p);
    if(p->count == p->capacity)
    {
        PeoInfo*ptr = (PeoInfo*)realloc(p->data,(p->capacity+2)*sizeof(PeoInfo));
        if(ptr == NULL)
        {
            printf(" AddContact:%s\n",strerror(errno));
            return;
        }
        else
        {
            p->data = ptr;
            p->capacity = p->capacity+2;
            printf("增容成功！\n");
        }

    }
            printf("请输入姓名：");
            scanf(" %s",&p->data[p->count].name);
            printf("请输入年龄：");
            scanf(" %d",&p->data[p->count].age);
            printf("请输入性别：");
            scanf(" %s",&p->data[p->count].gender);
            printf("请输入电话号码：");
            scanf(" %s",&p->data[p->count].tele);
            printf("请输入地址：");
            scanf(" %s",&p->data[p->count].addr);
            (p->count)++;
    return;
}


//打印
void ShowContact(const Contact*p)
{
    assert(p);
    printf("%-15s\t%-3s\t%-10s\t%-13s\t%-30s\t\n","name","age","gender","telephone","address");
    for(int i = 0;i<p->count;i++)
    {
        printf("%-15s\t%-3d\t%-10s\t%-13s\t%-30s\t\n",p->data[i].name,
                                              p->data[i].age,
                                              p->data[i].gender,
                                              p->data[i].tele,
                                              p->data[i].addr);
                                        
    }
    return;
}


//删去某个联系人
//1.查找
static int FindByName(Contact*p,char name[])
{
    assert(p);
    int i = 0;
    for(i = 0;i<p->count;i++)
    {
        if(0 == strcmp(p->data[i].name,name))
        {
            return i;
        }
    }
    if(i == p->count)
    printf("没有此联系人\n");
    return -1;
}
//2.删除
void DelContact(Contact*p)
{
    assert(p);
    printf("请输入要删除的人的姓名：");
    char name[15] = {0};
    scanf(" %s",name);
    if(p->count == 0)
    {
        printf("没有联系人，无法删除\n");
        return;
    }
    else
    {
        int pri = FindByName(p,name);
        if(pri != -1)
        {
            for(int i = pri;i<p->count-1;i++)
            {
                p->data[i] = p->data[i+1];
            }
        }
    }
    (p->count)--;
    return;
}

//按姓名查找
void SearchContact( Contact*p)
{
    assert(p);
    printf("请输入要查找的人的姓名：");
    char name[15] = {0};
    scanf(" %s",name);
    if(p->count == 0)
    {
        printf("没有联系人\n");
        return;
    }
    else
    {
        int pri = FindByName(p,name);
        if(pri != -1)
        {
            printf("%-15s\t%-3s\t%-10s\t%-13s\t%-30s\t\n","name","age","gender","telephone","address");
            printf("%-15s\t%-3d\t%-10s\t%-13s\t%-30s\t\n",  p->data[pri].name,
                                                            p->data[pri].age,
                                                            p->data[pri].gender,
                                                            p->data[pri].tele,
                                                            p->data[pri].addr);
            }
    }
    return;
}


//修改联系人
void ModContact(Contact*p)
{
    assert(p);
    printf("请输入要修改的人的姓名：");
    char name[15] = {0};
    scanf(" %s",name);
    if(p->count == 0)
    {
        printf("没有联系人，无法修改\n");
        Sleep(1000);
        return;
    }
    else
    {
        int pri = FindByName(p,name);
        printf("请输入姓名：");
        scanf(" %s",&p->data[pri].name);
        printf("请输入年龄：");
        scanf(" %d",&p->data[pri].age);
        printf("请输入性别：");
        scanf(" %s",&p->data[pri].gender);
        printf("请输入电话号码：");
        scanf(" %s",&p->data[pri].tele);
        printf("请输入地址：");
        scanf(" %s",&p->data[pri].addr);
        printf("修改成功\n");
    }
    return;
}

//按照姓名排序
int com_name(const void*e1,const void*e2)
{
    return strcmp(((PeoInfo*)e1)->name,((PeoInfo*)e2)->name);
}
void SortContact(Contact*p)
{
    assert(p);
    qsort(p->data,p->count,sizeof(p->data[0]),com_name);
    /*for(int i = 0;i < p->count;i++)
    {
        for(int j = 0;j < p->count - i - 1;j++)
        {
            if(strcmp(p->data[j].name, p->data[j+1].name) > 0)
            {
                PeoInfo tem = p->data[j];
                p->data[j] = p->data[j+1];
                p->data[j+1] = tem;
            }
        }
    }*/
    return;
}


void DestroyContact(Contact*p)
{
    assert(p);
    free(p->data);
    p->data = NULL;
    p = NULL;
    return;
}