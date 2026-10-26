#include <stdio.h>
#include <string.h>

typedef struct Kaja {
    char nev[50];
    int mennyiseg;
} Kaja;

int keres(Kaja *k, int meret, char const *mit){
    for (int i = 0; i < meret; i+=1){
        if (strcmp(k[i].nev, mit) == 0){
            return i;
        }
    }
    return -1;
}

int main()
{
    Kaja k[2] = {
        {"hamburger", 10},
        {"sajtburger", 0}
    };
    char kaja[20];

    while(scanf("%[^\n]", kaja) == 1){
        int talalat = keres(k, 2, kaja);
        if (talalat != -1){
            if (k[talalat].mennyiseg > 0){
                printf("%s %d db", k[talalat].nev, k[talalat].mennyiseg);
            }
            else{
                printf("%s elfogyott.", k[talalat].nev);
            }
        }
        else{
            printf("Nincs találat.");
        }
    }
}
