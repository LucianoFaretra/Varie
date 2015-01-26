/*                 Sviluppato da Luciano Faretra 20/01/2015 rilasciato sotto licenza GNUv3
                                        Fusione2

    Affinamento Top Down

    INPUT                     DESCRIZIONE                                                           DOMINIO
    VoliPtr                   Puntatore al file Voli.txt                                            Stringhe di caratteri
    CodiceVolo                Codice identificativo Volo contenuto in VoliPtr                       stringa di caratteri
    OrarioPartenza            Orario di partenza apparecchio contenuto in VoliPtr                   reale con due cifre decimali >= 0, <= 24
    Destinazione              Destinazione del volo contenuto in VoliPtr                            stringa di caratteri
    OrarioArrivo              Orario di arrivo del volo contenuto in VoliPtr                        reale con due cifre decimali >= 0, <= 24
    PostiTotali               Posti totali aereo contenuto in VoliPtr                               intero senza segno > 0
    Prezzo                    Prezzo del volo coontenuto in VoliPtr                                 reale a doppia precisione >= 0
    AumentiPtr                Puntatore al file Aumenti.txt contente gli aumenti di prezzi          Stringhe di caratteri
    CodiceVoloAumenti         Codice identificativo Volo contenuto in AumentiPtr                    stringa di caratteri
    PrezzoAumenti             Prezzo del volo coontenuto in AumentiPtr                                 reale a doppia precisione >= 0


    OUTPUT                    DESCRIZIONE                                                           DOMIONIO
    VoliAggiornatiPtr         Puntatore a VoliAggiornati contenente tutte le info di volo aggiornate stringhe di caratteri
    CodiceVolo                Codice identificativo Volo aggiornato contenuto in VoliAggiornatiPtr     stringa di caratteri
    OrarioPartenza            Orario di partenza apparecchio aggiornato contenuto in VoliAggiornatiPtr reale con due cifre decimali >= 0, <= 24
    Destinazione              Destinazione del volo aggiornato contenuto in VoliAggiornatiPtr          stringa di caratteri
    OrarioArrivo              Orario di arrivo del volo aggiornato contenuto in VoliAggiornatiPtr      reale con due cifre decimali >= 0, <= 24
    PostiTotali               Posti totali aereo aggiornato contenuto in VoliAggiornatiPtr             intero senza segno > 0
    Prezzo                    Prezzo del volo aggiornato coontenuto in VoliAggiornatiPtr               reale a doppia precisione >= 0
    msgErrore                 Stampa un messaggio d'errore nel caso in cui ci sia un aumento per       stringa di caratteri
                              un volo fantasma (COD. 666)

    DATI DI LAVORO            DESCRIZIONE                                                           DOMINIO

    1.  Il programma legge il file Voli.txt
        Caria in memoria le informazioni dei voli
        Il programma legge il file Aumenti.txt
        Caria in memoria le informazioni degli aumenti

        mentre ci sono ancora aumenti da controllare
            indiceVoli = 0
            mentre ci sono ancora Voli da controllare
                    Se CodiceVoloAumenti == CodiceVolo
                        Allora
                            Prezzo = PrezzoAumenti
                            Stampa volo attuale in VoliAggiornatiPtr
                        Altrimenti Se CodiceVoloAumenti < CodiceVolo
                            Allora
                                Stampa msgErrore
                        Altrimenti
                            incrementa indiceVoli di 1
                            Stampa volo attuale in VoliAggiornatiPtr
                    Fine Se
            Fine Mentre
            Passa ad aumento successivo
        Fine Mentre

*/
#include <stdio.h>
#include <stdlib.h>
#include "globali.h"
#include "fusione.h"
#include "stampa.h"

void fusione( void )
{

FILE *VoliPtr;
FILE *VoliAggiornatiPtr;
FILE *AumentiPtr;

    char *msgErrore = "COD. 666";

    DatiVolo VoliInServizio = { "", 0.00, "", 0.00, 0, 0.00 };
    AumentiVoli AumentiVoliInServizio = { "", 0.00 };


    if(( VoliPtr = fopen( "Voli.txt", "r" )) == NULL ){
        puts(msgErrore);
    }
    else{
        if(( AumentiPtr = fopen( "Aumenti.txt", "r" )) == NULL ){
        puts(msgErrore);
        }
        else{
            if(( VoliAggiornatiPtr = fopen( "VoliAggiornati.txt", "w" )) == NULL ){
                puts(msgErrore);
            }
            else{
                while( !feof(AumentiPtr) ){
                    while( !feof(VoliPtr) ){
                        fscanf(AumentiPtr, "%s %lf", AumentiVoliInServizio.CodiceVoloAumenti, &AumentiVoliInServizio.PrezzoAumenti );
                        fscanf(VoliPtr, "%s %f %s %f %u %lf", VoliInServizio.CodiceVolo, &VoliInServizio.OrarioPartenza, VoliInServizio.Destinazione,
                                                                &VoliInServizio.OrarioArrivo, &VoliInServizio.PostiTotali, &VoliInServizio.Prezzo);

                        if(AumentiVoliInServizio.CodiceVoloAumenti == VoliInServizio.CodiceVolo){
                            VoliInServizio.Prezzo = AumentiVoliInServizio.PrezzoAumenti;
                            fprintf(VoliAggiornatiPtr, "%s %.2f %s %.2f %u %.2lf\n", VoliInServizio.CodiceVolo, VoliInServizio.OrarioPartenza, VoliInServizio.Destinazione,
                                                                            VoliInServizio.OrarioArrivo, VoliInServizio.PostiTotali, VoliInServizio.Prezzo);
                        }
                        else if(AumentiVoliInServizio.CodiceVoloAumenti < VoliInServizio.CodiceVolo){
                            puts(msgErrore);
                        }
                        else{
                            fprintf(VoliAggiornatiPtr, "%s %.2f %s %.2f %u %.2lf\n", VoliInServizio.CodiceVolo, VoliInServizio.OrarioPartenza, VoliInServizio.Destinazione,
                                                                            VoliInServizio.OrarioArrivo, VoliInServizio.PostiTotali, VoliInServizio.Prezzo);
                        }
                    }
                    rewind(VoliPtr);
                }
            }
            stampa( VoliPtr, VoliAggiornatiPtr );
        }
        fclose(AumentiPtr);
    }
return;
}
