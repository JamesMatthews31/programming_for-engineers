/*
Filename: Task 4.c
Description: 

1. Create an integer array of size 15 with some random numbers, making sure the number 42 is
included somewhere.
2. Prompt the user to enter the target code to search for.
3. Use a for loop to search for the target in the array.
4. If the target is found, print a message like "Access Code Found at Position X" (where X is the
index) and immediately exit the loop.
5. If the loop finishes without finding the target, print a "Code Not Found" message.

Author: James Matthews
Date: 24/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>

int main(){
    int numArray[] = {44, 78, 73, 42, 5, 58, 9, 50, 12, 43, 71, 36, 29, 76, 80};
    int targetCode;
    printf("Enter target code:");
    scanf("%d",&targetCode);
    // Iterates through list to find the code, returning the index if it is found, or printing not found if not.
    for (int i = 0; i < 15; i++){
        if (numArray[i] == targetCode){
            printf("Access code found at position %d",i);
            return 0;
        }
    }
    printf("Code not found");
    return 1;
}