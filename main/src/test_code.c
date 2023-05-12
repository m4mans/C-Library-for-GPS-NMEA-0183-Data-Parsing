/*
Author: Muhammad Ans
Cowlar Task for Embedded Systems
This is a test code to parse GPS Data from NMEA 0183 messaging protocol.
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "data_parse.h" //Header to parse GPS data

void app_main(void)
{
  // Sample payloads from NMEA 0183 Protocol
  const char *packet = "Lorem$GPGGA,210230,3855.4487,N,09446.0071,W,1,07,1.1,370.5,M,-29.5,M,,*7A\r\n987u";
  // const char *packet = "Lorem$GPGGA,210230,3855.4487,N,09446.0071,W,1,07,1.1,370.5,M,-29.5,M,,*7A\r\n987u";
  // const char *packet = "Lorem$GPGGA,210230,3855.4487,N,09446.0071,W,1,07,1.1,370.5,M,-29.5,M,,*7A\r\n987u";

  // struct declaration to get data from the library
  struct gps_data_parse gpsDataS;

  // library function Call
  if (gpsDataF(packet, &gpsDataS)) // pass the data payload and pointer to the struct
  {
    // print all fields at once
    printData(&gpsDataS);

    // print missing fields if any
    printf("%s\n", gpsDataS.fieldsError);
    // prints Check Sum
    printf("Check Sum: %s\n", gpsDataS.checkSum);
  }
  else
  {
    // Get the reason of failure
    printf("%s\n", gpsDataS.failures);
  }
  vTaskDelay(100);
}
