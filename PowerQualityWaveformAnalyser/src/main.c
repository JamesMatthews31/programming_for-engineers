/*
Filename: main.c
Description: Main implementation of functions
Author: James Matthews
Date: 15/05/2026
Version: 0.1.0
Log:
Version 0.0.1: First stage that implementation seems to be complete, any testing yet to be done.
Version 0.1.0: First main.c to be able to run from start to finish. Results still innacurate
Version 0.1.1: Now cleans memory
Version 1.0.0: Presumed final version with 2 of 4 strech goals implemnted.
*/

#include "io.h"
#include "waveform.h"
#include <stdio.h>
#include <windows.h>

int main(){

    // Define variables to have memory allocated to it

    waveform *waveformLog = 0;
    double *RMSValues = 0;
    float *P2PValues = 0;
    float *DCOffsetValues = 0;
    int *clippingCounts = 0;
    float *varianceValues = 0;
    float *standardDevValues = 0;
    int sampleCount = 0;
    

    // Call readInput to get data, then set up memory usig storageSetup, then calcAll. writeOutput based on calcAll output, sort internally with no return, and finally free allocated memory using cleanUp

    sampleCount = readInput(&waveformLog);
    storageSetup(&RMSValues, &P2PValues, &DCOffsetValues, &clippingCounts, &varianceValues, &standardDevValues);
    calcAll(waveformLog, RMSValues, P2PValues, DCOffsetValues, clippingCounts, varianceValues, standardDevValues, sampleCount);
    writeOutput(RMSValues, P2PValues, DCOffsetValues, clippingCounts, varianceValues, standardDevValues, sampleCount);
    quickSort(&waveformLog, 0, sampleCount - 1);
    cleanUp(waveformLog, RMSValues, P2PValues, DCOffsetValues, clippingCounts, varianceValues, standardDevValues);


    return 0;
    
}