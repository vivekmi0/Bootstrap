//WAP to find the sum of n complex numbers using structures and 4 or more functions.
#include <stdio.h>
int a[50],coun,sum=0;

int countt()
{
    printf("Enter the count for the total numbers: ");
    scanf("%d",&coun);
    return coun;
}
int input(int coun)
{
    printf("Enter the Numbers to be added:");
    for(int i =0;i<coun;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i =0;i<coun;i++)
    {
        sum=sum+a[i];
    }
    return sum;
}
int display()
{
    printf("The sum of the given numbers is: %d",sum);
}

int main()
{
    int n=countt();
    int s =input(n);
    display(s);
}