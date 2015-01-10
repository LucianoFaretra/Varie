#include <stdlib.h>
#include <stdio.h>
#define MAX 200 //Grandezza massima matrice
#include "AccessoAiDati.h"

void ScrivereElemento(float *matrice, int i, int j, float valore) //i è il valore da inserire
{//scrive il primo elemento nella matrice
matrice[(int)(i*MAX+j)] = valore;
return;
}

float LetturaElemento(float *matrice, int i, int j) //restituisce il valore
{//legge il primo elemento nella matrice
return matrice[(int)(i*MAX+j)];
}
