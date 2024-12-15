#include <stdio.h>
//Bubble sort function
void bubbleSort(int arr[],int n)
{
  int i,j;
     for(i=0;i<n-1;i++)
  {
     for(j=0;j<n-i-1;j++)
    {
     if(arr[j]>arr[j+1])
     {int temp=arr[j]; arr[j]=arr[j+1]; arr[j+1]=temp;}
    }
  }
}
//Print array function
void printArray(int arr[],int size)    
{
    for(int i=0;i<size;i++)
    printf("%d ",arr[i]);  printf("\n");
}

int main() {
    int arr[]={55,20,10,17,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("former:");  printArray(arr,n);
    bubbleSort(arr,n);
    printf("later:");   printArray(arr,n);
    return 0;
}
