#include <stdlib.h>
#include <stdio.h>

#include "Scrittura_array.h"

void Scrittura_array(char array, int i, char valore)
{


    if( array == NULL ){
        puts("Errore, puntatore nullo #[Debug info. fn(Scrittura_array)]#");
    }
    else{
        array[i] = valore;
    }

return;
}
