/*
  letturaFile(FILE *consumi)

  INPUT               DESCRIZIONE                                                       DOMINIO
  consumi             File di testo contenente i consumi di un modulo contratturale     Stringhe di caratteri alfanumerici

  OUTPUT                   DESCRIZIONE                                                       DOMINI
  DatiConsumi              Struttura dati contenente:
     numeroUnitaAbi           Numero di unita abitative                                         intero senza segno >=0
     consumoAnnualeModulo     Consumo annuale totale di N unità abitative                       reale >=0

  Legge il file di testo
  Se se è possibile aprire il file
     Carica su consumoAnnualeModulo il consumo totale del modulo contratuale
     Casica su numeroUnitaAbi il numero di unita abitative

  Se il file non e' null
     Allora
           Finche ci sono ancora righe nel file
                  Leggi riga e carica la variabile numeroUnitaAbi e consumoAnnualeModulo
                  Passa a riga succesiva
     Altrimenti
               Stampa messaggio d'errore

************************************************************************************************************************
 totaleUnitaAbitative(DatiConsumi)

 INPUT               DESCRIZIONE                                                       DOMINIO
 DatiConsumi         Struttura contenente i dati del file consumi
 	numeroUnitaAbi           Numero di unita abitative                                         intero senza segno >=0
    consumoAnnualeModulo     Consumo annuale totale di N unità abitative                       reale >=0
 fascia              Array conentente le 5 fasce di prezzo                             reale >=0.460468, <= 1.825007
 consumoMedio        Consumo medio per modulo contrattuale                             reale >= 0
 SERVFOGNA           Costo fognatura per metro cubo                                    reale 0.116788
 SERVDEPURAZIONE     Costo depurazione per metro cubo                                  reale 0.335273

 OUTPUT                   DESCRIZIONE                                                       DOMINI
 numeroUnitaAbi           Numero di unita abitative                                         intero senza segno >=0
 consumoAnnualeModulo     Consumo annuale totale di N unità abitative                       reale >=0
 importoTotaleUnita       Importo da pagare in totale per un'unita abi                      reale >=0

 Divide il consumo totale per unita abitative e calcola la media di consumo
 dopo di che secondo la tabella a fasce ne calcola l'importo totale
 somma le spese di fognatura e deputazione

 consumoMedio = consumoAnnualeModulo / numeroUnitaAbi

 Se consumoMedio e da 0 a 73
    Allora
           importoTotaleUnita = consumoMedio * fascia[0]
 Altrimenti Se consumoMedio e da 73.1 a 110
    Allora
          importoTotaleUnita = consumoMedio * fascia[1]
  Altrimenti Se consumoMedio e da  110.1 a 146
    Allora
          importoTotaleUnita = consumoMedio * fascia[2]
 Altrimenti Se consumoMedio e da 110.1 a 146
    Allora
          importoTotaleUnita = consumoMedio * fascia[3]
 Altrimenti Se consumoMedio e da 146.1 a 256
    Allora
          importoTotaleUnita = consumoMedio * fascia[4]
 Altrimenti Se consumoMedio e oltre 256
    Allora
          importoTotaleUnita = consumoMedio * fascia[5]

    Somma a importoTotaleUnita l'importo fisso MODULOCONTRATTUALE
    Somma a importoTotaleUnita l'importo fisso UNITAIMMOBILIARE * numeroUnitaAbi
    Somma a importoTotaleUnita le spese di fognatura
    Somma a importoTotaleUnita le spese di deputazione
    Stampa (importoTotaleUnita)

    Casi di test:
    numeroUnitaAbi = 2 casi di test
    consumoAnnualeModulo = 2 casi di test

    Totale 4 casi di test riducibili a 3

    Caso 1:
    numeroUnitaAbi = -1
    consumoAnnualeModulo 1000

    Output:
    Il consumo totale per un unita abitativa e pari a: 12.55
    I consumi totali del modulo abitativo composto da [NUMERORANDOM] unita con 1000 MC consumati sono: [NUMERORANDOM]

    Caso 2

    numeroUnitaAbi = 10
    consumoAnnualeModulo -1

    Output:
    Il consumo totale per un unita abitativa e pari a: 13.76
    I consumi totali del modulo abitativo composto da 10 unita con -1 MC consumati sono: 137.60

    Caso 3

    numeroUnitaAbi = 10
    consumoAnnualeModulo 1000

    Output:
    Il consumo totale per un unita abitativa e pari a: 119.44
    I consumi totali del modulo abitativo composto da 10 unita con 1000 MC consumati sono: 1194.36


 *********************************************************************************
 stampaTotaliUnita(float importoTotaleUnita, DatiInput DatiConsumi)
 INPUT               DESCRIZIONE                                                       DOMINIO
 DatiConsumi         Struttura contenente le informazioni sui consumi
 importoTotaleUnita       Importo da pagare in totale per un'unita abi                      reale >=0

 OUTPUT               DESCRIZIONE                                                       DOMINIO
 Stampa totali        DatiConsumi.numeroUnitaAbi * importoTotaleUnita                   reale >= 0

 Mostra a video il totale dei consumi

 Stampa: I consumi totali del modulo abitativo composto da DatiConsumi.numeroUnitaAbi unita con DatiConsumi.consumoAnnualeModulo MC consumati sono: importoTotaleUnita * DatiConsumi.numeroUnitaAbi


*/
#include <stdio.h>
#include <stdlib.h>
#define MODULOCONTRATTUALE 12.55
#define UNITAIMMOBILIARE 12.55
#define SERVFOGNA 0.116788
#define SERVDEPURAZIONE 0.335273

typedef struct{
        unsigned int numeroUnitaAbi;
        float consumoAnnualeModulo;
}DatiInput;

void stampaTotaliUnita(float importoTotaleUnita, DatiInput DatiConsumi);
DatiInput letturaFile(FILE* consumi);
float totaleUnitaAbitative(DatiInput DatiConsumi);


int main(void)
{
FILE *consumi;
DatiInput DatiConsumi;
float importoTotaleUnita;

     if((consumi = fopen("consumi.txt", "r")) == NULL){
         printf("Impossibile aprire il file consumi.txt in lettura");
     }
     else{
         DatiConsumi = letturaFile(consumi);
         importoTotaleUnita = totaleUnitaAbitative(DatiConsumi);
         stampaTotaliUnita(importoTotaleUnita, DatiConsumi);
     }
  system("PAUSE");
  return 0;
}

DatiInput letturaFile(FILE* consumi)
{
     DatiInput DatiConsumi; //Struttura contenente i dati letti da file
     if( consumi != NULL){
           while(!feof(consumi)){
               fscanf(consumi, "%u %f", &DatiConsumi.numeroUnitaAbi, &DatiConsumi.consumoAnnualeModulo);
           }
     }
     else{
          puts("Attenzione puntatore a file non valido");
     }

return DatiConsumi;
}

float totaleUnitaAbitative(DatiInput DatiConsumi)
{
 float fascia[5] = {0.460468, 0.604245, 0.994113, 1.487911, 1.825007};
 float consumoMedio;
 float importoTotaleUnita;

 consumoMedio = DatiConsumi.consumoAnnualeModulo / DatiConsumi.numeroUnitaAbi;

 if( consumoMedio >= 0 && consumoMedio <= 73 ){
     importoTotaleUnita = consumoMedio * fascia[0];
 }
 else if( consumoMedio >= 73.1 && consumoMedio <= 110){
      importoTotaleUnita = consumoMedio * fascia[1];
 }
 else if( consumoMedio >=  110.1 && consumoMedio <= 146){
          importoTotaleUnita = consumoMedio * fascia[2];
 }
 else if( consumoMedio >= 146.1 && consumoMedio <=  256){

          importoTotaleUnita = consumoMedio * fascia[3];
 }
 else if( consumoMedio > 256 ){

          importoTotaleUnita = consumoMedio * fascia[4];
}
 importoTotaleUnita += ( MODULOCONTRATTUALE / DatiConsumi.numeroUnitaAbi);
 importoTotaleUnita += UNITAIMMOBILIARE;
 importoTotaleUnita += (consumoMedio * SERVFOGNA);
 importoTotaleUnita += (consumoMedio * SERVDEPURAZIONE);

printf("Il consumo totale per un unita abitativa e pari a: %.2f\n", importoTotaleUnita );

return importoTotaleUnita;
}

void stampaTotaliUnita(float importoTotaleUnita, DatiInput DatiConsumi)
{
     printf("\nI consumi totali del modulo abitativo composto da %u unita con %.2f MC consumati sono: %.2f", DatiConsumi.numeroUnitaAbi, DatiConsumi.consumoAnnualeModulo, (importoTotaleUnita * DatiConsumi.numeroUnitaAbi));

return;
}
