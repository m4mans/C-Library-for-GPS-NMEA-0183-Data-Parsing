
#ifndef DATA_PARSE_H_
#define DATA_PARSE_H_

#include <stdio.h>

#define MAX_STRING_LENGTH 82

//Struct to store parsed data fields
struct gps_data_parse
{
    char t[15];
    float latMinutes;
    float latDegrees;
    char latDir[1];
    float lonMinutes;
    float lonDegrees;
    char lonDir[1];
    int qualInd;
    int numSat;
    float HDOP;
    float altAntenna;
    char unitsAntenna[1];
    float geiodalSeparation;
    char unitsSeparation[1];
    int ageCorrection;
    int correctionSta;
    int parseSuccess;
    char fieldsError[50];
    char failures[50];
    char checkSum[50];
};

int gpsDataF(const char *, struct gps_data_parse *); //function to parse data
void printData(struct gps_data_parse *); //function to print data

#endif 