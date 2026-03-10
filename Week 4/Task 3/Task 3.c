/*
Filename: Task 3.c
Description: 

1. Create an integer array of size 12 and initialize it with a mix of positive, negative, and zero
values (e.g., 1, 5, -2, 0, 8, -1, 0, 0, 9, -4, 2, 1).
2. Use a for loop to iterate through the array.
3. Inside the loop, use if-else if-else statements to check if the current element is positive,
negative, or zero.
4. Use three separate counter variables (positiveCount, negativeCount, zeroCount) to keep track
of the totals.
5. After the loop, print the final counts for each category.

Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

int main(){
    int sysReportReadings[] = {1, 5, -2, 0, 8, -1, 0, 0, 9, -4, 2, 1};
    int okCount = 0;
    int errorCount = 0;
    int standbyCount = 0;
    // Categorises each value in the array based on the values provided in the description
    for (int i = 0; i < 12; i++){
        if (sysReportReadings[i] > 0){
            okCount++;
        }
        else if (sysReportReadings[i] < 0){
            errorCount++;
        }
        else{
            standbyCount++;
        }
    }
    // Prints counts
    printf("Ok Count: %d\n", okCount);
    printf("Error Count: %d\n", errorCount);
    printf("Standby Count: %d\n", standbyCount);
}