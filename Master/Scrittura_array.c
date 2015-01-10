#include <stdlib.h>
#include <stdio.h>

#include "Scrittura_array.h"

void Scrittura_array(float array[], int i, int j, float valore) //i è il valore da inserire
{//scrive il primo elemento nella matrice
array[(i*(int)array[1]+j)] = valore;

return;
}
