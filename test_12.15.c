#include <stdio.h>

/*int main()
{
  const char*p = "sdsdfdfg";
  printf("%s\n",p);
  return 0;
}*/

/*int main()
{
  char*p1 = "asdfg";
   char*p2 = "asdfg";
  char arr1[] =  "asdfg";
  char arr2[] =  "asdfg";
  
  if(p1 == p2)
  {
    printf("equal\n");
  }
  else
  printf("not equal\n");
  if(arr1 == arr2)
  {
    printf("equal\n");
  }
  else
  printf("not equal\n");
  return 0;
}*/

/*int main()
{
  int arr1[] = {1,2,3,4,5};
  int arr2[]= {2,3,4,5,6};
  int arr3[] = {3,4,5,6,7}; 
  int*parr[] = {arr1,arr2,arr3};

  int n = sizeof(parr)/sizeof(parr[0]);
  for(int i = 0;i<n;i++)
  {
    for(int j = 0;j<5;j++)
    {
      printf("%d ",*(parr[i]+j));
    }
    printf("\n");
  }
  return 0;
}*/

int main()
{
  int arr[10] = {0};
  printf("%p\n",arr);
  printf("%p\n",arr+1);

  printf("%p\n",&arr[0]);
  printf("%p\n",&arr[0]+1);

  printf("%p\n",&arr);
   printf("%p\n",(&arr)+1);
   return  0;
} 