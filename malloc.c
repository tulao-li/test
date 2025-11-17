#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main()
{
    int*p = (int*)malloc(40);
    if(p == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }
    else
    {
        for(int i = 0;i<14;i++)
        {
            *(p+i) = i;
        }
        for(int i = 0;i<14;i++)
        {
            printf("%d  ",*(p+i));
        }
    }
    return 0;
}