#include "konyv.h"
#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

int kovetkezo_id(Konyv *elso);

void konyv_hozzaad(Konyv **elso) {
    Konyv *uj = (Konyv *) malloc(sizeof(Konyv));

    if (uj == NULL) {
        printf("Memoriafoglalasi hiba!\n");
        return;
    }

    uj->id = kovetkezo_id(*elso);

    printf("Cím: ");
    scanf(" %100[^\n]", uj->cim);

    printf("Szerzo: ");
    scanf(" %100[^\n]", uj->szerzo);

    printf("Oldalszam: ");
    scanf("%d", &uj->oldalszam);

    printf("Kategoria: ");
    scanf(" %50[^\n]", uj->kategoria);

    printf("Kiadas eve: ");
    scanf("%d", &uj->kiadasev);

    printf("Ertekeles (0 - ha nem még nincs olvasva): ");
    scanf("%d", &uj->ertekeles);


    int allapot = 0;
    printf("Olvasasi allapot: ");
    printf("Olvasasi allapot:\n");
    printf("1. Nem olvasott\n");
    printf("2. Folyamatban\n");
    printf("3. Olvasott\n");
    printf("Valasztas: ");
    scanf("%d", &allapot);

    switch (allapot) {
        case 1:
            uj->allapot = NEMOLVASOTT;
            break;
        case 2:
            uj->allapot = FOLYAMATBAN;
            break;
        case 3:
            uj->allapot = OLVASOTT;
            break;
        default:
            uj->allapot = NEMOLVASOTT;
            break;
    }

    uj->kovetkezo = NULL;

    if (*elso == NULL) {
        *elso = uj;
    } else {
        Konyv *akt = *elso;

        while (akt->kovetkezo != NULL) {
            akt = akt->kovetkezo;
        }

        akt->kovetkezo = uj;
    }
    printf("Konyv sikeresen hozzadva");
}

int kovetkezo_id(Konyv *elso) {
    int maxID = 0;

    Konyv *aktualis = elso;

    while (aktualis != NULL) {
        if (aktualis->id > maxID) {
            maxID = aktualis->id;
        }
        aktualis = aktualis->kovetkezo;
    }

    return maxID + 1;
}
