#include <stdio.h>

void lyaly(char const *be, char *ki) {
    int k = 0;
    for (int i = 0; be[i] != '\0'; i += 1) {
        if (be[i] != 'j') {
            ki[k] = be[i];
            k += 1;
        } else {
            ki[k] = 'l';
            k += 1;
            ki[k] = 'y';
            k += 1;
        }
    }
    ki[k] = '\0';
}

int keres2(int *t, int meret, int mit) {
    for (int i = 0; i < meret; i += 1) {
        if (t[i] == mit) {
            return i;
        }
    }
    return -1;
}

int f2() {
    char ki[6];
    lyaly("jaj\n", ki);
    printf("%s", ki);

    int a[5] = {11, 22, 33, 44, 55};
    int talalat = keres2(a, 5, 44);
    if (talalat != -1) {
        printf("Keresett index: %d\n", talalat);
    }
    else {
        printf("Nincs találat\n");
    }
}
