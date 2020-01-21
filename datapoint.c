//
// Created by lufle002 on 20.01.20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datapoint.h"

/**
 * Anzahl der Zeilen einer Datei auslesen
 * @param filename Dateiname
 * @return Anzahl der Zeilen
 */
int read_file_lines(char* filename) {
    FILE* fp;
    int lineCount = 0;
    char ch;

    if ((fp = fopen(filename, "r")) != NULL) {
        while (!feof(fp)) {
            ch = fgetc(fp);
            if (ch == '\n')
                ++lineCount;
        }

        fclose(fp);
        return ++lineCount;
    } else {
        return 0;
    }
}

/**
 * Auslesen aller Messdaten in der Datei
 * @param filename Dateiname
 * @param lines  Anzahl der Zeilen in der Datei
 * @return Array mit den Messdaten. Sind keine Messdaten vorhanden oder ist ein Fehler aufgetreten
 * wird NULL zurückgegeben
 */
datapoint_t* read_file_data(char* filename, int lines) {
    FILE* fp;
    datapoint_t* datapoint = NULL;
    char lineBuffer[200];
    int currentLine = 0;

    if (lines > 0) {
        datapoint = (datapoint_t*)malloc(lines * sizeof(datapoint_t));

        if ((fp = fopen(filename, "r")) != NULL) {
            fseek(fp, 0, SEEK_SET);

            while (fgets(lineBuffer, sizeof(lineBuffer), fp)) {
                datapoint_t tmpDatapoint;

                sscanf(lineBuffer, "%s\t%s\t%lf\t%lf\t%d\t%d\t%d\t%d\t%lf\t%lf\t%lf\t%d\t%lf\n", tmpDatapoint.details.event,
                       tmpDatapoint.details.datetime, &tmpDatapoint.details.latitude, &tmpDatapoint.details.longitude,
                        &tmpDatapoint.details.altitude, &tmpDatapoint.details.hhh, &tmpDatapoint.details.hgeom1,
                        &tmpDatapoint.details.hgeom2, &tmpDatapoint.details.PPPP, &tmpDatapoint.details.TTT,
                        &tmpDatapoint.details.RH, &tmpDatapoint.details.dd, &tmpDatapoint.details.ff);



                datapoint[currentLine] = tmpDatapoint;

                ++currentLine;
            }

            return datapoint;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

/**
 * Ausgeben der Messdaten
 * @param datapoint Datapoint
 * @param lines Anzahl der Messdaten
 */
void print_datapoint(datapoint_t* datapoint, int lines) {
    for (int i = 0; i < lines; i++) {
        printf("%s %s %lf %lf %d %d %d %d %lf %lf %lf %d %lf\n", datapoint[i].details.event, datapoint[i].details.datetime,
                datapoint[i].details.latitude, datapoint[i].details.longitude, datapoint[i].details.altitude, datapoint[i].details.hhh,
                datapoint[i].details.hgeom1, datapoint[i].details.hgeom2, datapoint[i].details.PPPP, datapoint[i].details.TTT, datapoint[i].details.RH,
                datapoint[i].details.dd, datapoint[i].details.ff);
    }
}