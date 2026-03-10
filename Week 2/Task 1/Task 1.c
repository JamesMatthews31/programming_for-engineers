/*
Filename: Task 1.c
Description: You are initializing a new sensor module. Your first task is to declare variables to
hold its calibration data, assign them values, and print them to the console to verify they are
stored correctly.
Author: James Matthews
Date: 07/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>
int main(void){
    int sensorID = 99;
    float temperature = 12.34;
    char status = 'A';
    printf("Sensor ID: %d\n", sensorID);
    printf("Temperature: %.2f\n", temperature);
    printf("Status: %c\n", status);
}
