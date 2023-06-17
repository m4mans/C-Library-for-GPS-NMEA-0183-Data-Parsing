# C-Library-for-GPS-NMEA-0183-Data-Parsing

C Library for GPS NMEA 0183 Data Parsing
The GPS Parser Library is a C library for parsing GPS data from NMEA 0183 (GPGGA) payloads. It provides a simple and easy-to-use interface for extracting GPS data fields such as latitude, longitude, altitude, time, and number of satellites from a NMEA 0183 (GPGGA) strings.

Installation
To install the GPS Parser Library, follow these steps:

Download or clone the repository to your local machine.
Include the data_parser.h header file in your C source code.
Link against the GPS Parser Library during compilation.
Prerequisites
To make this library work perfectly, these tools are needed:

ESP-IDF v5.0 Stable release
ESP-IDF tool chain
Usage
To use the GPS Parser Library, follow these steps:

Download or clone the repository to your local machine.
Include the data_parser.h header file in your C source code.
Link against the GPS Parser Library during compilation.
Call the gpsDataF() function to parse a NMEA 0183 (GPGGA) sentence and extract the GPS data fields. Pass in a pointer to a struct gps_data_parse to store the parsed GPS data.
Use the extracted GPS data fields stored in the struct gps_data_parse to print the extracted data to console or perform further processing or analysis.
Note: Call the printData function to print the extracted GPS data fields to the console at once.
Here's an example code snippet to demonstrate how to use the GPS Parser Library:

#include <stdio.h>
#include "data_parse.h" 

int app_main(void) {
    const char *packet = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    struct gps_data_parse gpsDataS;
    gpsDataF(packet, &data);
    printf("Latitude\n");
    printf("Degrees: %f°\n", gpsDataS.latDegrees);
    printf("Minutes: %f'\n", gpsDataS.latMinutes);
    printf("Direction: %s\n", gpsDataS.latDir);
    printf("Longitude\n");
    printf("Degrees: %f°\n", gpsDataS.lonDegrees);
    printf("Minutes: %f'\n", gpsDataS.lonMinutes);
    printf("Direction: %s\n", gpsDataS.lonDir);
    printf("Quality Indicator: %d\n", gpsDataS.qualInd);
    printf("Number of Satellites: %d\n", gpsDataS.numSat);
    printf("HDOP: %0.2f\n", gpsDataS->HDOP);
    printf("Time (HH:MM:SS): %sn", gpsDataS.t);
    //To print all the data at once 
    printData(&gpsDataS);
    return 0;
}
This example code snippet demonstrates how to parse a GPGGA sentence using the gpsDataF() function and print the extracted GPS data fields to the console using the printData() function. You can use the extracted GPS data fields for further processing or analysis, such as plotting the location on a map or calculating the distance between two points.

Functions Reference
gpsDataF(char* packet, struct gps_data_parse* gpsData)
The gpsDataF() function parses a NMEA 0183 (GPGGA) sentence and extracts the GPS data fields into a struct gps_data_parse.

Parameters
sentence - A pointer to a null-terminated string representing a NMEA 0183 (GPGGA) sentence.
gpsData - A pointer to a struct gps_data_parse to store the parsed GPS data.
printData(struct gps_data_parse* data)
The printData() function prints the extracted GPS data fields stored in a struct gps_data_parse to the console.

Parameters
gpsData - A pointer to a struct gps_data_parse containing the parsed GPS data.
Contributing
If you would like to contribute to the GPS NMEA 0183 Data Parsing library, please feel free to submit a pull request.

