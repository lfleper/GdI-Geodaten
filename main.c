#include "main.h"


char* FILENAME_SHORT = "radiosonde_auszug_kurz.txt";
char* FILENAME_LONG = "radiosonde_auszug_lang.txt";
char* FILENAME_LONG_TEST = "radiosonde_auszug_kurz.txt";

int main() {
    int lines = read_file_lines(FILENAME_LONG);
    datapoint_t* datapoint = read_file_data(FILENAME_LONG, lines);

    sort(datapoint, lines, LATITUDE);

    if (datapoint != NULL) {
        print_datapoint(datapoint, lines);
        free(datapoint);
    }

    return EXIT_SUCCESS;
}
void sort(datapoint_t *datapoint, int elements, SORT_TYPE_t sortType){
    mergeSort(datapoint, 0, elements - 1, sortType);
}

void merge(datapoint_t *datapoint, int p, int q, int r, SORT_TYPE_t sortType) {
    int n1 = q - p + 1;
    int n2 = r - q;

    datapoint_t *L = (datapoint_t*) malloc(sizeof(datapoint_t) * (n1 + 2));
    datapoint_t *R = (datapoint_t*) malloc(sizeof(datapoint_t) * (n2 + 2));

    for (int i = 1; i <= n1; i++) {
        L[i] = datapoint[p + i - 1];
    }

    for (int j = 1; j <= n2; j++) {
        R[j] = datapoint[q + j];
    }

    L[n1 + 1].details.latitude = INT_MAX;
    R[n2 + 1].details.latitude = INT_MAX;

    L[n1 + 1].details.longitude = INT_MAX;
    R[n2 + 1].details.longitude = INT_MAX;

    L[n1 + 1].details.TTT = INT_MAX;
    R[n2 + 1].details.TTT = INT_MAX;


    int i = 1;
    int j = 1;
    for (int k = p; k <= r; k++){
        switch (sortType){
            case LATITUDE:
                if(L[i].details.latitude <= R[j].details.latitude){
                    datapoint[k] = L[i];
                    i++;
                } else {
                    datapoint[k] = R[j];
                    j++;
                }
                break;
            case LONGITUDE:
                if(L[i].details.longitude <= R[j].details.longitude){
                    datapoint[k] = L[i];
                    i++;
                } else {
                    datapoint[k] = R[j];
                    j++;
                }
                break;
            case DISTANZ:
                break;
            case TTT:
                if(L[i].details.TTT <= R[j].details.TTT){
                    datapoint[k] = L[i];
                    i++;
                } else {
                    datapoint[k] = R[j];
                    j++;
                }
                break;
        }
    }
    free(L);
    free(R);
}
void mergeSort(datapoint_t *datapoint, int p, int r, SORT_TYPE_t sortType) {
    if (p < r) {
        int q = floor((p + r) / 2);
        mergeSort(datapoint, p, q, sortType);
        mergeSort(datapoint, q + 1, r, sortType);
        merge(datapoint, p, q, r, sortType);
    }
}
