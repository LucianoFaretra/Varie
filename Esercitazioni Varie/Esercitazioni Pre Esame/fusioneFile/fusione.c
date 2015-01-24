#include "globale.h"

void fusione( char *messaggioErrore, char *messaggioFileNonTrovato )
{
    FILE *VoliPtr;
    FILE *AumentiPtr;
    FILE *VoliAggiornatiPtr;
    size_t contatoreRighe = 0;
    unsigned int numeroVoli = 0;
    unsigned int numeroAumenti = 0;


    DatiDiVolo voliFiumicino[MAXNUMEROVOLIAEREI]; //Dichiara 10 possibili voli
    memset(voliFiumicino, 0, MAXNUMEROVOLIAEREI); //Inizializza l'array

    AumentoPrezzi aumentiVoliFiumicino[MAXNUMEROAUMENTI]; //Dichiara 10 possibili voli
    memset(aumentiVoliFiumicino, 0, MAXNUMEROAUMENTI); //Inizializza l'array


    if( ( VoliPtr = fopen("Voli.txt", "r") ) == NULL ){
        puts(messaggioFileNonTrovato);
    }
    else{
        while( !feof(VoliPtr) ){
            fscanf(VoliPtr, "%4s%f%19s%f%u%lf", voliFiumicino[contatoreRighe].CodiceVolo, &voliFiumicino[contatoreRighe].OrarioPartenza, voliFiumicino[contatoreRighe].Destinazione,
                                                       &voliFiumicino[contatoreRighe].OrarioArrivo, &voliFiumicino[contatoreRighe].PostiTotali, &voliFiumicino[contatoreRighe].Prezzo );
        contatoreRighe++;
        numeroVoli++;
        }
    }
    fclose(VoliPtr);

    contatoreRighe = 0;
    if( ( AumentiPtr = fopen("Aumenti.txt", "r") ) == NULL ){
        puts(messaggioFileNonTrovato);
    }
    else{
        while( !feof(AumentiPtr) ){
            fscanf(AumentiPtr, "%4s%lf", aumentiVoliFiumicino[contatoreRighe].CodiceVolo, &aumentiVoliFiumicino[contatoreRighe].NuovoPrezzo );
        contatoreRighe++;
        numeroAumenti++;
        }
    }
    fclose(AumentiPtr);

    if(numeroVoli != numeroAumenti){
        puts("Attenzione, il numero dei voli non combaciano con il numero degli aumenti");
    }
    else{
        if( ( VoliAggiornatiPtr = fopen("VoliAggiornati.txt", "w") ) == NULL ){
            puts(messaggioFileNonTrovato);
        }
        else{
            numeroVoli = 0;
            while(numeroVoli != numeroAumenti){
                if( 0 == strcmp( voliFiumicino[numeroVoli].CodiceVolo, aumentiVoliFiumicino[numeroVoli].CodiceVolo )){
                    fprintf( VoliAggiornatiPtr, "%s %.2f %s %.2f %u %.2lf\n", aumentiVoliFiumicino[numeroVoli].CodiceVolo, voliFiumicino[numeroVoli].OrarioPartenza, voliFiumicino[numeroVoli].Destinazione, voliFiumicino[numeroVoli].OrarioArrivo, voliFiumicino[numeroVoli].PostiTotali, aumentiVoliFiumicino[numeroVoli].NuovoPrezzo );
                }
                else{
                    puts(messaggioErrore);
                }
            numeroVoli++;
            }
        }
    }
    fclose(VoliAggiornatiPtr);

return;
}
