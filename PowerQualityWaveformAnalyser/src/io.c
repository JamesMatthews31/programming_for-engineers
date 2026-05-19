/*
Filename: io.c
Description: Header file source code for io functions (Reading from csv and writing to txt file)
Author: James Matthews
Date: 15/05/2026
Version: 0.0.1
Log:
- Version 0.0.1: readInput implemented, yet to do output.
- Version 0.0.2: Tested the program as a whole compiled executable and fixed issue of repeatedly asking for directory by removing secondary pointer definition. And added readInput src code.
- Version 0.0.3: Tested program to check that read input was getting the right amount of data in by printing count. Now reverted as test passed.
- Version 0.0.4: Changed the management of pointers in readInput as I believe it was not returning hte pointer correctly
- Version 0.1.0: The code in this file now enables main.c to run from start to finish, providing an output file. Results still innacurate
*/

#define _CRT_SECURE_NO_WARNINGS
#include "io.h"
#include "waveform.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int readInput(waveform **waveformLog){

    FILE *filePointer = NULL;

    while (filePointer == NULL){

        // Create temp variable to store filePath directory
        
        char filePath[500];

        // Ask user for directory input

        printf("Enter the directory of the .csv file to be analysed: \n");

        // Scan directory into filePath

        scanf("%s", filePath);

        // Connect the file to the pointer to read
        filePointer = fopen(filePath, "r");

        // Check that file exists and return error if not
        if (filePointer == NULL){
            printf("Error, could not open file. Please try again");
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

    *waveformLog = malloc(lineCount * sizeof(waveform));

    fgets(currentLine, sizeof(currentLine), filePointer);

    // Iterates through all rows of the csv and uses sscanf to split the entry at commas and immediately assign to the waveform structure array
    while (fgets(currentLine, sizeof(currentLine), filePointer) != NULL){

        sscanf(currentLine, "%f,%lf,%lf,%lf,%lf,%lf,%lf,%lf", 
            &(*waveformLog)[count].timestamp, 
            &(*waveformLog)[count].phaseAVoltage, 
            &(*waveformLog)[count].phaseBVoltage, 
            &(*waveformLog)[count].phaseCVoltage, 
            &(*waveformLog)[count].lineCurrent, 
            &(*waveformLog)[count].frequency, 
            &(*waveformLog)[count].powerFactor, 
            &(*waveformLog)[count].thdPercent);
        count++;
        printf("%d",count);
        
    }

    fclose(filePointer);

    return lineCount;

}

int writeOutput(double *RMSValues, float *P2PValues, float *DCOffsetValues, int *clippingCounts, int sampleCount){

    // Define variables to be used to identify a readable file.

    FILE *filePointer;

    int count = 0;
    int emptyFile = 0;
    char fileName[20];

    // Loops until an undefined file is found

    while(emptyFile == 0){

        // Put count into the name of the file so that files arent overwritten in the case of multiple files being filtered

        snprintf(fileName, sizeof(fileName), "outputData%d.txt", count);

        filePointer = fopen(fileName, "r");

        // If the file doesn't exist, end this while loop

        if (filePointer == NULL){

            emptyFile = 1;

        }

        // If the file exists, increment counter and allow the loop to continue

        else{

            count++;
            fclose(filePointer);

        }

    }

    // Opens the file to write and prints data outputs to it

    filePointer = fopen(fileName, "w");

    fprintf(filePointer, "Analysed data for file at directory");
    fprintf(filePointer, "%-20s| %-15s| %-15s| %-15s\n", "", "Phase A", "Phase B", "Phase C");
    fprintf(filePointer, "------------------------------------------------------------------------\n");
    fprintf(filePointer, "%-20s| %-15.4lf| %-15.4lf| %-15.4lf\n", "RMS (V)", RMSValues[0], RMSValues[1], RMSValues[2]);
    fprintf(filePointer, "------------------------------------------------------------------------\n");
    fprintf(filePointer, "%-20s| %-15.4f| %-15.4f| %-15.4f\n", "Peak to peak (V)", P2PValues[0], P2PValues[1], P2PValues[2]);
    fprintf(filePointer, "------------------------------------------------------------------------\n");
    fprintf(filePointer, "%-20s| %-15.4f| %-15.4f| %-15.4f\n", "DC Offset (V)", DCOffsetValues[0], DCOffsetValues[1], DCOffsetValues[2]);
    fprintf(filePointer, "------------------------------------------------------------------------\n");
    fprintf(filePointer, "%-20s| %-15d| %-15d| %-15d\n", "No. Clipped values", clippingCounts[0], clippingCounts[1], clippingCounts[2]);
    fprintf(filePointer, "------------------------------------------------------------------------\n");
    fprintf(filePointer, "Over %d samples", sampleCount);

    fclose(filePointer);

    return 0;
}


