#include <stdio.h>

void AV(double *felszin, double *terfogat, double oldal) {
    *felszin = 6 * oldal * oldal;
    *terfogat = oldal * oldal * oldal;
}

int main() {
    double oldal = 2.7;
    double A, V;
    AV(&A, &V, oldal);
    printf("A= %g, V = %g", A, V);

    return 0;
}