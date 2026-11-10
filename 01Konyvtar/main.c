#include <stdio.h>

#include "fajl.h"
#include "menu.h"
#include "konyv.h"

int main() {
    Konyv *elso = NULL;
    fomenu(&elso);

    konyvek_felszabadit(elso);
    printf("\nPov Memory: I had strings, but now I'm free.-Ultron\n");
    return 0;
}
