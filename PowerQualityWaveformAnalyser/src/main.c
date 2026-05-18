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

    waveform *waveformLog;
    float *RMSValues;
    float *P2PValues;
    float *DCOffsetValues;
    int *clippingCounts;
    int *sampleCount;

    sampleCount = readInput(&waveformLog);
    storageSetup();
    calcAll(&waveformLog, &RMSValues, &P2PValues, &DCOffsetValues, &clippingCounts, &sampleCount);

    return 0;
}