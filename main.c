#include <stdio.h>
#include <time.h>

// Aufgabe 1: Währungsumrechnung

double euro2dollar(double euro) // gibt die übergebene Euro (double) als Dollars (double) zurück.
{
    const double euro2dollars = 1.3810095;
    return euro * euro2dollars;
}

double dollar2euro(double dollar)
{
    const double dollar2euros = 0.72410798043;
    return dollar * dollar2euros;
}


// Aufgabe 2: Währungstabelle

void printTable(int anfang, int ende, int schrittweite)
{
    int i;

    // --------
    // Euro2Dollar table
    // --------

    // Header
    printf("\n      Euro   |    Dollar\n-----------------------\n");


    // Body
    for(i = anfang; i <= ende; i += schrittweite)
        printf("%8d.00  |  %8.2f\n", i, euro2dollar(i));


    // --------
    // Dollar2Euro table
    // --------

    // Header
    printf("\n      Dollar  |    Euro\n-----------------------\n");


    // Body
    for(i = anfang; i <= ende; i += schrittweite)
        printf("%8d.00  |  %8.2f\n", i, dollar2euro(i));

    printf("\n\n");

}


// Aufgabe 3: Datum

int monateImJahr(int jahr)
{
    return 12;
}

int istSchaltjahr(int jahr)
{
    if (jahr % 4 == 0 && (jahr % 100 != 0 || jahr % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int tageImMonat(int jahr, int monat)
{
    int anzahlTage = 0;
    if (monat == 4 || monat == 6 || monat == 9 || monat == 11)
        anzahlTage = 30;
    else if (monat == 2 && istSchaltjahr(jahr))
        anzahlTage = 29;
    else if (monat == 2 && !istSchaltjahr(jahr))
        anzahlTage = 28;
    else
        anzahlTage = 31;

    return anzahlTage;
}


int main(int argc, char** argv)
{
    double eingabe, euro, dollar;
    int anfang,ende , schrittweite, auswahl = 99, beenden = 0;


    do {
        switch (auswahl)
        {
            case 1:
                printf("\nBitte geben Sie einen Geldbetrag ein!\n");
                scanf("%lf", &eingabe);
                dollar = euro2dollar(eingabe);
                euro = dollar2euro(eingabe);
                printf("\neuro2dollar:%lf", dollar);
                printf("\ndollar2euro:%lf\n", euro);
                break;
            case 2:
                printf("\nBitte geben Sie einen Anfangswert, einen Endwert und eine Schrittweite ein!\n");
                scanf("%d%d%d",&anfang,&ende,&schrittweite);
                printTable(anfang, ende, schrittweite);
                break;
            case 99:
                break;
            case 0:
                beenden = 1;
                break;
            default:
                printf("\nFalsche Auswahl!");
                break;

        }
        printf("\nBitte treffen Sie Ihre Wahl:\n\t1\tWaehrungsumrechnung\n\t2\tWaehrungstabelle\n\t0\tEnde\n");

    } while (scanf("%d",&auswahl) == 1 && beenden == 0);
    return 0;
}
