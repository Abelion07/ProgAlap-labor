#include <stdio.h>
#include <stdbool.h>

void kerdojel(char const *be, char *ki) {
    int k = 0;
    for (int i = 0; be[i] != '\0'; i += 1) {
        if (be[i] != '?') {
            ki[k++] = be[i];
        } else {
            ki[k++] = '?';
            ki[k++] = '?';
            ki[k++] = '?';
        }
    }
    ki[k] = '\0';
}

bool van_e_nagyobb(double *t, int meret, int keresett) {
    for (int i = 0; i < meret; i += 1) {
        if (keresett < t[i]) {
            return true;
        }
    }
    return false;
}

int f3() {
    char ki[9];
    kerdojel("Mi ez?\n", ki);
    printf("%s", ki);

    double t[5] = {1.1, 2.2, 3, 4, 5};
    if (van_e_nagyobb(t, 5, 8)) {
        printf("Van nagyobb\n");
    }
    else {
        printf("Nincs nagyobb\n");
    }
}
