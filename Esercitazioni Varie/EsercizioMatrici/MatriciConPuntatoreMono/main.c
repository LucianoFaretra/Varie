#include <stdlib.h>
#include <stdio.h>
#include "DatiGlobali.h"
#include "InputOutput.h"
#include "Operazioni.h"

int main()
{

//(int *)malloc(sizeof(float));

/*Allocazione memoria matrici*/
float *matrice = NULL;
float *matrice2 = NULL;
float *matrice3 = NULL;

/*Fine Allocazione memoria matrici*/

int Decisione = -1;

while(Decisione < 0 || Decisione > 4)
    {
    printf("Selezionare il tipo di operazione da effettuare, digitando il numero corrispondente e premendo INVIO \n \n");
    printf("1. Matrice Scalare, moltiplica una Matrice per un valore dato. \n");
    printf("2. Matrice Trasposta, inverte la posizione delle righe con quelle delle colonne\n");
    printf("3. Somma di Matrici, somma due Matrici \n");
    printf("4. Prodotto di Matrici, restituisce il prodotto tra due Matrici \n");
    printf("0. Esci \n \n");
    printf("Qualsiasi altro valore non verra' accettato\n");
    printf("Effettua la tua scelta: ");

    scanf("%d", &Decisione);
    }

if(Decisione == 1)
        {
        printf("Hai scelto di calcolare una Matrice Scalare, premi INVIO per continuare \n");
        getchar();
        getchar();

        matrice = calloc(DIM*DIM, sizeof(float));
        matrice3 = calloc(DIM*DIM, sizeof(float));
        ProdottoScalare(matrice, matrice3);
        free(matrice);
        matrice = NULL;
        StampaMatriceRisulta(matrice3);
        free(matrice3);
        matrice3 = NULL;
        }

else if(Decisione == 2)
        {
        printf("Hai scelto di calcolare una Matrice Trasposta, premi INVIO per continuare \n");
        getchar();
        getchar();
        matrice = calloc(DIM*DIM, sizeof(float));
        matrice3 = calloc(DIM*DIM, sizeof(float));
        MatriceTrasposta(matrice, matrice3);
        free(matrice);
        matrice = NULL;
        StampaMatriceRisulta(matrice3);
        free(matrice3);
        matrice3 = NULL;
        }

else if(Decisione == 3)
        {
        printf("Hai scelto di calcolare una Somma tra due Matrici, premi INVIO per continuare \n");
        getchar();
        getchar();
        matrice = calloc(DIM*DIM, sizeof(float));
        matrice2 = calloc(DIM*DIM, sizeof(float));
        matrice3 = calloc(DIM*DIM, sizeof(float));
        MatriceSomma(matrice, matrice2, matrice3);
        free(matrice);
        matrice = NULL;
        free(matrice2);
        matrice2 = NULL;
        StampaMatriceRisulta(matrice3);
        free(matrice3);
        matrice3 = NULL;
        }

else if(Decisione == 4)
        {
        printf("Hai scelto di calcolare un Prodotto tra due Matrici, premi INVIO per continuare \n");
        getchar();
        getchar();
        matrice = calloc(DIM*DIM, sizeof(float));
        matrice2 = calloc(DIM*DIM, sizeof(float));
        matrice3 = calloc(DIM*DIM, sizeof(float));
        MatriceMoltiplicazione(matrice, matrice2, matrice3);
        free(matrice);
        matrice = NULL;
        free(matrice2);
        matrice2 = NULL;
        StampaMatriceRisulta(matrice3);
        free(matrice3);
        matrice3 = NULL;
        }

printf("\n\nGrazie per aver scelto il Nostro Programma, premi invio per uscire. \n\n\n Developed by Transistori");
getchar();
getchar();

return 0;
}
