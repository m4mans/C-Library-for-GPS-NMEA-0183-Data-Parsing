/*
Author: Muhammad Ans
Cowlar Task for Embedded Systems
This is an example code to parse GPS Data from NMEA 0183 messaging protocol.
*/

#include <stdio.h>
#include "gps_data_parse.h" //Header to parse GPS data
#include "esp_log.h"

static const char *TAG = "";

void app_main(void)
{
  char payload[] = "$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";
  // char payload[] = "";
  //char payload[] = "$GPGGA,636322.22,3404.7041778,N,07044.3966270,W,4,13,1.00,495.144,M,29.200,M,0.10,0000*5F";

  gps_data gpsData;
  gpsData = Parse_gps_data(payload);

  if (gpsData.check_sum_matched)
  {
    ESP_LOGW(TAG, "CHECKSUM VALIDATED!\n");
  }
  else
  {
    ESP_LOGW(TAG,"CHECKSUM IS NOT VALIDATED!\n");
  }

    // prints all the fields
    // print_data(gpsData); //prints all the fields at once

    // printing individual fields
    ESP_LOGD(TAG,"Time:                   %s\n", gpsData.time_stamp);
    ESP_LOGD(TAG,"Latitude:               %s\n", gpsData.latitude);
    ESP_LOGD(TAG,"Latitude Direction:     %s\n", gpsData.lat_direction);
    ESP_LOGD(TAG,"Longitude:              %s\n", gpsData.longitude);
    ESP_LOGD(TAG,"Longitude Direction:    %s\n", gpsData.lon_direction);
    ESP_LOGD(TAG,"Quality Indicator:      %s\n", gpsData.qual_ind);
    ESP_LOGD(TAG,"Number of Satellites:   %s\n", gpsData.num_satellites);
    ESP_LOGD(TAG,"HDOP:                   %s\n", gpsData.HDOP);
    ESP_LOGD(TAG,"Altitude of Antenna:    %s\n", gpsData.altitude_antenna);
    ESP_LOGD(TAG,"Unit of Altitude:       %s\n", gpsData.units_antenna);
    ESP_LOGD(TAG,"Geoidal Separation:     %s\n", gpsData.geoidal_separation);
    ESP_LOGD(TAG,"Unit of Geoidal:        %s\n", gpsData.units_separation);
    ESP_LOGD(TAG,"Age Correction:         %s\n", gpsData.age_correction);
    ESP_LOGD(TAG,"Station Correction:     %s\n", gpsData.correction_sta);
    ESP_LOGD(TAG,"Parsed Check Sum        %s\n", gpsData.parsed_checksum);
    ESP_LOGD(TAG,"Calculated Check Sum    %s\n", gpsData.calculated_checksum);
    printf("dhd %s", gpsData.calculated_checksum);
}
