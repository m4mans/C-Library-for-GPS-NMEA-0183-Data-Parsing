/*
This library just parses GP Talker ID.
It uses a function "gpsDataF" to parse Data.
The Function takes a payload in the form of a string and a pointer to the struct and gives individual data fields.
There's another function to print all the fields at once, saving the effort to get individual fields one by one.
*/

#include <string.h>
#include <stdlib.h>
#include "gps_data_parse.h"

gps_data Parse_gps_data(char *msg)
{
    gps_data gpsData;

    // Initializing data fields with a default value
    strcpy(gpsData.time_stamp, field_missing);
    strcpy(gpsData.latitude, field_missing);
    strcpy(gpsData.lat_direction, field_missing);
    strcpy(gpsData.longitude, field_missing);
    strcpy(gpsData.lon_direction, field_missing);
    strcpy(gpsData.qual_ind, field_missing);
    strcpy(gpsData.num_satellites, field_missing);
    strcpy(gpsData.HDOP, field_missing);
    strcpy(gpsData.altitude_antenna, field_missing);
    strcpy(gpsData.units_antenna, field_missing);
    strcpy(gpsData.geoidal_separation, field_missing);
    strcpy(gpsData.units_separation, field_missing);
    strcpy(gpsData.age_correction, field_missing);
    strcpy(gpsData.correction_sta, field_missing);
    strcpy(gpsData.calculated_checksum, field_missing);
    strcpy(gpsData.parsed_checksum, field_missing);
    
    // clears checksum integrity flag 
    gpsData.check_sum_matched = false;

    // declaring the delimiter for strsep() function
    char delimiter[5] = ",";
    // pointer to the 2nd half of the separated string
    char *post_delimiter = msg;
    // pointer to the 1st half of the separated string
    char *pre_delimiter = msg;

    if (!(strncmp(msg, "$GPGGA", 6)))
    {
        // Setting the string validity flag
        gpsData.string_validity = true;

        int asterisk = 0;
        int j = 0;

        // Extracting checksum from the given payload
        for (int i = 0; post_delimiter[i] != '\0'; i++)
        {
            if (post_delimiter[i] == '*')
            {
                asterisk = 1;
                continue;
            }
            else if (asterisk)
            {
                gpsData.parsed_checksum[j++] = post_delimiter[i];
            }
        }
        gpsData.parsed_checksum[j] = '\0';

        if (!(strcmp(gpsData.parsed_checksum, "")))
        {
            strcpy(gpsData.parsed_checksum, field_missing);
            strcpy(gpsData.calculated_checksum, "");
        }
        else
        {
            ////Checksum Validation
            char check_sum = 0;
            int i = 1; // Start from index 1 to skip the leading '$' character
            while (post_delimiter[i] != '*' && post_delimiter[i] != '\0')
            {
                check_sum ^= post_delimiter[i];
                i++;
            }
            sprintf(gpsData.calculated_checksum, "%02X", check_sum);

            // Confirms if the calculated checksum validates with the given checksum
            if (strcmp(gpsData.parsed_checksum, gpsData.calculated_checksum) == 0)
            {
                gpsData.check_sum_matched = true;
            }
            else
            {
                gpsData.check_sum_matched = false;
            }

            pre_delimiter = strsep(&post_delimiter, "*");
            post_delimiter = pre_delimiter;
            pre_delimiter = strsep(&post_delimiter, delimiter);

            // Parsing time
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.time_stamp, field_missing);
            }
            else
            {
                // converting time to standard format
                int hours, minutes, seconds;
                float milliseconds;
                sscanf(pre_delimiter, "%2d%2d%2d.%f", &hours, &minutes, &seconds, &milliseconds);

                if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59)
                {
                    sprintf(gpsData.time_stamp, "%02d:%02d:%02d.%03d", hours, minutes, seconds, (int)(milliseconds * 1000));
                }
                else
                {
                    strcpy(gpsData.time_stamp, "Invalid time format!");
                }
            }

            // Parsing Latitude
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.latitude, field_missing);
            }
            else
            {
                strcpy(gpsData.latitude, pre_delimiter);
            }

            // Parsing latitude direction
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.lat_direction, field_missing);
            }
            else
            {
                strcpy(gpsData.lat_direction, pre_delimiter);
            }

            // Parsing longitude
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.longitude, field_missing);
            }
            else
            {
                strcpy(gpsData.longitude, pre_delimiter);
            }

            // Parsing Longitude Direction
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.lon_direction, field_missing);
            }
            else
            {
                strcpy(gpsData.lon_direction, pre_delimiter);
            }

            // Parsing Quality Indicator
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.qual_ind, field_missing);
            }
            else
            {
                strcpy(gpsData.qual_ind, pre_delimiter);
            }

            // Parsing Number of satellites
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.num_satellites, field_missing);
            }
            else
            {
                strcpy(gpsData.num_satellites, pre_delimiter);
            }

            // Parsing HDOP
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.HDOP, field_missing);
            }
            else
            {
                strcpy(gpsData.HDOP, pre_delimiter);
            }

            // Parsing altitude of antenna
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.altitude_antenna, field_missing);
            }
            else
            {
                strcpy(gpsData.altitude_antenna, pre_delimiter);
            }

            // Parsing units of altitude of antenna
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.units_antenna, field_missing);
            }
            else
            {
                strcpy(gpsData.units_antenna, pre_delimiter);
            }

            // Parsing Geoidal Separation
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.geoidal_separation, field_missing);
            }
            else
            {
                strcpy(gpsData.geoidal_separation, pre_delimiter);
            }

            // Parsing units of Geoidal Separation
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.units_separation, field_missing);
            }
            else
            {
                strcpy(gpsData.units_separation, pre_delimiter);
            }

            // Parsing Age Correction
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.age_correction, field_missing);
            }
            else
            {
                strcpy(gpsData.age_correction, pre_delimiter);
            }

            // Parsing Satellite Correction
            pre_delimiter = strsep(&post_delimiter, delimiter);
            if (!(strcmp(pre_delimiter, "")))
            {
                strcpy(gpsData.correction_sta, field_missing);
            }
            else
            {
                strcpy(gpsData.correction_sta, pre_delimiter);
            }

            return gpsData;
        }
        return gpsData;
    }
    else
    {
        // cleard the string valiidty flag
        gpsData.string_validity = false;

        // stored invalid string flag in all fields
        strcpy(gpsData.time_stamp, invalid_payload);
        strcpy(gpsData.latitude, invalid_payload);
        strcpy(gpsData.lat_direction, invalid_payload);
        strcpy(gpsData.longitude, invalid_payload);
        strcpy(gpsData.lon_direction, invalid_payload);
        strcpy(gpsData.qual_ind, invalid_payload);
        strcpy(gpsData.num_satellites, invalid_payload);
        strcpy(gpsData.HDOP, invalid_payload);
        strcpy(gpsData.altitude_antenna, invalid_payload);
        strcpy(gpsData.units_antenna, invalid_payload);
        strcpy(gpsData.geoidal_separation, invalid_payload);
        strcpy(gpsData.units_separation, invalid_payload);
        strcpy(gpsData.age_correction, invalid_payload);
        strcpy(gpsData.correction_sta, invalid_payload);
        strcpy(gpsData.calculated_checksum, invalid_payload);
        strcpy(gpsData.parsed_checksum, invalid_payload);
        return gpsData;
    }
}

void print_data(gps_data gpsData)
{
    printf("Time:                   %s\n", gpsData.time_stamp);
    printf("Latitude:               %s\n", gpsData.latitude);
    printf("Latitude Direction:     %s\n", gpsData.lat_direction);
    printf("Longitude:              %s\n", gpsData.longitude);
    printf("Longitude Direction:    %s\n", gpsData.lon_direction);
    printf("Quality Indicator:      %s\n", gpsData.qual_ind);
    printf("Number of Satellites:   %s\n", gpsData.num_satellites);
    printf("HDOP:                   %s\n", gpsData.HDOP);
    printf("Altitude of Antenna:    %s\n", gpsData.altitude_antenna);
    printf("Unit of Altitude:       %s\n", gpsData.units_antenna);
    printf("Geoidal Separation:     %s\n", gpsData.geoidal_separation);
    printf("Unit of Geoidal:        %s\n", gpsData.units_separation);
    printf("Age Correction:         %s\n", gpsData.age_correction);
    printf("Station Correction:     %s\n", gpsData.correction_sta);
    printf("Parsed Check Sum        %s\n", gpsData.parsed_checksum);
    printf("Calculated Check Sum    %s\n", gpsData.calculated_checksum);
}