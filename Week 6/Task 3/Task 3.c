/*
Filename: Task 3.c
Description: To use pointers to allow a function to modify variables in the function that
called it. This is how C functions can effectively "return" multiple values.
Author: James Matthews
Date: 03/03/2026
Version: 1.0
Log:
*/

#include <stdio.h>

void splitTime(long totalSec, int *hr, int *min, int *sec);

int main(void){
    int hours, minutes,seconds;
    long total = 3661;
    splitTime(total, &hours, &minutes, &seconds);
    printf("Time: %d:%d:%d\n",hours,minutes,seconds); 
}

void splitTime(long totalSec, int *hr, int *min, int *sec){
    *hr = totalSec / 3600;
    *min = (totalSec % 3600) / 60;
    *sec = totalSec % 60;
}