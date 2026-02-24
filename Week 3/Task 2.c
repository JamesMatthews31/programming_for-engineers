#include <stdio.h>
#include <stdlib.h>

int comparison(const void* a,const void* b){
    // Compares the 2 numbers that the qsort function wants to sort, so if a is smaller it is negative, and opposite for if b is smaller.
    float tempA = *(float*)a;
    float tempB = *(float*)b;

    if (tempA < tempB) return -1;
    else if (tempA > tempB) return 1;
    else return 0;
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
    // Inbuilt quick sort function using a comparison function to sort the array into ascending order
    qsort(numArray,4,sizeof(float),comparison);
    printf("The numbers in ascending order are: %.4f, %.4f, %.4f, %.4f\n",numArray[0],numArray[1],numArray[2],numArray[3]);
    printf("The numbers in descending order are: %.4f, %.4f, %.4f, %.4f\n",numArray[3],numArray[2],numArray[1],numArray[0]);
    return 0;
}