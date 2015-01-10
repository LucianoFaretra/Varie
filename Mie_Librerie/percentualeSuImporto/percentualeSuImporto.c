/*                 Sviluppato da Luciano Faretra 02/01/2015 rilasciato sotto licenza GNUv3
                                    Esercizio Commissioni su vendite

****************************************************************************************************************
    Funzione    percentualeSuImporto( importoSuCuiCalcolare, percentuale )

    INPUT                           DESCRIZIONE                                                     DOMINIO
    importoSuCuiCalcolare           Importo su cui calcolare la percentuale                         double >= 0
    percentuale                     Percentuale utilizzata per il calcolo                           double >= 0

    OUTPUT                          DESCRIZIONE                                                     DOMIONIO
    importoPercentuale              il percentuale di importoSuCuiCalcolare                         double >= 0

    DATI DI LAVORO                  DESCRIZIONE                                                     DOMINIO

*****************************************************************************************************************


    Se importoSuCuiCalcolare > 0
        Allora
            Se percentuale > 0
                Allora
                    return ( importoSuCuiCalcolare * percentuale / 100 )
                Altrimenti Se percentuale == 0
                    Allora
                        return 0
            Fine Se
        Altrimenti
            Se importoSuCuiCalcolare == 0
                Allora
                    return 0
            Fine Se
    Fine Se

    return -1

*/

double percentualeSuImporto( double importoSuCuiCalcolare, double percentuale )
{
    double importoPercentuale = -1;

    if( importoSuCuiCalcolare > 0 ){

        if( percentuale > 0 ){

            importoPercentuale = ( importoSuCuiCalcolare * percentuale / 100 );
            return importoPercentuale;

        }
        else if ( percentuale == 0 ){

            return 0;

        }
    }
    else if( importoSuCuiCalcolare == 0 ){

        return 0;

    }
    /*printf("%s", "Attenzione valori in input della funzione non validi"); //Debig info */
    return -1;
}

