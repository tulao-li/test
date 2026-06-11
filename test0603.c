#include <stdio.h>
#include <stdlib.h>

void swap(int * data,int m,int n)
{
    int tem = data[m];
    data[m] = data[n];
    data[n] = tem;
}

// 标准无BUG大顶堆调整
void adjust(int data[], int pos, int length)
{
    int val = data[pos];
    // 左孩子下标
    int k = pos * 2;
    while(k <= length)
    {
        // 选左右孩子中大的
        if(k+1 <= length && data[k] < data[k+1])
            k++;
        if(val < data[k])
        {
            data[pos] = data[k];
            pos = k;
            k = pos*2;
        }
        else
            break;
    }
    data[pos] = val;
}

void heapSort(int data[], int len)
{
    // 建大顶堆
    for(int i = len/2; i >= 1; i--)
        adjust(data,i,len);
    // 堆排序交换
    for(int i = len; i>1; i--)
    {
        swap(data,1,i);
        adjust(data,1,i-1);
    }
}

int main()
{
    int data[] = {-1,47,35,60,95,77,15,28};
    int arr_len = sizeof(data)/sizeof(data[0])-1;
    heapSort(data,arr_len);

    for(int i=1; i<=arr_len; i++)
    {
        printf("%d ",data[i]);
    }
    system("pause");
    return 0;
}