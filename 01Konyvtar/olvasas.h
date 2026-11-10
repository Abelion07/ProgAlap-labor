#ifndef INC_01KONYVTAR_OLVASAS_H
#define INC_01KONYVTAR_OLVASAS_H

typedef struct Olvasas {
    int ID;
    int olvasasID;
    int osszesOldal;
    char kezdes[11];
    char utolso_rekord[11];
    char befejezes[11];
    int aktoldal;
} Olvasas;

#endif //INC_01KONYVTAR_OLVASAS_H
