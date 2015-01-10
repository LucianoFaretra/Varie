#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "globali.h"
#include "input.h"

char input()
{
FILE *file;

string buffer;
char *riga;

if ((file = fopen ("parole.txt", "r")) != NULL)
    {
    riga = fgets(buffer, 100, file);
    if(riga == NULL)
        {
        printf("Attenzione c'è stato un errore nella lettura della stringa");
        }
    }
else printf("errore nell’apertura del file\n");

return buffer[];
}
