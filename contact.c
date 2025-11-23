#include "contact.h"

void menu()
{
    printf("**********************************\n");
    printf("******  1.add       2.del    *****\n");
    printf("******  3.search    4.modify *****\n");
    printf("******  5.show      6.sort   *****\n");
    printf("******  0.exit               *****\n");
    printf("**********************************\n");
}


int main()
{
    int input = 0;
    Contact con;//创建通讯录（可放100人）
    InitContact(&con);
    do
    {
        /* code */
        menu();
        printf("请选择：");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
            AddContact(&con);
            break;
            case 2:
            DelContact(&con);
            break;
            case 3:
            SearchContact(&con);
            break;
            case 4:
            ModContact(&con);
            break;
            case 5:
            ShowContact(&con);
            break;  
            case 6:
            SortContact(&con);
            break;
            case 0:
            printf("退出程序\n");
            break;
            default:
            printf("选择错误，请重新选择\n");
            Sleep(1000);
            break;
        }
    } while (input);
    return 0;
}