#include <stdlib.h>
#include <stdio.h>

#include "Inserimento_ combinazione_ decifratore.h"

void Inserimento_ combinazione_ decifratore(char Colori_decifratore[])
{
    unsigned int i = 1;
    unsigned int j = 1;
    char valore;
    /*(combinazione_decifratore[] NON DICHIARATA*/

    while(i <= 4){//Mentre ci sono ancora colonne disponibili
        printf( "%s", "Prego inserire il colore desiderato: ");
        while( j <= Lettura_array( Colori_decifratore[], i)){//Finchè j è minore o uguale al numero di colori
            printf("%c", Lettura_array( Colori_decifratore[], j));
            j++;
        }
        scanf("%c", &valore);
        Scrittura_array(combinazione_decifratore[], i, valore);
        i++;
    }

return;
}
