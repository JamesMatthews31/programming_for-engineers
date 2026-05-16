/*
Filename: io.c
Description: Header file source code for io functions (Reading from csv and writing to txt file)
Author: James Matthews
Date: 15/05/2026
Version: 0.0.1
Log:
- Version 0.0.1: readInput implemented, yet to do output
*/

#include "io.h"
#include "waveform.h"
#include <stdio.h>

int readInput(){

    FILE *filePointer = NULL;

    while (filePointer == NULL){

        // Create temp variable to store filePath directory
        
        char filePath[500];

        // Ask user for directory input

        printf("Enter the directory of the .csv file to be analysed: \n");

        // Scan directory into filePath

        fgets(filePath, 500, stdin);

        // Create pointer to file
        FILE *filePointer;

        // Connect the file to the pointer to read
        filePointer = fopen(filePath, "r");

        // Check that file exists and return error if not
        if (filePointer == NULL){
            printf("Error, could not open file. Please try again");
            fclose(filePointer);
        }

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

    fclose(filePointer);

    return 0;

}
