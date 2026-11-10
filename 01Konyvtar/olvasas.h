#ifndef INC_01KONYVTAR_OLVASAS_H
#define INC_01KONYVTAR_OLVASAS_H

typedef struct Olvasas {
    int ID;
    int konyv_id;
    char kezdes[11];
    char utolso_rekord[11];
    char befejezes[11];
    int aktoldal;

    struct Olvasas* kovetkezo;
} Olvasas;

Olvasas* olvasas_beolvasas(const char *fajlnev);
void olvasas_felszabadit(Olvasas* elso);

#endif //INC_01KONYVTAR_OLVASAS_H
