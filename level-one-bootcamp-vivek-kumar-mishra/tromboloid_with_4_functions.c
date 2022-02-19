//WAP to find the volume of a tromboloid using 4 functions.
#incude <stdio.h>
float input();
float calc(float,float,float);
int main()
{
input();
return0;
}
float calc(float h,float d,float b)
{
float v;
v=((0.33)*((h*d)+d))/b;
return(v);
{
float input()
{
float x,y,z,volume;
printf("Enter the h=");
scanf(%f",&x);
printf("enter the d=");
scanf("%f",&y);
printf(Enter the b=");
scanf("%f",&z);
volume=calc(x,y,z);
printf("The Volume is=%f",volume);
return 0;
