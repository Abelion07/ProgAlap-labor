#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "olvasas.h"
#include "debugmalloc.h"
//fajlbol olvassa es feltolti az olvasas adatait listaba
Olvasas *olvasas_beolvasas(const char* fajlnev) {
    FILE *file = fopen(fajlnev, "r");

    if (file == NULL) {
        printf("Hiba a fajl betoltesenel.");
        return NULL;
    }

    Olvasas* elso = NULL;
    Olvasas* utolso = NULL;

    char sor[200];
    while (fgets(sor, sizeof(sor), file) != NULL) {
        Olvasas *uj = (Olvasas *) malloc(sizeof(Olvasas));

        if (uj == NULL) {
            printf("Memoriafoglalasi hiba\n");
            fclose(file);
            return elso;
        }

        uj->kovetkezo = NULL;

        char *adat = strtok(sor, ";");
        uj->ID = atoi(adat);

        adat = strtok(NULL, ";");
        uj->konyv_id = atoi(adat);

        adat = strtok(NULL, ";");
        strcpy(uj->kezdes, adat);

        adat = strtok(NULL, ";");
        strcpy(uj->utolso_rekord, adat);

        adat = strtok(NULL, ";");
        uj->aktoldal = atoi(adat);

        adat = strtok(NULL, ";\r\n");
        strcpy(uj->befejezes, adat);

        if (elso == NULL) {
            elso = uj;
            utolso = uj;
        } else {
            utolso->kovetkezo = uj;
            utolso = uj;
        }
    }

    fclose(file);
    return elso;
}
//felszabaditja az olvasasi adatoknak foglalt helyet.
void olvasas_felszabadit(Olvasas *elso) {
    Olvasas *aktualis = elso;

    while (aktualis != NULL) {
        Olvasas *kovetkezo = aktualis->kovetkezo;
        free(aktualis);
        aktualis = kovetkezo;
    }
}