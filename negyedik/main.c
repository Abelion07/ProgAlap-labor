#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kocka(double *terfogat, double *felszin, double o)
{
    *terfogat = o*o*o;
    *felszin = 6*o*o;
}

int Akereses(int t[], int keresett, int meret)
{
    for (int i = 0; i < meret; i += 1)
    {
        if (t[i] == keresett)
        {
            return i;
        }
    }
    return -1;
}

int *Bkereses(int *t, int keresett, int meret)
{
    for (int i = 0; i < meret; i+=1)
    {
        if (t[i] == keresett)
        {
            return &t[i];
        }
    }
    return NULL;
}

int *Ckereses(int *t, int meret, int keresett)
{
    for (int *p = t; p != t + meret; ++p)
    {
        if (*p == keresett)
        {
            return p;
        }
    }
    return NULL;
}

void csere(char *be, char *ki, int hossz){
    int j = 0;
    for (int i = 0; i < hossz; i += 1){
        if (be[i] != ' '){
            ki[j] = be[i];
            j += 1;
        }
    }
    ki[j] = '\0';
}

int main()
{
    //2. feladat - Kocka
    double oldal = 2.7, terfogat, felszin;
    kocka(&terfogat, &felszin, oldal);
    printf("A kocka felszine: %g\nA kocka terfogata: %g\n", felszin, terfogat);

    //3.feladat
    int tomb[8] = {1,2,3,4,5,6,7,8};
    int keresett_szam = 3;

    //a)
    int index = Akereses(tomb, keresett_szam, 8);
    if (index == -1){
        printf("Nincs talalat\n");
    }
    else {
        printf("A keresett szam indexe: %d\n", index);
    }

    //b)
    int *Btalalat = Bkereses(tomb, keresett_szam, 8);
    printf("A talalt elem memoriacimkeje: %p\n", Btalalat);
    printf("A talalt eleme indexe: %d\n", *Btalalat - *tomb);


    //c),
    int *Ctalalat = Ckereses(tomb, 8, keresett_szam);
    printf("Keresett elem memoriacime: %p\n", Ctalalat);
    printf("A keresett elem indexe = %d\n", *Ctalalat - *tomb);


    //4. feladat
    printf("\nKerek egy nevet: ");
    char nev[50];
    scanf("%s", nev);

    for(int i = 0; nev[i] != '\0'; i += 1){
        printf("%c\n", nev[i]);
    }
    printf("\n");

    //5. feladat
    char BEszoveg[50] = "   hello, mizu?  ";
    char KIszoveg[50];
    int szoveghossz = strlen(BEszoveg);
    csere(BEszoveg, KIszoveg, szoveghossz);
    printf("%s", KIszoveg);

    return 0;

}