/*                 Sviluppato da Luciano Faretra 31/12/2014 rilasciato sotto licenza GNUv3
                                    ArrotondamentiMonetari
    Affinamento Top Down

    INPUT                           DESCRIZIONE                                                     DOMINIO
    numeroInserito                  Numero inserito da arrotondare                                  double >= 0

    OUTPUT                          DESCRIZIONE                                                     DOMIONIO
    numeroArrotondatoAIntero        Numero intero arrotondato all'intero piu vicino                 int >= 0
    numeroArrotondatoADecimi        Numero intero arrotondato alla posizione dei decimi             float >= 0
    numeroArrotondatoACentesimi     Numero intero arrotondato alla posizione dei centesimi          float >= 0
    numeroArrotondatoAMigliaia      Numero intero arrotondato alla posizione dei millesimi          float >= 0

    DATI DI LAVORO                  DESCRIZIONE                                                     DOMINIO

    1. Il programma arrotonda l'intero inserito all'intero piu vicino

*/

#include <math.h>

unsigned int numeroArrotondatoAIntero( double x )
{

return floor( x + .5 );
}

float numeroArrotondatoADecimi( double x )
{

return floor( x * 10 + .5 ) / 10;
}

float numeroArrotondatoACentesimi( double x )
{

return floor( x * 100 + .5 ) / 100;
}

float numeroArrotondatoAMigliaia( double x )
{

return floor( x * 1000 + .5 ) / 1000;
}
