#include <stdio.h>
#include "calculator.h"

int main(void) {
    int a = 2, b = 3;
    int bemenet;
    while (bemenet != 9) {
        printf("Összeadás = 1 --- Kivonás = 2 --- Szorzás --- 3 --- Kilépés = 9\n");
        scanf("%d", &bemenet);
        if (bemenet != 1 && bemenet != 2 && bemenet != 3 && bemenet != 9) {
            printf("Érvénytelen!\n");
        } else {
            switch (bemenet) {
                case 1:
                    printf("%d\n", osszead(a, b));
                    break;
                case 2:
                    printf("%d\n", kivon(a, b));
                    break;
                case 3:
                    printf("%d\n", szoroz(a, b));
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
