#include "globale.h"

void stampa( char *messaggioFileNonTrovato )
{
    FILE *VoliPtr;
    FILE *VoliAggiornatiPtr;

    char CodiceVolo[LUNGHEZZACODICEVOLO];
    float OrarioPartenza;
    float OrarioArrivo;
    char Destinazione[LUNGHEZZANOMICITTA];
    unsigned int PostiTotali;
    double Prezzo;

    if((VoliPtr = fopen("Voli.txt", "r")) == NULL ){
        puts(messaggioFileNonTrovato);
    }
    else{
        if((VoliAggiornatiPtr = fopen("VoliAggiornati.txt", "r")) == NULL ){
            puts(messaggioFileNonTrovato);
        }
        else{
            while( !feof( VoliAggiornatiPtr ) ){
                fscanf(VoliPtr, "%4s %f %19s %f %u %lf", CodiceVolo, &OrarioPartenza, Destinazione, &OrarioArrivo, &PostiTotali, &Prezzo);
                printf("%4s %.2f %19s %.2f %u %.2lf\n", CodiceVolo, OrarioPartenza, Destinazione, OrarioArrivo, PostiTotali, Prezzo);
                fscanf(VoliAggiornatiPtr, "%4s %f %19s %f %u %lf", CodiceVolo, &OrarioPartenza, Destinazione, &OrarioArrivo, &PostiTotali, &Prezzo);
                printf("%4s %.2f %19s %.2f %u %.2lf\n", CodiceVolo, OrarioPartenza, Destinazione, OrarioArrivo, PostiTotali, Prezzo);
            }
        }
    }
return;
}
