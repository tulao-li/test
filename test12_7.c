#include <stdio.h>
#include <errno.h>
#include <string.h>
/*int  main()
{
    FILE* pf = fopen("test.txt","r");
    if(pf == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }
   
    for(int i = 0;i<26;i++)
    {
      char c = fgetc(pf);
      printf("%c ",c);
    }
    fputc('a',pf);
    fclose(pf);
    pf = NULL;
    return 0;
}*/
struct S
{
    char name[20];
    int age;
    float score;
};
/*int main()
{
    struct S s1 = {0};

    FILE*pf = fopen("contact.txt","r");
    if(pf == NULL)
    {
        perror("文件阅读：");
        return 1;
    }
    fscanf(pf,"%s  %d  %f",s1.name,&s1.age,&s1.score);
    printf("%s  %d  %.2f",s1.name,s1.age,s1.score);
    fclose(pf);
    pf = NULL;
    return 0;
}*/
int main()
{
    struct S s1 = {"zhangsan",55,9.23};
    char buf[100] = {0};
    sprintf(buf ,"%s  %d  %f",s1.name,s1.age,s1.score);
    printf("%s\n",buf);
    return 0;
}