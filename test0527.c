/*#include <stdio.h>
//顺序查找
int search(int*arr,int len,int n)
{
    if(arr == NULL)
    {
        return 0;
    }
    for(int i = 0;i<len;i++)
    {
        if(n == arr[i])
        {
            return i+1;
        }
    }
    return 0;
}
//折半查找
int binary_search(int*arr,int len,int value)
{
    if((arr == NULL)||(len == 0))
    {
        return 0;
    }
    int low  =0;
    int high = len-1;
    int mid;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(value == arr[mid])
        {
            return mid+1;
        }
        else if(value> arr[mid])
        {
            low = mid+1;
        }
        else  if(value < arr[mid])
        {
            high = mid-1;
        }
    }
    return 0;
}
int main()
{
    int arr[] = {5,6,26,45,48,55,65,98,100,125};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pos = search(arr,n,5);
    int pos2 = binary_search(arr,n,55);
    printf("%i %i\n",pos,pos2);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#define ENDKEY 0
typedef int KeyType;
typedef struct node
{
    KeyType key;
    struct node* lchild;
    struct node* rchild;
}BSTNode,*BSTree;
//递归查找
BSTree SearchBST1(BSTree T,KeyType key)
{
    if(T == NULL)
    {
        return NULL;
    }
    if(key == T->key)
    {
        return T;
    }
    if(key > T->key)
    {
        return SearchBST1(T->rchild,key);
    }
    if(key < T->key)
    {
        return SearchBST1(T->lchild,key);
    }
}
//非递归查找
BSTree SearchBST2(BSTree T,KeyType key)
{
    if(T == NULL)
    {
        return NULL;
    }
    BSTree pos = T;
    while(pos != NULL)
    {
        if(pos->key == key)
        {
            return pos;
        }
        else if(pos->key < key)
        {
            pos = pos->rchild;
        }
        else if(pos->key > key)
        {
            pos = pos->lchild;
        }
    }
    return NULL;
}    
//递归插入
void InsertBSTree1(BSTree*T,KeyType value)
{
    if(*T == NULL)
    {
        BSTree newnode = (BSTree)malloc(sizeof(BSTNode));
        if(newnode == NULL)
        {
            printf("Memory allocation error.\n");
            return;
        }
        newnode->key = value;
        newnode->lchild = NULL;
        newnode->rchild = NULL;
        (*T) = newnode;
    }
    else if((*T)->key < value)
    {
        InsertBSTree1(&(*T)->rchild,value);
    }
    else if((*T)->key > value)
    {
         InsertBSTree1(&(*T)->lchild,value);
    }
    else
    {
        return;
    }
    return ;
}
//非递归插入
void InsertBST2(BSTree*T,KeyType value)
{
    BSTree p,parent;
    p = *T;
    while(p!= NULL)
    {
        parent = p;
        if(p->key < value)
        {
            p = p->rchild;
        }
        else if(p->key > value)
        {
            p = p->lchild;
        }
        else
        {
            return;
        }
    }
    BSTree newnode = (BSTree)malloc(sizeof(BSTNode));
    if(newnode == NULL)
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newnode->key = value;
    newnode->lchild = newnode->rchild = NULL;
    if(parent == NULL)
    {
        *T = newnode;
    }
    else if(parent->key < value)
    {
        parent->rchild = newnode;
    }
    else if(parent->key > value)
    {
        parent->lchild = newnode;
    }
}
int main()
{
    BSTree T;
    int k;//要查找的关键字
    BSTree result1,result2;

}


