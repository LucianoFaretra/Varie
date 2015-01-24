#include <stdlib.h>
#include <stdio.h>
#include "AccessoAiDati.h"
#include "DatiGlobali.h"

void ScrivereElemento(float *matrice, int i, int j, float valore) //i e' il valore da inserire
{//scrive il primo elemento nella matrice
matrice[(i*(DIM)+j)] = valore;
return;
}

float LetturaElemento(float *matrice, int i, int j) //restituisce il valore
{//legge il primo elemento nella matrice
return matrice[(i*(DIM)+j)];
}
