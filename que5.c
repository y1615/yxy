#include<stdio.h>
int main()
{
    int A[2][3]={{1,2,3},{4,5,6}};
    int i,j;
    printf("row:\n");
    for(i=0;i<2;i++)
  {
    for(j=0;j<3;j++)
   {printf("%d",A[i][j]);}
  } 
   printf("\n");
   printf("col:\n");
    for(j=0;j<3;j++)
  {
    for(i=0;i<2;i++)
   {printf("%d",A[i][j]);}
  } return 0;
}
