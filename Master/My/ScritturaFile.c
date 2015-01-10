#include <stdlib.h>
#include <stdio.h>
#include "Lettura_array.h"

int Scrittura_file(int i, FILE *fileDiTesto)
{

	
	if ((fileDiTesto = fopen("file_di_testo.txt", "r")) != NULL)			//1° controllo
		fileDiTesto = fopen("file_di_testo.txt", "w");						//apertura del file in scrittura
		else fileDiTesto = fopen("file_di_testo.txt", "w");
			fprintf(fileDiTesto, "%c", Lettura_array(array, i));
	fclose(fileDiTesto);													//chiude il file

	return 0;
}

