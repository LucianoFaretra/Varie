/*

INPUT               DESCRIZIONE                                                                                     DOMINIO
Voli.txt            File di testo contenente le informazioni di volo                                                stringhe di caratteri
Voli                Struttura contenente le informazioni sui voli                                                   struttura di dati
Voli.CodiceVolo     Codice volo univoco                                                                             scrtinga di caratteri
Voli.OrarioPartenza Orario di partenza aereo                                                                        reale >=0, <= 24
Voli.Destinazione   Destinazione del volo                                                                           stringa di caratteri
Voli.OrarioArrivo   Orario di atterraggio                                                                           reale >= 0, <= 24
Voli.PostiTotali    posti totale aereomobile                                                                        intero senza segno
Voli.Prezzo         Prezzo del volo                                                                                 reale >= 0
Aumenti.txt         File di testo contenente le informazioni sugli aumenti                                          stringhe di caratteri
Aumenti             Struttura contenente le informazioni sugli aumenti                                              struttura di dati
Aumenti.CodiceVolo  Codice volo univoco                                                                             scrtinga di caratteri
Aumenti.NuovoPrezzo Prezzo del volo aggiornato                                                                      reale >= 0
MAXNUMEROVOLI       Massimo numero di voli elaborati sal programma                                                  intero senza segno > 0

OUTPUT              DESCRIZIONE                                                                                     DOMINIO
Voli                Struttura contenente le informazioni sui voli aggiornate                                        strutture di dati
VoliAggiornati.txt  File di testo contenente le informazioni di volo con i prezzi aggiornati                        stringhe di caratteri
erroreVoli          Codice d'errore da mostrare nel caso in cui ci sia un volo fantasma                             stringa di caratteri

DATI DI LAVORO      DESCRIZIONE                                                                                     DOMINIO
numeroVoli          Numero di voli letti da file                                                                    intero senza segno >= 0
numeroAumenti       Numero aumenti letti da file                                                                    intero senza segno >= 0
indiceVoli          Indice utilizzato epr scorrere la struttura Voli                                                intero senza segno >= 0
indiceAumenti       Indice usato epr scorrere la struttura aumenti                                                  intero senza segno >= 0

    1   Se e' possibile aprire il file Voli.txt
            Allora
                Se e' possibile aprire il file Aumenti.txt
                    Allora
                        Mentre ci sono ancora righe da leggere nel file Voli.txt
                            Leggi la riga e inseriscilo nella struttura Voli[numeroVoli]
                            incrementa numeroVoli di uno
                        Fine Mentre

                        Mentre ci sono ancora righe da leggere nel file Aumenti.txt
                            Leggi la riga e inseriscilo nella struttura Aumenti[numeroAumenti]
                            incrementa numeroAumenti di uno
                        Fine Mentre
                    Altrimenti
                        Stampa messaggio d'errore
                Fine Se
            Altrimenti
                Stampa messaggio d'errore
        Fine Se

        Azzera indiceAumenti
        Mentre indiceAumenti < numeroAumenti
            Azzera indiceVoli
            Mentre indiceVoli < numeroVoli
                Se Voli[indiceVoli].CodiceVolo e' uguale a Aumenti[indiceAumenti].CodiceVolo
                    Allora
                       Voli[indiceVoli].Prezzo = Aumenti[indiceAumenti].NuovoPrezzo
                       indiceVoli = numeroVoli
                    Altrimenti Se Aumenti[indiceAumenti].CodiceVolo < Voli[indiceVoli].CodiceVolo
                        Allora
                            Stampa erroreVoli
                            indiceVoli = numeroVoli
                    Altrimenti
                        incrementa indiceVoli di uno
                Fine Se
            Fine Mentre
        Inrementa indiceAumenti di uno
        Fine Mentre

        indiceVoli = 0
        Se è possibile creare il file VoliAggiornati.txt
            Allora
                Mentre indiceVoli < numeroVoli
                    Salva Voli[indiceVoli] nel file VoliAggiornati.txt
                    incrementa indiceVoli di uno
            Altrimenti
                Stampa: impossibile creare file VoliAggiornati.txt
        Fine Se


*/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "fusione.h"
#define MAXNUMEROVOLI 10


typedef struct{
    char CodiceVolo[5];
    float OrarioPartenza;
    char Destinazione[15];
    float OrarioArrivo;
    unsigned int PostiTotali;
    float Prezzo;
}DatiDiVolo;

typedef struct{
    char CodiceVolo[5];
    float NuovoPrezzo;
}DatiAumento;

int fusione()
{
FILE *VoliPtr;
FILE *AumentiPtr;
FILE *VoliAggiornatiPtr;

unsigned int numeroVoli = 0;
unsigned int numeroAumenti = 0;
size_t indiceVoli;
size_t indiceAumenti;
char *erroreVoli = "COD. 666 VOLO FANTASMA";

DatiDiVolo Voli[MAXNUMEROVOLI];
DatiAumento Aumenti[MAXNUMEROVOLI];

    memset(Voli, 0, MAXNUMEROVOLI);
    memset(Aumenti, 0, MAXNUMEROVOLI);

    if((VoliPtr = fopen("Voli.txt", "r")) != NULL ){
        if((AumentiPtr = fopen("Aumenti.txt", "r")) != NULL ){
            while(!feof(VoliPtr)){
                fscanf(VoliPtr, "%4s %f %14s %f %u %f", Voli[numeroVoli].CodiceVolo, &Voli[numeroVoli].OrarioPartenza, Voli[numeroVoli].Destinazione, &Voli[numeroVoli].OrarioArrivo, &Voli[numeroVoli].PostiTotali, &Voli[numeroVoli].Prezzo);
                numeroVoli++;
            }

            while(!feof(AumentiPtr)){
                fscanf(AumentiPtr, "%4s %f", Aumenti[numeroAumenti].CodiceVolo, &Aumenti[numeroAumenti].NuovoPrezzo);
                numeroAumenti++;
            }
            fclose(VoliPtr);
            fclose(AumentiPtr);
        }
        else{
        puts("Non e' stato possibile aprire il file Aumenti.txt");
        }
    }
    else{
        puts("Non e' stato possibile aprire il file Voli.txt");
    }


    indiceAumenti = 0;
    while( indiceAumenti < numeroAumenti ){
        indiceVoli = 0;
        while( indiceVoli < numeroVoli ){
            if( 0 == strcmp(Voli[indiceVoli].CodiceVolo, Aumenti[indiceAumenti].CodiceVolo) ){
               Voli[indiceVoli].Prezzo = Aumenti[indiceAumenti].NuovoPrezzo;
               indiceVoli = numeroVoli;
            }
            else{
                indiceVoli++;
                if(indiceVoli == numeroVoli){
                    puts(erroreVoli);
                }
            }
        }
    indiceAumenti++;
    }

    if((VoliAggiornatiPtr = fopen("VoliAggiornati.txt", "w")) != NULL ){
        indiceVoli = 0;
        while( indiceVoli < numeroVoli ){
            fprintf(VoliAggiornatiPtr, "%s %2.2f %s %2.2f %u %.2f\n", Voli[indiceVoli].CodiceVolo, Voli[indiceVoli].OrarioPartenza, Voli[indiceVoli].Destinazione, Voli[indiceVoli].OrarioArrivo, Voli[indiceVoli].PostiTotali, Voli[indiceVoli].Prezzo);
            indiceVoli++;
        }
        fclose(VoliAggiornatiPtr);
    }
    else{
        puts("impossibile creare file VoliAggiornati.txt");
    }



return 1;//L'operazione ha avuto sucesso
}
