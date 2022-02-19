// Write The Hspc Program Rectangle Area

#include <stdio.h>
#include <math.h>
typedef struct vertex
{
    float x;
    float y;
} ver;
typedef struct vertices
{
    ver three_vertices[3];
} vert;
struct vertices input()
{
    vert data;
    printf("Enter the coordinates of the rectangle:\n");
    scanf("%f %f", &data.three_vertices[0].x, &data.three_vertices[0].y);
    scanf("%f %f", &data.three_vertices[1].x, &data.three_vertices[1].y);
    scanf("%f %f", &data.three_vertices[2].x, &data.three_vertices[2].y);
    return data;
}
float distance(ver v1, ver v2)
{
    return (sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2)));
}
float Compute(vert data)
{
    float area;
    float dist01 = distance(data.three_vertices[0], data.three_vertices[1]);
    float dist02 = distance(data.three_vertices[0], data.three_vertices[2]);
    float dist12 = distance(data.three_vertices[1], data.three_vertices[2]);
    if(dist01>=dist02 && dist01>=dist12)
    {
        area=dist02*dist12;
    }
    else if(dist02>=dist01 && dist02>=dist12)
    {
        area=dist01*dist12;
    }
    else
    {
        area=dist01*dist02;
    }
    return area;
}
void display(vert data, float area)
{
printf("Area of rectangle with vertices (%.1f,%.1f),(%.1f,%.1f),(%.1f,%.1f) is %.1f\n", data.three_vertices[0].x, data.three_vertices[0].y, data.three_vertices[1].x, data.three_vertices[1].y, data.three_vertices[2].x, data.three_vertices[2].y, area);
}
int main()
{
    int nRectangle;
    float area;
    scanf("%d", &nRectangle);
    vert rectangles[nRectangle];
    for (int i = 0; i < nRectangle; i++)
        rectangles[i] = input();
    for (int i = 0; i < nRectangle; i++)
    {
        area = Compute(rectangles[i]);
        display(rectangles[i], area);
    }
    return 0;
}