#include <stdio.h>
#include <math.h>

void f1() {
    printf("1. %f\n", 1.23456789123456789123456789e40);
    printf("2. %g\n", 1e40);
    printf("3. %s\n", 1e3 + 1 == 1e3 ? "igaz" : "hamis");
    printf("4. %s\n", 1e30 + 1 == 1e30 ? "igaz" : "hamis");
    printf("5. %g\n", pow(10, 40) / pow(10, -40));
    printf("6. %g\n", powf(10, 40) / powf(10, -40));
}

void f2() {
    //2. feladat
    double eredmeny;
    eredmeny = (4 + 2 - (3 - (6 + 4.0 / 5))) / (3 * (2 - 7));
    printf("%f\n", eredmeny);
}

void f3() {
    //3. feladat
    int i = 1;
    while (i > 0) {
        ++i;
    }
    printf("int: %d\n", i);
    short int j = 1;
    while (j > 0) {
        ++j;
    }
    printf("short int: %d\n", j);

    signed char m = 1;
    while (m > 0) {
        ++m;
    }
    printf("signed char: %d\n", m);
}

void f4() {
    // 4. feladat
    for (int i = 0; i < 40; i++) {
        printf("%d. %d\n", i, 1 << i);
    }

    unsigned int szam = 1;

    while (szam != 0) {
        printf("%u\n", szam);
        szam <<= 1;
    }

    unsigned long long int szam2 = 1;
    int bitek = 0;

    while (szam2 != 0) {
        bitek += 1;
        szam2 <<= 1;
    }

    printf("Bitek szama: %d\n", bitek);
    //unsigned short int = 16 bit
    //unsigned int = 32 bit
    //unsigned long int = 64 bit
}

void f5() {
    unsigned long int szam = 29;

    for (int i = 31; i >= 0; i--) {
        printf("%lu", (szam >> i) & 1UL);
    }
}

void f6() {
    unsigned long szamok[8] = {
        0U, 1931988508U, 581177634U, 581374240U,
        581177632U, 581177634U, 1919159836U, 0U
    };

}

int main(void) {
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    return 0;
}
