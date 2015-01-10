#include <stdio.h>
#include <stdlib.h>

// Funzione Confronto Classifica che scrive su file i primi 10 punteggi effettuati dal giocatore

 // Dato di input: serie di punteggi effettuati dal giocatore
void Confronto_classifica(int Punteggio_partita) {



  FILE *fd;

  int punteggio_scelto1;
  int punteggio_scelto2;
  int punteggio_scelto3;
  int punteggio_scelto4;
  int punteggio_scelto5;
  int punteggio_scelto6;
  int punteggio_scelto7;
  int punteggio_scelto8;
  int punteggio_scelto9;
  int punteggio_file1;
  int punteggio_file2;
  int punteggio_file3;
  int punteggio_file4;
  int punteggio_file5;
  int punteggio_file6;
  int punteggio_file7;
  int punteggio_file8;
  int punteggio_file9;
  int punteggio_file10;


  printf("Leggi il tuo secondo punteggio da confrontare \n");
  printf("\nN.B il tuo primo punteggio è stato già salvato su file ");
  scanf("\n" "%d",&punteggio_scelto1);
  printf("Leggi il terzo punteggio");
  scanf("%d",&punteggio_scelto2);
  printf("Leggi il quarto punteggio");
  scanf("%d",&punteggio_scelto3);
  printf("Leggi il quinto punteggio");
  scanf("%d",&punteggio_scelto4);
  printf("Leggi il sesto punteggio");
  scanf("%d",&punteggio_scelto5);
  printf("Leggi il settimo punteggio");
  scanf("%d",&punteggio_scelto6);
  printf("Leggi il ottavo punteggio");
  scanf("%d",&punteggio_scelto7);
  printf("Leggi il nono punteggio");
  scanf("%d",&punteggio_scelto8);
  printf("Leggi il decimo punteggio");
  scanf("%d",&punteggio_scelto9);


		/* apre il file in scrittura */
  fd=fopen("file1.txt", "r");
  if( fd == NULL ) {
       printf("Errore di apertura del file ");}
else {
/* scrive il numero */
  fd=fopen("file1.txt","r");
  fscanf(fd,"%d\n",&punteggio_file1);
  if (punteggio_scelto1 > punteggio_file1)
  fd=fopen("file1.txt","a");
  fprintf(fd,"%d\n", punteggio_scelto1);
  rewind(fd);

  fscanf(fd,"%d\n",&punteggio_file2);
  if (punteggio_scelto2 > punteggio_scelto1)
  fd=fopen("file1.txt","a");
  fprintf(fd,"%d\n", punteggio_scelto2);
  rewind(fd);

  fscanf(fd,"%d\n",&punteggio_file3);
  if (punteggio_scelto3 > punteggio_scelto2)
  fd=fopen("file1.txt","a");
  fprintf(fd,"%d\n", punteggio_scelto3);
  rewind(fd);

  fscanf(fd,"%d\n",&punteggio_file4);
  if (punteggio_scelto4 > punteggio_scelto3)
  fd=fopen("file1.txt","a");
  fprintf(fd,"%d\n", punteggio_scelto4);
  rewind(fd);

  fscanf(fd,"%d\n",&punteggio_file5);
  if (punteggio_scelto5 > punteggio_scelto4)
  fd=fopen("file1.txt","a");
  fprintf(fd,"%d\n", punteggio_scelto5);
  rewind(fd);

  fscanf(fd,"%d\n",&punteggio_file6);
  if (punteggio_scelto6 > punteggio_scelto5)
  fd=fopen("file1.txt","a");
  fprintf(fd,"%d\n", punteggio_scelto6);
  rewind(fd);

  fscanf(fd,"%d\n",&punteggio_file7);
  if (punteggio_scelto7 > punteggio_scelto6)
  fd=fopen("file1.txt","a");
  fprintf(fd,"%d\n", punteggio_scelto7);
  rewind(fd);

  fscanf(fd,"%d\n",&punteggio_file8);
  if (punteggio_scelto8 > punteggio_scelto7)
  fd=fopen("file1.txt","a");
  fprintf(fd,"%d\n", punteggio_scelto8);
  rewind(fd);

  fscanf(fd,"%d\n",&punteggio_file9);
  if (punteggio_scelto9 > punteggio_scelto8)
  fd=fopen("file1.txt","a");
  fprintf(fd,"%d\n", punteggio_scelto9);
  rewind(fd);

/* chiude il file */
  fclose(fd);

}
     getchar();
     getchar();
return;
}
