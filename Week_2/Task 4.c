#include <stdio.h>
#include <math.h>

int main(void){
    float height = 0;
    float length = 0;
    float hyp = 0;
    float area = 0;
    float perimeter = 0;
    printf("Please enter the height of the triangle: ");
    scanf("%f", &height);
    printf("Please enter the length of the triangle: ");
    scanf("%f", &length);
    hyp = sqrt((height * height) + (length * length));
    area = height * length * 0.5;
    perimeter = height + length + hyp;
    printf("The area of the triangle is: %.4f\n", area);
    printf("The perimeter of the triangle is: %.4f\n", perimeter);
}