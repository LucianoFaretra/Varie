#include "globale.h"

void fusione( char *messaggioErrore, char *messaggioFileNonTrovato )
{
    FILE *VoliPtr;
    FILE *AumentiPtr;
    FILE *VoliAggiornatiPtr;
    size_t contatoreRighe = 0;
    unsigned int numeroAumenti = 0;
    unsigned int numeroInserimenti = 0;

    DatiDiVolo voliFiumicino[MAXNUMEROVOLIAEREI]; //Dichiara 10 possibili voli
    memset(voliFiumicino, 0, MAXNUMEROVOLIAEREI); //Inizializza l'array

    AumentoPrezzi aumentiVoliFiumicino[MAXNUMEROAUMENTI]; //Dichiara 10 possibili voli
    memset(aumentiVoliFiumicino, 0, MAXNUMEROAUMENTI); //Inizializza l'array


    if( ( VoliPtr = fopen("Voli.txt", "r") ) == NULL ){
        puts(messaggioFileNonTrovato);
    }
    else{
        while( !feof(VoliPtr) ){
            fscanf(VoliPtr, "%4s %f %19s %f %u %lf\n", voliFiumicino[contatoreRighe].CodiceVolo, &voliFiumicino[contatoreRighe].OrarioPartenza, voliFiumicino[contatoreRighe].Destinazione,
                                                        &voliFiumicino[contatoreRighe].OrarioArrivo, &voliFiumicino[contatoreRighe].PostiTotali, &voliFiumicino[contatoreRighe].Prezzo );
        contatoreRighe++;
        numeroInserimenti++;
        }
    }
    fclose(VoliPtr);

    contatoreRighe = 0;
    if( ( AumentiPtr = fopen("Aumenti.txt", "r") ) == NULL ){
        puts(messaggioFileNonTrovato);
    }
    else{
        while( !feof(AumentiPtr) ){
            fscanf(AumentiPtr, "%4s %lf", aumentiVoliFiumicino[contatoreRighe].CodiceVolo, &aumentiVoliFiumicino[contatoreRighe].NuovoPrezzo );

        contatoreRighe++;
        numeroAumenti++;
        }
    }
    fclose(AumentiPtr);

    printf("Numero aumenti; %d\n Numero voli: %d\n", numeroAumenti, numeroInserimenti);
    if( ( VoliAggiornatiPtr = fopen("VoliAggiornati.txt", "w")) == NULL){
        puts(messaggioFileNonTrovato);
    }
    else{
        do{
            contatoreRighe = 0;
            while(contatoreRighe <= numeroInserimenti ){
                if( aumentiVoliFiumicino[numeroAumenti].CodiceVolo != voliFiumicino[contatoreRighe].CodiceVolo ){
                    puts(messaggioErrore);
                }
                else{
                    fprintf( VoliAggiornatiPtr, "%4s %f %19s %f %u %lf\n", aumentiVoliFiumicino[numeroAumenti].CodiceVolo, voliFiumicino[contatoreRighe].OrarioPartenza, voliFiumicino[contatoreRighe].Destinazione, voliFiumicino[contatoreRighe].OrarioArrivo, voliFiumicino[contatoreRighe].PostiTotali, aumentiVoliFiumicino[numeroAumenti].NuovoPrezzo );
                    }
            contatoreRighe++;
            }
            numeroAumenti--;
        }while(numeroAumenti == 0);
    fclose(VoliAggiornatiPtr);
    }

return;
}
