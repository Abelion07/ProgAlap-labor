#include <stdio.h>

int kob(int bekert) {
    return bekert * bekert * bekert;
}

int abszolutertek(int be) {
    if (be < 0) {
        return be * (-1);
    } else {
        return be;
    }
}

int maganhangzo(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }

    return 0;
}


typedef struct Datum {
    int ev, ho, nap;
} Datum;

typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;

void datum_kiir(Datum d);

void versenyzo_kiir(Versenyzo v);

int main(void) {
    // tombok_frissito;
    double szamok[10] = {2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8};

    /* Az eredeti tömb kiírása */
    printf("Összesen %d szám van.\n", 10);
    for (int i = 0; i < 10; i += 1)
        printf("[%d]=%g ", i, szamok[i]);
    printf("\n\n");

    /* Negatívak indexeinek kigyűjtése */
    double negativak[10];
    int negtombelem = 0;
    for (int i = 0; i < 10; i += 1) {
        if (szamok[i] < 0) {
            negativak[negtombelem] = szamok[i];
            negtombelem += 1;
        }
    }

    /* Negatívak kiírása */
    for (int i = 0; i < negtombelem; i++)
        printf("%g ", negativak[i]);

    // fuggvenyek_alapok;
    printf("%d\n", kob(4));
    printf("%d\n", abszolutertek(10));
    printf("%d\n", abszolutertek(-10));

    // maganhangzo;
    // char c;
    //
    // while (scanf("%c", &c) != EOF) {
    //
    //     char kisbetu = c;
    //
    //     if (kisbetu >= 'A' && kisbetu <= 'Z') {
    //         kisbetu = kisbetu + ('a' - 'A');
    //     }
    //
    //     if (maganhangzo(kisbetu)) {
    //         printf("%cv%c", c, kisbetu);
    //     } else {
    //         printf("%c", c);
    //     }
    // }

    //struktura_bemelegito;
    typedef struct koordinatak {
        double x, y;
    } koordinatak;

    koordinatak p1 = {2.2, 1.6};
    koordinatak p2;

    printf("x2: ");
    scanf("%lf", &p2.x);
    printf("y2: ");
    scanf("%lf", &p2.y);

    koordinatak p3;

    p3.x = (p1.x + p2.x) / 2;
    p3.y = (p1.y + p2.y) / 2;

    printf("Felezopont: %.2f; %.2f", p3.x, p3.y);

    //Összetett adatszerkezet

    Versenyzo versenyzok[5] =
    {
        {"Am Erika", {1984, 5, 6}, 1},
        {"Break Elek", {1982, 9, 30}, 3},
        {"Dil Emma", {1988, 8, 25}, 2},
        {"Kasza Blanka", {1979, 6, 10}, 5},
        {"Reset Elek", {1992, 4, 5}, 4},
    };

    /* 0-s versenyző neve - printf %s */
    printf("%s\n", versenyzok[0].nev);
    /* 2-es versenyző helyezése */
    printf("%d\n", versenyzok[2].helyezes);
    /* 4-es versenyző születési dátumát (írd meg a datum_kiir függvényt!) */
    datum_kiir(versenyzok[4].szuletes);
    /* 1-es versenyző nevének kezdőbetűjét (ne feledd, a sztring karaktertömb) */
    printf("%c\n", versenyzok[1].nev[0]);
    /* az 1-es versenyző dobogós-e? igen/nem, akár ?: operátorral, de egy printf-fel */
    printf(versenyzok[1].helyezes <= 3 ? "igen\n" : "nem\n");
    /* az 4-es versenyző gyorsabb-e, mint a 3-as versenyző? */
    printf(versenyzok[4].helyezes < versenyzok[3].helyezes ? "gyorsabb\n" : "nem gyorsabb\n");
    /* az 1-es versenyző ugyanabban az évben született-e, mint a 2-es? */
    printf(versenyzok[1].szuletes.ev == versenyzok[2].szuletes.ev
               ? "ugyanabban az evben szulettek\n"
               : "Nem ugyanabban az evben szulettek\n");

    /* egészítsd ki a versenyzo_kiir() függvényt,
    * aztán írd ki az 1-es versenyző összes adatát */
    versenyzo_kiir(versenyzok[1]);
    /* végül listázd ki az összes versenyzőt sorszámozva, összes adatukkal. */
    for (int i = 0; i < 5; i += 1) {
        printf("%d.", i);
        versenyzo_kiir(versenyzok[i]);
    }

    // Menüvezérlet program
    int a = 1;
    int bekert;

    do {
        printf("a = %d\n", a);
        printf("0. Alapertek visszaallitasa (a = 1)\n"
            "1. Hozzaad 1-et\n"
            "2. Megforditja az elojelet\n"
            "3. Szorozza 2-vel\n"
            "9. Kilepes\n");

        scanf("%d", &bekert);

        switch (bekert) {
            case 0:
                a = 1;
                break;
            case 1:
                a += 1;
                break;
            case 2:
                a = a * -1;
                break;
            case 3:
                a = a * 2;
                break;
            case 9:
                break;
        }
    } while (bekert != 9);

    return 0;
}

void datum_kiir(Datum d) {
    /* dátum kiírása */
    printf("%04d.%02d.%02d.\n", d.ev, d.ho, d.nap);
}

void versenyzo_kiir(Versenyzo v) {
    /* a versenyző összes adatának kiírása */
    printf("nev: %s\n ", v.nev);
    printf("szuletesi datum: ");
    datum_kiir(v.szuletes);
    printf("helyezes: %d\n", v.helyezes);
}
