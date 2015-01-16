/*                 Sviluppato da Luciano Faretra 16/01/2015 rilasciato sotto licenza GNUv3
                                        Stringhe palindrome

    Affinamento Top Down
    Funzione Main

    INPUT                           DESCRIZIONE                                                     DOMINIO
    parolePtr                       File parole.tx contenente le parole da controllare              stringhe di caratteri
    parola                          Parola letta dal file da esaminare                              stringa di caratteri

    OUTPUT                          DESCRIZIONE                                                     DOMIONIO
    eUnaPalindroma                  Messaggio che conferma il trattarsi di una parola palindroma    stringa di caratteri
    nonEunaPalindroma               Messaggio che conferma il trattarsi di una parola non palindroma stringa di caratteri
    numeroLettere                   Numero di lettere che contine la parola                         unsigned int

    DATI DI LAVORO                  DESCRIZIONE                                                     DOMINIO
    indiceArray                     Indice utilizzato per scorrere l'array di caratteri             unsigned int

    1. Il programma riceve un file in iingresso il quale contiene delle parole da analizzare e capire se sono palindrome

    1.1 Il programma controlla se il file non e' presente
            Allora
                Stampa un messaggio d'errore
            Altrimenti
                Apre il file
                Legge la prima riga
                Definisci la grandezza della parola
                Se la parola ha faratteri dispari allora
                    Allora
                        La lettera centrale e' la prima lettera
                        fin quando sono state controllate tutte le lettere
                            Se lettera centrale + 1 e lettera centrale -1 sono uguali
                                Allora
                                    Controlla lettera successiva
                                Altrimenti
                                    Stampa nonEunaPalindroma
                            Fine Se
                    Altrimenti
                        se le due lettere centrali sono uguali
                            Allora
                                fin quando sono state controllate tutte le lettere
                                    Se lettera centrale + 1 e lettera centrale -1 sono uguali
                                        Allora
                                            Controlla lettera successiva
                                        Altrimenti
                                            Stampa nonEunaPalindroma
                                    Fine Se
                            Altrimenti
                                Stampa nonEunaPalindroma
                Fine Se

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define GRANDEZZAMASSIMAPAROLA 20

int main(void)
{

FILE *parolePtr;

    char parola[GRANDEZZAMASSIMAPAROLA];
    char *eUnaPalindroma = " e' palindroma!";
    char *nonEunaPalindroma = " non e' palindroma!";
    char *fileNonEsistente = "Attenzione si e' tentato di aprire un file non esistente";
    unsigned int numeroLettere;
    unsigned int indiceLettere;
    unsigned int valoreSentinella = 0;
    size_t indiceArray;


    if((parolePtr = fopen("parole.txt", "r")) == NULL ){
            puts(fileNonEsistente);
    }
    else{
        while(!feof(parolePtr)){
            valoreSentinella = 0;
            fscanf(parolePtr, "%s", parola);
            indiceArray = 0;
            numeroLettere = strlen(parola);
                if( ( numeroLettere % 2 ) != 0 ){
                    indiceArray = floor(numeroLettere / 2);
                    indiceLettere = 1;
                    while( ( indiceArray + indiceLettere != numeroLettere ) && valoreSentinella != 1 ){
                        if( parola[indiceArray + indiceLettere] != parola[indiceArray - indiceLettere] ){
                            printf("%s%s\n", parola, nonEunaPalindroma);
                            valoreSentinella = 1;
                        }
                    indiceLettere++;
                    }
                    if(valoreSentinella == 0){
                       printf("%s%s\n", parola, eUnaPalindroma);
                    }
                }
                else{
                    indiceArray = 0;
                    indiceLettere = numeroLettere;
                    while( ( indiceArray != numeroLettere ) && valoreSentinella != 1 ){
                        if( parola[indiceArray] != parola[indiceLettere - 1] ){
                            printf("%s%s\n", parola, nonEunaPalindroma);
                            valoreSentinella = 1;
                        }
                    indiceArray++;
                    indiceLettere--;
                    }
                    if(valoreSentinella == 0){
                       printf("%s%s\n", parola, eUnaPalindroma);
                    }
                }
        }
    }
return 0;
}
