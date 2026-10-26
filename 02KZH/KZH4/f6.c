#include <stdio.h>

void kettospont(char const *be, char *ki) {
    int k = 0;
    for (int i = 0; be[i] != '\0'; i += 1) {
        if (be[i] != ':')
            ki[k++] = be[i];
        else {
            ki[k++] = ':';
            ki[k++] = ' ';
        }
    }
    ki[k] = '\0';
}

int *keres6(int *t, int meret, int oszto) {
    for (int i = 0; i < meret; i++) {
        if (t[i] % oszto == 0)
            return &t[i];
    }
    return NULL;
}

int f6() {
    char ki[14];
    kettospont("bot:pad:sok", ki);
    printf("%s", ki);

    int a[5] = {11, 22, 33, 44, 55};
    int *talalat = keres6(a, 5, 3);
    if (talalat != NULL)
        printf("%d", *talalat);
    else
        printf("nincs");

}
