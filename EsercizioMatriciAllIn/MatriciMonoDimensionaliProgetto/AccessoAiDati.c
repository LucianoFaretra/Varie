#include <stdlib.h>
#include <stdio.h>

#include "DatiGlobali.h"
#include "AccessoAiDati.h"

void ScrivereElemento(float matrice[], int i, int j, float valore) //i è il valore da inserire
{//scrive il primo elemento nella matrice
matrice[(i*(int)matrice[1]+j)] = valore;

return;
}

float LetturaElemento(float matrice[], int i, int j) //restituisce il valore
{//legge il primo elemento nella matrice

return matrice[(i*(int)matrice[1]+j)];
}
