#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 10
#define INFINITY 9999
#define True 1
#define False 0
#define Error -1
#define Ok 1
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef char VertexData;
typedef struct ArcNode
{
    int adj;//adjacent
}ArcNode;

typedef struct 
{
   VertexData vexs[MAX_VERTEX_NUM];//顶点数组
   ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
   int vexnum;//顶点数
   int arcnum;//边数
   GraphKind kind;
}AdjMatrix;

int LocateVertex(AdjMatrix *G,VertexData v);//定位顶点
int CreateDN(AdjMatrix *G);//邻接矩阵创建有向图
void PrintMatrix(AdjMatrix*G);//打印
int main()
{
    AdjMatrix G;
    CreateDN(&G);
    PrintMatrix(&G);
    return 0;
}
int LocateVertex(AdjMatrix *G,VertexData v)
{
    if(G == NULL)
    {
        return -1;
    }
    for(int i = 0;i<G->vexnum;i++)
    {
        if(v == G->vexs[i])
        {
            return i;
        }
    }
    return -1;
}
int CreateDN(AdjMatrix *G)
{
    if(G == NULL)
    {
        printf("wrong\n");
        return -1;
    }
    printf("Please enter the number of vertices and arcs of the graph(e.g.3 4)\n");
    scanf(" %d %d",&(G->vexnum),&(G->arcnum));
    G->kind = DG;
    //初始邻接矩阵，全部为无穷大
    for(int i = 0;i<G->vexnum;i++)
    {
        for(int j = 0;j<G->vexnum;j++)
        {
            G->arcs[i][j].adj = INFINITY;
        }
    }
    //得到顶点字符
    for(int i = 0;i<G->vexnum;i++)
    {
        printf("Please enter the character of th %d-th vertex:",i+1);
        scanf(" %c",&(G->vexs[i]));
    }
    //得到每条边
    char v1;
    char v2 = 0;
    int wei = 0;
    int n1 = 0;
    int n2 = 0;
    for(int i = 0;i<G->arcnum;i++)
    {
        printf("Please enter two vertices and weight of the %d-th edge(e.g.A B 5)\n");
        scanf(" %c %c %d",&v1,&v2,&wei);
        n1 = LocateVertex(G,v1);
        n2 = LocateVertex(G,v2);
        if((n1 == -1)||(n2 == -1))
        {
            printf("Error.Vertex does not exist,skip the edge.\n");
            continue;
        }
        G->arcs[n1][n2].adj = wei;
    }
    return 0;
}
void PrintMatrix(AdjMatrix*G)
{
    if(G == NULL)
    {
        return;
    }
    printf("The adjacency matrix is as follows.\n");
    for(int i = 0;i<G->vexnum;i++)
    {
        for(int j = 0;j<G->vexnum;j++)
        {
            if(G->arcs[i][j].adj == INFINITY)
            {
                printf(" - ");
            }
            else
            {
                printf("%2d ",G->arcs[i][j].adj);
            }
        }
        printf("\n");
    }
    return;
}