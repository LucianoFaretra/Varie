#include <stdio.h>
#include <stdlib.h>

// esempio classifica confronto del punteggio attuale con quello precedente se è maggiore lo scrive altrimenti restituisce 0 oppure non record

//Funzione confronto classifica Input: Punteggio dell'utente

int main() {
    
   int punteggio_scelto1;
   int punteggio_scelto2;
   int punteggio_scelto3;
   int punteggio_scelto4;
   int punteggio_scelto5;
   int punteggio_scelto6;
   int punteggio_scelto7;
   int punteggio_scelto8;
   int punteggio_scelto9;
   int punteggio_scelto10;
   
   printf("Inserisci il tuo primo punteggio ");
   scanf("%d",&punteggio_scelto1);
   printf("Inserisci il tuo secondo punteggio ");
   scanf("%d",&punteggio_scelto2);
   printf("Inserisci il tuo terzo punteggio ");
   scanf("%d",&punteggio_scelto3);  
   printf("Inserisci il tuo quarto punteggio ");
   scanf("%d",&punteggio_scelto4);  
   printf("Inserisci il tuo quinto punteggio ");
   scanf("%d",&punteggio_scelto5);
   printf("Inserisci il tuo sesto punteggio ");
   scanf("%d",&punteggio_scelto6);  
   printf("Inserisci il tuo settimo punteggio ");
   scanf("%d",&punteggio_scelto7);     
   printf("Inserisci il tuo ottavo punteggio ");
   scanf("%d",&punteggio_scelto8);
   printf("Inserisci il tuo nono punteggio ");
   scanf("%d",&punteggio_scelto9);
   printf("Inserisci il tuo decimo punteggio ");
   scanf("%d",&punteggio_scelto10); 
        
   
   printf("Ecco la tua classifica dei migliori 10 punteggi \n");
   printf("\n");
   printf("1)Punteggio: ");
   printf("%d",punteggio_scelto1);
   printf("\n");
 
   if (punteggio_scelto2 > punteggio_scelto1) 
      {  printf("2)Punteggio: ");
        printf("%d",punteggio_scelto2);
        printf("\n");
        }
        else { 
             printf("2)Punteggio: ");
             printf("0");
             printf("\n");     }
   
   if (punteggio_scelto3 > punteggio_scelto2) 
     {   printf("3)Punteggio: ");
        printf("%d",punteggio_scelto3);
        printf("\n"); 
        
        }
     else {   
              printf("3)Punteggio: ");
              printf("0");
              printf("\n");          
                }
 
   if (punteggio_scelto4 > punteggio_scelto3) 
     {  printf("4)Punteggio: ");
        printf("%d",punteggio_scelto4);
        printf("\n"); }
        
        else { 
             printf("4)Punteggio: ");
             printf("0");
             printf("\n");                 }
   
   if (punteggio_scelto5 > punteggio_scelto4) 
      {  printf("5)Punteggio: ");
        printf("%d",punteggio_scelto5);
        printf("\n");   }
        
        else {  
             printf("5)Punteggio: ");
             printf("0");
             printf("\n");  }
        
 
  if (punteggio_scelto6 > punteggio_scelto5) 
      {  
        printf("6)Punteggio: ");
        printf("%d",punteggio_scelto6);
        printf("\n");  }
        
        else {   
             printf("6)Punteggio: ");
             printf("0");
             printf("\n"); 
             
             }
        
        
  
   if (punteggio_scelto7 > punteggio_scelto6) 
       { printf("7)Punteggio: ");
        printf("%d",punteggio_scelto7);
        printf("\n"); }
        
        else {  
             printf("7)Punteggio: ");
             printf("0");
             printf("\n");     }
        
        if (punteggio_scelto8 > punteggio_scelto7) 
        {
        printf("8)Punteggio: ");
        printf("%d",punteggio_scelto8);
        printf("\n");  }
        
        else {   
             printf("8)Punteggio: ");
             printf("0");
             printf("\n"); 
             
                  }
            
   
   if (punteggio_scelto9 > punteggio_scelto8) 
        {
        printf("9)Punteggio: ");
        printf("%d",punteggio_scelto9);
        printf("\n"); }
        
        else {  
             printf("9)Punteggio: ");
             printf("0");
             printf("\n"); 
             
             }
                                       
   if (punteggio_scelto10 > punteggio_scelto9) 
        {
        printf("10)Punteggio: ");
        printf("%d",punteggio_scelto10);
        printf("\n"); }
        
        else { 
             printf("10)Punteggio: ");
             printf("0");
             printf("\n"); 
                   }
         
    
   getchar();
   getchar();
   return 0;}
