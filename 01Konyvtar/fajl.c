#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fajl.h"
#include "debugmalloc.h"
#include "konyv.h"

//felszabaditja a memoriat
void konyvek_felszabadit(Konyv *elso) {
    Konyv *aktualis = elso;

    while (aktualis != NULL) {
        Konyv *kovetkezo = aktualis->kovetkezo;

        free(aktualis);

        aktualis = kovetkezo;
    }
}
//kiirja a konyvek listat
void konyvek_kiir(Konyv *elso) {
    Konyv *aktualis = elso;

    printf("\n");
    printf(
        "+-----+----------------------+----------------------+-------+-----------------+------+--------------+-----------+\n");
    printf("| %-3s | %-20s | %-20s | %-5s | %-15s | %-4s | %-12s | %-9s |\n",
           "ID", "Cim", "Szerzo", "Oldal", "Kategoria", "Ev", "Allapot", "Ertekeles");
    printf(
        "+-----+----------------------+----------------------+-------+-----------------+------+--------------+-----------+\n");

    while (aktualis != NULL) {
        char *allapot;

        switch (aktualis->allapot) {
            case OLVASOTT:
                allapot = "Olvasott";
                break;

            case FOLYAMATBAN:
                allapot = "Folyamatban";
                break;

            case NEMOLVASOTT:
                allapot = "Nem olvasott";
                break;
        }

        printf("| %-3d | %-20s | %-20s | %-5d | %-15s | %-4d | %-12s | %-9d |\n",
               aktualis->id,
               aktualis->cim,
               aktualis->szerzo,
               aktualis->oldalszam,
               aktualis->kategoria,
               aktualis->kiadasev,
               allapot,
               aktualis->ertekeles);

        aktualis = aktualis->kovetkezo;
    }

    printf(
        "+-----+----------------------+----------------------+-------+-----------------+------+--------------+-----------+\n");
}
//fajlbol olvassa es feltolti a konyvek adatait listaba
Konyv *konyv_beolvasas(const char *fajlnev) {
    FILE *fajl = fopen(fajlnev, "r");

    if (fajl == NULL) {
        printf("Hibás fájlnév");
        return NULL;
    }

    Konyv *elso = NULL;
    Konyv *utolso = NULL;

    char sor[400];

    while (fgets(sor, sizeof(sor), fajl) != NULL) {
        Konyv *uj = (Konyv *) malloc(sizeof(Konyv));

        if (uj == NULL) {
            printf("Memoriafoglalasi hiba");
            fclose(fajl);
            return elso;
        }

        uj->kovetkezo = NULL;

        char *adat = strtok(sor, ";");
        uj->id = atoi(adat);

        adat = strtok(NULL, ";");
        strcpy(uj->cim, adat);

        adat = strtok(NULL, ";");
        strcpy(uj->szerzo, adat);

        adat = strtok(NULL, ";");
        uj->oldalszam = atoi(adat);

        adat = strtok(NULL, ";");
        strcpy(uj->kategoria, adat);

        adat = strtok(NULL, ";");
        uj->kiadasev = atoi(adat);

        adat = strtok(NULL, ";");
        if (strcmp(adat, "olvasott") == 0) {
            uj->allapot = OLVASOTT;
        } else if (strcmp(adat, "folyamatban") == 0) {
            uj->allapot = FOLYAMATBAN;
        } else {
            uj->allapot = NEMOLVASOTT;
        }

        adat = strtok(NULL, ";\n");
        uj->ertekeles = atoi(adat);

        if (elso == NULL) {
            elso = uj;
            utolso = uj;
        } else {
            utolso->kovetkezo = uj;
            utolso = uj;
        }
    }

    fclose(fajl);
    return elso;
}
