#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Fetch the current time
char *get_current_time() {

    // Fetch the current datetime
    time_t now = time(NULL);

    // Express the current datetime in the local timezone
    struct tm *timeinfo = localtime(&now);

    // Dynamically allocate memory for an array of 20 characters
    char *buffer = malloc(20 * sizeof(char));

    // Format the datetime
    strftime(buffer, 20, "%Y-%m-%d %H:%M", timeinfo);
    return buffer;
}


// Convert the current datetime to swatch time
char *get_swatch_time(char *date_time) {

    // Declare a tm with default values
    struct tm tm = {0};

    // Parse date_time and fill tm with values
    strptime(date_time, "%Y-%m-%d %H:%M:%S", &tm);

    // Calculate the current time
    int total_seconds = tm.tm_hour * 3600 + tm.tm_min * 60 + tm.tm_sec;

    // Convert the current time to swatch time
    double swatch_time = (double)total_seconds / 86.4;

    // Dynamically allocate memory for an array of 6 characters
    char *swatch_str = malloc(6 * sizeof(char));

    // Format the datetime
    snprintf(swatch_str, 20, "%04d-%02d-%02d @%03.0f",
    tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, swatch_time);
    return swatch_str;
}


int main() {
    char *date_time = get_current_time();
    char *swatch_time = get_swatch_time(date_time);
    printf("%s", swatch_time);

    // Free the dynamically allocated memory
    free(date_time);
    free(swatch_time);
    return 0;
}
