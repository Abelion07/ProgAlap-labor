#include <stdio.h>
#include <string.h>

typedef struct Fagyi {
    char iz[50];
    int mennyiseg;
} Fagyi;

int keres(Fagyi *tomb, int hossz, char const *mit) {
    for (int i = 0; i < hossz; i += 1) {
        if (strcmp(tomb[i].iz, mit) == 0) {
            return i;
        }
    }
    return -1;
}

int feladat2() {
    char iz[20];
    Fagyi fagyik[6] = {
        {"pisztacia", 0},
        {"karamell", 2},
        {"vanillia", 3},
        {"rumosdio", 6},
        {"kave", 9},
        {"tutti-frutti", 7},
    };
    while (scanf("%20[^\n]", iz) == 1) {
        int talalat = keres(fagyik, 6, iz);
        if (talalat != -1) {
            if (fagyik[talalat].mennyiseg > 0) {
                printf("%s %d db\n",
                       fagyik[talalat].iz,
                       fagyik[talalat].mennyiseg);
            } else {
                printf("A %s kifogyott.\n",
                       fagyik[talalat].iz);
            }
        } else {
            printf("%s nem is volt.\n", iz);
        }
    }
}
