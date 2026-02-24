#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Enter a number between -10 and 10:");
    int num;
    scanf("%d",&num);
    if (num < -10 || num > 10){
        printf("Exit code 1: Out of range error");
        return 1;
    }
    else if (num < 0){
        printf("Negative number,");
        if (num % 2 == 0){
            printf(" Even");
        }
        else{
            printf(" Odd");
        }
    }
    else if (num > 0){
        printf("Positive number,");
        if (num % 2 == 0){
            printf(" Even");
        }
        else{
            printf(" Odd");
        }
    }
    else{
        printf("Zero");
    }
}