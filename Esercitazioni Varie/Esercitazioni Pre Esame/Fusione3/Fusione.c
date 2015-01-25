/*   Prova Test Laboratorio Faretra Luciano 25/01/2015 - Fusione FIle

    INPUT				DESCRIZIONE																							DOMINIO
    VoliPtr				Puntatore a File di testo contenente i dati di volo													Stringhe di caratteri
    CodiceVolo			Codice identificativo volo univoco contenuto nel file Voli.txt										Stringa di caratteri
    OrarioPartenza		Oratio di partenza del volo contenuto nel file Voli.txt												Reale >=0, <=24
	Destinazione		Destinazione del volo contenuto nel file Voli.txt													Sringa di caratteri
	OrarioArrivo		Orario arrivo del volo contenuto nel file Voli.txt													Reale >=0, <=24
	PostiTotali			Posti totali presenti nell'aereo																	unsigned int > 0
	Prezzo				Prezzo del volo contenuto nel file Voli.txt															Reale doppia precisione >= 0
	AumentiPtr			Puntatore a File di testo contenente i codici di volo ed il prezzo dei voli che hanno sub.aumento	Stringhe di caratteri
	CodiceVolo			Codice Volo delle tratte che hanno subito un aumento												stringa di caratteri
	NuovoPrezzo			Nuovo prezzo del volo riferito al codice volo presente nel file Aumenti.txt							Reale doppia precisione >= 0
	
	OUTPUT				DESCRIZIONE																							DOMINIO
	VoliAggiornatiPtr	Puntatore a File di testo contenente i dati di volo	aggiornati										Stringhe di caratteri
	CodiceVolo			Codice identificativo volo univoco																	Stringa di caratteri
    OrarioPartenza		Oratio di partenza del volo																			Reale >=0, <=24
	Destinazione		Destinazione del volo																				Sringa di caratteri
	OrarioArrivo		Orario arrivo del volo																				Reale >=0, <=24
	PostiTotali			Posti totali presenti nell'aereo																	unsigned int > 0
	NuovoPrezzo			Nuovo prezzo del volo riferito al codice volo presente nel file Aumenti.txt							Reale doppia precisione >= 0
	DatiVolo			Struttura contenente tutte le informazioni di volo													Struttura dati
	AumentiVoli			Struttura contentenente i dati d'aumento															Struttura dati

	DATI DI LAVORO		DESCRIZIONE																							DOMINIO
	numeroVoli			Numero voli analizzati																				intero senza segno
	numeroAumenti		Numero aumenti analizzati																			intero senza segno
	indiceAumenti		Indice utilizzato epr controlalre gli aumenti														intero senza sengno
	indiceVoli			Indice utilizzato per controllare i voli															intero senza segno
	
	Affinamento:
	
	Il programma riceve due file in Input.
	Apre il file Voli.txt e lo carica in memoria
	Apre il file Aumenti.txt e lo carica in memoria
	Aggiorna i voli con il nuovo prezzo presente in Aumenti.txt
	Salva sul file VoliAggiornati.txt le informazuoni aggiornate
	
	Ulteriore Affinamento:
	
	Se è possibile aprire il file Voli.txt in lettura
		Allora
			Se è possibile aprire il file Aumenti.txt in Lettura
				Allora
					Mentre la riga del file Voli.txt è diversa dalla fine del file
						Leggi riga Voli.txt e salvala nella struttura DatiVolo
						incrementa numeroVoli di 1
						Passa a riga successiva
					Fine Mentre
					
					Mentre la riga del file Aumenti.txt è diversa dalla fine del file
						Leggi riga AUmenti.txt e salvala nella struttura AumentiVoli
						incrementa indiceAumenti di 1
						Passa a riga successiva
					Fine Mentre
				Altrimenti
					Stampa: "Impossibile aprire il file Aumenti.txt in lettura"
			Fine Se
		Altrimenti
			Stampa: "Impossibile aprire il file Voli.txt in lettura"
	Fine Se
	
	
					
					
	Azzera indiceAumenti
	finchè indiceAumenti <= numeroAumenti
		Azzera indiceVoli
		finchè indiceVoli <= numeroVoli
			Se aumenti.CodiceVolo e' uguale a  CodiceVolo
				Allora
					Sostituisci Prezzo con NuovoPrezzo
					indiceVoli = numeroVoli
				Altrimenti
					Se aumenti.CodiceVolo < CodiceVolo 
						Allora
							Stampa: Codice d'errore
					Fine Se
			Fine Se
		Passa a Volo successivo
		Fine Se
	Passa ad Aumento successivo
	Fine Se
	
	
	
	Se è possibile aprire il file VoliAggiornati.txt in scrittura
		Allora
			Mentre ci sono ancora Voli
				Salva il Volo nel file VoliAggiornati.txt
				Passa a Volo successivo
			Fine Mentre
		Altrimenti
			Stampa: Non e' stato possibile creare il file VoliAggiornati.txt
	Fine Se
	
	
	
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DatiGlobali.h"

typedef struct{
	char CodiceVolo[5];
	float OrarioPartenza;
	char Destinazione[21];
	float OrarioArrivo;
	unsigned int PostiTotali;
	double Prezzo;
}stutturaDatiVolo;

typedef struct{
	char CodiceVolo[5];
	double NuovoPrezzo;
}stutturaAumentiVoli;


void fusione( void ) 
{
FILE *VoliPtr;
FILE *AumentiPtr;
FILE *VoliAggiornatiPtr;

unsigned int numeroVoli = 0;
unsigned int numeroAumenti = 0;
size_t indiceAumenti;
size_t indiceVoli;
	
stutturaDatiVolo DatiVolo[NUMEROVOLIMASSIMO];
stutturaAumentiVoli AumentiVoli[NUMEROVOLIMASSIMO];
	
	if((VoliPtr = fopen(VOLI, "r")) == NULL ){
		puts("Impossibile aprire il file Voli.txt in lettura");
	}
	else{
		if((AumentiPtr = fopen(AUMENTI, "r")) == NULL ){
			puts("Impossibile aprire il file Aumenti.txt in lettura");
		}
		else{
			indiceVoli = 0;
			while(!feof(VoliPtr)){
				fscanf(VoliPtr, "%s %f %s %f %u %lf", DatiVolo[indiceVoli].CodiceVolo, &DatiVolo[indiceVoli].OrarioPartenza, DatiVolo[indiceVoli].Destinazione, &DatiVolo[indiceVoli].OrarioArrivo, &DatiVolo[indiceVoli].PostiTotali, &DatiVolo[indiceVoli].Prezzo );
				
				indiceVoli++;
				numeroVoli++;
			}
			indiceAumenti = 0;
			while(!feof(AumentiPtr)){
				fscanf(AumentiPtr, "%s %lf", AumentiVoli[indiceAumenti].CodiceVolo, &AumentiVoli[indiceAumenti].NuovoPrezzo );
				
				indiceAumenti++;
				numeroAumenti++;
			}
		}
				
	}
	fclose(VoliPtr);
	fclose(AumentiPtr);

				
	indiceAumenti = 0;
	while( indiceAumenti < numeroAumenti ){
		indiceVoli = 0;
		while( indiceVoli < numeroVoli ){
			if( strcmp(AumentiVoli[indiceAumenti].CodiceVolo, DatiVolo[indiceVoli].CodiceVolo) == 0 ){
				DatiVolo[indiceVoli].Prezzo = AumentiVoli[indiceAumenti].NuovoPrezzo;
				indiceVoli = numeroVoli;
			}
			else{
				if( strcmp(AumentiVoli[indiceAumenti].CodiceVolo, DatiVolo[indiceVoli].CodiceVolo ) < 0 )
					puts("COD10: Tentativo di aumentare prezzo volo inesistente");
			}

		indiceVoli++;
		}
	indiceAumenti++;
	}
	
	
	
	if((VoliAggiornatiPtr = fopen(AGGIORNATI, "w")) == NULL){
		puts("Non e' stato possibile creare il file dei Voli Aggiornati");
	} 
	else{
		indiceVoli = 0;
		while( indiceVoli < numeroVoli ){
			fprintf(VoliAggiornatiPtr, "%s %.2f %s %.2f %u %.2lf\n", DatiVolo[indiceVoli].CodiceVolo, DatiVolo[indiceVoli].OrarioPartenza, DatiVolo[indiceVoli].Destinazione, DatiVolo[indiceVoli].OrarioArrivo, DatiVolo[indiceVoli].PostiTotali, DatiVolo[indiceVoli].Prezzo );
		indiceVoli++;
		}
	}
	fclose(VoliAggiornatiPtr);
return;
}


