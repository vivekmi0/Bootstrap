//Write a program to find the sum of n different numbers using 4 functions
#include<stdio.h>
int main()
{
    int number1,number2,sum;
    printf("Enter two numbers\n");
    scanf("%d%d",&number1,&number2);
    sum=number1+number2;
    printf("%d+%d=%d\n",number1,number2,sum);
    return 0;
}
