/*
Filename: Task 3.c
Description: 

Define an appropriate structure type (use typdef) for the following:

    i) Point which stores the (real number valued) x and y coordinates of a point
    on a screen
    ii) Rectangle which stores the coordinates of two points: the upper left and lower
    right corners of a rectangle (use a nested structure).

Write functions which perform the following operations on a Rectangle structure r passed as an
argument:

    (a) Computer the area of r.
    (b) Compute the centre or r, returning it as a Point value.
    (c) Move r by x units in the x direction and y units in the y direction. Hint: in this case,
    the function arguments will be the values of x and y and a pointer to r

Author: James Matthews
Date: 10/03/2026
Version: 1.0
Log:
*/

#include <stdio.h>

// Structures

typedef struct{
    float x;
    float y;
} point;

typedef struct{
    point upperLeft;
    point lowerRight;
} rectangle;

// Function prototypes

float area(rectangle rect);
point centre(rectangle rect);
void translate(rectangle *rect, float x, float y);

int main(){
    rectangle r;
    float x, y;
    // Collects all coordinates and translation 
    printf("Enter the x coordinate of the upper left corner:");
    scanf("%f",&r.upperLeft.x);
    printf("Enter the y coordinate of the upper left corner:");
    scanf("%f",&r.upperLeft.y);
    printf("Enter the x coordinate of the lower right corner:");
    scanf("%f",&r.lowerRight.x);
    printf("Enter the y coordinate of the lower right corner:");
    scanf("%f",&r.lowerRight.y);
    printf("Enter x translation:");
    scanf("%f",&x);
    printf("Enter y translation:");
    scanf("%f",&y);
    printf("The area of the rectangle is: %.4f\n", area(r));
    printf("The centre of the rectangle is: (%.4f, %.4f)\n", centre(r).x, centre(r).y);
    translate(&r, x, y);
    printf("The new upper left corner is: (%.4f, %.4f)\n", r.upperLeft.x, r.upperLeft.y);
    printf("The new lower right corner is: (%.4f, %.4f)\n", r.lowerRight.x, r.lowerRight.y);



}

float area (rectangle rect){
    return (rect.lowerRight.x - rect.upperLeft.x) * (rect.upperLeft.y - rect.lowerRight.y);
}

point centre(rectangle rect){
    point centrePoint;
    centrePoint.x = (rect.upperLeft.x + rect.lowerRight.x) / 2;
    centrePoint.y = (rect.upperLeft.y + rect.lowerRight.y) / 2;
    return centrePoint;
}

void translate(rectangle *rect, float x, float y){
    rect->upperLeft.x += x;
    rect->upperLeft.y += y;
    rect->lowerRight.x += x;
    rect->lowerRight.y += y;
}