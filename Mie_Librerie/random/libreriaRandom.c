/*                 Sviluppato da Luciano Faretra 03/01/2015 rilasciato sotto licenza GNUv3
                                    Genera array casuali

****************************************************************************************************************
    Funzione    generaArrayMonodimensionali( array[], grandezzaArray, generaDa, generaFino )

    INPUT                           DESCRIZIONE                                                     DOMINIO
    array                           Array monodimensionale in cui salvare i numeri                  int >= 0
    grandezzaArray                  Grandezza dell'array                                            int >= 0
    generaDa                        Intervallo di numeri usati per generare, es da 0                int >= 0
    generaFino                      Intervallo di numeri usati per generare, es fino a 1000         int >= 0

    OUTPUT                          DESCRIZIONE                                                     DOMIONIO
    array                           Array modificata                                                int >= 0

    DATI DI LAVORO                  DESCRIZIONE                                                     DOMINIO
    contatorePosizioni              Contatore utilizzato per calcolare le posizioni dell'array      int >= 0

*****************************************************************************************************************


    Inizzializza il seme per il generatore di numeri casuali
    Mentre contatorePosizioni < grandezzaArray
        array[contatorePosizioni] = rand()
        contatorePosizioni++
    Fine Mentre

    return -1

*/
#include <stdlib.h>
#include <time.h>
void generaArrayMonodimensionali( int array[], int grandezzaArray, int generaDa, int generaFino )
{
    int contatorePosizioni = 0;

    srand(time(NULL));

    while( contatorePosizioni < grandezzaArray ){
        array[contatorePosizioni] = ( generaDa + rand() % ( generaFino - generaDa ) );
        contatorePosizioni++;
    }

return;
}
