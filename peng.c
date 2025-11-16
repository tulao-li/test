/*#include <stdio.h>
int main()
{
    int a = -7;
    int b = a<<1;
    printf("%d\n",b);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int a = 3;
    int b = 5 ;
    printf("%d  %d\n",a,b);
    a = b^a;;
    b = b^a;
    a = a^b;
    printf("%d   %d\n",a,b);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    printf("请输入一个数：");
    int n = 0;
    int count = 0;
    scanf(" %d",&n);
    for(int i = 0;i<33;i++)
    {
        if(n&0 == 0)
        {
        n = n>>1;
    }
    printf("有%d位\n",count);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int a = 13;
    a &= (~(1<<4));
    printf("%d",a);
    return 0;
}*/


/*#include <stdio.h>
int main()
{
    char a = '0';
    printf("%d",sizeof a);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    int c = a||b;
    printf("%d",c);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int a = 0,b = 2,c = 3,d = 4;
    int i = ++a||b++||++d;
    printf("%d %d %d %d ",a,b,c,d);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int arr[10] = {0};
    arr[7] = 9;
    7[arr] = 77;
    printf("%d",7[arr]);
    return 0;
}*/

/*#include <stdio.h>
#include <string.h>
struct Stu {
    char name[20]; // 假设名字最多 19 个字符，加一个结束符
    int age;
    double score;
};
void set_stu(struct Stu*ps)
{
    strcpy((*ps).name,"zhangsan");
    (*ps).age = 20;
    (*ps).score = 9;
}

void print_stu(struct Stu*ps)
{
    printf("%s %d %lf",(*ps).name, (*ps).age, (*ps).score);
}
int main()
{
    struct Stu s = {0};
    set_stu(&s);
    print_stu(&s);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int n = 0;
    scanf(" %d",&n);
    int arr[50];
    for(int i =0;i<n;i++)
    {
        int a = 0;
        scanf(" %d",&a);
        arr[i] = a;
    } 
    int del = 0;
    scanf(" %d",&del);
    for(int i = 0;i<n;i++)
    {
        if(arr[i]!= del)
        {
            printf("%d ",arr[i]);
        }

    }

    return 0;

}*/
/*#include <stdio.h>
int main()
{
    int min = 100,max = 0;
   
    int n = 0;
    scanf("%d",&n);
    int arr[20] = {0};
    for(int i = 0;i<n;i++)
     {
        int a = 0;
        scanf(" %d",&a);
        arr[i] = a;
        if(arr[i]>max)
        max = arr[i];
        if(arr[i]<min)
        min = arr[i];
     }
        printf("%d ",max-min);
    
    return 0;
}   */
/*#include <stdio.h>
int main()
{
    char arr1[10];
    char arr2[20] ;
    int ret = 1;
    int i = 0;
    while( (ret = scanf("%c",&arr1[i]))!= EOF)
    {
    
        if(arr1[i]>='a'&&arr1[i]<='z')
        {
            arr2[i] = arr1[i]-32;
        }
        else if(arr1[i]>='A'&&arr1[i]<='Z')
        {
            arr2[i] = arr1[i]+32;
        }
        i++;
    }
    for(int j = 0;j<i;j++)
    {
        printf("%c\n",arr2[j]);
    }
    return 0;
}*/
/*#include <stdio.h>
#include <ctype.h>
int main()
{
    char z;
    while(scanf("%c",&z)!=EOF)
    {
         if(islower(z))
         printf("%c\n",toupper(z));
         if(isupper(z))
         printf("%c\n",tolower(z));

    }
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    char ch;
    while(scanf(" %c",&ch)!=EOF)
    {
        if((ch>='a'&ch<='z')||(ch>='A'&&ch<='Z'))
        printf("%c is an alphabet\n",ch);
        else
        {
            printf("no\n");
        }
    }
    return 0;

}*/
/*#include <stdio.h>
int main()\
{
    int arr[3] = {0};
    for(int i = 0;i<3;i++)
    {
        scanf(" %d",&arr[i]);
    }
    int max = arr[0];
    for(int i = 0;i<2;i++)
    {
        if(arr[i]<arr[i+1])
        {
            max = arr[i+1];
        }

    }
    printf("%d\n",max);
    return 0;
}*/
/*#include <stdio.h>
int shuixian(int i)
{
    int n = 0;
   for(int j = 10;j<=10000;j*=10)
   {
        n += (i/j)*(i%j);
   }
   return n;
}
int main()
{
    int ret = 0;
    for(int i = 10000
        ;i<=99999;i++)
    {
        ret = shuixian(i);
        if(ret == i)
        printf("%d  ",i);
    }
    return 0;
}*/
/*#include<stdio.h>
int main()
{
    long n = 0;
    scanf("%ld",&n);
    int flag = 0;
    int arr[10] = {0};
    int j = 0;
    for(j = 0;n/10!=0;j++)
    {
        arr[j] = n%10;
        n = n/10;

    }
    arr[j] = n;
    int ret = j;
    for(int i = 0;i<ret;i++)
    {
        for(int p = i+1;p<ret;p++)
        {
            if(arr[i] == arr[p])
            {
                flag++;
            }
        }
    
    }
    if(flag)
    printf("yes\n");
    else
    printf("no\n");
    return 0;
}*/
/*#include <stdio.h>
 int my_strlen(char *ch)
 {
    int i = 0;
    while(*(ch+i)!='\0')
    {
        i++;
    }
    return i;

 }
int main()
{
    char ch[] = "sssfv";
    int ret = my_strlen(ch);
    printf("%d",ret);



}*/
/*#include <stdio.h>
int main ()
{
    int a = 9,b = 0,c = 8;
    int*pa[3] = {&a,&b,&c};
    for(int i = 0;i<3;i++)
    *(pa[i]) = 70;
    printf("%d",*pa[0]);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int arr1[] = {1,2,2,4};
    int arr2[]= {4,5,6,7};
    int arr3[] = {8,4,5,9};
    int*parr[] = {arr1,arr2,arr3};
    int i = 0;
    for( i = 0;i<3;i++)

    {
        for(int j = 0;j<4;j++)
        {printf("%d  ",parr[i][j]);}
        printf("\n");
    }
    return 0;

}*/
/*#include <stdio.h>
struct Peo
{
    char name[20];
    char gender[10];
    int age;
    char tele[13];
    int height;
};

void print1(struct Peo*p)
{
    printf("%s  %s  %d  %s  %d\n",p->name,p->gender,p->age,p->tele,p->height);

};
int main()
{
    struct Peo ren1 = {"lilichen","女",18,"123456",166};
    print1(&ren1);
    return 0;
}*/
/*#include <stdio.h>
int num1(int n)
{
    int count = 0;
    for(int i = 0;i<32;i++)
    {
         count += (n>>i)&1;
    }
    return count;
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    int count =num1(n);
    printf("%d",count);
    return 0;
}*/
/*#include <stdio.h>
int xiangtong(int n1,int n2)
{
    int n = n1^n2;
    int total = 0;
    for(int i = 0;i<32;i++)
    {
        total +=(n>>i)&1;
    }
    return total;
}

int main()
{
    int n1 = 0,n2 = 0;
    scanf("%d %d",&n1,&n2);
    int total = xiangtong(n1,n2);
    printf("%d",total);
    return 0;
}*/
/*#include <stdio.h>
int ji(int n)
{
    for(int i = 0;i<32;i+=2)
    {
        
    }
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    printf("%d",ji(n));
    printf("%d",ou(n));
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    int n =0;
    while(scanf("%d",&n)==1)
   { for(int i =0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        
        {    if(i==j||(i+j)==(n-1))
            {
                printf("*");

            }
            else
            printf(" ");
        }
        printf("\n");
    }
}
    return 0;    
}*/
/*#include <stdio.h>
int main()
{
   
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int i = 0;
    for(int i = 0;i<=11;i++)
    {
        arr[i] = 0;
        printf("%d  ",arr[i]);
    }
    return 0;
}*/
/*#include<stdio.h>
#include <assert.h>

int my_strlen(const char*arr)
{
    assert(arr);
    if(*arr == '\0')
    return 0;
    else
    return 1+my_strlen(arr+1);
    

}

int main()
{
    char arr[] = {'\0'};
    int n = my_strlen(arr);
    printf("%d\n",n);
    return 0;
}*/
/*#include <stdio.h>
#include <string.h>
int main()
{
    char arr[]= "hello,world";
    int l = strlen(arr);
    for(int i = 0;i<l;i++)
    {
        printf("%c ",*(arr+i));
    }
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    char arr[20] = {0};
    gets(arr);
    for(int i = 19;i>=0;i--)
    {
        if(arr[i]!='0')
        {
            printf("%c",arr[i]);
        }
    }
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int n = 0,total = 0,p = 6;
    scanf("%d",&n);
    for(int i = 1;i<=10^p;i*=10)
    {
        total += n*i*p;
        p--;
    }
    printf("%d",total);
    return 0;
}*/
/*#include <stdio.h>
#include <math.h>
int main()
{
    for(int n = 1;n<=100000;n++)
    {
        int m = n;
        int total = 0;
        int l = 0;
        for(int i = 1;i<=1000000;i*=10)
        {
            l++;
            if(n/i == 0)
            {
                break;
            }
        }
        l--;
        for(int i = 10;n>0;)
        {
            total += (int)pow(n%i,l);
            n = n/i;
        }
        if(m == total)
        printf("%d  ",m);
        n=m;
    }
    return 0;
    
}*/
/*#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 0;j<n/2;j++)
        {
            if()   
        }
    }
}*/
/*#include<stdio.h>
int main()
{
    int n = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n-i;j++)
        {
            printf(" ");
        }
        for(int j = 0;j<2*i+1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<=i;j++)
        {
            printf(" ");

        }
        for(int j = 0;j<2*n-2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}*/

/*#include <stdio.h>
int water(int n)
{
    if(n%2 == 1 && n!= 1)
    return n/2 + water(n/2+1);
    if(n%2 == 0&& n!= 0)
    return n/2 + water(n/2);
    if(n == 0 || n== 1)
    return 0;
}
int main()
{
    int mon = 0;
    scanf("%d",&mon);
    int total = water(mon);
    printf("%d\n",total+mon);
    return 0;
}*/
/*#include <stdio.h>
#include <string.h>

int main()
{
    char arr[10][10] = {0};
    int i =0;
   while (i < 10 && scanf("%s", arr[i]) == 1)
    {
        i++;  // 每读取一个单词，索引+1
    }
    for(int j =i-1;j>=0;j--)
    {
        if(arr[j][0] != '\0')
        {
            printf("%s ",arr[j]);
        }
    }
    return 0;


}*/
/*#include <stdio.h>
#include <string.h>

void reverse(char*left,char*right)
{
    while(left<right)
    {
        char tem = *left;
        *left = *right;
        *right = tem;
        left++;
        right--;
   }
}

int main()
{
    char arr[100] = {0};
    gets(arr);
    int len = strlen(arr);
    reverse(&arr[0],&arr[len-1]);
    int start = 0;
    int end = start;

    while(arr[start]!='\0')
    {
        while(arr[end]!=' '&&arr[end]!='\0')
        end++;
        reverse(&arr[start],&arr[end-1]);
        start = ++end;
    }
    printf("%s\n",arr);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int a = 1;
    int n = *(char*)&a;
    if(n == 1)
    {
        printf("小端存储\n");
    }
    else if (n == 0)
    {
        code 
        printf("大段存储\n");
    }
    return 0;
    
}*/
/*#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE*pf = fopen("test.txt","w");
    if(pf == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }

   fputs("Hello,world\n",pf);
    
    fclose(pf);
    pf = NULL;
    return 0;
}*/
/*#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
    FILE*pf = fopen("test.txt","r");
    if(pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    char arr[10] = "dicbsdiva";
    fgets(arr,10,pf);
    printf("%s",arr);

    fclose(pf);
    pf = NULL;
    return 0;

}*/
/*#include <stdio.h>
#include <string.h>
#include <errno.h>
struct s
{
    char name[15];
    int age;
    float score;
};
int main()
{
    struct s si = {0};
    FILE*pf = fopen("test.txt","rb");
    if(pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    fread(&si,sizeof(struct s),1,pf);

    fclose(pf);
    pf == NULL;

    return 0;


}*/


/*#include <stdio.h>
#include <string.h>
int main()
{
   
    if(strlen("abs") - strlen("ssfdgdfhdg")> 0)
    {
        printf(">\n");

    }
    else
    {
        printf("<\n");
    }
   
    return 0;
}*/
#include <stdio.h>
int main()
{
    int n = 9;
    float *pflo = (float*)&n;
    printf("%d\n",n);
    printf("%f\n",*pflo);
    *pflo = 9.0;
    printf("%f\n",*pflo);
    printf("%d\n",n);
    return 0;

}


 
