//Write a program to find the volume of a tromboloid using one function
#include <stdio.h>
#include <math.h>

int main()
{
    float h,d,b,volume;
    printf("enter the value");
    scanf("%f%f%f",&h,&d,&b);
    volume=((h*d*b)+(d/b))/3;
    printf("volume of tromboloid is:%.3f",volume);
    return 0;
}