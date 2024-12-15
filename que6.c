#include<stdio.h>
int two_dim_array_access(int*x,int i,int j,int m,int n,int C)
{
    int index=m*C+n;//Calculate the index of the target element in a array
    int*target=x+index;//Calculate the address of the target element
    return*target;
}
int main()
{
    int A[2][3]= {{1,2,3},{4,5,6}};
    int C=3;
    int result=two_dim_array_access(&A[0][0],0,0,1,1,C);
    printf("A[1][1] is:%d\n",result);
    return 0;
}
