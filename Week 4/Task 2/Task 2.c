#include <stdio.h>
#include <stdlib.h>

int main(){
    float sigStrReadings[] = {88.5, 92.1, 85.0, 95.3, 89.9, 91.2, 84.8, 90.5};
    float sum = 0;
    float min = sigStrReadings[0];
    float max = sigStrReadings[0];
    for (int i =0; i < 8; i++){
        sum += sigStrReadings[i];
        if (sigStrReadings[i] < min){
            min = sigStrReadings[i];
        }
        if (sigStrReadings[i] > max){
            max = sigStrReadings[i];
        }
        
    }
    printf("Sum: %.1f\n", sum);
    printf("Average: %.1f\n", sum/8);
    printf("Min: %.1f\n", min);
    printf("Max: %.1f\n", max);
}