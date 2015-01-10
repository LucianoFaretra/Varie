#include <stdlib.h>
#include <stdio.h>
#define COLONNE     100
#define RIGHE       102

float matrice[RIGHE][COLONNE];
float matrice2[RIGHE][COLONNE];
void NumeroRigheEColonneMatrice();
void CalcoloMatrice();
void InputMatrice();
void StampaDati();

int main()
{
NumeroRigheEColonneMatrice();
InputMatrice();
CalcoloMatrice();
StampaDati();

return 0;
}

void NumeroRigheEColonneMatrice()
{
int i = RIGHE - 1;
int j = COLONNE - 2;

printf("Programma di calcolo per la Somma di due Matrici\n\n");
printf("===========================================================================\n");
printf("Inserire il numero di Righe di cui sono composte le Matrici, fino ad un massimo di 100 Righe e premere INVIO: \n");
printf("===========================================================================\n");
while(matrice[i][j] < 1.000000)
     {
     printf("Per cortesia inserire almeno una Riga ");
     scanf("%f", &matrice[i][j]);
     }

 j = j + 1;

    printf("\n===========================================================================\n");
    printf("Inserire il numero di Colonne di cui sono composte le Matrici, fino ad un massimo di 100 Colonne e premere INVIO: \n");
    printf("===========================================================================\n");
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Colonna ");
        scanf("%f", &matrice[i][j]);
        }
return;
}

void InputMatrice()
{
int i = 0;
int j = 0;

printf("Adesso inserire i dati della Prima Matrice:\n");
while(i < matrice[RIGHE - 1][COLONNE - 2])
        {
            j = 0;
            while(j < matrice[RIGHE - 1][COLONNE - 1])
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
printf("\n===========================================================================\n");
i = 0;
j = 0;
printf("Adesso inserire i dati della Seconda Matrice:\n");
    while(i < matrice[RIGHE - 1][COLONNE - 2])
        {
            j = 0;
            while(j < matrice[RIGHE - 1][COLONNE - 1])
                {
                printf("Inserire il numero in posizione Riga: ");
                printf("%d", i + 1);
                printf(" e Colonna: ");
                printf("%d", j + 1);
                printf(" della Seconda Matrice e premere invio. ");
                scanf("%f", &matrice2[i][j]);
                j = j + 1;
                }
                i = i + 1;
        }
return;
}

void CalcoloMatrice()
{
int i = 0;
int j = 0;

while(i < matrice[RIGHE - 1][COLONNE - 2])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE - 1])
        {
            matrice[i][j] = matrice[i][j] + matrice2[i][j];
            j = j + 1;
        }
    i = i + 1;
    }
return;
}

void StampaDati()
{
int i = 0;
int j = 0;

printf("\n===========================================================================\n");
printf("La somma delle due Matrici e' :\n");
while(i < matrice[RIGHE - 1][COLONNE - 2])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE - 1])
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
