#ifndef KOLKO
#define KOLKO

#define WYMIARY 4
#define REMIS 0
#define KOMPUTER 1
#define GRACZ -1
#define GLEBIA 6

int zajete_pola;

typedef struct znak
{
    char gracza;
    char komputera;
} def_znaki;

int wiersz, kolumna;
def_znaki znaki;

bool ponowna_gra();
bool nastepna_gra();
bool sprawdzenie(char plansza[WYMIARY][WYMIARY], int pion, int poziom);
int rozpoznaj_wygrana(char znak);
int czy_wygrana(char plansza[WYMIARY][WYMIARY]);
int oceniajaca(int glebokosc, char plansza[WYMIARY][WYMIARY], char znak);
void sprawdz_wygranie(int gra, int zajete_pola);
void wyczysc(char plansza[WYMIARY][WYMIARY]);
void wyswietl(char plansza[WYMIARY][WYMIARY]);
void ini_plansza (char plansza[WYMIARY][WYMIARY]);
void ustalenie_znak();
void ruch_g (char plansza[WYMIARY][WYMIARY], char znak_gracza);

#endif