/* Faretra Luciano prova di laboratiorio 27 Gennaio

INPUT           DESCRIZIONE                                         DOMINIO
alfa            Puntatore a File ElencoTreni.txt                           stringhe di caratteri
MAXTRENI        Numero massimo di treni da leggere da file                intero senza segno
CodiceTreno     Codice univoco del treno contenuto in ElencoTreni.txt    stringa di caratteri
Partenza        Citta di partenza contenuto in ElencoTreni.txt           stringa di caratteri
OraPartenza     Orario partenza treno contenuto in ElencoTreni.txt       reale con due decimali
Arrivo          Città di arrivo del treno contenuto in ElencoTreni.txt   stringa di caratteri
OraArrivo       Orario di arrivo del trno  contenuto in ElencoTreni.txt  reale con due decimali
Prezzo          Prezzo del biglietto contenuto in ElencoTreni.txt        reale

Output          Descrizione                                          DOMINIO
treno1          Struttura dati contenente le informazioni sul treno  struttura di dati



Assegna a alfa l'indirizzo del file ElencoTreni.txt
        Se il puntatore è nullo
           Allora
                 Stampa messaggio d'errore
           Altrimenti
                     Leggi il file, Finchè ci sono ancora righe
                     Carica la riga nella struttra dati
                     Passa a riga successiva
        Fine Se


***********************************************************************************************************
Funzione Visualizza(FILE* alfa)
INPUT           DESCRIZIONE                                         DOMINIO
alfa            Puntatore a File ElencoTreni.txt                    stringhe di caratteri
buffer          Buffer di lettura                                   stringa di caratteri
MAXBUFFER       Dimensione massima del buffer                       intero senza segno >0

Output          Descrizione                                          DOMINIO
CodiceTreno     Codice univoco del treno contenuto in ElencoTreni.txt    stringa di caratteri
Partenza        Citta di partenza contenuto in ElencoTreni.txt           stringa di caratteri
OraPartenza     Orario partenza treno contenuto in ElencoTreni.txt       reale con due decimali
Arrivo          Città di arrivo del treno contenuto in ElencoTreni.txt   stringa di caratteri
OraArrivo       Orario di arrivo del trno  contenuto in ElencoTreni.txt  reale con due decimali
Prezzo          Prezzo del biglietto contenuto in ElencoTreni.txt        reale

Mostra il contenuto del file
       Se il puntatore alfa è nullo
          Allora
                Stampa messaggio d'errore
          Altrimenti
                Leggi la riga e caricala nel buffer
                    Stampa il contenuto del buffer
                      Se l'ultimo carattere del buffer non è un newline
                         Allora
                               Stampa un newline
                      Fine Se
       Fine Se


***********************************************************************************************************
Funzione mostraPartenze(FILE* alfa, char partenza[])
INPUT           DESCRIZIONE                                         DOMINIO
alfa            Puntatore a File ElencoTreni.txt                    stringhe di caratteri
partenza        Città di partenza da cercare                        stringa dic aratteri
numeroTreni     Numero dei treni presenti sul file                  intero senza segno


Output          Descrizione                                          DOMINIO
CodiceTreno     Codice univoco del treno contenuto in ElencoTreni.txt    stringa di caratteri
Partenza        Citta di partenza contenuto in ElencoTreni.txt           stringa di caratteri
OraPartenza     Orario partenza treno contenuto in ElencoTreni.txt       reale con due decimali
Arrivo          Città di arrivo del treno contenuto in ElencoTreni.txt   stringa di caratteri
OraArrivo       Orario di arrivo del trno  contenuto in ElencoTreni.txt  reale con due decimali
Prezzo          Prezzo del biglietto contenuto in ElencoTreni.txt        reale

DATIDILAVORO    DESCRIZIONE                                           DOMINIO
indiceArray     Indice array per scorrere tra i diversi treni         intero senza segno


Mostra i dati relativi ad una determinata partenza

        Se il puntatore alfa è nullo
           Allora
                 Stampa messaggio d'errore
           Altrimenti
                     Leggi il file, Finchè ci sono ancora righe
                     Carica la riga nella struttra dati
                     incrementa numeroTreni di uno
                     Passa a riga successiva
        Fine Se

        Mentre indiceArray < numeroTreni
               Se treni1[indiceArray].Partenza = partenza
                      Allora
                        Visualizza treno
                Fine Se
            incrementa indiceArray di uno
        Fine Mentre

 ***********************************************************************************************************
Funzione mostraPrezzo(FILE* alfa, float minimo, float massimo)

INPUT           DESCRIZIONE                                         DOMINIO
alfa            Puntatore a File ElencoTreni.txt                    stringhe di caratteri
minimo          intervallo di prezzo minimo                         reale
massimo         intervallo di prezzo massimo                        reale


Output          Descrizione                                          DOMINIO
CodiceTreno     Codice univoco del treno contenuto in ElencoTreni.txt    stringa di caratteri
Partenza        Citta di partenza contenuto in ElencoTreni.txt           stringa di caratteri
OraPartenza     Orario partenza treno contenuto in ElencoTreni.txt       reale con due decimali
Arrivo          Città di arrivo del treno contenuto in ElencoTreni.txt   stringa di caratteri
OraArrivo       Orario di arrivo del trno  contenuto in ElencoTreni.txt  reale con due decimali
Prezzo          Prezzo del biglietto contenuto in ElencoTreni.txt        reale

DATIDILAVORO    DESCRIZIONE                                           DOMINIO
indiceArray     Indice array per scorrere tra i diversi treni         intero senza segno



        Se il puntatore è nullo
           Allora
                 Stampa messaggio d'errore
           Altrimenti
                     Leggi il file, Finchè ci sono ancora righe
                     Carica la riga nella struttra dati
                     incrementa numeroTreni di uno
                     Passa a riga successiva
        Fine Se

        Mentre indiceArray < numeroTreni
               Se treni1[indiceArray].Prezzo >= minimo && treni[indiceArray].Prezzo <= massimo
                  Allora
                        Visualizza Treno
                Fine Se
                incrementa indiceArray di uno
        Fine Mentre


Funzione mostra(Treni treno1)

INPUT           DESCRIZIONE                                         DOMINIO
treno1          Struttura contenente i dati del treno               Struttura dati

Output          Descrizione                                         DOMINIO
CodiceTreno     Codice univoco del treno contenuto in treno1        stringa di caratteri
Partenza        Citta di partenza contenuto in treno1               stringa di caratteri
OraPartenza     Orario partenza treno contenuto in treno1           reale con due decimali
Arrivo          Città di arrivo del treno contenuto in treno1       stringa di caratteri
OraArrivo       Orario di arrivo del trno  contenuto in treno1      reale con due decimali
Prezzo          Prezzo del biglietto contenuto in treno1            reale
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBUFFER 80

typedef struct{
        char CodiceTreno[6];
        char Partenza[21];
        float OraPartenza;
        char Arrivo[21];
        float OraArrivo;
        float Prezzo;
        }Treni;


void mostraPartenze(FILE* alfa, char partenza[]);
void visualizza(FILE* alfa);
void mostraPrezzo(FILE* alfa, float minimo, float massimo);
void mostra(Treni treno1);


int main(void)
{
FILE *alfa;
unsigned int scelta;
unsigned int esitoScanf;
char partenza[21];
float minimo;
float massimo;

      if((alfa = fopen("ElencoTreni.txt", "r")) == NULL ){
              puts("Attenzione non è stato possibile aprire il file ElencoTreni.txt");
     }
     else{
          puts("Selezionare la modalità di utilizzo");
          puts("0 - Visualizza tutti i treni nel file");
          puts("1 - Inserisci una partenza e mostra se ci sono treni che partono da li");
          puts("2 - Inserisci un range minimo e massimo e mostra i treni nel range");
          puts("3 - Esci");


          do{
             if((esitoScanf = scanf("%d", &scelta )) == 0 || scelta > 3 ){
               scanf("%*[^\n]");
               puts("Input non valido");
            }
          }while(esitoScanf == 0 );

          if(scelta == 0){
            visualizza(alfa);
          }
          else if(scelta == 1){
            printf("%s", "Inserire la partenza: ");
            scanf("%20s", partenza);
            mostraPartenze(alfa, partenza);
          }
          else if(scelta == 2){
                printf("Inserire il prezzo minimo :");
                scanf("%f", &minimo);
                printf("\nInserire il prezzo massimo :");
                scanf("%f", &massimo);
                mostraPrezzo(alfa, minimo, massimo);
          }
          else{
          }
    }
fclose(alfa);
  system("PAUSE");
  return 0;
}

void visualizza(FILE* alfa)
{
char buffer[MAXBUFFER]; /*buffer di lettura da file*/

     if(alfa == NULL ){
              puts("Funzione visualizza puntatore nullo");
     }
     else{
          while(!feof(alfa)){
                fgets(buffer, (MAXBUFFER - 1), alfa);
                puts(buffer);
                if(buffer[(strlen(buffer))-1] != '\n'){
                printf("%s", "\n");
                }
          }

     }
return;
}

void mostraPartenze(FILE* alfa, char partenza[])
{
Treni treno = {"", "", 0.00, "", 0.00, 0.00};

     if(alfa == NULL){
             puts("Puntatore alfa nella funzione mostraPartenze nullo");
     }
     else{
           while(!feof(alfa)){
                fscanf(alfa, "%5s %20s %f %20s %f %f", treno.CodiceTreno, treno.Partenza, &treno.OraPartenza, treno.Arrivo, &treno.OraArrivo, &treno.Prezzo);
                if( strcmp(treno.Partenza, partenza) == 0 ){
                    mostra(treno);
                }
           }
     }

return;
}

void mostraPrezzo(FILE* alfa, float minimo, float massimo)
{
Treni treno = {"", "", 0.00, "", 0.00, 0.00};

     if(alfa == NULL){
         puts("Puntatore alfa nella funzione mostraPartenze nullo");
     }
     else{
          while(!feof(alfa)){
            fscanf(alfa, "%5s %20s %f %20s %f %f", treno.CodiceTreno, treno.Partenza, &treno.OraPartenza, treno.Arrivo, &treno.OraArrivo, &treno.Prezzo);
            if( treno.Prezzo >= minimo && treno.Prezzo <= massimo ){
                mostra(treno);
            }
          }
    }
return;
}

void mostra(Treni treno1)
{
   printf("%5s %20s %.2f %20s %.2f %.2f\n", treno1.CodiceTreno, treno1.Partenza, treno1.OraPartenza, treno1.Arrivo, treno1.OraArrivo, treno1.Prezzo);
return;
}
