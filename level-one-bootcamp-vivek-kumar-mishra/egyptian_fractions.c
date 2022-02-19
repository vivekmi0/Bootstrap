//Write the Egyptian Fractions

#include<stdio.h>

typedef struct fraction
{
      int num, den;

}Fraction;

typedef struct egyptian_fraction
{
      int n;
      int unit_fraction[100];
      Fraction sum;
}Egyptian_fraction;

Egyptian_fraction input_1()
{
      Egyptian fraction f;
      printf(“Enter n: \n”);
      scanf(“%d”, &f.n);
      
      for(int i=0; i<f.n; i++)
      {
            printf(“Enter the denominator of unit fraction: \n”);
            scanf(“%d”, &f.unit_fraction[i]);
      }
      return f;
}

void input_n(int n, Egyptian_fraction[n])
{
      for(int i=0; i<n; i++)
      {
            f[i] = input_1();
      }
}
Fraction add_2_unit_fractions(Fraction f, int d)
{
             Fraction rf;
             rf.num = d + f.den;
             rf.den = f.den *d;
             int gcd = find_gcd(rf.num, rf.den);
            rf.num /= gcd;
            rf.den /=gcd;
            return rf;
}

int get_gcd(int n, int d)
{
       int gcd;
       for(int i=2; i<=n && i<=d; i++)
       {
              if(n%i == 0 && d%1 == 0)
              {
                      gcd = i;
              }
       }
       return gcd;
}

void compute_1(Egyptian_fraction *f)
{
       int g=0;
       for(int i=0; i<f.n; i++)
       {
             g = gcd(g, f.unit_fraction[i])
       }
}


void compute_n(int n, Egyptian_fraction f[n])
{
       for(int i=0; i<n; i++)
       {
             compute_1(&f[i]);
       }
}
void output_1(Egyptian_fraction f)
{
       for(int i=0; i<f.n; i++)
      {
            printf(“ 1/%d”, f.unit_fraction[i]);
      }
      printf(“Egyptian fraction = %d/%d \n”, f.sum.num, f.sum.den);
}

void output_n(int n, Egyptian_fraction f[n])
{
      for(int i=0; i<n; i++)
      {
           output_1(f[i]);
      }
}

int main()
{
      int n;
      printf(“Number of problems\n”);
      scanf(“%d”, &n);
      Egyptian_fraction f[n];
      input_n(n,f);
      compute_n(n,f);
      output_n(n,f);
      return 0;
}