/*
Filename: Task 3.c
Description: Your team is working on a project with international partners who use the metric
system. You need to create a utility that converts speed from miles per hour (mph) to
kilometers per hour (km/h).
Author: James Matthews
Date: 07/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

int main(void){
    float speedMPH = 0;
    float speedKMH = 0;
    printf("Please enter speed in miles per hour: ");
    scanf("%f", &speedMPH);
    speedKMH = speedMPH * 1.60934;
    printf("Your speed in kilometers per hour is: %.5f\n", speedKMH);
}