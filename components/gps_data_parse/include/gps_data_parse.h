#ifndef DATA_PARSE_H_
#define DATA_PARSE_H_

#include <stdio.h>
#include <stdlib.h> // for atoi, atof
#include <string.h> // for strchr
#include <stdbool.h>

#define invalid_payload "Invalid Data" // Define a constant string for indicating missing fields
#define field_missing "Not Found!"     // Define a constant string for indicating missing fields

// GPS data structure for parsed data

typedef struct gps_data_parse
{
    char time_stamp[25];          // GPS time stamp
    char latitude[15];            // Latitude value
    char lat_direction[15];       // Latitude direction (North/South)
    char longitude[15];           // Longitude value
    char lon_direction[15];       // Longitude direction (East/West)
    char qual_ind[15];            // Quality indicator
    char num_satellites[15];      // Number of satellites
    char HDOP[15];                // Horizontal Dilution of Precision
    char altitude_antenna[15];    // Altitude of antenna
    char units_antenna[15];       // Units of antenna altitude
    char geoidal_separation[15];  // Geoidal separation
    char units_separation[15];    // Units of geoidal separation
    char age_correction[15];      // Age of correction
    char correction_sta[15];      // Correction station ID
    char calculated_checksum[15]; // Checksum calculated from the data
    char parsed_checksum[15];     // Checksum parsed from the data
    bool string_validity;
    bool check_sum_matched; // Flag indicating whether the calculated checksum matches the parsed checksum
} gps_data;

// Function to parse GPS data
// takes a data Pointer to the input GPS data string as a parameter
// return Parsed GPS data structure
gps_data Parse_gps_data(char *data);

// Function to print GPS data
// takes a Parsed GPS data structure as input
// returs nothing
void print_data(gps_data);

#endif // DATA_PARSE_H_
