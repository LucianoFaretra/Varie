#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DatiGlobali.h"

void stampa(void)
{
FILE *VoliAggiornatiPtr;
FILE *VoliPtr;
char buffer[80];

     if((VoliPtr = fopen(VOLI, "r")) != NULL ){
        
		if((VoliAggiornatiPtr = fopen(AGGIORNATI, "r")) != NULL ){
			 while(!feof(VoliPtr)){
				fgets(buffer, 80, VoliPtr);
				printf("%s", buffer);
				if((buffer[strlen(buffer)-1]) != '\n'){
					puts("");
				}
				fgets(buffer, 80, VoliAggiornatiPtr);
				printf("%s\n", buffer);
				if((buffer[strlen(buffer)-1]) != '\n'){
					puts("");
				}
			}
        }
        else{
	 		printf("Attenzione non e' stato possibile aprire il file: %s\n", AGGIORNATI);
	 	}
	 	
	 }
	 else{
	 	printf("Attenzione non e' stato possibile aprire il file: %s\n", VOLI);
	 }
        
return;
}
