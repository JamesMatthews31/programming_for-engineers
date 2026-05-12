#include "io.h"
#include "waveform.h"
#include <stdio.h>

int readInput(char *filePath[]){
    // Create pointer to file
    FILE *filePointer;

    // Connect the file to the pointer to read
    filePointer = fopen(filePath[0], "r");

    // Check that file exists and return error if not
    if (filePointer == NULL){
        printf("Error, could not open file.");
        return 1;
    }

    // Initialise variables that will be needed to read the file
    char currentLine[200];
    int lineCountEst = 1000;
    int count = 0;


    
    waveform *waveformLog = malloc(lineCountEst * sizeof(waveform));

    while (fgets(currentLine, sizeof(currentLine), filePointer) != NULL){

        sscanf(currentLine, "%f,%lf,%lf,%lf,%lf,%lf,%lf,%lf", 
            &waveformLog[count].timestamp, 
            &waveformLog[count].phaseAVoltage, 
            &waveformLog[count].phaseBVoltage, 
            &waveformLog[count].phaseCVoltage, 
            &waveformLog[count].lineCurrent, 
            &waveformLog[count].frequency, 
            &waveformLog[count].powerFactor, 
            &waveformLog[count].thdPercent);
        count++;
    }

    
}