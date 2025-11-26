#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    int *p = (int*)calloc(3,sizeof(int));
    if(p == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }
    for(int i = 0;i<3;i++)
    {
        *(p+i) = i+1;
    }
    free(p);
    p = NULL;
    return 0;
}