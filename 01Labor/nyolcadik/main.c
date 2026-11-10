#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugmalloc.h"
//
int f1(void) {
    int n;
    printf("Kerem a tomb hosszat: ");
    scanf("%d", &n);

    double *t = malloc(n * sizeof(double));
    if (t == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i += 1) {
        scanf("%lf", &t[i]);
    }

    for (int i = n - 1; i >= 0; i -= 1) {
        printf("%.2f ", t[i]);
    }
    printf("\n");

    free(t);
    return 0;
}

int f2(void) {
    char txt[] = "hello";

    char *p = malloc((strlen(txt) + 1) * sizeof(char));
    strcpy(p, txt);
    printf("TXT: %s\n", p);

    free(p);
    return 0;
}

int f3() {
    double *t = NULL;
    int db = 0;
    double szam = 0;
    while (scanf("%lf", &szam) == 1 && szam != -1) {
        double *uj = malloc((db + 1) * sizeof(double));

        if (uj == NULL) {
            free(t);
            return 1;
        }

        for (int i = 0; i < db; i += 1) {
            uj[i] = t[i];
        }

        free(t);
        t = uj;
        t[db] = szam;
        db += 1;
    }

    for (int i = db - 1; i >= 0; i -= 1) {
        printf("%.2f ", t[i]);
    }
    free(t);
    return 0;
}

int f4() {
    char *t = NULL;
    char c;
    int db = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        char *uj = malloc((db + 2) * sizeof(char));

        if (uj == NULL) {
            free(t);
            return 1;
        }

        for (int i = 0; i < db; i += 1) {
            uj[i] = t[i];
        }
        free(t);

        t = uj;
        t[db] = c;
        db += 1;
    }

    t[db] = '\n';
    for (int i = 0; i < db; i += 1) {
        printf("%c", t[i]);
    }

    free(t);
    return 0;
}

char *hosszu_sort_olvas(void) {
    char *t = NULL;
    int db = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        char *uj = malloc((db + 2) * sizeof(char));

        if (uj == NULL) {
            free(t);
            return NULL;
        }

        for (int i = 0; i < db; i += 1) {
            uj[i] = t[i];
        }

        free(t);
        t = uj;

        t[db] = c;
        db++;
    }

    if (t == NULL) {
        t = malloc(sizeof(char));

        if (t == NULL)
            return NULL;
    }

    t[db] = '\0';

    return t;
}

int main() {
    f1();
    f2();
    f3();
    f4();

    printf("Irj be egy sort: ");

    char *szoveg = hosszu_sort_olvas();

    printf("Beolvasott szoveg: %s\n", szoveg);

    free(szoveg);

    return 0;
}