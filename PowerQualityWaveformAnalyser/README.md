In order to use this program, navigate to Debug in build and open PowerQualityWaveformAnalyser.exe.
When this is open paste the directory of the desired .csv file to be analysed into the window. 
This should then create the output .txt file with summary statistics to the same directory as the .exe

If it is not already build, in order to build cd into the build directory then run cmake --build .
This will then provide the compiled to be used.

Notes on certain outputs.
 - If an empty .csv file is parsed it will not provide normal outputs for RMS and offset, and instead -nan(ind). This is equivalent to a blank output due to an error with division by 0.
 - 