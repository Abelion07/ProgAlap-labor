#include <stdio.h>

double atlag(int *tomb, int kezdoszint, int szintekszama) {
    double ossz = 0;
    for (int i = kezdoszint; i < kezdoszint + szintekszama; i++) {
        ossz += tomb[i];
    }
    return ossz / szintekszama;
}

double vizsgal(int *tomb, int kezdoszint, int szintekszama) {
    double min = atlag(tomb, 0, szintekszama);
    for (int i = 1; i < szintekszama - 1; i++) {
        if (min > atlag(tomb, kezdoszint, szintekszama)) {
            min = atlag(tomb, kezdoszint, szintekszama);
        }
    }
    return min;
}

int feladat3() {
    int lakok[5] = {8,6,8,2,1};
    int min = vizsgal(lakok, 2, 3);
    printf("%.2f", min);

}