cmake_minimum_required(VERSION 3.10)
project(PowerQualityWaveformAnalyser C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

set(SOURCES
    src/main.c
    src/io.c
    src/waveform.c
)

add_executable(PowerQualityWaveformAnalyser ${SOURCES})
