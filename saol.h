#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10

void menu(void);
void game(void);
void Initboard(char board[ROWS][COLS],int rows,int cols,char set);
void PrintBoard(char broad[ROWS][COLS],int row,int col);
void Setlei(char broad[ROWS][COLS],int row,int col);
void paicha(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
int number_lei(char mine[ROWS][COLS],int x,int y);


void Initboard(char board[ROWS][COLS],int rows,int cols,char set)
{
    int i = 0,j = 0;
    for(i = 0;i<rows;i++)
    {
        for(j = 0;j<cols;j++)
        {
            board[i][j] = set;
        }
    }
}

void PrintBoard(char board[ROWS][COLS],int row,int col)
{
    printf("**************扫雷游戏******************\n");
    printf("  ");
    for(int j = 1;j<=col;j++)
    {
        printf("%d ",j);
    }
    printf("\n");
    for(int i = 1;i<=row;i++)
    {
        printf("%d ",i);
        for(int j = 1;j<=col;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("**************扫雷游戏******************\n");
}

void menu()
{
    printf("*********************************\n");
    printf("***********  1.play *************\n");
    printf("***********  0.exit *************\n");
    printf("*********************************\n");
}

void Setlei(char board[ROWS][COLS],int row,int col)
{
    int count = COUNT;
    do
    {
        int n = rand()%row+1;
        int m =rand()%col+1;
        if(board[n][m] == '0')
         {
            board[n][m] = '1';
            count--;
         }
    } while (count);
}

int number_lei(char mine[ROWS][COLS],int x,int y)
{
    int flag = 0;
    for(int i = -1;i<=1;i++)
    {
        for(int j = -1;j<=1;j++)
        {
            if(mine[x+i][y+j] == '1')
            flag = flag+1;
        }
    }
    return flag;
}

void paicha(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x = 0,y = 0;
    int win = 0;
   while(win < row*col - COUNT)
    {
        printf("请输入坐标:");
        scanf(" %d %d",&x,&y);
        if(x>0&&x<=row&&y>0&&y<=col)
        {
            if(mine[x][y] == '1')
                {
                    printf("你被炸死了\n");
                    return;
                }
                else if(show[x][y] == '*')
                {
                    win++;
                    int ret = number_lei(mine ,x,y);
                    show[x][y] = ret+'0';
                    PrintBoard(show,ROW,COL);
                    if(win == row*col - COUNT)
                    printf("玩家胜利！\n");
                }
                else if(show[x][y] != '*')
                {
                    printf("已排查过，请重新选择\n");
                }
        }
        else
        {
            printf("选择非法，请重新选择\n");
        }
    }
}
