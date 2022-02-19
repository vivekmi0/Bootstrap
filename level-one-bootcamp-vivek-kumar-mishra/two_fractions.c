//WAP to find the sum of two fractions.
#include<stdio.h>

typedef struct
{
	int num,denom;
}frac;
frac input1()
{
	frac a;
    printf(" Enter numerator of frac 1 : ");
	scanf("%d",&a.num);
	printf(" Enter denominator of frac 1 : ");
	scanf("%d",&a.denom);
	return a;
}
frac input2()
{
	frac b;
    printf(" Enter numerator of frac 2 : ");
	scanf("%d",&b.num);
	printf(" Enter denominator of frac 2 : ");
	scanf("%d",&b.denom);
	return b;
}
int gcd_calc(int a,int b)
{
	int gcd;
	for(int i=1;i<=a && i<=b;i++)
	{
		if(a%i==0 && b%i==0)
			gcd=i;
	}
	return gcd;
}
frac add(frac a, frac b)
{
	frac sum;
	sum.num=(a.num*b.denom)+(b.num*a.denom);
	sum.denom=a.denom*b.denom;
	int h=gcd_calc(sum.num,sum.denom);
	sum.num=sum.num/h;
	sum.denom=sum.denom/h;
	return sum;
}
void print(frac a,frac b,frac f)
{
	printf("The sum fraction is %d/%d",f.num,f.denom);
}
int main()
{
    frac a,b,f;
 	a=input1(a);
	b=input2(b);
	f=add(a,b);
	print(a,b,f);
}