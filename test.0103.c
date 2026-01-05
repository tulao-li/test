/*#include <stdio.h>
int main()
{
    printf("Enter first date(mm/dd/yy):");
    int m1 = 0,d1 = 0,y1 = 0;
    scanf("%d/%d/%d",&m1,&d1,&y1);
    int m2 = 0,d2 = 0,y2 = 0;
    printf("Enter second date(mm/dd/yy):");
    scanf("%d/%d/%d",&m2,&d2,&y2);
    if((y2>y1)||((y2 == y1)&&(m2>m1))||((y2==y1)&&(m2==m1)&&(d2>d1)))
    {
        printf("%d/%d/%d is the earlier than %d/%d/%d",m1,d1,y1,m2,d2,y2);
    }
    else
    printf("%d/%d/%d is the earlier than %d/%d/%d",m2,d2,y2,m1,d1,y1);
    return 0;
    
}*/
/*#include <stdio.h>
int main()
{
    int n = 0;
    printf("Enter value for n:");
    scanf("%d",&n);
    float e = 1.0;
    for(int i = 1;i<=n;i++)
    {
        int p = 1;
        for(int j = 1;j<=i;j++)
        {
            p = p*j;
        }
        e = e+1.0/p;

    }
    printf("Approximation of e: %.5f",e);
    return 0;
}*/
/*#include <stdio.h>

void max_min(int a[],int n,int*max,int*min)
{
    *max = a[0];
    *min = a[0];
    for(int i = 0;i<n;i++)
    {
    
        if(*max<a[i])
        *max = a[i];
    }
    for(int i = 0;i<n;i++)
    {
       
        if(*min>a[i])
        *min = a[i];
    }
}*/


/*#include <stdio.h>
void reverse_name(char *name)
{
    char first[50] = {0};
    char last[50] = {0};
    char newname[100] = {0};
    int start = 0;
    for(int i = 0;name[i] == ' ';i++)
    {
        start = i+1;
    }
    int j = 0;
    for(j = 0;name[start]!= ' ';start++,j++)
    {
        first[j] = name[start];
    }
    first[j] = '\0';
    start++;
    int p = 0;
    for(p = 0;name[start] != ' ';start++,p++)
    {
        last[p] = name[start];
    }
    last[p] = '.';
    last[p+1] ='\0';
    sprintf(name,"%s,%c",last,first[0]);

}
int read_line(char str[],int n)
{
   fgets(str,n,stdin);
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
        i++;

    }
    return i;
}

int main()
{
    printf("Enter a first and a last name:");
    char str[100];
    read_line(str,100);
    reverse_name(str);
    printf("%s",str);
    return 0;
}*/

/*#include <stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node*next;
} ;

struct node *add_list(struct node*list,int n)
{
    struct node *head = malloc(sizeof(struct node));
    head->value = n;
    head->next = list;
    return head;
}
int main()
{
    struct node*list = NULL;
    int i =0,n = 0;
    printf("ENter 3 integers:");
    for(i = 0;i<3;i++)
    {
        scanf(" %d",&n);
        list = add_list(list,n);
        printf("(*first).value = %d\n",list->value);

    }
    struct node*tem;
    while(list!= NULL)
    {
        tem = list;
        list = list->next;
        free(tem);
    }
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    int n1 = 0,n2 = 0,n3 = 0;
    scanf("(%d,%d,%d)",&n1,&n2,&n3);
    float I1 = n1*0.3 +n2*0.59 +n3*0.11;
    printf("(%.0f,%.0f,%.0f)",I1,I1,I1);
    return 0;
}*/

/*#include <stdio.h>
unsigned sum_of_factors(unsigned n)
{
   
    int total =0;
    for(int i =1;i<n;i++)
    {
        if(n%i == 0)
        {
            total = total+i;
        }
    }
    return total;
}
int main()
{
    int n = 0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        int p = sum_of_factors(i);
        if((sum_of_factors(p) == i)&&(i<p) )
        {
            printf("(%d,%d)",i,p);
        }
    }
    return 0;
}*/

/*#include <stdio.h>
int is_mirror(char*s1,char*s2)
{
    int len1 = 0;
    int len2 = 0;
    while(s1[len1] != '\0')
    {
        len1++;
    }
    while(s2[len2]!= '\0')
    {
        len2++;
    }
    if(len1 != len2)
    {
        return 0;
    }
    int flag = 0;
    for(int i = 0,j = len2-1;i<len1,j>=0;i++,j--)
    {
        if(s1[i] == s2[j])
        {
            flag++;
        }
    }
    if(flag == len1)
    return 1;
    else
    return 0;
}

int main()
{
    char s1[50] = {0},s2[50] = {0};
    scanf(" %s",&s1);
    scanf(" %s",&s2);
    int n = is_mirror(s1,s2);
    if(n)
    {
        printf("Yes\n");
    }
    else
    printf("No\n");
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
typedef struct node { //链表结点类型定义
    int data;
    struct node *next;
} node;
typedef struct { //采用头结点模式的链表类型定义
    node head;  //头结点
    int length; //链表长度（即结点数量）
} mlist;


void list_sort(mlist *L)
{
      if(L->length <=1)
      return ;
    
      node*ptem = &(L->head);
      node* tem = L->head.next;
      for(int i = 0;i<L->length-1;i++)
      {

        int n = tem->data;
        node*ptem2 = tem; 
        node* tem2 = tem->next;
        for(int j = i+1;j<L->length;j++)
        {
            if(n>=tem2->data)
            {
                node*pp = tem2->next;
                ptem->next = tem2;
                tem2->next = tem->next;
                ptem2->next = tem;
                tem->next = pp;
            }
            ptem2 = ptem2->next;
            tem2 = tem2->next;
        }
        tem = tem->next;
        ptem = ptem->next;
        
      }


}    */
/*#include <stdio.h>
#include <math.h>

double area(double a,double b,double c)
{
    if((a+b >c)&&(b+c>a)&&(a+c >b))
    {
        double s = (a+b+c)/2.0;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        return area;

    }
    else
    return -1;
}

int main() {
  float a, b, c;
  scanf("%f %f %f", &a, &b, &c);
  double res = area(a, b, c);
  if (res < 0)
    printf("invalid");
  else
    printf("%.2lf", res);
}*/
/*#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool is_perfect(unsigned m)
{
    int total =0;
    for(int i = 1;i<m;i++)
    {
        if(m%i == 0)
        {
            total+=i;
        }
    }
    if(total == m)
    {
        return true;
    }
    else
    return false;
}
static void print_perfect(unsigned a, unsigned b) {
  int c = 0;
  for (unsigned i = a; i <= b; ++i)
    if (is_perfect(i)) {
      ++c;
      printf("(%d)", i);
    }
  if (!c)
    printf("()");
  putchar('\n');
}
int main() {
  unsigned a, b;
  scanf("%u%u", &a, &b);
  print_perfect(a, b);
  return 0;
}*/
/**
 * 将压缩到一维数组的二维方阵还原
 * 首先要根据一维数组的非0元素个数m，计算二维方阵的阶数n。
 * 提示：n接近于sqrt(2m)
 *
 * 参数说明：
 *      -
 * a：int[]，存储压缩数据的一维数组。其中的第一个0值只表示结尾，不是压缩数据。
 *      - b：int[][MAXN]，待还原的方阵。
 * 返回值说明：
 *      - int。方阵的阶数。
 */
/*#include <math.h>
#include <stdio.h>
#define MAXN 512
int a[MAXN];
int b[MAXN][MAXN];

int restore_matrix(int a[], int b[][MAXN]) 
{
    int m = 0;
    while(a[m] != 0)
    {
        m++;
    }
    int n = sqrt(2*m);
    int c = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(i+j<n-1)
            b[i][j] = 0;
            else
            {
                b[i][j] = a[c];
                c++;
            }

        }
    }
    return n;
  
}
int main() {
  int i, j;
  i = 0;
  while (1) {
    scanf("%d", &a[i]);
    if (a[i] == 0)
      break;
    ++i;
  }
  int n = restore_matrix(a, b);
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
      printf("%d ", b[i][j]);
  putchar('\n');
  return 0;
}*/
/*对于原始字符串s和结果字符串t：
    - 指针p从s开头向后，找到第一个非空格字符；
    - 指针q从s尾部向前，找到第一个非空格字符；
    - 将指针p、q之间的字符复制到t中；
    - 字符串t封尾。
 * 去除字符串两端空格的函数trim
 * 将字符串开头和末尾的所有空格字符去除
 *
 * 参数说明：
 *      - s：char*，原始字符串
 *      - t：char*，去掉所有首尾空格后的字符串
 * 返回值说明：
 *      - 无*/

/*#include <stdio.h>
#include <string.h>
 
void trim(char *s, char *t) {
  char*p = &s[0];
  int i = 0;
  while(s[i] == ' ')
  {
    i++;
  }
  p = &s[i];
  int len = 0;
  while(s[len] != '\0')
  {
    len++;
  }
  
  int j = len-1;
  while(s[j] ==' ')
  {
    j--;
  }

  int c = 0;
  for(c = 0;c<=(j-i);c++)
  {
    t[c] = s[i+c];
  }
  t[c] = '\0';

}
#define MAXN 512
extern void trim(char *s, char *t);
int main() {
  char s[MAXN + 1], t[MAXN + 1];
  fgets(s, MAXN, stdin);
  char *p = strchr(s, '\n');
  if (p)
    *p = '\0';
  trim(s, t);
  printf("(%s)\n", t);
  return 0;
}*/
/** 用冒泡排序法对键值对数组按键进行排序（升序）
 *
 * 参数说明：
 *      - kv：int[]，键值对数组
 *      - n：int，数组长度
 * 返回值说明：
 *      - 无
 **/
/*#include <stdio.h>
#include <string.h>
typedef struct {
  char key[30]; // 用字符串表示的键
  int value;    // 基于简化的目的，数值的类型是int
} pair;
 
void sort_kv(pair kv[], int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            int l = strcmp(kv[j].key, kv[j+1].key);
            if(l>0)
            {
                pair tem = kv[j];
                kv[j] = kv[j+1];
                kv[j+1] = tem;

            }
        }
    }
}
pair kv[128]; // kv是键值对类型的数组
static void print_kv(pair kv[], int n) {
  for (int i = 0; i < n; ++i)
    printf("(%s=>%d)", kv[i].key, kv[i].value);
  putchar('\n');
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s%d", kv[i].key, &kv[i].value);
  sort_kv(kv, n);
  print_kv(kv, n);
  return 0;}*/
  /*#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int n = 0;
    scanf("%d",&n);
    if(n%3 == 0)
    sum+=n;
  }
  printf("%d\n", sum);
  return 0;
}*/



/*#include <stdio.h>

// 线性表的最大容量
#define CAPACITY  128

typedef struct {
    int len; // 线性表实际存储的元素个数
    int data[CAPACITY]; // 数组形式的存储空间。数据存储在该数组前len个单元中，后面的单元空置
} list;

@brief 判断线性表是否是非递减序列
@param list* 线性表的指针
@return int 如果是非递减序列返回1，否则返回0，并输出第一个违例的前后两项元素值

int is_non_decreasing(list *lst) {
 if(lst->len == 1)
 return 1;
 for(int i =0;i<lst->len-1;i++)
 {
    if(lst->data[i]>lst->data[i+1])
    {
      printf("%d %d\n",lst->data[i],lst->data[i+1]);
       return 0;
    }

 }
 return 1;
}

int main() {
  int N;
  scanf("%d", &N);
  list lst;
  lst.len = N;
  for (int i = 0; i < N; i++) {
    scanf("%d", &lst.data[i]);
  }
  if (is_non_decreasing(&lst)) {
    printf("yes\n");
  }
  return 0;
}*/

/*#include <stdio.h>

int main() {
    char c;
    char S[1001]; // len(S) ≤ 1000
    int count = 0;

    scanf("%c", &c);
    scanf("%s", S);
int i = 0;
    while(S[i] != '\0')
    {
      if(S[i] == c)
      {
        count++;
      }
      i++;
    }
  
printf("%d",count);
    return 0;
}*/
/*#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    // 你的代码写在 TODO 和 END OF TODO 之间。
    // 请勿修改这对标签外的任何代码！！！

    // TODO
    int bio[20] = {0};
    int i = 0;
    while(N != 0)
    {
      bio[i] = N%2;
      N = N/2;
      i++;
    }
    for(int j = i-1;j>=0;j--)
    {
      printf("%d",bio[j]);
    }
    // END OF TODO

    return 0;
}*/
#include <stdio.h>

// 你的代码写在 TODO 和 END OF TODO 之间。
// 请勿修改这对标签外的任何代码！！！

/*
@brief 统计水质合格的天数
@param n 检测天数
@return int 水质合格的天数
*/
int qualified(int n,int t) {
  // 在此函数中，需要用到整数输入
  // TODO
  int total = 0;
for(int i = 0;i<n;i++)
{
  int p = 0;
  scanf("%d",&p);
  if(p>=t)
total++;
}
return total;
  // END OF TODO
}

int main() {
  int N, T;
  scanf("%d", &N);
  scanf("%d", &T);

  printf("%d\n", qualified(N, T));
  return 0;
}
