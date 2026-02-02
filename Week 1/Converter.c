#include <stdio.h>

int main() {
    float speedmph, speedms = 0.0;
    printf("Enter speed in meters per second: ");
    scanf("%f", &speedms);
    speedmph = speedms * 2.23694;
    printf("Speed in miles per hour is: %.5f", speedmph);
}