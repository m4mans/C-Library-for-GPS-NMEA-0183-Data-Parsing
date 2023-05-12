/*
This library just parses GP Talker ID.
It uses a functin "gpsDataF" to parse Data.
The Function takes a payload in the form of a string and a pointer to the strcut and gives individual data fields.
There's another function to print all the fields at once saving the effort to get individual fields one by one.
*/
#include <string.h>
#include <stdlib.h>
#include "data_parse.h"

//function to parse the GPS data from "GPGGA" talker ID & sentence formatter
int gpsDataF(const char *dataPacket, struct gps_data_parse *gpsDataS)
{
    //Check validity of the given string
    char *start = strstr(dataPacket, "$GPGGA");
    if (start == NULL)
    {
        // '$GPGGA' not found in the payload
        strcat(gpsDataS->failures, "$GPGGA not found!\n");
        return 0;
    }

    // Find the end position of the string
    char *end = strstr(start, "*");
    if (end == NULL)
    {
        // end delimiter not found
        strcat(gpsDataS->failures, "End delimiter '*' not found!");
        return 0;
    }

    // Find the end of the line
    char *line_end = strstr(end, "\r\n");
    if (line_end == NULL)
    {
        // line ending not found
        strcat(gpsDataS->failures, "<CR> <LF> not found!");
        return 0;
    }

    // Calculate the length of the substring between '$GPGGA' and the end delimiter
    // Extract the substring
    unsigned int substr_len = strlen(start) - strlen(line_end);
    char strWithChkSum[substr_len];
    strncpy(strWithChkSum, start, substr_len);
    // Add a null terminator at the end of the extracted string
    strWithChkSum[substr_len] = '\0';

    //Gets the checksum value from the payload
    char *token;
    char *strWithoutChkSum;
    strWithoutChkSum = strtok(strWithChkSum, "*");
    char *checkSumHex = strtok(NULL, "\0");
    
    //CheckSum
    int chkSum = 0;
    //Gets XOR of all the characters between '$' and '*'
    for (int i = 1; i < strlen(strWithoutChkSum); i++)
    {
        chkSum ^= (unsigned char)strWithoutChkSum[i];
    }

    //Converts the XOR decimal value to hexadecimal
    char checkSumCal[3];
    sprintf(checkSumCal, "%02X", chkSum);

    //Confirms if the calculated checksum validates with the given checksum
    if (strcmp(checkSumCal, checkSumHex) == 0)
    {
        strcpy(gpsDataS->checkSum, "Check sum matched!");
    }
    else
    {
        strcpy(gpsDataS->checkSum, "Check sum not matched!");
    }
    token = strtok(strWithoutChkSum, ",");

    //Parsing Individual Fields
    
    // TIME
    token = strtok(NULL, ",");
    int j = 0;
    for (int i = 0; i < strlen(token); i += 2)
    {
        if (i > 0)
        {
            gpsDataS->t[j++] = ':';
        }
        gpsDataS->t[j++] = token[i];
        gpsDataS->t[j++] = token[i + 1];
    }

    gpsDataS->t[15] = '\0';

    // Latitude
    token = strtok(NULL, ",");
    float latitude = atof(token);
    latitude /= 100.0;
    gpsDataS->latDegrees = (int)latitude;
    gpsDataS->latMinutes = (latitude - gpsDataS->latDegrees) * 60.0;
    token = strtok(NULL, ",");
    strcpy(gpsDataS->latDir, token);

    // Longitude
    token = strtok(NULL, ",");
    float longitude = atof(token);
    longitude /= 100.0;
    gpsDataS->lonDegrees = (int)longitude;
    gpsDataS->lonMinutes = (longitude - gpsDataS->lonDegrees) * 60.0;
    token = strtok(NULL, ",");
    strcpy(gpsDataS->lonDir, token);

    // Quality Indicator
    token = strtok(NULL, ",");
    gpsDataS->qualInd = (int)atof(token);

    // Number of Stations
    token = strtok(NULL, ",");
    gpsDataS->numSat = (int)atof(token);

    // Horizontal dilution of precision
    token = strtok(NULL, ",");
    gpsDataS->HDOP = atof(token);

    // Altitude of antenna
    token = strtok(NULL, ",");
    gpsDataS->altAntenna = atof(token);

    // Units of alitiude (either feets or meters)
    token = strtok(NULL, ",");
    strcpy(gpsDataS->unitsAntenna, token);

    // Geoidal Separation
    token = strtok(NULL, ",");
    gpsDataS->geiodalSeparation = atof(token);

    // Units of alitiude (either feets or meters)
    token = strtok(NULL, ",");
    strcpy(gpsDataS->unitsSeparation, token);

    return 1; 
}


//fucntion to print all the parsed fields
void printData(struct gps_data_parse *gpsDataS)
{
    printf("Time: %s\n", gpsDataS->t);

    printf("Latitude\n");
    printf("Degrees: %f°\n", gpsDataS->latDegrees);
    printf("Minutes: %f'\n", gpsDataS->latMinutes);
    printf("Direction: %s\n", gpsDataS->latDir);

    printf("Longitude\n");
    printf("Degrees: %f°\n", gpsDataS->lonDegrees);
    printf("Minutes: %f'\n", gpsDataS->lonMinutes);
    printf("Direction: %s\n", gpsDataS->lonDir);

    printf("Quality Indicator: %d\n", gpsDataS->qualInd);
    printf("Number of Satellites: %d\n", gpsDataS->numSat);
    printf("HDOP: %0.2f\n", gpsDataS->HDOP);
    printf("Altitude of Antenna: %0.2f%s\n", gpsDataS->altAntenna, gpsDataS->unitsAntenna);
    printf("Geoidal Separation: %0.2f%s\n", gpsDataS->geiodalSeparation, gpsDataS->unitsSeparation);
}

