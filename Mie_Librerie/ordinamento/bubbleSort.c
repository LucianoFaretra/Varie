#include <stdio.h>
#include <stdlib.h>

int bubbleSort( int array[], unsigned int grandezzaArray )
{
    unsigned int passate;    /*Contatore delle passate*/
    size_t i;       /*Contatore dei confronti*/
    int temp;    /*Locazione temporanea utilizzata per effettuare gli scambi*/
    int noScambi = 0;

    passate = 1;
    while( passate < grandezzaArray ){
        i = 0;
        noScambi = 0;
        while( i < grandezzaArray ){
            if( array[i] > array[i + 1] ){ //Confronta elemento con successivo, se piu grande lo scambia
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                noScambi++;
            }
        i++;
        }
    if( noScambi == 0){// Se non vengono operati scambi in una passata significa che l'arrai e' in posizione esatta
        return 0;
    }
    passate++;
    grandezzaArray--; //Ad ogni passata si e' sicuri che l'ultimo membro spostato e in poosizione giusta
    }

    return 0;
}
