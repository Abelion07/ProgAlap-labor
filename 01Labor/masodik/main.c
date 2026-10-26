#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int szamokszorzata()
{
    int n = 1;
    int szorzat = 1;
    while (n <= 8)
    {
        szorzat = szorzat * n;
        n++;
    }

    printf("%d\n", szorzat);
    return 0;
}

int n_megallapitasa()
{
    int szorzat = 1;
    int n = 8;
    while (n > 1)
    {
        szorzat *= n;
        n -= 1;
    }
    printf("%d\n", szorzat);
    return 0;
    //n = 3 => 6720
}

int lnko()
{
    int a = 11220;
    int b = 2002;
    while (b > 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("lnko = %d\n", a);
    return 0;
    //44
}

int karakterkod()
{
    char betu;
    while (scanf("%c", &betu) == 1)
        printf("betu='%c', betu=%d\n", betu, betu);

    return 0;
}

int tulindexeles()
{
    int tomb[10];

    for (int i = 0; i < 10; i += 1)
        tomb[i] = i * 10;

    int i = 0;
    while (i < 20)
    {
        printf("%d. elem: %d\n", i, tomb[i]);
        i += 1;
    }

    return 0;
}

int legkisebb()
{
    int tomb[10] = {25, 69, 54, 8, 77, 6, 29, 10, 3, 98};
    int legkisebb = tomb[0];
    int indexe = 0;

    for (int i = 1; i < 10; i++)
    {
        if (tomb[i] < legkisebb)
        {
            legkisebb = tomb[i];
            indexe = i;
        }
    }
    printf("A legkisebb szam: %d\n", legkisebb);
    printf("A legkisebb indexe: %d\n", indexe);
    return 0;
}

int tombleptetes(){
    char szo[10] = {'P', 'i', 't', 'a', 'g', 'o', 'r', 'a', 's', 'z'};

    for (int i = 0; i < 10; i += 1)
    {
        for (int j = 0; j < 10; j += 1)
        {
            printf("%c ", szo[j]);
        }
        printf("\n");

        char elsokarakter = szo[0];
        for (int j = 0; j < 9; j += 1)
        {
            szo[j] = szo[j + 1];
        }
        szo[9] = elsokarakter;
    }
    return 0;
}

int main()
{
    szamokszorzata();
    n_megallapitasa();
    lnko();
    // karakterkod();
    tulindexeles();
    legkisebb();
    tombleptetes();
    return 0;
}