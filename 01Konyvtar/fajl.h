#ifndef INC_01KONYVTAR_FAJL_H
#define INC_01KONYVTAR_FAJL_H

#include "konyv.h"

Konyv *konyv_beolvasas(const char *fajlnev);
void konyvek_kiir(Konyv *elso);
void konyvek_felszabadit(Konyv *elso);

#endif //INC_01KONYVTAR_FAJL_H
