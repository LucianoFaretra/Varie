#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "stampa.h"

void stampa(void)
{
FILE *VoliAggiornatiPtr;
FILE *VoliPtr;
    char buffer[80];

    if((VoliAggiornatiPtr = fopen("VoliAggiornati.txt", "r")) == NULL){
        puts("Impossibile aprire il file VoliAggiornati.txt");
    }
    else{
        if((VoliPtr = fopen("Voli.txt", "r")) == NULL){
            puts("Impossibile aprire il file Voli.txt");
        }
        else{
            while(!feof(VoliPtr)){
                fgets(buffer, 80, VoliPtr);
                printf("%s",buffer);
                if( buffer[(strlen(buffer)) - 1] != '\n'){
                    puts("");
                }
                fgets(buffer, 80, VoliAggiornatiPtr);
                printf("%s",buffer);
                if( buffer[(strlen(buffer)) - 1] != '\n'){
                    puts("");
                }
                puts("");
            }
            fclose(VoliPtr);
            fclose(VoliAggiornatiPtr);

        }
    }

}
