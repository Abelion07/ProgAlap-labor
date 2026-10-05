#include <stdio.h>


//-----------------------------------------1.példa------------------------------------------
int dupla(int *tomb, int meret) {
    for (int *p = tomb; p < tomb + meret; p++) {
        *p = *p * *p;
        // tomb[i] = *(tomb + i)
    }
    return 0;
}

int egyes() {
    int tomb[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // tomb => 0. elemre mutató hely.
    // *tomb = 1
    // &*tomb => tomb 0. elemének helye
    // *&*tomb = 1
    dupla(tomb, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d, ", tomb[i]);
    }

    return 0;
}

//-----------------------------------------2.példa------------------------------------------
int reverse(int *t, int meret) {
    //0 => n.elem
    //n => 0.
    int n = meret - 1;
    int cache;
    for (int i = 0; i < meret / 2; i++) {
        cache = t[i];
        t[i] = t[n];
        t[n] = cache;
        n--;
    }
    return 0;
}

int kettes() {
    int t[5] = {1, 2, 3, 4, 5};
    reverse(t, 5);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", t[i]);
    }
    return 0;
}

int main() {
    egyes();
    kettes();
    return 0;
}
