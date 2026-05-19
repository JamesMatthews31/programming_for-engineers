/*
Filename: main.c
Description: Main implementation of functions
Author: James Matthews
Date: 15/05/2026
Version: 0.1.0
Log:
Version 0.1.0:
- First stage that implementation seems to be complete, any testing yet to be done.
*/

#include "io.h"
#include "waveform.h"

int main(){

    waveform *waveformLog = 0;
    double *RMSValues = 0;
    float *P2PValues = 0;
    float *DCOffsetValues = 0;
    int *clippingCounts = 0;
    int sampleCount = 0;

    sampleCount = readInput(&waveformLog);
    storageSetup();
    calcAll(waveformLog, RMSValues, P2PValues, DCOffsetValues, clippingCounts, sampleCount);
    writeOutput(RMSValues, P2PValues, DCOffsetValues, clippingCounts, sampleCount);

    return 0;
}