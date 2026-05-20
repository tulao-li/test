#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* HuffmanCode;
typedef struct 
{
    unsigned int weight;
    unsigned int parent,LChild,RChild;
}HTNode,*HuffmanTree;

void select(HuffmanTree ht,int n,int *s1,int*s2)
{
    int min1 = 0;
    int min2 = 0;
    for(int i = 1;i<=n;i++)
    {
        if(ht[i].parent == 0)
        {
            if((min1 == 0)||(ht[min1].weight>ht[i].weight))
            {
                min2 = min1;
                min1 = i;
            }
            else if((min2 == 0)||(ht[min2].weight >ht[i].weight))
            {
                min2 = i;
            }
        }
    }
    *s1 = min1;
    *s2 =  min2;
}
void CrtHuffmanTree(HuffmanTree*ht,int*w,int n)
{
    int m = 2*n - 1;//所有节点数
    *ht = (HuffmanTree)malloc(sizeof(HTNode)*(m+1));
    if((*ht) == NULL)
    {
        return;
    }
    for(int i = 1;i<=n;i++)
    {
        (*ht)[i].weight = w[i];
        (*ht)[i].LChild = 0;
        (*ht)[i].RChild = 0;
        (*ht)[i].parent = 0;
    }//初始化（叶子节点）
    for(int i = n+1;i<=m;i++)
    {
        (*ht)[i].weight = 0;
        (*ht)[i].LChild = 0;
        (*ht)[i].RChild = 0;
        (*ht)[i].parent = 0;
    }//初始化
    for(int i = (n+1);i<=m;i++)
    {
        int s1 ,s2;
        select(*ht,i-1,&s1,&s2);
        (*ht)[i].weight = (*ht)[s1].weight + (*ht)[s2].weight;
        (*ht)[i].LChild = s1;
        (*ht)[i].RChild = s2;
        (*ht)[s1].parent = i;
        (*ht)[s2].parent = i;
    }
}
void outputHuffmanTree(HuffmanTree HT,int m)
{
    if(m!= 0)
    {
        printf("%d   ",HT[m].weight);
        outputHuffmanTree(HT,HT[m].LChild);
        outputHuffmanTree(HT,HT[m].RChild);
    }
}
void CrtHuffmanCode(HuffmanTree *ht,HuffmanCode**hc,int n)
{
    int start = n-1;
    int c = 1;
    int p = 0;
    char*cd;
    cd = (char*)malloc(sizeof(char)*n);
    if(cd == NULL)
    {
        return;
    }
    cd[n-1] = '\0';
    *hc = (HuffmanCode*)malloc(sizeof(HuffmanCode)*(n+1));
    if((*hc) == NULL)
    {
        return;
    }
    for(int i = 1;i<=n;i++)
    {
        start = n-1;
        for(c = i,p = (*ht)[i].parent;p != 0;c = p,p = (*ht)[p].parent)
        {
            if(c == (*ht)[p].LChild)
            {
                start--;
                cd[start] = '0';
            }
            else if(c == (*ht)[p].RChild)
            {
                start--;
                cd[start] = '1';
            }
        }
        (*hc)[i] = (char*)malloc((n - start) * sizeof(char));
        if((*hc)[i] == NULL)
        {
            return;
        }
        strcpy((*hc)[i],&cd[start]);
    }
    free(cd);
    for(int i = 1;i<=n;i++)
    {
        printf("Weight %d: %s\n",(*ht)[i].weight,(*hc)[i]);
    }
}
int main()
{
    HuffmanTree HT;
    HuffmanCode *HC;
    int *w;
    int i = 0;
    int n;
    int m;
    printf("Enter number of leaf nodes:");
    scanf("%d",&n);
    w = (int*)malloc(sizeof(int)*(n+1));
    for(i = 1;i<=n;i++)
    {
        printf("Enter weight of node %d:",i);
        scanf("%d",&w[i]);
    }
    CrtHuffmanTree(&HT,w,n);
    m = 2*n-1;
    printf("\nPreorder traversal of Huffman Tree:\n");
    outputHuffmanTree(HT, m);
    printf("\n\n 6.21 Huffman Codes:\n");
    CrtHuffmanCode(&HT, &HC, n);
     for (i = 1; i <= n; i++)
        free(HC[i]);
    free(HC);
    free(HT);
    free(w);

    return 0;
}