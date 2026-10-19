#include <stdio.h>

double atlag(int *tomb, int kezdoszint, int szintekszama) {
    double ossz = 0;
    for (int i = kezdoszint; i < kezdoszint + szintekszama; i += 1) {
        ossz += tomb[i];
    }
    return ossz / szintekszama;
}

double vizsgal(int *tomb, int n, int sz) {
    double min = atlag(tomb, 0, sz);
    for (int i = 1; i < n - 1; i += 1) {
        if (atlag(tomb, i, sz) < min) {
            min = atlag(tomb, i, sz);
        }
    }
    return min;
}

void feladat3() {
    int a[5] = {6, 2, 4, 7, 5};
    double min = vizsgal(a, 3, 2);
    printf("%.2f", min);
}
