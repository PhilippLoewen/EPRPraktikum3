#include <stdio.h>


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

void printTable(double anfang, double ende, double schrittweite)
{
    double i;
    if(schrittweite <= 0)
        return;

    // --------
    // Euro2Dollar table
    // --------

    // Header
    printf("\n      Euro   |    Dollar\n-----------------------\n");


    // Body
    for(i = anfang; i <= ende; i += schrittweite)
        printf("%8.2lf  |  %8.2f\n", i, euro2dollar(i));


    // --------
    // Dollar2Euro table
    // --------

    // Header
    printf("\n      Dollar  |    Euro\n-----------------------\n");


    // Body
    for(i = anfang; i <= ende; i += schrittweite)
        printf("%8.2lf  |  %8.2f\n", i, dollar2euro(i));

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

int pruefeDatum(int jahr, int monat, int tag)
{
    int gueltig = 1;
    if (!(monat >= 1 && monat <= monateImJahr(jahr)))
        gueltig = 0;
    if (tag > tageImMonat(jahr, monat) || tag < 1)
        gueltig = 0;
    return gueltig;
}



int tageBisWeihnachten(int jahr, int monat, int tag)
{
    if (pruefeDatum(jahr,monat,tag) == 0)
        return -1;

    int tmpJahr = jahr, tmpMonat = monat, tmpTag = tag,warSchon = 0, anzahlTage = 0, endTag = 0;
    if (tmpMonat == 12 && tmpTag > 24)
        warSchon = 1;

    for (tmpJahr = jahr; tmpJahr <= jahr + warSchon; tmpJahr++)
    {
        if (tmpJahr == jahr)
            tmpMonat = monat;
        else
            tmpMonat = 1;
        for (tmpMonat; tmpMonat <= 12; tmpMonat++)
        {
            if (tmpMonat == monat)
                tmpTag = tag;
            else
                tmpTag = 1;

            for (tmpTag; tmpTag <= tageImMonat(tmpJahr, tmpMonat); tmpTag++)
                anzahlTage += 1;

        }
    }
    return anzahlTage;
}


int main(int argc, char** argv)
{
    double eingabe, euro, dollar, anfang, ende , schrittweite;
    int  auswahl = 99, beenden = 0;
    int jahr = 0, monat = 0, tag = 0, anzahlTage;
    printf("Test\n");

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
                printf("\nBitte geben Sie einen Anfangswert ein!\n");
                scanf("%lf", &anfang);
                printf("\nBitte geben Sie einen Endwert ein!\n");
                scanf("%lf", &ende);
                printf("\nBitte geben Sie eine Schrittweite ein!\n");
                scanf("%lf", &schrittweite);
                printTable(anfang, ende, schrittweite);
                break;
            case 3:
                printf("Bitte geben Sie ein Datum in der Form \"YYYY MM DD\" ein!\n");
                scanf("%d%d%d", &jahr, &monat, &tag);
                if (pruefeDatum(jahr, monat, tag) == 1)
                    printf("\nDas Datum %d-%d-%d ist korrekt.\n",jahr,monat,tag);
                else
                    printf("\nDas Datum %d-%d-%d ist nicht korrekt.\n",jahr,monat,tag);
                break;
            case 4:
                printf("Bitte geben Sie ein Datum in der Form \"YYYY MM DD\" ein!\n");
                scanf("%d%d%d", &jahr, &monat, &tag);
                if (!pruefeDatum(jahr,monat, tag))
                {
                    printf("Das Datum ist nicht korrekt");
                }
                else
                {
                    anzahlTage = tageBisWeihnachten(jahr, monat, tag);
                    printf("\nBis Weihnachten sind es noch %d Tage.\n", anzahlTage);
                }
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
        if (beenden == 1)
            break;

        printf("\nBitte treffen Sie Ihre Wahl:\n\t1\tWaehrungsumrechnung\n\t2\tWaehrungstabelle\n\t3\tDatum ueberpruefen\n\t4\tTage bis Weihnachten\n\t0\tEnde\n");
    } while (scanf("%d",&auswahl) == 1);
    return 0;
}

