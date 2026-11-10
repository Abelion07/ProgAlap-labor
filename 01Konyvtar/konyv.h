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

void konyv_hozzaad(Konyv **elso);

#endif
