/*
Filename: Task 2.c
Description: 

1. Declare and initialize an array of 8 floats with the following values: 88.5, 92.1, 85.0, 95.3, 89.9, 91.2, 84.8, 90.5.
2. Use a loop to traverse the array and find the minimum and maximum values.
3. Calculate the sum of all values and then compute the average.
4. Print the min, max, and average values to the screen.

Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

int main(){
    float sigStrReadings[] = {88.5, 92.1, 85.0, 95.3, 89.9, 91.2, 84.8, 90.5};
    float sum = 0;
    float min = sigStrReadings[0];
    float max = sigStrReadings[0];
    // Loops through array, adding each value to sum and then checking if it is the new max or min
    for (int i =0; i < 8; i++){
        sum += sigStrReadings[i];
        if (sigStrReadings[i] < min){
            min = sigStrReadings[i];
        }
        if (sigStrReadings[i] > max){
            max = sigStrReadings[i];
        }
        
    }
    // Prints requested values
    printf("Average: %.1f\n", sum/8);
    printf("Min: %.1f\n", min);
    printf("Max: %.1f\n", max);
}