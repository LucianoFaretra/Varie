#include <stdlib.h>
#include <stdio.h>

Lettura_file(nomefile.txt, char vettore[])
{
    FILE *dataPtr; //dataPtr è il puntatore ad un file di testo

    if( ( dataPtr = fopen( "nomefile.txt", "r" ) ) == NULL ){
        puts("Errore, non è possibile aprire il file #[Debug info. fn(Lettura_file)]#");
    }//Fine if
    else{
        fscanf( dataPtr, %29s)
                             Leggi file di testo
                             Carica file nell’array
                Altrimenti
                              Stampa messaggio errore
    FINE SE

}
