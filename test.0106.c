/*#include <stdio.h>
int main()
{
    printf("Enter amout of loan:");
    double loan = 0.0,rate = 0.0,payment = 0.0;
    scanf("%lf",&loan);
    printf("Enter interest rate: ");
    scanf("%lf",&rate);
    printf("Enter monthly payment: ");
    scanf("%lf",&payment);
    for(int i = 0;i<3;i++)
    {
        
        loan = loan+loan*rate/100.00/12.00-payment;
        printf("Balance remaining after first payment: $%.2lf\n",loan);
    }
    return 0;

}*/
/*#include <stdio.h>
int main()
{
    long long n = 0;
    printf("Enter a number: ");
    scanf("%d",&n);
    int num[10] = {0};
    int i = 0;
    while(n!= 0)
    {
        num[i] = n%10;
        n= n/10;
        i++;
    }
    printf("Digit:	0123456789\n");
    printf("Occurrences:");
    for(int j = 0;j<10;j++)
    {
        int flag = 0;
        for(int p = 0;p<i;p++)
        {
            if(num[p] == j)
            {
                flag++;
            }
            
        }
         printf("%d",flag);
    }
    return 0;
}*/
/*#include <stdio.h>
#include <string.h>
int main()
{
    char word[20][20] = {0};
    int i = 0;
    printf("Enter word: ");
    for(i = 0;i<20;i++)
    {
        int p = 0;
        for( p = 0;p<20;p++)
        {
            char c  = getchar();
            if(c == '\n')
            {
                break;
            }
            word[i][p]= c;
            word[i][p+1] = '\0';
        }
        if(p == 4)
        break;
         printf("Enter word: ");
       
    }
    
    char small[20] = {0},large[20] = {0};
    strcpy(small,word[0]);
    strcpy(large,word[0]);
    for(int j = 0;j<i+1;j++)
    {
        if(strcmp(small,word[j])>0)
        {
            strcpy(small,word[j]);
        }
        if(strcmp(large,word[j])<0)
        {
            strcpy(large,word[j]);
        }
    }
    printf("Smallest word: %s\n",small);
    printf("Largest word:%s",large);
    return 0;
    
}*/
/*#include <stdio.h>
int main(
    {
        printf("Enter a dollar amount:");
        int dollar  = 0;
        scanf("%s",&dollar);
        int n20 = 0,n10 = 0,n5 = 0,n1 = 0;
        n20 = dollar/20;
        dollar = dollar%20;
        n10 = dollar/10;
        dollar = dollar%10;

    }
)*/
/*#include <stdio.h>
int main()
{
    int mm = 0,dd = 0,yyyy = 0;
    scanf("%d/%d/%d",&mm,&dd,&yyyy);
    printf("%.4d%.2d%.2d\n",yyyy,mm,dd);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    printf("Enter two fractions separated by a plus sign:");
    int a = 0,b = 0,c = 0,d = 0;
    scanf("%d/%d+%d/%d",&a,&b,&c,&d);
    int n1 = 0,n2 = 0;
    n1 = a*d+c*b;
    n2 = b*d;
    printf("The sum is:%d/%d",n1,n2);
    return 0;
}*/
/*#include <stdio.h>


 * @brief 求集合的交集
 *
 * @param A 输入集合
 * @param B 输入集合
 * @param C A 和 B 的交集
 
void intersect(int *A, int *B, int *C) {
  // TODO
    int k = 0;
    int i = 0;
    while(A[i] != 0)
    {
        int j = 0;
        while(B[j] != 0)
        {
            if(A[i] == B[j])
            {
                C[k++] = A[i];
            }
            j++;
        }
        i++;
    }
    C[k++] = 0;
  // END OF TODO
}


 * @brief 输入以 -1 结尾的正整数集合（数组）
 *
 * @param S 集合
 
void input_set(int *S) {
  int i = 0, v;
  do {
    scanf("%d", &v);
    S[i++] = v;
  } while (v != -1);
  S[i - 1] = 0; // 用 0 替换数组中的 -1，作为数组结束的标志
}

// 集合最大元素个数
#define MAXN 20

int main() {
  int A[MAXN], B[MAXN], C[MAXN];

  input_set(A);
  input_set(B);

  intersect(A, B, C);
  for (int i = 0; C[i] != 0; ++i) // 用 0 作为数组结束的标志
    printf("%d ", C[i]);
  printf("\n");

  return 0;
}*/
/*#include <stdio.h>
#include <ctype.h> // 引入头文件以使用 isdigit 函数

// 你的代码写在 TODO 和 END OF TODO 之间。
// 请勿修改这对标签外的任何代码！！！


 * @brief 读取字符串中的整数
 *
 * @param s 字符串
 * @return int 字符串中嵌入的整数。如果没有，则返回 0。

int get_int(char *s) 
{
  // 在此函数中，需要用到字符输出
  // TODO
    /*int i = 0;
    int num[10] = {0};
    int count = 0;
    while(s[i] != '\0')
    {
        if(s[i]>='0'&&s[i]<='9')
        {
           num[count] = (int)s[i]-'0';
           count++;
        }
        num[count] = 0;
        i++;
    }
    if(count == 0)
    {
        return 0;
    }
    else
    {
        int back = 0;
        count = count-1;
        for(int j = count;j>=0;j--,count--)
        {
            if(j == 0)
            {
                back = back+num[count];
            }
            else
            {int t = 1;
            for(int l = 0;l<j;l++)
            {
                t = t*10;
            }
            back = back+(num[count])*t;}
        }
        return back;
    }

    int result = 0;
    int found = 0;
    for(int i = 0;s[i]!= '\0';i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            found = 1;
            result = result*10+(s[i]-'0');
        }
    }
  // END OF TODO
}

char S[1000];
int main() {
  scanf("%999s", S); // 读取字符串，最多999个字符，防止溢出
  printf("%d\n", get_int(S));

  return 0;
}*/

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char*p = (char*)malloc(100);
    printf("Enter some words:");
    scanf("%s",p);
    while(p!= NULL)
    {
        if(strlen(p) == 5)
        printf("%s\n",p);
        scanf("%s",p);
    }
    return 0;
}*/
/*#include <stdio.h>
void reserve_name(char*name)
{
    char first[50] = {0},last[50] = {0};
    int i = 0,j = 0,p = 0;//循环计数
    while(name[i] == ' ')
    {
        i++;
    }
    while(name[i]!= ' ')
    {
        first[j] = name[i];
        i++;
        j++;
    }
    first[j] = '\0';
    while(name[i+1] != ' ')
    {
        last[p] = name[i+1];
        i++;
        p++;
    }
    last[p] = '\0';
    sprintf(name,"%s,%c.",last,first[0]);
}

int read_line(char str[],int n )
{
      fgets(str,n,stdin);
    int i = 0;
    while(str[i]!= '\n')
    {
        i++;
    }
    str[i] = '\0';
    return i;
}

int main()
{
    printf("Enter a first and last name: ");
    char str[40] = {0};
    read_line(str,40 );
    reserve_name(str);
    printf("%s",str);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node*next;
};
struct node*add_list(struct node*list,int n)
{
    struct node *newnode = malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Error:malloc failed in add_list\n");
        exit(EXIT_FAILURE);
    }
    newnode->value = n;
    newnode->next = list;
    return newnode;
}


int main()
{
    struct node*list = NULL;
    int i = 0,n = 0;
    printf("Enter 3 integers:");
    for(i = 0;i<3;i++)
    {
        scanf("%d",&n);
        list = add_list(list,n);
        printf("(*first).value = %d\n", list->value);
    }
    struct node*tmp;
    while(list!= NULL)
    {
        tmp = list;
        list = list->next;
        free(tmp);

    }
    return 0;
}