#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LUNGHEZZACODICEVOLO 5
#define LUNGHEZZANOMICITTA 20
#define MAXNUMEROVOLIAEREI 10
#define MAXNUMEROAUMENTI 10

typedef struct{
    char CodiceVolo[LUNGHEZZACODICEVOLO];
    float OrarioPartenza;
    float OrarioArrivo;
    char Destinazione[LUNGHEZZANOMICITTA];
    unsigned int PostiTotali;
    double Prezzo;
}DatiDiVolo;

typedef struct{
    char CodiceVolo[LUNGHEZZACODICEVOLO];
    double NuovoPrezzo;
}AumentoPrezzi;

