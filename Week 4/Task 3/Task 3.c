#include <stdio.h>
#include <stdlib.h>

int main(){
    int sysReportReadings[] = {1, 5, -2, 0, 8, -1, 0, 0, 9, -4, 2, 1};
    int okCount = 0;
    int errorCount = 0;
    int standbyCount = 0;
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
    printf("Ok Count: %d\n", okCount);
    printf("Error Count: %d\n", errorCount);
    printf("Standby Count: %d\n", standbyCount);
}