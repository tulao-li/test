#include "saol.h"
int main()
{
    int input = 0;
    do
    {
       menu();
       printf("请选择：");
       scanf(" %d",&input);
       switch(input)
       {
        case 1:
        game();
        break;
        case 0:
        printf("游戏结束\n");
        break;
        default:
        printf("选择错误，请重新选择\n");
        break;
       }

    } while (input);
    return 0;
}

void game()
{
    srand((unsigned int )time(NULL));
    char mine[ROWS][COLS];
    char show[ROWS][COLS];
    Initboard(mine,ROWS,COLS,'0');//初始化雷数组
    Initboard(show,ROWS,COLS,'*');//初始化展示数组
    PrintBoard(show,ROW,COL);
    Setlei(mine,ROW,COL);
    paicha(mine,show,ROW,COL);
    PrintBoard(mine,ROW,COL);
}