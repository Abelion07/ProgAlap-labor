#include <stdio.h>

void szuszog(char const *be, char *ki) {
    int k = 0;
    for (int i = 0; be[i] != '\0'; i += 1) {
        if (be[i] != 's') {
            ki[k] = be[i];
            k += 1;
        } else {
            ki[k] = 's';
            k += 1;
            ki[k] = 'z';
            k += 1;
        }
    }
    ki[k] = '\0';
}

int keres(int *t, int meret, int keresett) {
    for (int i = 0; i < meret; i += 1) {
        if (t[i] == keresett) {
            return i;
        }
    }
    return -1;
}

int f1() {
    char ki[20];
    szuszog("susog", ki);
    printf("%s\n", ki);

    int a[5] = {11, 22, 33, 44, 55};
    int talalat = keres(a, 5, 33);
    if (talalat != -1) {
        printf("Keresett index: %d\n", talalat);
    }
    else {
        printf("Nincs találat\n");
    }
}
