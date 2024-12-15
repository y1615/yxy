#include<stdio.h>
#include "module.h"
int main()
{
    printf("Function 1 returns:%d\n",function1());
    printf("Function 2 returns:%d\n",function2());
    printf("Global variable:%d\n",global_variable);
    return 0;
}
