#include <stdlib.h>
#include <stdio.h>
#define COLONNE     100
#define RIGHE       102

float matrice[RIGHE][COLONNE];
void NumeroRigheEColonneMatrice();
void InputMatrice();
void StampaDati();

int main()
{
NumeroRigheEColonneMatrice();
InputMatrice();
StampaDati();

return 0;
}

void NumeroRigheEColonneMatrice()
{
int i = RIGHE - 1;
int j = COLONNE - 2;

printf("Programma di calcolo per una Matrice Trasposta\n\n");
printf("===========================================================================\n");
printf("Inserire il numero di Righe di cui e' composta la Matrice, fino ad un massimo di 100 Righe e premere INVIO: \n");
printf("===========================================================================\n");
    matrice[i][j] = 0;
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Riga ");
        scanf("%f", &matrice[i][j]);
        }

    j = j + 1;
    printf("\n===========================================================================\n");
    printf("Perfetto, adesso inserire il numero di Colonne di cui e'' composta la Matrice: ");
    printf("===========================================================================\n");
    matrice[i][j] = 0;
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Colonna ");
        scanf("%f", &matrice[i][j]);
        }
}

void InputMatrice()
{
int i = 0;
int j = 0;

printf("Adesso inserire i dati della Matrice:\n");
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
return;
}

void StampaDati()
{
int i = 0;
int j = 0;

printf("\n===========================================================================\n");
printf("Ecco la tua matrice trasposta\n");
j = 0;
while(j < matrice[RIGHE - 1][COLONNE - 1])
    {
        i = 0;
        while(i < matrice[RIGHE - 1][COLONNE - 2])
                {
                printf("%.2f\t", matrice[i][j]);
                i = i + 1;
                }
        j = j + 1;
        printf("\n");
      }
printf("\n===========================================================================\n");
getchar();
getchar();
return;
}
