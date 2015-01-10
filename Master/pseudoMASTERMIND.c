//leggi le impostazioni

    Lettura file(Impostazioni.txt)

    SE le impostazioni hanno l’audio attivo{
        Allora
            Abilita audio
        Altrimenti
            Disabilita audio
    }FINE SE

    SE la difficoltà è impostata a facile{
        Allora
            imposta come colori decifratore e codificatore 6 variabili colore
        Altrimenti
            imposta come colori decifratore e codificatore 9 variabili colore
    }FINE SE

    SE la lingua è impostata come italiano{
        Allora
            utilizza schermata in italiano
        Altrimenti
            utilizza schermata in inglese
    }FINE SE

    SE il gioco è in modalità single player{
        Allora
            Inserimento_combinazione_codificatore(combinazione_codificatore)
        Altrimenti
            Generazione_combinazione_casuale
    }FINE SE

    Inizializza le righe a 0
    ESEGUI{
        Stampa_campo(Colori_decifratore, Esito_pioli)
        Leggi i 4 colori inseriti dal decifratore
        Inserimento_combinazioni_decifratore (Colori_decifratore)
        Confronta_colori (Colori_decifratore,Colori_codificatore, Esito_pioli)

        SE Esito_pioli ha 4 pioli codice neri
            Allora
                vittoria = 1
                Righe = 9
            Altrimenti
                vittoria = 0
        FINE SE

    Incrementa righe di 1
    }FINCHE’ ci sono righe disponibili

    SE vittoria = 1{
        Allora
            Calcolo_punteggio
            Stampa schermata Vittoria
                SE il punteggio è un nuovo record{
                    Allora
                        Confronto_classifica
                        Stampa_schermata (Classifica.txt)
                }FINE SE
        Altrimenti
            Stampa_schermata (Gameover.txt)
    }FINE SE
