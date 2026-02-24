#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    unsigned int maxValue = 0;
    unsigned int keyValue = 0;
    printf("Enter the maximum key value: ");
    scanf("%u", &maxValue);
    keyValue = rand()%(maxValue + 1);
    printf("The key value is: %u\n", keyValue);
}