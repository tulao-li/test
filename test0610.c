/*#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef int OtherType;
typedef struct {
    KeyType key;
    OtherType other;
}RecordType;

void InsSort(RecordType R[],int len)
{
    if(len == 0)
    {
        return;
    }
    for(int i = 2;i<=len;i++)
    {
       
        R[0] = R[i];
        int j = i-1;
        while(R[j].key > R[0].key)
        {
            R[j+1] = R[j];
            j--;
        }
        R[j+1] = R[0];
    }
}
void BinSort(RecordType R[],int len)
{
    if(len == 0)
    {
        return;
    }
    RecordType x;
    for(int i = 2;i<=len;i++)
    {
        x = R[i];
        int low = 1;
        int high = i-1;
        int mid;
        while(low<= high)
        {
            mid = (low+high)/2;
            if(R[mid].key > x.key)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        for(int j = i-1;j>=low;j--)
        {
            R[j+1] = R[j];
        }
        R[low] = x;
    }
}
int main()
{
    int i,j;
    RecordType R[20];
    int len;
    printf("number?:");
    scanf(" %d",&len);
    for(i = 1;i<=len;i++)
    {
        printf("%d:",i);
        fflush(stdin);
        scanf(" %d",&j);
        R[i].key = j;
    }
    for(i=1;i<=len;i++)
        printf("%d  ",R[i].key);
    printf("\n");
    BinSort(R,len);
    for(i=1;i<=len;i++)
        printf("%d  ",R[i].key);
    printf("\n");
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef int OtherType;
typedef struct 
{
    KeyType key;
    OtherType other;
}RecordType;
void ShellInsert(RecordType R[],int len,int delta)
{
    if(len == 0)
    {
        return;
    }
    int j;
    for(int i = 1+delta;i<=len;i++)
    {
        if(R[i].key < R[i-delta].key)
        {
            R[0] = R[i];
            for(j = i-delta;i>0 && R[0].key < R[j].key;j-= delta)
            {
                R[j+delta] = R[j];
            }
            R[j+delta] = R[0];
        }
    }
}
void ShellSort(RecordType R[],int len,int delt[],int n)
{
    int i;
    for(i = 0;i<n-1;++i)
    {
        ShellInsert(R,len,delt[i]);
    }
}
int main()
{
    RecordType R[20];
    int len;
    int delta[3] = {4,2,1};
    printf("number??:");
    scanf(" %d",&len);
    int j = 0;
    for(int i = 1;i<=len;i++)
    {
        printf("%d??:",i);
        fflush(stdin);
        scanf("%d",&j);
        R[i].key = j;
    }
    for(int i=1;i<=len;i++)
		printf("%d  ",R[i].key);
	printf("\n");
	
	ShellSort(R,len,delta,3);
	for(int i=1;i<=len;i++)
		printf("%d  ",R[i].key);
	printf("\n");
}*/
/*#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType key;
	OtherType other_data;
}RecordType;*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int KeyType;
typedef int OtherType;
typedef struct 
{
    KeyType key;
    OtherType other;
}RecordType;
void   sift(RecordType  r[],  int k, int m)//堆调整
{
    int i = k;//根节点最后位置
    int left = k*2;
    
    RecordType f = r[k];
    int x = r[k].key;
    int max;//子节点中较大的那个的下标
    while(left<=m)
    {
         int right = left+1;
    // 只保留一次选max逻辑，删掉重复的177-184
    if(right > m)
        max = left;
    else
        max = r[left].key>r[right].key ? left:right;

    // 补上缺失的终止判断（核心修复）
    if(x >= r[max].key)
        break;

    r[i] = r[max];
    i = max;
    left = max*2;
    
    }
    r[i] = f;
}
void   crt_heap(RecordType r[], int length )//构建大项堆
{
    if(length == 0)
    {
        return;
    }
    for(int i = length/2;i>0;i--)
    {
        sift(r,  i, length);
    }
}
void  HeapSort(RecordType  r[],int length)//堆排序
{
    if(length == 0)
    {
        return;
    }
    for(int i = length;i>1;i--)
    {
        RecordType p = r[1];
        r[1] = r[i];
        r[i] = p;
        sift(r, 1, i-1);
    }
}
int main()
{
    int len;
    printf("How long?\n");
    scanf(" %d",&len);
    RecordType R[20];
    for(int i = 1;i<=len;i++)
    {
        printf("%d:",i);
        scanf(" %d",&(R[i].key));
    }
    for(int i = 0;i<len;i++)
    {
        printf("%d  ",R[i+1].key);
    }
    printf("\n");
    HeapSort(R,len);
    for(int i = 0;i<len;i++)
    {
        printf("%d  ",R[i+1].key);
    }
    return 0;
}
