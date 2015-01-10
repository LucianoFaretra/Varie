

Lettura_impostazioni()
{
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


}
