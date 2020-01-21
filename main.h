//
// Created by Tristan Schneider on 21.01.20.
//

#ifndef GDI_MAIN_H
#define GDI_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include "datapoint.h"
#include <math.h>
#include <limits.h>

typedef enum{
    LATITUDE = 0,
    LONGITUDE = 1,
    DISTANZ = 2,
    TTT = 3,
} SORT_TYPE_t;

void mergeSort(datapoint_t *datapoint, int p, int r, SORT_TYPE_t sortType);
void sort(datapoint_t *datapoint, int elements, SORT_TYPE_t sortType);
void merge(datapoint_t *datapoint, int p, int q, int r, SORT_TYPE_t sortType);

#endif //GDI_MAIN_H
