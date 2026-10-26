//Példa: "Hello, vilag!" → "Hello, vilag!4!"
#include <stdio.h>
#include <stdbool.h>

void felkialtojel(char const *be, char *ki) {
    int k = 0;
    for (int i = 0; be[i] != '\0'; i += 1) {
        if (be[i] != '!') {
            ki[k++] = be[i];
        }
        else {
            ki[k++] = '!';
            ki[k++] = '4';
            ki[k++] = '!';
        }
    }
    ki[k] = '\0';
}

bool van_e_kisebb(int *t, int meret, int p) {
    for (int i = 0; i < meret; i += 1) {
        if (t[i] < p) {
            return true;
        }
    }
    return false;
}

int f4() {
    char ki[16];
    felkialtojel("Hello, vilag!\n", ki);
    printf("%s", ki);

    int a[5]  = {11, 22, 33, 44, 55};
    if (van_e_kisebb(a, 5, 11)) {
        printf("Van kisebb\n");
    }
    else {
        printf("Nincs kisebb\n");
    }
}