/*
Filename: Task 2.c
Description: Write a program that asks the user to input 4 numbers and displays the values in
both (a) ascending and (b) descending order.
Author: James Matthews
Date: 10/02/2026
Version: 1.1
Log:
Rewrote to use a hand coded sort, not the quick sort from a library.
*/

#include <stdio.h>

/*
Logic of bubble sort:
For every item in the array, compare it to the next item.
Swap the items in the first item is larger than the second item.
Repeat until sorted.
*/

int bubbleSort(float array[], int n){
    int swapped = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1]){
                
                float temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = 1;
            }
        }
    }
    return 0;
}


int main(){
    float numArray[] = { 0, 0, 0, 0 };
    float tempA, tempB = 0;
    // Collects all nunber inputs and puts them into an array
    printf("Enter number 1:");
    scanf("%f",&numArray[0]);
    printf("Enter number 2:");
    scanf("%f",&numArray[1]);
    printf("Enter number 3:");
    scanf("%f",&numArray[2]);
    printf("Enter number 4:");
    scanf("%f",&numArray[3]);
    // Calls earlier defined bubble sort function
    bubbleSort(numArray, 4);
    printf("The numbers in ascending order are: %.4f, %.4f, %.4f, %.4f\n",numArray[0],numArray[1],numArray[2],numArray[3]);
    printf("The numbers in descending order are: %.4f, %.4f, %.4f, %.4f\n",numArray[3],numArray[2],numArray[1],numArray[0]);
    return 0;
}