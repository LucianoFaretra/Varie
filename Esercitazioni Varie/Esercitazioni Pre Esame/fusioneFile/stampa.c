#include "globale.h"

void stampa( char *messaggioFileNonTrovato )
{
    FILE *VoliPtr;
    FILE *VoliAggiornatiPtr;

    char bufferLettura[100];


    if((VoliPtr = fopen("Voli.txt", "r")) == NULL ){
        puts(messaggioFileNonTrovato);
    }
    else{
        if((VoliAggiornatiPtr = fopen("VoliAggiornati.txt", "r")) == NULL ){
            puts(messaggioFileNonTrovato);
        }
        else{
            while( !feof( VoliPtr ) ){
                 fgets(bufferLettura, 100, VoliPtr);
                 printf("%s", bufferLettura);
                 fgets(bufferLettura, 100, VoliAggiornatiPtr);
                 printf("%s", bufferLettura);
            }
        }
    }
return;
}
