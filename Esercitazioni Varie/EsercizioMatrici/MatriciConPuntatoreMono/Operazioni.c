#include <stdlib.h>
#include <stdio.h>

//#include "DatiGlobali.h"
#include "Operazioni.h"
#include "InputOutput.h"
#include "AccessoAiDati.h"

void MatriceTrasposta(float *matrice, float *matrice3)
{
int n = 0;
int i = 0;
int j = 0;
float valore = 0;
int righe = 0;
int colonne = 0;

/* INIZIO BLOCCO DI INPUT*/
n = 1;//Prima Matrice
InserimentoNumeroRigheEColonne(matrice, n);

InserimentoElementiMatrice(matrice, n);

/* Inizio Aggiornamento indici matrice Output*/
valore = LetturaElemento(matrice, righe, colonne);
colonne++;
ScrivereElemento(matrice3, righe, colonne, valore);

valore = LetturaElemento(matrice, righe, colonne);
colonne=0;
ScrivereElemento(matrice3, righe, colonne, valore);
/* Fine Aggiornamento indici matrice Output*/
/* FINE BLOCCO DI INPUT*/

/* INIZIO BLOCCO DI CALCOLO*/
i = 0;
while(i < LetturaElemento(matrice, righe, colonne))
    {
        j = 0;
        while(j < LetturaElemento(matrice, righe, colonne+1))
        {
            valore = LetturaElemento(matrice, i, j+2);
            ScrivereElemento(matrice3, j, i+2, valore);
            j++;
        }
    i++;
    }
/* FINE BLOCCO DI CALCOLO*/
return;
}

void MatriceMoltiplicazione(float *matrice, float *matrice2, float *matrice3)
{

int n = 0;
int i = 0;
int j = 0;
int c = 0;
int righe = 0;
int colonne = 0;
float valore;
float risulta;

/* INIZIO BLOCCO DI INPUT*/
while(LetturaElemento(matrice, righe, colonne+1) != LetturaElemento(matrice2, righe, colonne) || LetturaElemento(matrice, righe, colonne) == 0.000000 || LetturaElemento(matrice2, righe, colonne) == 0.000000 || LetturaElemento(matrice, righe, colonne+1) == 0.000000 || LetturaElemento(matrice2, righe, colonne+1) == 0.000000)
      {
       printf("n\n\n\n==============================ATTENZIONE==================================\n");
       printf("Per moltiplicare 2 matrici, il numero di righe della seconda matrice devono essere uguali alle colonne della prima, prego reinserire i dati. ");
       printf("\n==============================ATTENZIONE==================================\n\n\n\n");
        n = 1;//Prima Matrice

        InserimentoNumeroRigheEColonne(matrice, n);

        n = 2;//Seconda Matrice

        InserimentoNumeroRigheEColonne(matrice2, n);
      }

n = 1;//Prima Matrice
InserimentoElementiMatrice(matrice, n);

n = 2;//Seconda Matrice
InserimentoElementiMatrice(matrice2, n);

CopiaIndici(matrice, matrice3);
/* FINE BLOCCO DI INPUT*/

/* INIZIO BLOCCO DI CALCOLO*/
i = 0;
while(i < LetturaElemento(matrice, righe, colonne))
    {
        j = 0;
        while(j < LetturaElemento(matrice, righe, colonne+1))
        {
            c = 0;
            while(c < LetturaElemento(matrice, righe, colonne+1))
            {
            risulta = LetturaElemento(matrice, i, c+2)*LetturaElemento(matrice2, c, j+2);
            valore = LetturaElemento(matrice3, i, j+2) + risulta;
            ScrivereElemento(matrice3, i, j+2, valore);
            c++;
            }
        j++;
        }
    i++;
    }
/* FINE BLOCCO DI CALCOLO*/
return;
}

void ProdottoScalare(float *matrice, float *matrice3)
{
int n = 0;
int i = 0;
int j = 0;
float valore = 0;
float scalare = InserimentoScalare();
int righe = 0;
int colonne = 0;

/* INIZIO BLOCCO DI INPUT*/
n = 1;//Prima Matrice

InserimentoNumeroRigheEColonne(matrice, n);

InserimentoElementiMatrice(matrice, n);

CopiaIndici(matrice, matrice3);
/* FINE BLOCCO DI INPUT*/

/* INIZIO BLOCCO DI CALCOLO*/
while(i < LetturaElemento(matrice, righe, colonne))
    {
        j = 0;
        while(j < LetturaElemento(matrice, righe, colonne+1))
        {
            valore = LetturaElemento(matrice, i, j+2) * scalare;
            ScrivereElemento(matrice3, i, j+2, valore);
            j++;
        }
    i++;
    }
return;
}

void MatriceSomma(float *matrice, float *matrice2, float *matrice3)
{

int n = 0;
int i = 0;
int j = 0;
float valore = 0;
int righe = 0;
int colonne = 0;

/* INIZIO BLOCCO DI INPUT*/
while(LetturaElemento(matrice, righe, colonne) != LetturaElemento(matrice2, righe, colonne) || LetturaElemento(matrice, righe, colonne+1) != LetturaElemento(matrice2, righe, colonne+1) || LetturaElemento(matrice, righe, colonne) == 0.000000 || LetturaElemento(matrice, righe, colonne+1) == 0.000000 || LetturaElemento(matrice2, righe, colonne) == 0.000000 || LetturaElemento(matrice2, righe, colonne) == 0.000000)
        {
       printf("\n\n\n\n==============================ATTENZIONE==================================\n");
       printf("Per sommare 2 matrici, il numero di righe e colonne di entrambe le Matrici devono essere di ugual numero, prego reinserire i dati. ");
       printf("\n==============================ATTENZIONE==================================\n\n\n\n");

       n = 1;//Prima Matrice
       InserimentoNumeroRigheEColonne(matrice, n);

       n = 2;//Seconda Matrice
       InserimentoNumeroRigheEColonne(matrice2, n);
      }

n = 1;//Prima Matrice
InserimentoElementiMatrice(matrice, n);

n = 2;//Seconda Matrice
InserimentoElementiMatrice(matrice2, n);

CopiaIndici(matrice, matrice3);
/* FINE BLOCCO DI INPUT*/

/* INIZIO BLOCCO DI CALCOLO*/
while(i < LetturaElemento(matrice, righe, colonne))
    {
        j = 0;
        while(j < LetturaElemento(matrice, righe, colonne+1))
        {
            valore = LetturaElemento(matrice, i, j+2) + LetturaElemento(matrice2, i, j+2);
            ScrivereElemento(matrice3, i, j+2, valore);
            j++;
        }
    i++;
    }
/* FINE BLOCCO DI CALCOLO*/
return;
}
