/*                 Sviluppato da Luciano Faretra 20/01/2015 rilasciato sotto licenza GNUv3
                                        Fusione2 - stampa

    Affinamento Top Down

    INPUT                     DESCRIZIONE                                                           DOMINIO
    VoliPtr                   Puntatore al file Voli.txt                                            Stringhe di caratteri
    VoliAggiornatiPtr         Puntatore a VoliAggiornati contenente tutte le info di volo aggiornate stringhe di caratteri


    OUTPUT                    DESCRIZIONE                                                           DOMIONIO
    VoliPtr                   Puntatore al file Voli.txt mostrato in standard output                Stringhe di caratteri
    VoliAggiornatiPtr         Puntatore a VoliAggiornati.txt mostrato in standard output            Stringhe di caratteri

    DATI DI LAVORO            DESCRIZIONE                                                           DOMINIO

    1.1 Apri il file Voli.txt
        Apri il file VoliAggiornati.txt
        Mentre ci sono ancora Voli
            Stampa una riga di Voli.txt
            Stampa una riga di VoliAggiornati.txt
        Fine Mentre


*/
#include <stdio.h>
#include <stdlib.h>
#include "stampa.h"

void stampa( FILE *VoliPtr, FILE *VoliAggiornatiPtr )
{
    char *msgErrore = "COD. 666";
    char buffer[100];

    rewind(VoliPtr);
    rewind(VoliAggiornatiPtr);

    if( VoliPtr != NULL ){
        if( VoliAggiornatiPtr != NULL ){
            while( !feof( VoliPtr ) ){
                fgets(buffer, 100, VoliPtr);
                fgets(buffer, 100, VoliAggiornatiPtr);

            }
            fclose(VoliPtr);
            fclose(VoliAggiornatiPtr);
        }
        else{
            puts(msgErrore);
        }
    }
    else{
        puts(msgErrore);
    }

return;
}
