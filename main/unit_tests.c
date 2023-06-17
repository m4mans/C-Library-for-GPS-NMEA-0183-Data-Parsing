#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "gps_data_parse.h" // Include the header file of the function to be tested
#include "esp_log.h"

#define error "Invalid Data"
static const char *TAG = "";


// Function to run the unit tests
void runTests()
{
    // Test case 1: Valid GPS data
    char payload[] = "$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";
    gps_data gpsData = Parse_gps_data(payload);

    // Test individual struct fields
    if (!(strcmp(gpsData.time_stamp, "00:21:53.000")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (time_stamp)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (time_stamp)\n");
    }

    if (!(strcmp(gpsData.latitude, "3342.6618")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (latitude)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (latitude)\n");
    }

    if (!(strcmp(gpsData.lat_direction, "N")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Latitude direction)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Latitude direction)\n");
    }

    if (!(strcmp(gpsData.longitude, "11751.3858")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Longitude)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Longitude)\n");
    }


    if (!(strcmp(gpsData.lon_direction, "W")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Longitude Direction)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Longitude Direction)\n");
    }

    if (!(strcmp(gpsData.qual_ind, "1")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Quality Indicator)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Quality Indicator)\n");
    }

    if (!(strcmp(gpsData.num_satellites, "10")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Num of Satellites)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Num of Satellites)\n");
    }

    if (!(strcmp(gpsData.HDOP, "1.2")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (HDOP)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (HDOP)\n");
    }

    if (!(strcmp(gpsData.altitude_antenna, "27.0")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Altitude of antenna)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Altitude of antenna)\n");
    }


    if (!(strcmp(gpsData.units_antenna, "M")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Units of Antenna)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Units of Antenna)\n");
    }


    if (!(strcmp(gpsData.geoidal_separation, "-34.2")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Geoidal Separation)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Geoidal Separation)\n");
    }

    if (!(strcmp(gpsData.units_separation, "M")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Units of Geoidal Separation)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Units of Geoidal Separation)\n");
    }

    if (!(strcmp(gpsData.age_correction, "Not Found!")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Age Correction)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Age Correction)\n");
    }

    if (!(strcmp(gpsData.correction_sta, "0000")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Units of Age Correction)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Units of Age Correction)\n");
    }

    if (!(strcmp(gpsData.calculated_checksum, "5E")))
    {
        ESP_LOGD(TAG, "Test case 1: Passed (Calculated Checksum)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 1: Failed (Calculated Checksum)\n");
    }

    // Test case 2: Empty payload
    char emptyPayload[] = "";
    gps_data emptyGpsData = Parse_gps_data(emptyPayload);

    // Test individual struct fields for empty payload
    if ((!strcmp(emptyGpsData.time_stamp, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (time_stamp)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (time_stamp)\n");
    }

        if (!(strcmp(emptyGpsData.latitude, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (latitude)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (latitude)\n");
    }

    if (!(strcmp(emptyGpsData.lat_direction, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Latitude direction)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Latitude direction)\n");
    }

    if (!(strcmp(emptyGpsData.longitude, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Longitude)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Longitude)\n");
    }


    if (!(strcmp(emptyGpsData.lon_direction, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Longitude Direction)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Longitude Direction)\n");
    }

    if (!(strcmp(emptyGpsData.qual_ind, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Quality Indicator)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Quality Indicator)\n");
    }

    if (!(strcmp(emptyGpsData.num_satellites, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Num of Satellites)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Num of Satellites)\n");
    }

    if (!(strcmp(emptyGpsData.HDOP, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (HDOP)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (HDOP)\n");
    }

    if (!(strcmp(emptyGpsData.altitude_antenna, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Altitude of antenna)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Altitude of antenna)\n");
    }


    if (!(strcmp(emptyGpsData.units_antenna, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Units of Antenna)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Units of Antenna)\n");
    }


    if (!(strcmp(emptyGpsData.geoidal_separation, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Geoidal Separation)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Geoidal Separation)\n");
    }

    if (!(strcmp(emptyGpsData.units_separation, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Units of Geoidal Separation)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Units of Geoidal Separation)\n");
    }

    if (!(strcmp(emptyGpsData.age_correction, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Age Correction)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Age Correction)\n");
    }

    if (!(strcmp(emptyGpsData.correction_sta, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Units of Age Correction)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Units of Age Correction)\n");
    }

    if (!(strcmp(emptyGpsData.calculated_checksum, error)))
    {
        ESP_LOGD(TAG, "Test case 2: Passed (Calculated Checksum)\n");
    }
    else
    {
        ESP_LOGE(TAG, "Test case 2: Failed (Calculated Checksum)\n");
    }
}

void app_main(void)
{
    runTests(); // Run the unit tests
}