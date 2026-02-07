#include <stdio.h>
#include <math.h>

float function(float x){
    const double PI = 3.14159265;
    return (float)(3*sin(x * PI) + 2*cos(x * PI));
}

int main(void){
    float startingValue = 0;
    float interval = 0;
    float currentX = 0;

    printf("Please enter the starting value: ");
    scanf("%f", &startingValue);
    printf("Please enter the interval: ");
    scanf("%f", &interval);
    printf("Value of x\tValue of f(x)\n");

    for(int i = 0; i < 4; i++){
        currentX = startingValue + i * interval;
        printf("%-10.4f\t%.4f\n", currentX, function(currentX));
    }
}