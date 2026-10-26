#include <stdio.h>
#include <stdbool.h>

void vesszo(char const *be, char *ki) {
    int k = 0;
    for (int i = 0; be[i] != '\0'; i++) {
        if (be[i] != ',') {
            ki[k++] = be[i];
        }
        else {
            ki[k++] = ',';
            ki[k++] = ' ';
        }
    }
    ki[k] = '\0';
}

bool keres5(int *t, int meret, int oszto) {
    for (int i = 0; i < meret; i += 1) {
        if (t[i] % oszto == 0)
            return true;
    }
    return false;
}

int f5() {
    //Példa: "lol,kek,wut" → "lol, kek, wut"
    char ki[14];
    vesszo("lol,kek,wut", ki);
    printf("%s\n", ki);

    int a[5] = {11, 22, 33, 44, 55};
    printf(keres5(a, 5, 10) ? "Osztja" : "Nem osztja");
}