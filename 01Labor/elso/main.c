#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tartaly()
{
    double m, atmero;

    printf("Tartaly festese\n");
    printf("\n");

    printf("Milyen magas? ");
    scanf("%lf", &m);

    printf("Mennyi az atmeroje? ");
    scanf("%lf", &atmero);

    double r = atmero / 2;
    double A;

    A = (2*r*r*3.14)+(2*r*3.14*m);

    printf("%f doboz festek kell.\n", A/2);

    return 0;
}

int masodfoku()
{
    int a,b,c;
    printf("a= ");
    scanf("%d", &a);
    printf("b= ");
    scanf("%d", &b);
    printf("c= ");
    scanf("%d", &c);

    int D = (b*b)-(4*a*c);

    if (D > 0)
    {
        int gyok1 = (-b+sqrt(D))/2*a;
        int gyok2 = (-b-sqrt(D))/2*a;
        printf("x1 = %d x2 = %d\n", gyok1, gyok2);
    }
    else if (D == 0)
    {
        printf("csak 1 valos gyoke van\n");
    }
    else
    {
        printf("Nincs valos gyok\n");
    }

    return 0;
}

int szamsor()
{
    int a = 1;
    while (a <= 20)
    {
        printf("%d\n", a);
        a = a + 1;
    }
    return 0;
}

int vonalhossz()
{
    int hossz;
    printf("\nMekkora hosszusagu legyen a vonal? ");
    scanf("%d", &hossz);
    printf("+");
    for(int i = 0; i < hossz; i++)
    {
        printf("-");
    }
    printf("+");

    return 0;
}

int main()
{
    tartaly();
    masodfoku();
    szamsor();
    vonalhossz();
    return 0;
}