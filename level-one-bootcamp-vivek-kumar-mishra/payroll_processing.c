// Write the payroll processing program

#include<stdio.h>
#include<string.h>
typedef struct type_one
{
    char name[100];
    float wage;
    float hour;
    float gross;
}t1;
typedef struct type_two
{
    char name1[100];
    int min;
}t2;
void input_type1(int ntc, t1 *ptr)
{
    for(int i=0;i<ntc;i++)
    {
        scanf("%s %f",ptr->name,&ptr->wage);
        ptr++;
    }
}
void input_type2(int nc,t2 *ptr)
{
    for(int i=0;i<nc;i++)
    {
        scanf("%s %d",ptr->name1,&ptr->min);
        ptr++;
    }
}
void compute(int ntc, int nc, t1 *ptr1, t2 *ptr2)
{
    t2 *temp=ptr2;
    for(int i=0;i<ntc;i++)
    {
        ptr2=temp;
        ptr1->hour=0.0;
        ptr1->gross=0.0;
        for(int j=0;j<nc;j++)
        {
            if(strcmp(ptr1->name,ptr2->name1)==0)
            {
                ptr1->hour+=ptr2->min/60.0;
                if((ptr2->min/60.0)<=40.0)
                    ptr1->gross+=(ptr1->wage*ptr2->min/60.0);
                else
                    ptr1->gross+=(ptr1->wage*40.0+(ptr2->min/60.0)-40.0*1.5*ptr1->wage);
            }
            ptr2++;
        }
        ptr1++;
    }
}
void display(int ntc, t1 *ptr)
{
    for(int i=0;i<ntc;i++)
    {
        if(ptr->gross>0)
            printf("%s: %.2f hours, $%.2f\n",ptr->name,ptr->hour,ptr->gross);
        ptr++;
    }
}
int main(void)
{
    int ntc;
    scanf("%d",&ntc);
    t1 arr1[ntc];
    input_type1(ntc,arr1);
    int nc;
    scanf("%d",&nc);
    t2 arr2[100];
    input_type2(nc,arr2);
    compute(ntc,nc,arr1,arr2);
    display(ntc,arr1);
    return 0;
}