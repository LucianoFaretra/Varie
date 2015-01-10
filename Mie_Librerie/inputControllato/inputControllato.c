#include <stdlib.h>
#include <stdio.h>

int inputControllatoIntero(void);
float inputControllatoFloat(void);
float inputControllatoUnsignedInt(void);


int inputControllatoIntero(void)
{
    int esitoScanf;
    int intero;

    do{
        esitoScanf = scanf("%d", &intero);
        if(esitoScanf == 0){
            printf( "%s", "Attenzione non e' stato inserito un input valido, reinserire il valore!\n");
            scanf("%*[^\n]");
        }
    }while(esitoScanf != 1);

return intero;
}

float inputControllatoFloat(void)
{
    int esitoScanf;
    float numeroVirgolaMobile;

    do{
        esitoScanf = scanf("%f", &numeroVirgolaMobile);
        if(esitoScanf == 0){
            printf( "%s", "Attenzione non e' stato inserito un input valido, reinserire il valore!\n");
            scanf("%*[^\n]");
        }
    }while(esitoScanf != 1);

return numeroVirgolaMobile;
}

float inputControllatoUnsignedInt(void)
{
    int esitoScanf;
    unsigned int numeroUnsignedInt;

    do{
        esitoScanf = scanf("%u", &numeroUnsignedInt);
        if(esitoScanf == 0){
            printf( "%s", "Attenzione non e' stato inserito un input valido, reinserire il valore!\n");
            scanf("%*[^\n]");
        }
    }while(esitoScanf != 1);

return numeroUnsignedInt;
}


