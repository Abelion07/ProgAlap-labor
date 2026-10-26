#include <stdio.h>

int f1() {
    int nevezes[13] = {0};
    int darab = 0;
    int kat = 0;
    scanf("%d %d", &kat, &darab);
    while (kat != -1) {
        nevezes[kat - 1] += darab;
        scanf("%d %d", &kat, &darab);
    }
    for (int i = 0; i < 13; i += 1) {
        if (nevezes[i] > 40) {
            printf("%d.kategórában %d db", i + 1, nevezes[i]);
        }
    }
    return 0;
}

int f2() {
    int datumok[13] = {0};
    int kat = 0;
    int szul = 0;
    scanf("%d %d", &kat, &szul);
    while (kat != -1) {
        if (datumok[kat - 1] < szul) {
            datumok[kat - 1] = szul;
        }
        scanf("%d %d", &kat, &szul);
    }
    for (int i = 0; i < 13; i += 1) {
        printf("%d %d", kat, szul);
    }
}

int f3() {
    int meres[24] = {0};
    int ora, perc, sebesseg;
    scanf("%d %d", &ora, &sebesseg);
    while (ora != -1) {
        if (sebesseg > 155) {
            meres[ora] += 1;
        }
        scanf("%d %d", &ora, &sebesseg);
    }
    for (int i = 0; i < 24; i += 1) {
        printf("%d %d", i, meres[i]);
    }
    return 0;
}

int f4() {
    int meres[24] = {0};
    int ora, sebesseg;
    scanf("%d %d", &ora, &sebesseg);
    while (ora != -1) {
        if (sebesseg >= 160)
            meres[ora] += 90000;
        else
            meres[ora] += 30000;
        scanf("%d %d", &ora, &sebesseg);
    }
    for (int i = 0; i < 24; i += 1) {
        printf("%d %d", i, meres[i]);
    }
    return 0;
}

int f5() {
    int kiszolgalas[50] = {0};
    int kassza, penztaros, osszeg;
    scanf("%d %d", &penztaros, &osszeg);
    while (penztaros != -1) {
        kiszolgalas[penztaros - 1] += osszeg;
        scanf("%d %d", &penztaros, &osszeg);
    }
    for (int i = 0; i < 50; i += 1) {
        printf("%d.pénztáros %d Ft", i, kiszolgalas[i]);
    }
}

int f6() {
    int kiszolgalas[50] = {0};
    int kassza, penztaros, osszeg;
    scanf("%d %d", &penztaros, &osszeg);
    while (penztaros != -1) {
        if (osszeg >= 8000)
            kiszolgalas[penztaros - 1] += 1;
        scanf("%d %d", &penztaros, &osszeg);
    }
    for (int i = 0; i < 50; i += 1) {
        if (kiszolgalas[i] != 0)
            printf("%d.pénztáros %d db", i, kiszolgalas[i]);
    }
}

int main(void) {
    // f1();
    // f2();
    f3();
    // f4();
    // f5();

    return 0;
}
