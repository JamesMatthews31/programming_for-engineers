/*
Filename: io.h
Description: Header file for input output capabilities
Author: James Matthews
Date: 15/05/2026
Version: 0.1
Log:
- Version 0.1: All known prototypes implemented with header guard
- Version 1.0.0: Presumed final version with up to data parameters. Note I forgot to update the version history here.
*/

// Header guard for IO_H

#ifndef IO_H
#define IO_H

#include "waveform.h"

// Function to read input of csv into waveform array

int readInput(waveform **waveformLog);

// Function to write the calculated statistics to output .txt file

int writeOutput(double *RMSValues, float *P2PValues, float *DCOffsetValues, int *clippingCounts, float *varianceValues, float *standardDevValues, int sampleCount);

// Function to free up used memory

int cleanUp(waveform *waveformLog, double *RMSValues, float *P2PValues, float *DCOffsetValues, int *clippingCounts, float *varianceValues, float *standardDevValues);

#endif
// End of header guard