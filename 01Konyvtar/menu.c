#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "fajl.h"

void konyvtar_menu(Konyv **elso);

void olvasasi_menu(void);

bool vizsgal(int *szam) {
    if (scanf("%d", szam) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return false;
    }
    return true;
}

void fomenu(Konyv** elso) {
    int valasztas = 0;

    do {
        printf("\n=== FOMENU ===\n");
        printf("1. Konyvtar\n");
        printf("2. Olvasasi naplo\n");
        printf("3. Adatok mentese fajlba\n");
        printf("4. Adatok betoltese fajlbol\n");
        printf("5. Kilepes\n");

        printf("Valasztas: ");

        if (!vizsgal(&valasztas)) {
            printf("HIBA: Nem számot adtál meg!\n");
            continue;
        }

        switch (valasztas) {
            case 1:
                konyvtar_menu(elso);
                break;
            case 2:
                olvasasi_menu();
                break;
            case 3:
                printf("Adatok mentese\n");
                break;
            case 4:
                printf("Adatok betoltese\n");
                konyvek_felszabadit(*elso);
                *elso = konyv_beolvasas("konyvek.csv");
                break;
            case 5:
                printf("Kilepes...\n");
                break;
            default:
                printf("Hibas menupont!\n");
        }
    } while (valasztas != 5);
}

void konyvtar_menu(Konyv** elso) {
    int valasztas = 0;

    do {
        printf("\n=== KONYVTAR ===\n");
        printf("1. Osszes konyv listazasa\n");
        printf("2. Uj konyv hozzaadasa\n");
        printf("3. Konyv keresese cim vagy szerzo alapjan\n");
        printf("4. Konyv adatainak modositasa\n");
        printf("5. Konyv torlese\n");
        printf("6. Vissza a fomenuhoz\n");

        printf("Valasztas: ");

        if (!vizsgal(&valasztas)) {
            printf("HIBA: Nem számot adtál meg!\n");
            continue;
        }

        switch (valasztas) {
            case 1:
                printf("Osszes konyv listazasa\n");
                konyvek_kiir(*elso);
                break;
            case 2:
                printf("Uj konyv hozzaadasa\n");
                break;
            case 3:
                printf("Konyv keresese\n");
                break;
            case 4:
                printf("Konyv modositasa\n");
                break;
            case 5:
                printf("Konyv torlese\n");
                break;
            case 6:
                break;
            default:
                printf("Hibas menupont!\n");
        }
    } while (valasztas != 6);
}


void olvasasi_menu(void) {
    int valasztas = 0;

    do {
        printf("\n=== OLVASASI NAPLO ===\n");
        printf("1. Folyamatban levo konyvek listazasa\n");
        printf("2. Konyv olvasasanak megkezdese\n");
        printf("3. Haladas rogzitese\n");
        printf("4. Konyv megjelolese elolvasottkent\n");
        printf("5. Vissza a fomenuhoz\n");

        printf("Valasztas: ");

        if (!vizsgal(&valasztas)) {
            printf("HIBA: Nem számot adtál meg!\n");
            continue;
        }

        switch (valasztas) {
            case 1:
                printf("Folyamatban levo konyvek\n");
                break;
            case 2:
                printf("Olvasas megkezdese\n");
                break;
            case 3:
                printf("Haladas rogzitese\n");
                break;
            case 4:
                printf("Konyv befejezese\n");
                break;
            case 5:
                break;
            default:
                printf("Hibas menupont!\n");
        }
    } while (valasztas != 5);
}
