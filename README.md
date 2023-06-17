# C Library for GPS NMEA 0183 Data Parsing

The GPS Parser Library is a C library for parsing GPS data from NMEA 0183 (GPGGA) payloads. It provides a simple and easy-to-use interface for extracting GPS data fields such as latitude, longitude, altitude, time, and the number of satellites from NMEA 0183 (GPGGA) strings.

## Approach
The code for the GPS data parser follows these steps to extract the necessary information and monitor missing or incorrect data:

1. The GPS data parser code consists of a function called `Parse_gps_data` to fulfill the requirements. This function takes a GPGGA string, performs operations to extract useful information, and returns the field data in a structure.

2. At the start of the function, the code initializes all the fields with default values.

3. Then, it checks whether the string starts with '$GPGGA' using the built-in string function `strcmp()`. If it does, the code proceeds with the parsing. Otherwise, the function returns, and the code execution is terminated.

4. Before parsing, it checks the validity of the checksum. It retrieves the exact checksum value given in the GPGGA sentence using a for loop. Next, it calculates the checksum of the given data by adding the XOR of all the characters between '$' and '*'. The XORed sum is then converted to hexadecimal to obtain the actual hexadecimal checksum.

5. The calculated checksum is compared with the extracted checksum from the given string to validate the integrity of the data.

6. Once the checksum is validated, the code starts parsing the time stamp (the first field) using the built-in function `strsep()`. This function divides a string into two halves based on the provided delimiter. If `strsep()` returns NULL, it means there is no data between two consecutive commas.

7. If the time field is NULL, the code stores the default value into the `time_stamp` field.

8. `strsep()` is used iteratively until the last available field. If `strsep()` returns an empty string, a message "Not Found!" is stored in that field.

## Usage
To use the GPS Parser Library, follow these steps:

## Installation
To include the GPS Parser component in your IDF project, follow these steps:

1. Download or clone the repository to your local machine.
2. Include the `gps_data_parser.h` header file in your C source code.
3. Link against the GPS Parser Library during compilation.

## Prerequisites
To make this library work perfectly, the following tools are needed:

- ESP-IDF v5.0 Stable release
- ESP-IDF toolchain

Download or clone the repository to your local machine.
Include the `data_parser.h` header file in your C source code.
Link against the GPS Parser Library during compilation.

## Functions Reference
`gpsDataF(char* sentence, struct gps_data_parse* gpsData)`
The `gpsDataF()` function parses a NMEA 0183 (GPGGA) sentence and extracts the GPS data fields into a `struct gps_data_parse`.

Parameters:
- `sentence` - A pointer to a null-terminated string representing a NMEA 0183 (GPGGA) sentence.
- `gpsData` - A pointer to a `struct gps_data_parse` to store the parsed GPS data.

`printData(struct gps_data_parse* gpsData)`
The `printData()` function prints the extracted GPS data fields stored in a `struct gps_data_parse` to the console.

Parameters:
- `gpsData` - A pointer to a `struct gps_data_parse` containing the parsed GPS data.

Contributing
If you would like to contribute to the GPS NMEA 0183 Data Parsing library, please feel free to submit a pull request.
