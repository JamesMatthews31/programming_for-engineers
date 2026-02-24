#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Program to randomly pick a number between 0 and 100, which is then assigned to letter grade A through F using a switch statement, returning errors if out of range

int main(){
    srand(time(NULL));
    int randNum = rand()%101;
    printf("%d\n",randNum);
    switch(randNum/10){
        case 10:
        case 9:
        case 8:
            printf("Grade: A");
            break;
        case 7:
        case 6:
            printf("Grade: B");
            break;
        case 5:
        case 4:
            printf("Grade: C");
            break;
        case 3:
            printf("Grade: D");
            break;
        case 2:
        case 1:
        case 0:
            printf("Grade: F");
            break;
        default:
            printf("Exit code 1: Out of range error");
            return 1;
    }
    return 0;
}