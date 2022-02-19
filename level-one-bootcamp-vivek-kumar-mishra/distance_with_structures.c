//WAP to find the distance between two points using structures and 4 functions.
#include <stdio.h>
#include <math.h>
struct point
{
    float x;
    float y;
};
typedef struct point Point;
Point input_coordinates()
{
    Point pt;
    printf("Enter the x coordinate\n");
    scanf("%f",&pt.x);
    printf("Enter the y coordinate\n");
    scanf("%f",&pt.y);
    return pt;
}
float compute(Point p1,Point p2)
{
    float distance;
    distance=sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
    return distance;
}
void output(Point p1, Point p2, float dist)
{
    printf("The distance between (x1,y1) i.e. (%f,%f) and (x2,y2) i.e. (%f,%f) is %f",p1.x,p1.y,p2.x,p2.y,dist);
}
int main(void)
{
    float dist;
    Point p1,p2;
    p1=input_coordinates();
    p2=input_coordinates();
    dist=compute(p1,p2);
    printf("\n x1=%f, x2=%f, y1=%f, y2=%f\n\n",p1.x,p2.x,p1.y,p2.y);
    output(p1,p2,dist);
    return 0;
}