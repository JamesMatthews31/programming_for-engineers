/*
Filename: Task 1.c
Description: Write a C program that declares an array of 10 doubles. Use a for loop to initialize all
elements of the array to -1.0. Finally, use another for loop to print all the elements to verify they
have been set correctly.
Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

int main(){
    double sensorReadings[10];
    // Fills array with -1s
    for (int i = 0; i < 10; i++){
        sensorReadings[i] = -1;
    }
    // Prints array
    for (int i = 0; i < 10; i++){
        printf("%f\n", sensorReadings[i]);
    }
    return 0;
}