#include <stdlib.h>
#include <stdio.h>

#include "InputOutput.h"
#include "AccessoAiDati.h"

void InserimentoNumeroRigheEColonne(float matrice[][DIM], int n)
{
float valore = 0;
int righe = 0;
int colonne = 0;

ScrivereElemento(matrice, righe, colonne, valore); //Reset Numero Righe
ScrivereElemento(matrice, righe, colonne+1, valore); //Reset Numero Colonne

printf("\n===========================================================================\n");
printf("\n\t\tInserire le Righe e le Colonne della Matrice numero: %d \n", n);
printf("\tNotaBene: una matrice non puo' essere composta 1 riga ed 1 colonna\n");
printf("\n===========================================================================\n");

while (LetturaElemento(matrice, righe, colonne) <= 1.000000 && LetturaElemento(matrice, righe, colonne+1) <= 1.000000)
    {
    printf("Per Cortesia inserire almeno una Riga ");
    scanf("%f", &valore);
    ScrivereElemento(matrice, righe, colonne, valore);

    printf("Per Cortesia inserire almeno una Colonna ");
    scanf("%f", &valore);
    ScrivereElemento(matrice, righe, colonne+1, valore);
    }
return;
}

void InserimentoElementiMatrice(float matrice[][DIM], int n)
{
int i = 0;
int j = 0;
float valore = 0;
int righe = 0;
int colonne = 0;

printf("\n\n\n\n********************************************************************************\n");
printf("\n\tProcedere all'inserimento degli Elementi della Matrice numero %d \n", n);
printf("\n********************************************************************************\n\n\n\n");

i = 0;
while(i < LetturaElemento(matrice, righe, colonne))
    {
    j = 0;
    while(j < LetturaElemento(matrice, righe, colonne+1))
        {
        printf("Inserire il numero in posizione Riga: ");
        printf("%d", i + 1);
        printf(" e Colonna: ");
        printf("%d", j + 1);
        printf(" e premere invio. ");
        scanf("%f", &valore);
        ScrivereElemento(matrice, i, j+2, valore);
        j++;
        }
    i++;
    }
return;
}

float InserimentoScalare(void)
{
float scalare = 0;

printf("\nInserire il valore Scalare e premere INVIO ");
scanf("%f", &scalare);
return scalare;
}

void StampaMatriceRisulta(float matrice[][DIM])
{
int i = 0;
int j = 0;
int righe = 0;
int colonne = 0;

printf("\n===========================================================================\n");
printf("La matrice di risulta e' :\n");
i = 0;
while(i < LetturaElemento(matrice, righe, colonne))
    {
    j = 0;
    while(j < LetturaElemento(matrice, righe, colonne+1))
        {
        printf("%.2f\t", LetturaElemento(matrice, i, j+2));
        j++;
        }
    printf("\n");
    i++;
    }
printf("\n===========================================================================\n");
getchar();
getchar();
return;
}

void CopiaIndici(float matrice[][DIM], float matrice3[][DIM])
{
int righe = 0;
int colonne = 0;
float valore = 0;

valore = LetturaElemento(matrice, righe, colonne);
ScrivereElemento(matrice3, righe, colonne, valore);

colonne++;

valore = LetturaElemento(matrice, righe, colonne);
ScrivereElemento(matrice3, righe, colonne, valore);

return;
}
