

Lettura_impostazioni()
{
Lettura file(Impostazioni.txt)

    SE le impostazioni hanno l�audio attivo{
        Allora
            Abilita audio
        Altrimenti
            Disabilita audio
    }FINE SE

    SE la difficolt� � impostata a facile{
        Allora
            imposta come colori decifratore e codificatore 6 variabili colore
        Altrimenti
            imposta come colori decifratore e codificatore 9 variabili colore
    }FINE SE

    SE la lingua � impostata come italiano{
        Allora
            utilizza schermata in italiano
        Altrimenti
            utilizza schermata in inglese
    }FINE SE

    SE il gioco � in modalit� single player{
        Allora
            Inserimento_combinazione_codificatore(combinazione_codificatore)
        Altrimenti
            Generazione_combinazione_casuale
    }FINE SE


}
