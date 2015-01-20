typedef struct{
    char CodiceVolo[5];
    float OrarioPartenza;
    char Destinazione[15];
    float OrarioArrivo;
    unsigned int PostiTotali;
    double Prezzo;
}DatiVolo;

typedef struct{
    char CodiceVoloAumenti[4];
    double PrezzoAumenti;
}AumentiVoli;
