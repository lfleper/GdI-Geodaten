//
// Created by lufle002 on 20.01.20.
//

#ifndef GDI_DATAPOINT_H
#define GDI_DATAPOINT_H

typedef struct polar {
    double a;
    double b;
} polar_t;

typedef struct cartesian {
    double x;
    double y;
    double z;
} cartesian_t;

typedef struct details {
    char event[30];
    char datetime[30];
    double latitude;
    double longitude;
    int altitude;
    int hhh;
    int hgeom1;
    int hgeom2;
    double PPPP;
    double TTT;
    double RH;
    int dd;
    double ff;
} details_t;

typedef struct datapoint {
    details_t details;
    polar_t polar;
    cartesian_t cartesian;
} datapoint_t;




/**
 * Anzahl der Zeilen einer Datei auslesen
 * @param filename Dateiname
 * @return Anzahl der Zeilen
 */
int read_file_lines(char* filename);

/**
 * Auslesen aller Messdaten in der Datei
 * @param filename Dateiname
 * @param lines  Anzahl der Zeilen in der Datei
 * @return Array mit den Messdaten. Sind keine Messdaten vorhanden oder ist ein Fehler aufgetreten
 * wird NULL zurückgegeben
 */
datapoint_t* read_file_data(char* filename, int lines);

/**
 * Ausgeben der Messdaten
 * @param datapoint Datapoint
 * @param lines Anzahl der Messdaten
 */
void print_datapoint(datapoint_t* datapoint, int lines);

#endif //GDI_DATAPOINT_H
