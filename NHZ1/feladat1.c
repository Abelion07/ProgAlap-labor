#include <stdio.h>
#include <stdbool.h>

int prime(int n) {
    for (int i = 2; i < n; i += 1) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int negyzetosszeg(int n) {
    int sum = 0;
    while (n != 0) {
        int jegy = n % 10;
        sum += jegy * jegy;
        n /= 10;
    }
    return sum;
}

bool boldog(int n) {
    while (n != 4 && n != 1) {
        n = negyzetosszeg(n);
    }
    if (n == 1)
        return true;
    else
        return false;
}

void feladat1() {
    int n = 2;
    int darab = 1;
    while (darab <= 10) {
        if (prime(n) && boldog(n)) {
            printf("%d. %d\n", darab, n);
            darab += 1;
        }
        n += 1;
    }
}
