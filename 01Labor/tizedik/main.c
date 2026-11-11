#include <stdio.h>
#include "debugmalloc.h"
#include <stdlib.h>

typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;


/* létrehoz egy listát, benne egy csomó számmal */
ListaElem *lista_letrehoz(void) {
    int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListaElem *lis = NULL;

    for (int i = 0; szamok[i] != -1; ++i) {
        ListaElem *u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->kov = lis;
        u->adat = szamok[i];
        lis = u;
    }
    return lis;
}

int lista_hossz(ListaElem* list) {
    int db = 0;
    while (list != NULL) {
        db++;
        list = list->kov;
    }
    return db;
}

void felszabadit(ListaElem *list) {
    while (list != NULL) {
        ListaElem* kovetkezo = list->kov;
        free(list);
        list = kovetkezo;
    }
}

ListaElem* elejere_beszur(ListaElem* lista, int szam) {
    ListaElem* uj = malloc(sizeof(ListaElem));

    if (uj == NULL) {
        return lista;
    }

    uj->adat = szam;
    uj->kov=lista;

    return uj;
}

ListaElem *vegere_beszur(ListaElem *lista, int szam) {
    ListaElem *uj = malloc(sizeof(ListaElem));

    if (uj == NULL) {
        return lista;
    }

    uj->adat = szam;
    uj->kov = NULL;

    if (lista == NULL) {
        return uj;
    }

    ListaElem *mozgo = lista;

    while (mozgo->kov != NULL) {
        mozgo = mozgo->kov;
    }

    mozgo->kov = uj;

    return lista;
}

ListaElem* kereses(ListaElem* lista, int mit) {
    while (lista->kov != NULL) {
        if (lista->adat == mit) {
            return lista;
        }
        lista = lista->kov;
    }
    return NULL;
}

int main(void) {
    ListaElem *eleje;

    eleje = lista_letrehoz();
    eleje = elejere_beszur(eleje, 5);
    eleje = vegere_beszur(eleje, 13);
    eleje = vegere_beszur(eleje, 21);

    ListaElem *talalat = kereses(eleje, 13);

    if (talalat != NULL) {
        printf("Megtalaltam: %d\n", talalat->adat);
    } else {
        printf("Nincs ilyen szam!\n");
    }

    int hany = lista_hossz(eleje);
    printf("%d\n", hany);
    felszabadit(eleje);

    return 0;
}