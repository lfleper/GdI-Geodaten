#include <stdio.h>
#include <stdlib.h>
#include "datapoint.h"

const char* FILENAME_SHORT = "radiosonde_auszug_kurz.txt";
const char* FILENAME_LONG = "radiosonde_auszug_lang.txt";
const char* FILENAME_LONG_TEST = "radiosonde_auszug_kurz.txt";

int main() {
    int lines = read_file_lines(FILENAME_LONG);
    datapoint_t* datapoint = read_file_data(FILENAME_LONG, lines);

    if (datapoint != NULL) {
        print_datapoint(datapoint, lines);

        free(datapoint);
    }

    return EXIT_SUCCESS;
}
