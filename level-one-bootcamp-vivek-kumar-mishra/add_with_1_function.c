//Write a program to add two user input numbers using one function.
#include<stdio.h>
int val1(int x);
int val2(int y);
int sum(int x, int y);
void result(int r);
int main()
{
	int a,b,s=0;
	
	a=val1(a);
	b=val2(b);
	s=sum(a,b);
	result(s);
}
int val1(int x)
{
	printf("Enter the value=");
	scanf("%d",&x);
    return x;
}
int val2(int y)
{
	printf("Enter the value=");
	scanf("%d",&y);
    return y;
}
int sum(int x, int y)
{
	int r=0;
	r=x+y;
    return r;
}
void result(int r)
{
	printf("\nThe sum of the 2 given numbers is = %d",r);
}