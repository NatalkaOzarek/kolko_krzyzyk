#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "kolko.h"

#define WYMIARY 4
#define REMIS 0
#define KOMPUTER 1
#define GRACZ -1
#define GLEBIA 6

typedef struct znak
{
    char gracza;
    char komputera;
} def_znaki;

int wiersz = 1, kolumna = 1;
def_znaki znaki;

int rozpoznaj_wygrana(char znak){
    if(znak == znaki.komputera){
        return KOMPUTER;
    }
    if (znak == znaki.gracza)
    {
        return GRACZ;
    }
}

int czy_wygrana(char plansza[WYMIARY][WYMIARY]){
    int znak;
    for(int i = 0; i < WYMIARY; i++)
    {
        if(plansza[i][0] == plansza[i][1] && plansza[i][2] == plansza[i][0] && plansza[i][3] == plansza[i][0] && plansza[i][0] != ' ')
        {
            znak = plansza [i][0];
            return rozpoznaj_wygrana(znak);
        }
        if(plansza[0][i] == plansza[1][i] && plansza[2][i] == plansza[0][i] && plansza[3][i] == plansza[0][i] && plansza[0][i] != ' ')
        {
            znak = plansza [0][i];
            return rozpoznaj_wygrana(znak);
        }
    }
    if(plansza[0][0] == plansza [1][1] && plansza [2][2] == plansza [3][3] && plansza [0][0] == plansza [3][3] && plansza[0][0] != ' ')
    {
       znak = plansza[0][0]; 
       return rozpoznaj_wygrana(znak);
    }
    if(plansza[0][3] == plansza [1][2] && plansza [2][1] == plansza [3][0] && plansza [2][1] == plansza [1][2] && plansza[0][3] != ' ')
    {
        znak = plansza[0][3];
        return rozpoznaj_wygrana(znak);
    }
    else
        return REMIS;
}

int oceniajaca(int glebokosc, char plansza[WYMIARY][WYMIARY], char znak){
    int tab_random[4][4];
    int aktualna;
    char znak_przeciwnika;
    if(znak == znaki.komputera){
        znak_przeciwnika = znaki.gracza;
    }
    if(znak == znaki.gracza){
        znak_przeciwnika = znaki.komputera;
    }
    int brak_ruchu = 1;
    int o_wygranej = czy_wygrana(plansza); 
     if(o_wygranej != REMIS || glebokosc <= 0){
         return(o_wygranej);
    }
    int najlepsza;
    if(znak == znaki.komputera){
        najlepsza = 2 * GRACZ;
    }
    else{
        najlepsza = 2 * KOMPUTER;
    }
    for (int i = 0; i < WYMIARY; i++)
    {
        for (int j = 0; j < WYMIARY; j++){
            if(plansza[i][j] == ' '){
                plansza[i][j] = znak;
                aktualna = oceniajaca(glebokosc-1, plansza, znak_przeciwnika);
                plansza[i][j] = ' ';
                if(znak == znaki.komputera && aktualna > najlepsza){
                    najlepsza = aktualna;
                    if(glebokosc == GLEBIA){
                        wiersz = i;
                        kolumna = j;
                    }
                }
                if(znak == znaki.gracza && aktualna < najlepsza){
                    najlepsza = aktualna;
                }
                brak_ruchu = 0; 
            }
        }
    }
    if(brak_ruchu){
        return 0;
    }
    else{
        return najlepsza;
    }
}
