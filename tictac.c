/**********************************************************************\
* Kurzbeschreibung: Uebung: 25.2.2; Punkte: 0
*
* Datum:       Autor:           Grund der Aenderung:
* 05.06.2021   Denise Griebel   Neuerstellung
\**********************************************************************/
#include <stdio.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
void spielfeldbauen(char *feldArray, int quadratb);

int gewinner(char *spielfeld, int quadratl, char cMark, int stand);

int main( void )
{
    char c, Spieler = 'X';
    int eingabe_Test, feldgroesse, i, j, feldzeile, feldspalte, spielstand = -1;

    printf("Spielfeldgroesse (mind. 3 und max. 10):");
    eingabe_Test = scanf("%d", &feldgroesse);
     while(!eingabe_Test || feldgroesse < 3 || 10 < feldgroesse)
    {
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        printf("Eingabe Fehlerhaft!\n"
               "Spielfeldgroesse (mind. 3 und max. 10): ");
        eingabe_Test = scanf("%d", &feldgroesse);
    }

    char spielfeld[feldgroesse*feldgroesse];
    for(i = 0; i < feldgroesse; i++)
    {
        for(j = 0; j < feldgroesse; j++)
        {
            spielfeld[i*feldgroesse+j] = '.';
        }
    }

    do
    {
        if(Spieler == 'X')
        {
            printf("\nDein Zug, Spieler 1 (Zeile,Spalte): ");
            eingabe_Test = scanf("%d,%d", &feldzeile, &feldspalte);
            while(eingabe_Test != 2 ||                                                                          //TEST: zwei korrekte eingaben
                  spielfeld[(feldzeile-1)*feldgroesse+feldspalte-1] == 'X' ||                                   //TEST: Stelle nicht von Spieler 1 besetzt
                  spielfeld[(feldzeile-1)*feldgroesse+feldspalte-1] == 'O' ||                                   //TEST: Stelle nicht von Spieler 2 besetzt
                  (1 > feldspalte || feldspalte > feldgroesse || 1 > feldzeile || feldzeile > feldgroesse) )    //TEST: Stein liegt innerhalb des Spielfeldes
            {
                while ((c = getchar()) != '\n' && c != EOF)
                {
                }
                if(eingabe_Test != 2)
                {
                    printf("Eingabe fehlerhaft!\n");
                }
                else if(1 > feldspalte || feldspalte > feldgroesse || 1 > feldzeile || feldzeile > feldgroesse)
                {
                    printf("Bitte bleib im spielfeld. Danke!\n");
                }else
                {
                    printf(".... Unerlaubter Spielzug!\n");
                }
                printf("Neuer versuch Spieler 1 (zeile,spalte): ");
                eingabe_Test = scanf("%d,%d", &feldzeile, &feldspalte);
            }
            spielfeld[(feldzeile-1)*feldgroesse+feldspalte-1] = Spieler;
        }

        if(Spieler == 'O')
        {
            printf("\nDein Zug, Spieler 2 (Zeile,Spalte): ");
            eingabe_Test = scanf("%d,%d", &feldzeile, &feldspalte);
            while(eingabe_Test != 2 ||                                                                          //TEST: zwei korrekte eingaben
                  spielfeld[(feldzeile-1)*feldgroesse+feldspalte-1] == 'X' ||                                   //TEST: Stelle nicht von Spieler 1 besetzt
                  spielfeld[(feldzeile-1)*feldgroesse+feldspalte-1] == 'O' ||                                   //TEST: Stelle nicht von Spieler 2 besetzt
                  (1 > feldspalte || feldspalte > feldgroesse || 1 > feldzeile || feldzeile > feldgroesse) )    //TEST: Stein liegt innerhalb des Spielfeldes
            {
                while ((c = getchar()) != '\n' && c != EOF)
                {
                }
                if(eingabe_Test != 2)
                {
                    printf("Eingabe fehlerhaft!\n");
                }
                else if(1 > feldspalte || feldspalte > feldgroesse || 1 > feldzeile || feldzeile > feldgroesse)
                {
                    printf("Bitte bleib im spielfeld. Danke!\n");
                }else
                {
                    printf(".... Unerlaubter Spielzug!\n");
                }
                printf("Neuer versuch Spieler 2 (zeile,spalte): ");
                eingabe_Test = scanf("%d,%d", &feldzeile, &feldspalte);
            }
             spielfeld[(feldzeile-1)*feldgroesse+feldspalte-1] = Spieler;
        }
        spielfeldbauen(spielfeld, feldgroesse);

        spielstand = gewinner(spielfeld, feldgroesse, Spieler, spielstand);

        if(spielstand == -1)
        {
            if(Spieler == 'X')
            {
                Spieler = 'O';
            }else
            {
                Spieler = 'X';
            }
        }
    }while(spielstand == -1);

    if(spielstand == 1 && Spieler == 'X')
    {
        printf("\nSpieler 1 hat gewonne!!!\n");
    }
    else if(spielstand == 1 && Spieler == 'O')
    {
        printf("\nSpieler 2 hat gewonne!!!\n");
    }
    else
    {
        printf("\nUnentschieden!!!\n");
    }

return 0;
}

void spielfeldbauen(char *feldArray, int quadratb)
{
    int a, b;
    char spielfeld[quadratb][quadratb];
    for(a = 0; a < quadratb; a++)
    {
        for(b = 0; b < quadratb; b++)
        {
            spielfeld[a][b] = feldArray[a*quadratb+b];
        }
    }
    for(a = 0; a < quadratb; a++)
    {
        printf("\n%d\t", a+1);
        for(b = 0; b < quadratb; b++)
        {
            printf("%c ", spielfeld[a][b]);
        }
    }
    printf("\n");
}

int gewinner(char *spielfeld, int quadratl, char cMark, int stand)
{
    int a, b, ergebnis = stand;
    //TEST: vertikal
    for(a = 0; a < quadratl; a++)
    {
        if(ergebnis == 1)
        {
            break;
        }
        for(b = 0; b < (quadratl-2); b++)
        {
            if(ergebnis == 1)
            {
                break;
            }
            if(spielfeld[b*quadratl+a] == cMark && spielfeld[(b+1)*quadratl+a] == cMark && spielfeld[(b+2)*quadratl+a] == cMark)
            {
                ergebnis = 1;
            }
        }
    }
    //TEST: horizontal
    for(a = 0; a < quadratl; a++)
    {
        if(ergebnis == 1)
        {
            break;
        }
        for(b = 0; b < (quadratl-2); b++)
        {
            if(ergebnis == 1)
            {
                break;
            }
            if(spielfeld[a*quadratl+b] == cMark && spielfeld[a*quadratl+b+1] == cMark && spielfeld[a*quadratl+b+2] == cMark)
            {
                ergebnis = 1;
            }
        }
    }
    //TEST: Diagonal Links Oben nach Rechts Unten
    for(a = 0; a < (quadratl-2); a++)
    {
        if(ergebnis == 1)
        {
            break;
        }
        for(b = 0; b < (quadratl-2); b++)
        {
            if(ergebnis == 1)
            {
                break;
            }
            if(spielfeld[a*quadratl+b] == cMark && spielfeld[(a+1)*quadratl+b+1] == cMark && spielfeld[(a+2)*quadratl+b+2] == cMark)
            {
                ergebnis = 1;
            }
        }
    }
    //TEST: Diagonal Links Unten nach Rechts Oben
    for(a = quadratl-1; a > 1; a--)
    {
        if(ergebnis == 1)
        {
            break;
        }
        for(b = 0; b < (quadratl-2); b++)
        {
            if(ergebnis == 1)
            {
                break;
            }
            if(spielfeld[a*quadratl+b] == cMark && spielfeld[(a-1)*quadratl+b+1] == cMark && spielfeld[(a-2)*quadratl+b+2] == cMark)
            {
                ergebnis = 1;
            }
        }
    }
    //Test unentschieden
    int keingewinner = 0;
    for(a = 0; a < quadratl; a++)
    {
        for(b = 0; b < quadratl; b++)
        {
            if(spielfeld[a*quadratl+b] == '.')
            {
                keingewinner += 1;
            }
        }
    }
    if(keingewinner == 0 && ergebnis != 1)
    {
        ergebnis = 0;
    }
    return ergebnis;
}

