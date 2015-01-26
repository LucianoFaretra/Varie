/*

    ********************************************************************************************************************
    Funzione fusione
    INPUT               DESCRIZIONE                                                                 DOMINIO
    FILEVOLI            Nome del file contenente le informazioni di volo                            stringa di caratteri
    FILEAUMENTI         Nome del file contenente le informazioni sugli amenti                       stringa di caratteri
    FILEAGGIORNATO      Nome del file contenente le informazioni dei voli aggiornati                stringa di caratteri
    MAXVOLI             Numero di voli massimo supportati dall'implementazione                      intero senza segno
    FileVoliPtr         Puntatore al FILEVOLI                                                       Indirizzo di memoria
    FileAumentiPtr      Puntatore al FILEAUMENTI                                                    Indirizzo di memoria
    FileAggiornatoPtr   Puntatore al FILEAGGIORNATO                                                 Indirizzo di memoria
    Voli                Struttura contenente le informazioni sui voli correnti                      strutture di dati
    Aumenti             Strutture contenente le informazioni su gli amenti da effettuare            strutture di dati
    tipologiaLettura    Tipi 1 lettura Voli, Tipo 2 lettura Aumenti                                 intero senza segno, 1, 2


    OUTPUT              DESCRIZIONE                                                                DOMINIO
    Voli                Struttura contenente le informazioni sui voli correnti                     strutture di dati
    Voli                Strutture contenente le informazioni su gli amenti da effettuare           strutture di dati
    tipologiaLettura    Tipi 1 lettura Voli, Tipo 2 lettura Aumenti                                intero senza segno, 1, 2
    FilePtr             Puntatore al file che si desidera leggere                                  struttura tipo file

    1.1
    Dichiara le strutture dati
    Apre i file
    Richiama la funzione letturaFile per leggere il file dei voli
    Richiama la funzione letturaFile per leggere il file degli aumenti
    Richiama la funzione confrontoECreazioneFile

    1.2
    Dichiara la struttura Voli di MAXVOLI elementi
    Dichiara la struttura Aumenti di MAXVOLI elementi
    Assegna a FileVoliPtr l'indirizzo del FILEVOLI
        Se FileVoliPtr è nullo
            Allora
                Stampa: errore aprertura FILEVOLI
                return 0;
            Altrimenti
                tipologiaLettura = 1
                letturaFile( FileVoliPtr, Voli, tipologiaLettura)
                fclose(FileVoliPtr)
        Fine Se
    Assegna a FileAumentiPtr l'indirizzo del FILEAUMENTI
        Se FileAumentiPtr è nullo
            Allora
                Stampa: errore aprertura FILEAUMENTI
                return 0;
            Altrimenti
                tipologiaLettura = 2
                letturaFile( FileAumentiPtr, Aumenti, tipologiaLettura)
                fclose(FileAumentiPtr)
        Fine Se

    Assegna a FileAggiornatoPtr l'indirizzo del FILEAGGIORNATO
        Se FileAggiornatoPtr è nullo
            Allora
                Stampa: errore aprertura FILEAGGIORNATO
                return 0
            Altrimenti
                stampaFileAggiornato(Voli)
                fclose(FileAggiornatoPtr)
        Fine Se




    ********************************************************************************************************************
    Funzione letturaFile( puntatore a file da leggere, indirizzo della struttura, tipologiaLettura)
    INPUT                       DESCRIZIONE                                                                     DOMINIO
    FilePtr                     Puntatore al file che si sta leggendo                                           struttura tipo file
    DatiVolo                    Struttura vuota contenente le informazioni sui voli correnti                    strutture di dati
    DatiAumenti                 Strutture vuota contenente le informazioni su gli amenti da effettuare          strutture di dati
    tipologiaLettura            Tipi 1 lettura Voli, Tipo 2 lettura Aumenti                                     intero senza segno, 1, 2

    OUTPUT                          DESCRIZIONE                                                                 DOMINIO
    Voli                            Struttura contenente le informazioni sui voli correnti                      strutture di dati
    Aumenti                         Strutture contenente le informazioni su gli amenti da effettuare            strutture di dati
    Voli.DatiVolo.CodiceVolo        Codice identificativo univoco volo                                          stringa di caratteri != 0
    Voli.DatiVolo.OrarioPartenza    Orario di parenza volo                                                      reale con due decimali >= 0, <= 24
    Voli.DatiVolo.Destinazione      Lugo di destinazione volo                                                   stringa di caratteri
    Voli.DatiVolo.OrarioArrivo      Orario d'arrivo volo                                                        reale con due decimali >= 0, <= 24
    Voli.DatiVolo.PostiTotali       Postiti totali passeggeri aereomobile                                       intero senza segno > 0
    Voli.DatiVolo.Prezzo            Prezzo del volo                                                             reale doppia precisione con due decimali >= 0
    Voli.NumeroVoli                 Numero di voli presenti su file                                             intero senza segno
    Aumenti.DatiAumenti.CodiceVolo  Codice identificativo univoco volo                                          stringa di caratteri != 0
    Aumenti.DatiAumenti.NuovoPrezzo Nuovo prezzo del volo                                                       reale doppia precisione con due decimali >= 0
    Aumenti.NumeroAumenti           Numero degli aumenti presenti su file                                       intero senza segno

    1.1 La funzione legge il file e lo carica nella relativa struttura a seconda della tipologiaLettura

        numeroRiga = 0
    1.2 Se tipologiaLettura == 1
            Allora
                Mentre ci sono ancora righe
                    leggi il contenuto della riga e assegnali a DatiVolo[numeroRiga].CodiceVolo, DatiVolo[numeroRiga].OrarioPartenza, DatiVolo[numeroRiga].OrarioArrivo, DatiVolo[numeroRiga].PostiTotali, DatiVolo[numeroRiga].Prezzo, DatiAumenti[numeroRiga].CodiceVolo, DatiAumenti.NuovoPrezzo
                    incrementa numeroRiga di uno
                    Voli.NumeroVoli++;
                    Passa a riga successiva
                Fine Mentre
            Altrimenti
                Mentre ci sono ancora righe
                    leggi il contenuto della riga e assegnali a DatiAumenti.CodiceVolo, DatiAumenti.NuovoPrezzo
                    incrementa numeroRiga di uno
                    Aumenti.NumeroAumenti++;
                    Passa a riga successiva
                Fine Mentre
        Fine se

    ********************************************************************************************************************
    Funzione confrontoDati
    INPUT                           DESCRIZIONE                                                                 DOMINIO
    FILEAGGIORNATO                  Nome del file contenente le informazioni dei voli aggiornati                stringa di caratteri
    Volo                            Struttura contenente le informazioni sui voli correnti                      strutture di dati
    Aumenti                         Strutture contenente le informazioni su gli amenti da effettuare            strutture di dati
    Voli.DatiVolo.CodiceVolo        Codice identificativo univoco volo                                          stringa di caratteri
    Voli.DatiVolo.OrarioPartenza    Orario di parenza volo                                                      reale con due decimali >= 0, <= 24
    Voli.DatiVolo.Destinazione      Lugo di destinazione volo                                                   stringa di caratteri
    Voli.DatiVolo.OrarioArrivo      Orario d'arrivo volo                                                        reale con due decimali >= 0, <= 24
    Voli.DatiVolo.PostiTotali       Postiti totali passeggeri aereomobile                                       intero senza segno > 0
    Voli.DatiVolo.Prezzo            Prezzo del volo                                                             reale doppia precisione con due decimali >= 0
    Voli.NumeroVoli                 Numero di voli presenti su file                                             intero senza segno
    Aumenti.DatiAumenti.CodiceVolo  Codice identificativo univoco volo                                          stringa di caratteri
    Aumenti.DatiAumenti.NuovoPrezzo Nuovo prezzo del volo                                                       reale doppia precisione con due decimali >= 0
    Aumenti.NumeroAumenti           Numero degli aumenti presenti su file                                       intero senza segno

    OUTPUT                          DESCRIZIONE                                                                 DOMINIO
    Volo                            Struttura contenente le informazioni sui voli correnti                      strutture di dati
    Aumenti                         Strutture contenente le informazioni su gli amenti da effettuare            strutture di dati

    DATI DI LAVORO                  DESCRIZIONE                                                                 DOMINIO
    indiceArrayAumenti              indice utilizzato per scorrere gli array                                    intero senza segno
    indiceArrayVoli                 indice utilizzato per scorrere gli array                                    intero senza segno



    1.1 La funzione riceve le strtture DatiVolo e DatiAumenti
        Confronta i CodiceVolo di entrambe le strutture
            Se CodiceVolo sono uguali
                Allora
                    Aggiorna il prezzo della struttura DatiVolo
                Altrimenti Se DatiAumenti.CodiceVolo non è presente in DatiVolo.CodiceVolo
                    Allora
                        Stampa: errore volo fantasma
            Fine Se

    1.1 indiceArrayAumenti = 0
        Mentre indiceArrayAumenti < Aumenti.NumeroVoli
            indiceArrayVoli = 0
            Mentre indiceArrayVoli < Voli.NumeroVoli
                Se Voli.DatiVolo.CodiceVolo e Aumenti.DatiAumenti.CodiceVolo sono uguali
                    Allora
                        Voli.DatiVolo[indiceArrayVoli].Prezzo = Aumenti.DatiAumenti[indiceArrayAumenti].NuovoPrezzo
                        indiceArrayVoli = Voli.NumeroVoli
                    Altrimenti Se Aumenti.DatiAumenti[indiceArrayAumenti].CodiceVolo < Voli.DatiVolo[indiceArrayVoli].CodiceVolo
                        Allora
                            Stampa errore volo fantasma
                    Fine Altrimenti Se
                indiceArrayVoli++
                Fine se
            Fine Mentre
        indiceArrayAumenti++
        Fine Mentre

    ********************************************************************************************************************
    Funzione stampaFileAggiornato(FileAggiornatoPtr)

    INPUT                           DESCRIZIONE                                                                 DOMINIO
    Volo                            Struttura contenente le informazioni sui voli correnti                      strutture di dati
    Voli.DatiVolo.CodiceVolo        Codice identificativo univoco volo                                          stringa di caratteri
    Voli.DatiVolo.OrarioPartenza    Orario di parenza volo                                                      reale con due decimali >= 0, <= 24
    Voli.DatiVolo.Destinazione      Lugo di destinazione volo                                                   stringa di caratteri
    Voli.DatiVolo.OrarioArrivo      Orario d'arrivo volo                                                        reale con due decimali >= 0, <= 24
    Voli.DatiVolo.PostiTotali       Postiti totali passeggeri aereomobile                                       intero senza segno > 0
    Voli.DatiVolo.Prezzo            Prezzo del volo                                                             reale doppia precisione con due decimali >= 0
    Voli.NumeroVoli                 Numero di voli presenti su file                                             intero senza segno

    OUTPUT                          DESCRIZIONE                                                                 DOMINIO
    VoliAggiornati.txt              File di testo contenente i dati di volo con prezzi aggiornati               stringhe di caratteri

    DATI DI LAVORO                  DESCRIZIONE                                                                 DOMINIO
    indiceArrayVoli                 indice utilizzato per scorrere gli array                                    intero senza segno

    1.1 Mentre ci sono ancora voli
            Salva dati della struttura su file

    1.2 Mentre indiceArrayVoli < Voli.NumeroVoli
            Salva su FileAggiornatoPtr il Voli.DatiVolo[indiceArrayVoli].CodiceVolo, Voli.DatiVolo[indiceArrayVoli].OrarioPartenza, Voli.DatiVolo[indiceArrayVoli].Destinazione, Voli.DatiVolo[indiceArrayVoli].OrarioArrivo, Voli.DatiVolo[indiceArrayVoli].PostiTotali, Voli.DatiVolo[indiceArrayVoli].Prezzo
        Fine Mentre

*/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define FILEVOLI "Voli.txt"
#define FILEAUMENTI "Aumenti.txt"
#define FILEAGGIORNATO "VoliAggiornati.txt"
#define MAXVOLI 10

struct StrutturaVoli{
    unsigned int NumeroVoli;
    struct{
        char CodiceVolo[5];
        float OrarioPartenza;
        char Destinazione[15];
        float OrarioArrivo;
        unsigned int PostiTotali;
        float Prezzo;
    }DatiVolo;
}Voli[MAXVOLI];

struct StrutturaAumenti{
    unsigned int NumeroAumenti;
    struct{
        char CodiceVolo[5];
        float NuovoPrezzo;
    }DatiAumenti;
}Aumenti[MAXVOLI];

int fusione( void )
{
    void letturaFile(FILE *File, struct StrutturaVoli *Struttura, struct StrutturaAumenti *Struttura2, unsigned int tipologiaLettura);
    void confrontoDati(struct StrutturaVoli *Voli, struct StrutturaAumenti *Aumenti);
    void stampaFileAggiornato(FILE *File, struct StrutturaVoli *Struttura);

FILE *FileVoliPtr;
FILE *FileAumentiPtr;
FILE *FileAggiornatoPtr;

unsigned int tipologiaLettura;

//struct StrutturaVoli ;
//struct StrutturaAumenti ;


    if((fopen(FILEVOLI, "r")) == NULL ){
        printf("%s %s", "Impossibile aprire il file", FILEVOLI);
        return 0;
    }
    else{
        tipologiaLettura = 1;
        letturaFile( FileVoliPtr, Voli, Aumenti, tipologiaLettura);
        fclose(FileVoliPtr);
    }

    if((fopen(FILEAUMENTI, "r")) == NULL ){
        printf("%s %s", "Impossibile aprire il file", FILEAUMENTI);
        return 0;
    }
    else{
        tipologiaLettura = 2;
        letturaFile( FileAumentiPtr, Voli, Aumenti, tipologiaLettura);
        fclose(FileAumentiPtr);
    }

    confrontoDati(Voli, Aumenti);

    if((fopen(FILEAGGIORNATO, "w")) == NULL ){
        printf("%s %s", "Impossibile aprire il file", FILEAGGIORNATO);
        return 0;
    }
    else{
        stampaFileAggiornato(FileAggiornatoPtr, Voli);
        fclose(FileAggiornatoPtr);
    }

return 1;//Operazione Riuscita
}

void letturaFile(FILE *File, struct StrutturaVoli *Struttura, struct StrutturaAumenti *Struttura2, unsigned int tipologiaLettura )
{
size_t numeroRiga = 0;

    Struttura->NumeroVoli = 0;
    if( tipologiaLettura == 1 ){
        while( !feof(File) ){
            fscanf(File, "%s %f %s %f %u %f", Struttura->DatiVolo[numeroRiga].CodiceVolo, Struttura->DatiVolo[numeroRiga].OrarioPartenza, Struttura->DatiVolo[numeroRiga].Destinazione, Struttura->DatiVolo[numeroRiga].OrarioArrivo, Struttura->DatiVolo[numeroRiga].PostiTotali, Struttura->DatiVolo[numeroRiga].Prezzo );
            numeroRiga++;
            Struttura->NumeroVoli++;
        }
    }
    else{
        Struttura.NumeroAumenti = 0;
        while( !feof(File) ){
            fscanf(File, "%s %f", Struttura2.DatiAumenti[numeroRiga].CodiceVolo, Struttura2.DatiAumenti[numeroRiga].NuovoPrezzo);
            numeroRiga++;
            Struttura2.NumeroAumenti++;
        }
    }

return;//Operazione Riuscita
}

void confrontoDati(struct StrutturaVoli *Voli, struct StrutturaAumenti *Aumenti)
{
size_t indiceArrayAumenti;
size_t indiceArrayVoli;
char *codErrore = "Errore 666 Volo fantasma";


    indiceArrayAumenti = 0;
    while( indiceArrayAumenti < Aumenti.NumeroVoli ){
        indiceArrayVoli = 0;
        while( indiceArrayVoli < Voli.NumeroVoli ){
            if( 0 == strcmp( Voli.DatiVolo.CodiceVolo, Aumenti.DatiAumenti.CodiceVolo ) ){
                Voli.DatiVolo[indiceArrayVoli].Prezzo = Aumenti.DatiAumenti[indiceArrayAumenti].NuovoPrezzo
                indiceArrayVoli = Voli.NumeroVoli;
            }
            else if( -1 == strcmp( Aumenti.DatiAumenti.CodiceVolo, Voli.DatiVolo.CodiceVolo ){
                puts(codErrore);
            }
            indiceArrayVoli++
        }
    indiceArrayAumenti++
    }

return;
}

void stampaFileAggiornato(FILE *File, struct StrutturaVoli *Struttura)
{
size_t numeroRiga = 0;

    while( numeroRiga < Struttura.NumeroVoli ){
        fprintf(File, "%s %f %s %f %u %f", Struttura.DatiVolo[numeroRiga].CodiceVolo, Struttura.DatiVolo[numeroRiga].OrarioPartenza, Struttura.DatiVolo[numeroRiga].Destinazione, Struttura.DatiVolo[numeroRiga].OrarioArrivo, Struttura.DatiVolo[numeroRiga].PostiTotali, Struttura.DatiVolo[numeroRiga].Prezzo );
    numeroRiga++;
    }
return;
}
