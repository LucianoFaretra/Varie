#include <stdlib.h>
#include <stdio.h>
#define COLONNE     100
#define RIGHE       102

void NumeroRigheEColonneMatrice();
void InputMatrice();
void CalcoloMatrice();
void StampaDati();

float matrice[RIGHE][COLONNE];
float matrice2[RIGHE][COLONNE];
float matrice3[RIGHE][COLONNE];


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

printf("Programma di calcolo per Prodotto tra due Matrici\n\n");
printf("===========================================================================\n");
printf("Inserire il numero di Righe di cui e' composta la prima Matrice, fino ad un massimo di 100 Righe e premere INVIO: \n");
printf("===========================================================================\n");
    matrice[i][j] = 0;
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Riga ");
        scanf("%f", &matrice[i][j]);
        }

    j = j + 1;
    printf("\n===========================================================================\n");
    printf("Perfetto, adesso inserire il numero di Colonne di cui è composta la Matrice: ");
    printf("===========================================================================\n");
    matrice[i][j] = 0;
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Colonna ");
        scanf("%f", &matrice[i][j]);
        }

i = RIGHE - 1;
j = COLONNE - 2;
    printf("===========================================================================\n");
    printf("Adesso inserire il numero di Righe di cui è composta la Matrice da Moltiplicare: ");
    printf("===========================================================================\n");
    matrice2[i][j] = 0;
    while(matrice2[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Riga ");
        scanf("%f", &matrice2[i][j]);
        }

    j = j + 1;
    printf("===========================================================================\n");
    printf("Adesso inserire il numero di Colonne di cui è composta la Matrice da Moltiplicare: ");
    printf("===========================================================================\n");
    matrice2[i][j] = 0;
    while(matrice2[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Colonna ");
        scanf("%f", &matrice2[i][j]);
        }

if(matrice[RIGHE - 1][COLONNE - 1] != matrice2[RIGHE - 1][COLONNE - 2])
      {
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n==============================ATTENZIONE==================================\n");
       printf("Per moltiplicare 2 matrici, le righe della matrice moltiplicare devono essere pari alle colonne della matrice moltiplicante, premere un tasto per tornare alla schermata di selezione");
       printf("\n==============================ATTENZIONE==================================\n\n\n\n\n\n");
       getchar();
       main();
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
while(i < matrice2[RIGHE - 1][COLONNE - 2])
    {
        j = 0;
        while(j < matrice2[RIGHE - 1][COLONNE - 1])
        {
            printf("Inserire il numero in posizione Riga: ");
            printf("%d", i + 1);
            printf(" e Colonna: ");
            printf("%d", j + 1);
            printf(" e premere invio. ");
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
int c = 0;
float risulta[RIGHE] = {0};

while(i < matrice[RIGHE - 1][COLONNE - 2])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE - 1])
        {
            c = 0;
            while(c < matrice[RIGHE - 1][COLONNE - 1])
            {
            risulta[c] = matrice[i][c] * matrice2[c][j];
            matrice3[i][j] = matrice3[i][j] + risulta[c];
            c = c + 1;
            }
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
printf("Il prodotto delle due matrici e' :\n");
while(i < matrice[RIGHE - 1][COLONNE - 2])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE - 1])
        {
            printf("%.2f\t", matrice3[i][j]);
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
