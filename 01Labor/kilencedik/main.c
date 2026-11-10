#include <stdio.h>
#include <string.h>
#include "debugmalloc.h"

/*A masol fuggveny kijelol egy akkora tombnek szukseges helyet,
amelybe elfer a bemenetkent kapott tomb masolata*/
char *masol(char const *be) {
    char *uj = (malloc((strlen(be) + 1) * sizeof(char)));
    if (uj == NULL) {
        return NULL;
    }
    strcpy(uj, be);
    return uj;
}

void f1() {
    char *str = masol("alma");
    printf("%s\n", str);
    free(str);
}


char *hozzafuz(char *x, char const *y) {
    int hossz1 = strlen(x);
    int hossz2 = strlen(y);
    char *uj = realloc(x, (hossz1 + hossz2 + 1) * sizeof(char));
    if (uj == NULL)
        return NULL;

    strcat(uj, y);
    return uj;
}

void f2() {
    char *szo = masol("alma");
    char *bovites = "fa";

    char *uj = hozzafuz(szo, bovites);

    szo = uj;

    printf("%s\n", szo);
    free(szo);
}

char *resz(char const *szoveg, int kezdet, int veg) {
    int hossz = veg - kezdet;
    char *uj = malloc((hossz + 1) * sizeof(char));
    for (int i = 0; i < hossz; i++) {
        uj[i] = szoveg[kezdet + i];
    }
    uj[hossz] = '\0';
    return uj;
}

void f3() {
    char *a = resz("hello, vilag", 3, 9);
    printf("%s\n", a);
    free(a);
}

char *resz2(const char *be, int kezdet, int veg) {
    int ossz = strlen(be);
    int hossz = ossz - (veg - kezdet);

    char *uj2 = malloc((hossz + 1)*sizeof(char));

    int k = 0;
    for (int i = 0; i < ossz; i++) {
        if (i < kezdet || i >= veg) {
            uj2[k++] = be[i];
        }
    }
    uj2[k] = '\0';
    return uj2;
}

void f4() {
    char *a = resz2("hello, vilag", 5, 7);
    printf("%s\n", a);
    free(a);
}

char *beszur(const char *be, int index, const char *mit) {
    int hossz1 = strlen(be);
    int hossz2 = strlen(mit);

    char *uj = malloc((hossz1 + hossz2 + 1) * sizeof(char));

    int j = 0;
    for (int i = 0; i < index; i++) {
        uj[j] = be[i];
        j++;
    }

    for (int i = 0; i < hossz2; i++) {
        uj[j] = mit[i];
        j++;
    }

    for (int i = index; i < hossz1; i++) {
        uj[j] = be[i];
        j++;
    }

    uj[j] = '\0';

    return uj;
}

void f5(void) {
    char *a = beszur("hello!", 5, ", vilag");
    printf("%s\n", a);
    free(a);
}

int main(void) {
    f1();
    f2();
    f3();
    f4();
    f5();
}
