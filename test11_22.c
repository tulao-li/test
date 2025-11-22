#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
/*int main()
{
    int*p = (int*)calloc(10,sizeof(int));
    if(p == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;

    }
    for(int i = 0;i<10;i++)
    {
        printf("%i  ",*(p+i));
    }
    free(p);
    p = NULL;
      
    return 0;
}*/
int main()
{
    int*p = (int*)malloc(40);
    if(NULL == p)
    {
        printf("%s\n",strerror(errno));
    }
    for(int i = 0;i<10;i++)
    {
        *(p+i) = i+1;
    }
    int*ptr = (int*)realloc(p,80);
    if(ptr!= NULL)
    {
        p = ptr;
    }
    for(int i = 0;i<10;i++)
    {
        printf("%i  ",*(p+i));
    }
    free(p);
    p = NULL;
    return 0;
}