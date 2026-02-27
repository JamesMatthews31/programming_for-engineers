#include <stdio.h>
#include <stdlib.h>

void main(){
    int numArray[] = {44, 78, 73, 42, 5, 58, 9, 50, 12, 43, 71, 36, 29, 76, 80};
    int targetCode;
    printf("Enter target code:");
    scanf("%d",&targetCode);
    for (int i = 0; i < 15; i++){
        if (numArray[i] == targetCode){
            printf("Access code found at index %d",i);
            return;
        }
    }
    printf("Code not found");
}