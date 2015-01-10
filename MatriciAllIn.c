#include <stdlib.h>
#include <stdio.h>
#define RIGHE 102
#define COLONNE 100

float matrice[RIGHE][COLONNE] = {0, 0};
float matrice2[RIGHE][COLONNE] = {0, 0};
float MatriceRisulta[RIGHE][COLONNE];
int OperatoreMatrice = 0;

/*Menù Opzioni & Scelta utente*/
void SceltaMatrice(); //Menù di scelta della matrice con output decisoniale

/*Input Dati*/
void InserimentoMatrice();
void NumeroRigheEColonneMatrice();
//void ControlloRigheColonne();

/*Tipo matrici*/
void MatriceScalare();
void MatriceTrasposta();
void MatriceSomma();
void MatriceProdotto();

/*Output*/
void StampaDati();

int main()
{
SceltaMatrice();
return 0;
}

void SceltaMatrice()
{
int Decisione = 0;
int OperatoreMatrice = 0;

printf("Selezionare il tipo di operazione da effettuare, digitando il numero corrispondente e premendo INVIO \n \n");
printf("1. Matrice Scalare, moltiplica una Matrice per un valore dato. \n");
printf("2. Matrice Trasposta, inverte la posizione delle righe con quelle delle colonne \n");
printf("3. Somma di Matrici, somma due Matrici \n");
printf("4. Prodotto di Matrici, restituisce il prodotto tra due Matrici \n");
printf("5. Esci \n \n");
printf("Effettua la tua scelta: ");

scanf("%d", &Decisione);

if(Decisione == 0)
    {
    printf("Hai scelto di uscire dal programma, premi invio per chiudere \n");
    getchar();
    }
else if(Decisione == 1)
        {
        printf("Hai scelto di calcolare una Matrice Scalare, se è corretto, inserisci 1 e premi INVIO, altrimenti inserisci 0 e premi INVIO per tornare al menù precedente \n");
        OperatoreMatrice = 1;
        printf("Scelta effettuata: ");
        scanf("%d", &Decisione);
            if(Decisione == 0)
                {
                SceltaMatrice();
                }
            else
                {
                NumeroRigheEColonneMatrice();
                InserimentoMatrice();
                MatriceScalare();
                StampaDati();
                }
        }
else if(Decisione == 2)
        {
        printf("Hai scelto di calcolare una Matrice Trasposta, se è corretto, inserisci 1 e premi INVIO, altrimenti inserisci 0 e premi INVIO per tornare al menù precedente \n");
        OperatoreMatrice = 1;
        printf("Scelta effettuata: ");
        scanf("%d", &Decisione);
            if(Decisione == 0)
                {
                SceltaMatrice();
                }
            else
                {
                NumeroRigheEColonneMatrice();
                InserimentoMatrice();
                MatriceTrasposta();
                }
        }

else if(Decisione == 3)
        {
        printf("Hai scelto di calcolare una Somma tra due Matrici, se è corretto, inserisci 1 e premi INVIO, altrimenti inserisci 0 e premi INVIO per tornare al menù precedente \n");
        OperatoreMatrice = 3;
        printf("Scelta effettuata: ");
        scanf("%d", &Decisione);
            if(Decisione == 0)
                {
                SceltaMatrice();
                }
            else
                {
                NumeroRigheEColonneMatrice();
                InserimentoMatrice();
                MatriceSomma();
                StampaDati();
                }
        }

else if(Decisione == 4)
        {
        printf("Hai scelto di calcolare un Prodotto tra due Matrici, se è corretto, inserisci 1 e premi INVIO, altrimenti inserisci 0 e premi INVIO per tornare al menù precedente \n");
        OperatoreMatrice = 2;
        printf("Scelta effettuata: ");
        scanf("%d", &Decisione);
            if(Decisione == 0)
                {
                SceltaMatrice();
                }
            else
                {
                NumeroRigheEColonneMatrice();
                if(matrice[RIGHE - 1][COLONNE] != matrice2[RIGHE - 1][COLONNE - 1])
                    {
                        printf("Per Moltiprlicare 2 matrici, le righe della matrice moltiplicare devono essere pari alle colonne della matrice moltiplicante, premere un tasto per tornare alla schermata di selezione");
                        getchar();
                        SceltaMatrice();
                    }
                InserimentoMatrice();
                MatriceProdotto();
                StampaDati();
                }
        }

else if(Decisione < 0 || Decisione > 4)
    {
    printf("Valore inserito errato, premete invio per tornare alla schermata principale. ");
    getchar();
    SceltaMatrice();
    }
return;
}

void NumeroRigheEColonneMatrice()
{
int i = RIGHE - 1;
int j = COLONNE - 1;

if(OperatoreMatrice == 1)
    {
    printf("Perfetto, adesso inserire il numero di Righe di cui è composta la Matrice: ");
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Riga ");
        scanf("%f", &matrice[i][j]);
        }

    j = j + 1;

    printf("Perfetto, adesso inserire il numero di Colonne di cui è composta la Matrice: ");
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Colonna ");
        scanf("%f", &matrice[i][j]);
        }
    }
else if(OperatoreMatrice == 2)
    {
    printf("Perfetto, adesso inserire il numero di Righe di cui è composta la Matrice: ");
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Riga ");
        scanf("%f", &matrice[i][j]);
        }

    j = j + 1;

    printf("Perfetto, adesso inserire il numero di Colonne di cui è composta la Matrice: ");
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Colonna ");
        scanf("%f", &matrice[i][j]);
        }

i = RIGHE - 1;
j = COLONNE - 1;
    printf("Perfetto, adesso inserire il numero di Righe di cui è composta la Matrice da Sommare: ");
    while(matrice2[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Riga ");
        scanf("%f", &matrice2[i][j]);
        }

    j = j + 1;

    printf("Perfetto, adesso inserire il numero di Colonne di cui è composta la Matrice da Sommare: ");
    while(matrice2[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Colonna ");
        scanf("%f", &matrice2[i][j]);
        }
    }
else if(OperatoreMatrice == 3)
    {
    printf("Perfetto, adesso inserire il numero di Righe di cui è composta la Matrice: ");
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Riga ");
        scanf("%f", &matrice[i][j]);
        }
matrice2[i][j] = matrice[i][j];
    j = j + 1;

    printf("Perfetto, adesso inserire il numero di Colonne di cui è composta la Matrice: ");
    while(matrice[i][j] < 1.000000)
        {
        printf("Per cortesia inserire almeno una Colonna ");
        scanf("%f", &matrice[i][j]);
        }
matrice2[i][j] = matrice[i][j];
    }
return;
}

void InserimentoMatrice()
{
int i = 0;
int j = 0;
if(OperatoreMatrice == 1)
    {
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
    }
else
{
    printf("MACHEOOOOOOOOOOOO %d", OperatoreMatrice);
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
i = 0;
j = 0;
    while(i < matrice2[RIGHE - 1][COLONNE - 1])
        {
            j = 0;
            while(j < matrice2[RIGHE - 1][COLONNE])
                {
                printf("Inserire il numero in posizione Riga: ");
                printf("%d", i + 1);
                printf(" e Colonna: ");
                printf("%d", j + 1);
                printf(" della Matrice2 e premere invio. ");
                scanf("%f", &matrice2[i][j]);
                j = j + 1;
                }
                i = i + 1;
        }
}
return;
}

void MatriceScalare()
{
int i = 0;
int j = 0;
int scalare = 0;

printf("Inserisci il valore Scalare: ");
scanf("%d", &scalare);

while(i < matrice[RIGHE - 1][COLONNE - 1])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE])
        {
            MatriceRisulta[i][j] = matrice[i][j] * scalare;
            j = j + 1;
        }
    i = i + 1;
    }
return;
}

void MatriceTrasposta()
{
int i = 0;
int j = 0;
int v = 0;

printf("Ecco la tua matrice trasposta\n");
j = 0;
while(j < matrice[RIGHE - 1][COLONNE])
    {
        i = 0;
        while(i < matrice[RIGHE - 1][COLONNE - 1])
                {
                printf("%.2f\t", matrice[i][j]);
                i = i + 1;
                }
        j = j + 1;
        printf("\n");
      }
return;
}

void MatriceSomma()
{
int i = 0;
int j = 0;

while(i < matrice[RIGHE - 1][COLONNE - 1])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE])
        {
            MatriceRisulta[i][j] = matrice[i][j] + matrice2[i][j];
            j = j + 1;
        }
    i = i + 1;
    }
return;
}

void MatriceProdotto()
{
int i = 0;
int j = 0;
int c = 0;

float risulta[RIGHE] = {0};

while(i < matrice[RIGHE - 1][COLONNE - 1])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE])
        {
            c = 0;
            while(c < matrice[RIGHE - 1][COLONNE])
            {
            risulta[c] = matrice[i][c] * matrice2[c][j];
            MatriceRisulta[i][j] = MatriceRisulta[i][j] + risulta[c];
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

printf("La matrice di Risulta è la seguente: \n");

while(i < matrice[RIGHE - 1][COLONNE - 1])
    {
        j = 0;
        while(j < matrice[RIGHE - 1][COLONNE])
        {
            printf("%.02f", MatriceRisulta[i][j]); //Cifra arrotondata a 2 decimali
            printf("\t");
            j = j + 1;
        }
    printf("\n");
    i = i + 1;
    }
return;
}
