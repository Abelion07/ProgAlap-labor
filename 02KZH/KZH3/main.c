#include <stdio.h>
#include <stdbool.h>

//---------------1.feladat-------------------
typedef struct eredmeny {
    int tapasztalat;
    int ujszeruseg;
    int leiras;
} eredmeny;

eredmeny beolvasas1() {
    eredmeny e;
    scanf("%d %d %d", &e.tapasztalat, &e.ujszeruseg, &e.leiras);
    return e;
}

double pontszam(eredmeny e) {
    return 0.8 * e.tapasztalat + 1.0 * e.ujszeruseg + 1.2 * e.leiras;
}

int f1() {
    eredmeny e1 = beolvasas1();
    eredmeny e2 = beolvasas1();
    printf("Az összpontszám %.2f", pontszam(e1) + pontszam(e2));
}


//---------2. feladat------------
typedef struct automata {
    int kave, kapucsino, csoki;
} automata;

automata beolvasas2() {
    automata a;
    scanf("%d %d %d", &a.kave, &a.kapucsino, &a.csoki);
    return a;
}

int osszesen(automata a) {
    return 140 * a.kapucsino + 150 * a.csoki + 120 * a.kave;
}

int f2() {
    automata a1 = beolvasas2();
    automata a2 = beolvasas2();
    automata a3 = beolvasas2();
    int osszes = osszesen(a1)+osszesen(a2)+osszesen(a3);
    printf("Az összbevétel %d Ft.", osszes);
}

// --------- 3.feladat------------
typedef struct uralkodas {
    int mettol, meddig;
} uralkodas;

uralkodas beolvasas3() {
    uralkodas u;
    scanf("%d %d", &u.mettol, &u.meddig);
    return u;
}

bool tronviszaly(uralkodas u1, uralkodas u2) {
    if (u1.mettol <= u2.meddig && u2.mettol <= u1.meddig) {
        return true;
    }
    else {
        return false;
    }
}

int f3() {
    uralkodas u1 = beolvasas3();
    uralkodas u2 = beolvasas3();
    if (tronviszaly(u1,u2)) {
        printf("Volt trónviszály");
    }
    else
        printf("Nem volt trónviszály");
}

//--------4.feladat----------
typedef struct magassag {
    int lab, huvelyk;
} magassag;

magassag beolvasas4() {
    magassag m;
    scanf("%d %d", &m.lab, &m.huvelyk);
    return m;
}

int atvalto(magassag m) {
    return 12*m.lab+m.huvelyk;
}

int f4() {
    magassag m1 = beolvasas4();
    magassag m2 = beolvasas4();
    int m1h = atvalto(m1);
    int m2h = atvalto(m2);
    if (m1h > m2h)
        printf("Az első ember magasabb");
    else
        printf("A második ember magasabb");
}

//---------5.feladat---------
typedef struct ido {
    int o, p, mp;
} ido;

ido beolvas5() {
    ido i;
    scanf("%d %d %d", &i.o, &i.p, &i.mp);
    return i;
}

int masodpercre(ido i) {
    return i.o*3600+i.p*60+i.mp;
}

int f5() {
    ido i1 = beolvas5();
    ido i2 = beolvas5();
    if (masodpercre(i1) < masodpercre(i2))
        printf("Az első időpont van korábban.");
    else
        printf("A második időpont van korábban.");
}

//--------6.feladat---------
typedef struct tlap {
    int x, y, a, b;
} tlap;

tlap beolvas6() {
    tlap t;
    scanf("%d %d %d %d", &t.x, &t.y, &t.a, &t.b);
    return t;
}

int terulet(tlap t) {
    return t.a*t.b;
}

int f6() {
    tlap t1 = beolvas6();
    tlap t2 = beolvas6();
    printf("%s téglalap területe a nagyobb", terulet(t1)>terulet(t2) ? "Első" : "Második");
}

int main() {
    // f1();
    // f2();
    // f3();
    // f4();
    // f5();
    f6();
}

