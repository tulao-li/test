#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct CSNode
{
    DataType data;
    struct CSNode*FirstChild;
    struct CSNode*Nextsibiling;
}CSNode,*CSTree;

CSNode*find(CSTree root,char value)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == value)
    {
        return root;
    }
    CSNode*result = find(root->FirstChild,value);
    if(result != NULL)
    {
        return result;
    }
    return find(root->Nextsibiling,value);
}
void clearBuffer()
{
    while(getchar()!= '\n');
}
