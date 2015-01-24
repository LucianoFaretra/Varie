#include <stdlib.h>
#include <stdio.h>
#define COLONNE     100
#define RIGHE       101

float matrice[RIGHE][COLONNE];
void calcolo(float scalare);
float input();
void output();

int main()
{

calcolo(input());
output();

return 0;
}

float input()
{
int i = RIGHE - 1;
int j = COLONNE - 1;
float scalare = 0;

printf("Si sta calcolando un prodotto per Scalare\n\n");
printf("===========================================================================\n");
printf("Inserire il numero di Righe di cui e' composta la Matrice, fino ad un massimo di 100 Righe e premere INVIO: \n");
printf("===========================================================================\n");
while(matrice[i][j] < 1.000000)
     {
     printf("Per cortesia inserire almeno una Riga ");
     scanf("%f", &matrice[i][j]);
     }

 j = j + 1;

    printf("\n===========================================================================\n");
    printf("Inserire il numero di Colonne di cui e' composta la Matrice fino ad un massimo di 100 Colonne e premere INVIO: \n");
    printf("===========================================================================\n");
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Colonna ");
        scanf("%f", &matrice[i][j]);
        }
i = 0;
printf("\nInserire il valore di Scalare e premere INVIO ");
scanf("%f", &scalare);
while(i < matrice[RIGHE - 1][COLONNE - 1])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE])
        {
            printf("Inserire il numero in posizione Riga: ");
            printf("%d", i + 1);
            printf(" e Colonna: ");
            printf("%d", j + 1);
            printf(" e premere invio. ");
            scanf("%f", &matrice[i][j]);
            j = j + 1;
        }
    i = i + 1;
    }
return scalare;
}

void calcolo(float scalare)
{
int i = 0;
int j = 0;


while(i < matrice[RIGHE - 1][COLONNE - 1])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE])
        {
            matrice[i][j] = matrice[i][j] * scalare;
            j = j + 1;
        }
    i = i + 1;
    }
return;
}

void output()
{
int i = 0;
int j = 0;

printf("\n===========================================================================\n");
printf("Il prodotto della Matrice per lo Scalare e' \n");
while(i < matrice[RIGHE - 1][COLONNE - 1])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE])
        {
            printf("%.2f\t", matrice[i][j]);
            j = j + 1;
        }
    printf("\n");
    i = i + 1;
    }
printf("\n===========================================================================\n");
getchar();
getchar();
return;
}
