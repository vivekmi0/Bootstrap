//WAP to find the sum of n fractions.
#include<stdio.h>
struct fraction 
{
    int num;
    int deno;
};
typedef struct fraction Fract;
Fract input()
{
    Fract f;
    printf("Enter the numerator: ");
    scanf("%d",&f.num);
    printf("Enter the denominator: ");
    scanf("%d",&f.deno);
    return f;
}

void input_n(Fract f1[],int *n)
{
    printf("Enter the number of fractions: \n");
    scanf("%d", n);
    printf("Enter the values of the fraction\n");
    for(int i=0; i<*n; i++)
    {
         f1[i] = input();
    }
    
}

Fract sum(Fract f1, Fract f2)
{
    Fract f3;
    f3.num=(f1.num*f2.deno)+(f2.num*f1.deno);
    f3.deno = f1.deno*f2.deno;
    int g = gcd(f3.num,f3.deno);
    f3.num = f3.num/g;
    f3.deno = f3.deno/g;
    return f3;
}

Fract sum_n(Fract f1[], int n)
{
    Fract f3;
    f3.num = 0;
    f3.deno = 1;
    for(int i=0;i<n; i++)
    {
        f3 = sum(f1[i],f3);
    }
    return f3;
}

int gcd(int a, int b)
{
    int i,gcd=1,temp;
    if( a < b) 
    {
          temp = a;
          a=b;
          b=temp;
    }
    if ( a % b == 0) 
    {
       return b;
     }
 
    for ( i = b/2; i >=2 ; i--)
    {
        if( a%i == 0 && b%i==0)
	return i;
    }
    return gcd;
}

void output(Fract f1[], Fract f3, int n)
{
    printf("The sum of ");
    for(int i=0; i<n; i++)
    {
        if(i<n-1)
        printf("%d/%d + ", f1[i].num,f1[i].deno);
        else
        printf("%d/%d", f1[i].num,f1[i].deno);
    }
    printf(" is %d/%d ", f3.num, f3.deno);
}

int main()
{
    Fract f1[100],f3;
    int n;
    input_n(f1,&n);
    f3 = sum_n(f1,n);
    output(f1,f3,n);
    return 0;
}