#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 10
#define INFINITY 9999
#define Error -1
typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef char VertexData;
typedef struct ArcNode
{
    int tailvex,headvex;
    struct ArcNode*hlink,*tlink;
}ArcNode;//边结点结构

typedef struct VertexNode
{
    VertexData data;
    ArcNode*firstin;
    ArcNode*firstout;
}VertexNode;//顶点结点

typedef struct 
{
    VertexNode vertex[MAX_VERTEX_NUM];
    int vexnum;
    int arcnum;
    GraphKind kind;
}OrthList;
int LocateVertex(OrthList*G,VertexData v)
{
    if(G == NULL)
    {
        return -1;
    }
    for(int i = 0;i<G->vertex;i++)
    {
        if(v == G->vertex[i].data)
        {
            return i;
        }
    }
    return -1;
}
void CrtOrthList(OrthList*G)
{
    if(G == NULL)
    {
        printf("Input error.\n");
        return;
    }
}
int main()
{
    OrthList g;
    return 0;
}

