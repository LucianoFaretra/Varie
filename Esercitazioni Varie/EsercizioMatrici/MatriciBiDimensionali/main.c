
#include <stdlib.h>
#include <stdio.h>

#include "DatiGlobali.h"
#include "InputOutput.h"
#include "Operazioni.h"

int main()
{

float matrice[DIM][DIM] = {{0}};
float matrice2[DIM][DIM] = {{0}};
float matrice3[DIM][DIM] = {{0}};

int Decisione = -1;

while(Decisione < 0 || Decisione > 4)
    {
    printf("Selezionare il tipo di operazione da effettuare, digitando il numero corrispondente e premendo INVIO \n \n");
    printf("1. Matrice Scalare, moltiplica una Matrice per un valore dato. \n");
    printf("2. Matrice Trasposta, inverte la posizione delle righe con quelle delle colonne \n");
    printf("3. Somma di Matrici, somma due Matrici \n");
    printf("4. Prodotto di Matrici, restituisce il prodotto tra due Matrici \n");
    printf("0. Esci \n \n");
    printf("Qualsiasi altro valore non verrà accettato\n");
    printf("Effettua la tua scelta: ");

    scanf("%d", &Decisione);
    }

if(Decisione == 1)
        {
        printf("Hai scelto di calcolare una Matrice Scalare, premi INVIO per continuare \n");
        getchar();
        getchar();

        ProdottoScalare(matrice, matrice3);
        StampaMatriceRisulta(matrice3);
        }

else if(Decisione == 2)
        {
        printf("Hai scelto di calcolare una Matrice Trasposta, premi INVIO per continuare \n");
        getchar();
        getchar();
        MatriceTrasposta(matrice, matrice3);
        StampaMatriceRisulta(matrice3);
        }

else if(Decisione == 3)
        {
        printf("Hai scelto di calcolare una Somma tra due Matrici, premi INVIO per continuare \n");
        getchar();
        getchar();
        MatriceSomma(matrice, matrice2, matrice3);
        StampaMatriceRisulta(matrice3);
        }

else if(Decisione == 4)
        {
        printf("Hai scelto di calcolare un Prodotto tra due Matrici, premi INVIO per continuare \n");
        getchar();
        getchar();
        MatriceMoltiplicazione(matrice, matrice2, matrice3);
        StampaMatriceRisulta(matrice3);
        }

printf("\n\nGrazie per aver scelto il Nostro Programma, premi invio per uscire. \n\n\n Developed by Transistori");
getchar();
getchar();

return 0;
}
