
/*int main()
{
    int* arr[4] = {0};  
    char* ch[5] ={0};

    int arr2[5] = {0};
    int (*pa)[5] = &arr2;


}*/
/*int* func()
{
    int a = 10;
    return &a;
}

void test01()
{
    int*p = func();
    printf("%d\n",*p);
}

int main()
{
    test01();
    
    return 0;
}*/
/*#include <string.h>
int main()
{
    char arr[11] = {0};
    strcpy(arr,"HelloWorld");
    printf("%s",arr);
    return 0;

}*/
/*int main()
  {
    int a = 5;
    printf("%zu\n",sizeof(a));
    printf("%zu\n",sizeof(int));
    printf("%zu\n",sizeof(4.25));
    return 0;
  }*/
 /*int main()
 {
    int a = 10;
    int*p = &a;
    printf("%p\n",&a);
    printf("%p\n",p);
    printf("%p\n",&p);
    return 0;
 }*/
/*void swi(int*a,int*b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
int main()
{
    int a = 10;
    int b = 20;
    swi(&a,&b);
    printf("%d,%d",a,b);
    return 0;

}*/
/*int main()
{
    int a[] = {22,56,44,44,16,261};
    int *p = a;
    for(int i = 0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        printf("%d\n",a[i]);
    }
    printf("NEXT\n");
    for(int i = 0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        printf("%d\n",*(p+i));
    }
    return 0;
}*/
/*#include <string.h>

typedef struct student
{
    char stID[20];
    char stNAME[20];
    int age;
}student;

void InitialStu(student *p)
{
    strcpy((*p).stID,"2025091602028");
    strcpy((*p).stNAME,"mia");
    (*p).age = 20;
}; 

int main()
{
    student a;
    InitialStu(&a);
    printf("%s->%s->%d",a.stNAME,a.stID,a.age);
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 5;
    int*b = (int*)malloc(sizeof(int));
    *b = 10;
    printf("%d->%p\n",a,&a);
    printf("%d->%p",*b,b);
    free(b);
    return 0;
}*/
/*#include <stdio.h>
#include<string.h>
#include <stdlib.h>
void print(char*a)
{
    int n = strlen(a);
    for(int i =0;i<n;i++)
    {
        printf("%c",*(a+i));
    }
};

int main()
{ 
    char*a = (char*)malloc(15);
    strcpy(a,"Hello");
    
    print(a);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    char stuID[20];
    char stuNAME[20];
    int age;
} student;

int main()
{
    student*p = (student*)malloc(sizeof(student));
    strcpy(p->stuID,"2025091602028");
    strcpy(p->stuNAME,"xiaohong");
    p->age = 20;
    printf("%s->%s->%d",p->stuID,p->stuNAME,p->age);
    free(p);
    return 0;
}