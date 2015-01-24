#include <stdlib.h>
#include <stdio.h>
#include "AccessoAiDati.h"
#include "DatiGlobali.h"

void ScrivereElemento(float matrice[][DIM], int i, int j, float valore) //i e' il valore da inserire
{//scrive il primo elemento nella matrice
matrice[i][j] = valore;
return;
}

float LetturaElemento(float matrice[][DIM], int i, int j) //restituisce il valore
{//legge il primo elemento nella matrice
return matrice[i][j];
}
