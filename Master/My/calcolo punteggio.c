#include <stdio.h>
#include <stdlib.h>

// Funzione CalcoloPunteggio input: punteggio_partita e righe  
int main() {
    
    int righe;
    int punteggio_partita;
    
    printf("Inserisci numero riga ");
    scanf("%d",&righe);
    printf("\n");
    
    if(righe==9)
                    punteggio_partita=1000;
		else
			if (righe== 8)
				     punteggio_partita=900;
         else
             if ( righe == 7)
                     punteggio_partita=800;
         else
			if (righe== 6)
				     punteggio_partita=700;
		else
			if (righe == 5)
				 punteggio_partita=600;
		else
            if (righe == 4)
				 punteggio_partita=500;
        else
			if (righe == 3)
				 punteggio_partita=400;
	  else
			if  (righe== 2)
                 punteggio_partita=300;
	else
			if  (righe==1)
                 punteggio_partita=200;
	else
			if (righe==0)
                 punteggio_partita=0;
			
			printf("%d",punteggio_partita);
            printf("\n");
            printf("\n");
            system("pause");			
       return 0; }
