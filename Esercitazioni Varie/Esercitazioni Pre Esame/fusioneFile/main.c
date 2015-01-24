/*                 Sviluppato da Luciano Faretra 15/01/2015 rilasciato sotto licenza GNUv3
                                Esercitazione fusioneFile
    Affinamento Top Down
    Funzione Fusione

    INPUT                           DESCRIZIONE                                                         DOMINIO
    VoliPtr                         File di testo di nome VOli.txt contenente le informazioni del volo  Stringhe di caratteri
    CodiceVolo                      Codice univoco Volo contenuto in VoliPtr                            Stringhe Alfanumerica
    OrarioPartenza                  Orario di partenza dell'aereo, gli interi sono le ore, i decimali   float
                                    i minuti
    OrarioArrivo                    Orario di arrivo dell'aereo, gli interi sono le ore, i decimali     float
                                    i minuti
    Destinazione                    Città di destinazione dell'aereomobile                              stringa di caratteri
    PostiTotali                     Posti totali dell'aereomobile                                       intero senza segno > 0
    Prezzo                          Prezzo del miglietto                                                decimale a virgola mobile in doppia precisione

    AumentiPtr                      File di testo di nome Aumenti.txt contenente le informazioni del    Stringhe di caratteri
                                    volo
    CodiceVolo                      Codice di volo delle tratte che subiranno un aumento                Stringhe Alfanumeriche
    NuovoPrezzo                     Nuovo prezzo delle tratte contenute nel file Aumenti.txt            decimale a virgola mobile in doppia precisione


    OUTPUT                          DESCRIZIONE                                                         DOMIONIO
    VoliAggiornatiPtr               File di Testo VoliAggiornati.txt contenente i voli con i prezzi     stringhe di caratteri
                                    Aggiornati
    messaggioErrore                 Messaggio d'errore da mostrare nel caso in cui ci un aumento di     stringa di caratteri
                                    prezzo su un volo fantasma
    messaggioFileNonTrovato         Messaggio d'errore, file non trovato                                stringa di caratteri

    DATI DI LAVORO                  DESCRIZIONE                                                         DOMINIO


    1. Il modulo Fusione legge due file di testo, Voli.txt e Aumenti.txt, se un volo presente in Voli.txt è presente anche in Aumenti.txt, allora
        Salva il volo nel file VoliAggiornati.txt con il nuovo prezzo. Se un vlo è presente in Aumenti.txt e non in Voli.txt stampa un messaggio d'errore

    1.1 Se non e' presente il file Voli.txt
            Allora
                Stampa messaggioFileNonTrovato
            Altrimenti
                Mentre ci sono ancora righe
                    Carica i dati contenuti nel file nella struttura DatiDiVolo
                    Passa alla riga successiva
                Fine mentre
        Fine Se

        Se non e' presente il file Aumenti.txt
            Allora
                Stampa messaggioFileNonTrovato
            Altrimenti
                Mentre ci sono ancora righe
                    Carica i dati contenuti nel file nella struttura AumentoPrezzi
                    Passa alla riga successiva
                Fine mentre
        Fine Se

        mentre ci sono ancora voli da analizzare
            Controlla l'aumento 1 con il volo 1
                Se i codici di volo sono uguali
                    Allora
                        salva il volo con il prezzo aggiornato
                    Altrimenti
                        mostra messaggio d'errore
                Fine se
        Passa a volo successivo

    ***********************************************************************************************************************************************************

    Funzione Stampa
    INPUT                           DESCRIZIONE                                                         DOMINIO
    VoliPtr                         File di testo di nome VOli.txt contenente le informazioni del volo  Stringhe di caratteri
    VoliAggiornatiPtr               File di Testo VoliAggiornati.txt contenente i voli con i prezzi     stringhe di caratteri
                                    Aggiornati

    OUTPUT                          DESCRIZIONE                                                         DOMIONIO
    messaggioFileNonTrovato         Messaggio d'errore, file non trovato                                stringa di caratteri

    DATI DI LAVORO                  DESCRIZIONE                                                         DOMINIO

    Se non e' presente il file Voli.txt
        Allora
            Stampa messaggioFileNonTrovato
        Altrimenti
        Se non e' presente il file VoliAggiornati.txt
            Allora
                Stampa messaggioFileNonTrovato
            Altrimenti
                Mentre ci sono ancora righe
                    Stampa una riga del file Voli.txt
                    Stampa una riga del file VoliAggiornati.txt
                Fine mentre
            Fine Se
    Fine Se


*/
#include "globale.h"
#include "fusione.h"
#include "stampa.h"

int main( void )
{
    char *messaggioErrore = "Cod. Errore 666 - Volo non trovato. ";
    char *messaggioFileNonTrovato = "Cod. Errore 000 - File non trovato. ";

    fusione( messaggioErrore, messaggioFileNonTrovato );
    stampa( messaggioFileNonTrovato );

return 0;
}


