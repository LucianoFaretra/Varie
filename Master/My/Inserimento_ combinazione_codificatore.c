#include <stdlib.h>
#include <stdio.h>

#include "Inserimento_combinazione_codificatore.h"

void Inserimento_combinazione_codificatore()
{
    unsigned int i = 1;
    unsigned int j = 1;
    char valore;
    /*(combinazione_codificatore[] NON DICHIARATA*/

    while(i <= 4){//Mentre ci sono ancora colonne disponibili

        scanf("%c", valore);

        Scrittura_array(combinazione_codificatore, i, valore);
        i++;
        //Deve stampare la schermata aggiornata
    }

return;
}
