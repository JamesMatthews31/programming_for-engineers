#include "io.h"
#include "waveform.h"
#include <stdio.h>

int readInput(char *filePath){
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
    int count = 0;
    int lineCount = 0;

    // Gets the header row before the loop so that it is skipped

    fgets(currentLine, sizeof(currentLine), filePointer);

    // Counts number of rows in file
    while (fgets(currentLine, sizeof(currentLine), filePointer) != NULL){
        lineCount++;
    }

    rewind(filePointer);

    // Create the array to store the csv file contents in the heap based on lines read

    waveform *waveformLog = malloc(lineCount * sizeof(waveform));

    fgets(currentLine, sizeof(currentLine), filePointer);

    // Iterates through all rows of the csv and uses sscanf to split the entry at commas and immediately assign to the waveform structure array
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

    return 0;

}
