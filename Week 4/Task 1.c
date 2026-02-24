#include <stdio.h>
#include <stdlib.h>

int main(){
    double sensorReadings[10];
    for (int i = 0; i < 10; i++){
        sensorReadings[i] = -1;
    }
    for (int i = 0; i < 10; i++){
        printf("%f\n", sensorReadings[i]);
    }
}