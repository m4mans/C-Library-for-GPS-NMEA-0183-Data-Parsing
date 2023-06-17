# C-Library-for-GPS-NMEA-0183-Data-Parsing

The GPS Parser Library is a C library for parsing GPS data from NMEA 0183 (GPGGA) payloads. It provides a simple and easy-to-use interface for extracting GPS data fields such as latitude, longitude, altitude, time, and number of satellites from a NMEA 0183 (GPGGA) strings.

## Approach
There are 14 different data fields in a single unbroken GPGGA sentence along with a hexadecimal Checksum. To extract these fields and monitor the missing or wrong info, this code uses following steps: 
1. The GPS data parser code consists of a funstion Parse_gps_data, as per the requirement. This function takes a GPGGA string and performs operatons to extract useful information and then returns the fields data in a structre.
2. In the start of the function, code initiallizes all the fields with some default value. 
3. Then it checks whether the string contains '$GPGGA' in the very start of the string  using a built-in string function 'strcmp()'. if 'YES', the code would move formward with the parsing. But in case of 'NO', the function would return and code closes. 
4. Before parsing, it checks for the checksum validity which starts by getting the exact checksum value given in the GPGGA sentence using for loop. In the next step, the function calculates checksum of the given data by Xoring all the characters between '$' and '*'. The XORed sum is then converted to Hexadecimal to get the actual hex checksum. 
5. The checksum calculated in the above step is then compared with the extracted checksum from the given string to validate the integrity of data. 
6. Once, the checksum is validated/or not, the code would start paarsing time stamp (first field) using a built-in function strsep() [This fucntion cuts a string into twom halves based on the delimiter provided to the function]. Strsep gives NULL string if there's no data between two consecutie commas. 
7. If the time field is NULL, the code would store the default value into the  time_stamp. 
8. strsep() is used again and again till the last available field. If strsep() rerturns an empty string, a message "Not Found!" is strord into that field.


## Usage
To use the GPS Parser Library, follow these steps:


## Installation
To include the GPS Parser component in your IDF project, follow these steps:

Download or clone the repository to your local machine.
Include the gps_data_parser.h header file in your C source code.
Link against the GPS Parser Library during compilation.
## Prerequisites
To make this library work perfectly, these tools are needed:

ESP-IDF v5.0 Stable release
ESP-IDF tool chain

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
