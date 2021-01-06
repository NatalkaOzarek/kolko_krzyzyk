#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "kolko.h"

bool sprawdzenie(char plansza[WYMIARY][WYMIARY], int pion, int poziom)
{
    if(pion > 5 || pion < 0 || poziom > 5 || pion < 0){
        return false;
    }
    if (plansza[pion][poziom] != ' ')
    {
        return false;
    }
    if (plansza[pion][poziom] == ' ')
    {
        return true;
    }
}

void ruch_g (char plansza[WYMIARY][WYMIARY], char znak_gracza)
{
    printf("Podaj współrzędne gdzie chcesz wstawić znak (pozioma, pionowa) \n"); 
    int pion, poz;
    scanf("%i %i", &pion, &poz);
    bool k = sprawdzenie(plansza, pion, poz);
    while (k == false){
        printf("Nie możesz wstawić tu znaku, wprowadź współrzędne ponownie (pozioma, pionowa) \n");
        scanf("%i %i", &pion, &poz);
        k = sprawdzenie(plansza, pion, poz);
   }
    plansza[pion][poz] = znak_gracza;
}