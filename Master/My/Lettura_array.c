#include <stdlib.h>
#include <stdio.h>

#include "Lettura_array.h"

float Lettura_array(char array, int i)
{
    if( array == NULL ){
        puts("Errore, puntatore nullo #[Debug info. fn(Lettura_array)]#");
    }
    else{
        return array[i];
    }
return 0;
}
