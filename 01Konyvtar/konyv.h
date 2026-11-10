#ifndef INC_01KONYVTAR_KONYV_H
#define INC_01KONYVTAR_KONYV_H

typedef enum OlvasasiAllapot {
    OLVASOTT,
    FOLYAMATBAN,
    NEMOLVASOTT
} OlvasasiAllapot;

typedef struct Konyv {
    int id;
    char cim[101];
    char szerzo[101];
    int oldalszam;
    char kategoria[51];
    int kiadasev;
    OlvasasiAllapot allapot;
    int ertekeles;

    struct Konyv *kovetkezo;
} Konyv;

typedef struct Olvasas {
    int ID;
    int olvasasID;
    int osszesOldal;
    char kezdes[11];
    char utolso_rekord[11];
    char befejezes[11];
    int aktoldal;
} Olvasas;

void konyv_hozzaad(Konyv **elso);

#endif
