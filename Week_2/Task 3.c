#include <stdio.h>

int main(void){
    float speedMPH = 0;
    float speedKMH = 0;
    printf("Please enter speed in miles per hour: ");
    scanf("%f", &speedMPH);
    speedKMH = speedMPH * 1.60934;
    printf("Your speed in kilometers per hour is: %.5f\n", speedKMH);
}