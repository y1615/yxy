#include<stdio.h>
//Matrix multiplication function
void matrix_mukti(double A[3][4],double B[4][5],double C[3][5])
{
     for(int i=0;i<3;i++)
  {
     for(int j=0;j<5;j++)
   {
     C[i][j]=0; 
     for(int k=0;k<4;k++) {C[i][j]+=A[i][k]*B[k][j];}//Calculate according to the rules of matrix multiplication
   }
  }
}
//Test function
void test_matrix_multi()
{
double A[3][4]={{1.0,2.0,3.0,4.0},{5.0,6.0,7.0,8.0},{9.0,10.0,11.0,12.0}};
double B[4][5]={{1.0,2.0,3.0,4.0,5.0},{6.0,7.0,8.0,9.0,10.0},{11.0,12.0,13.0,14.0,15.0,},{16.0,17.0,18.0,19.0,20.0}};
double C[3][5];
     matrix_mukti(A,B,C);
//Print result matrixC
     printf("reslut C:\n");
     for(int i=0;i<3;i++)
  {
     for(int j=0;j<5;j++)
    {printf("%f",C[i][j]);}
     printf("\n");
  }
}
int main()
{
    test_matrix_multi();
    return 0;
}
