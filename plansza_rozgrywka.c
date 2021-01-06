#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

//#include "kolko.h"
#include "komputer.c"
#include "gracz.c"

#define WYMIARY 4
#define GLEBIA 6

int zajete_pola = 0;

void wyczysc(char plansza[WYMIARY][WYMIARY])
{
    for(int i = 0; i < WYMIARY; i++){
        for(int j = 0; j < WYMIARY; j++){
            plansza[i][j] =' ';
        }
    }
}

void wyswietl(char plansza[WYMIARY][WYMIARY])
{
    printf("   0 1 2 3 \n");
    for(int i = 0; i < WYMIARY; i++){
        printf("%i  ", i);
        for(int j = 0; j < WYMIARY; j++)
        {
            printf("%c ", plansza[i][j]);
        }  
        printf("\n");
    }
}

void ini_plansza (char plansza[WYMIARY][WYMIARY])
{
    for(int i = 0; i < WYMIARY; i++){
        for (int j = 0; j < WYMIARY; j++)
        {
            plansza[i][j] = ' ';
        }   
    }
}

void ustalenie_znak(){
    printf("Wprawadź znak którym chcesz grać i którym ma grać komputer \n");
    scanf("%c %c", &znaki.gracza, &znaki.komputera);
}


void sprawdz_wygranie(int gra, int zajete_pola){
    if(gra == KOMPUTER){
        printf("WYGRAŁEM Z TOBĄ \n");
        exit(0);
    }
    else if(gra == GRACZ){
        printf("WYGRAŁEŚ ZE MNĄ :( \n");
        exit(0);
    }
    else if(zajete_pola >= 15)
    {
        printf("WYGRALIŚMY OBOJE \n");
        exit(0);
    }
}

bool nastepna_gra(){
    printf("Czy chcesz grać ponownie? Naciśnij t jeśli tak i n jeśli nie");
    char znacznik;
    scanf("%c", &znacznik);
    printf("DUPA %c", znacznik);
    if(znacznik == 't'){
        return true;
    }
    else if(znacznik != 't'){
        return false;
    }
}

int main(){
    char znacznik = 1;
    int zajete_pola = 0;
    int gra = 0;
    char plansza[WYMIARY][WYMIARY];
    ini_plansza(plansza);
    bool k = true;
    while(k == true){
        ustalenie_znak();
        wyswietl(plansza);
        while( k == true ){
            ruch_g(plansza, znaki.gracza);
            ++zajete_pola;
            gra = czy_wygrana(plansza);
            sprawdz_wygranie(gra, zajete_pola);
            char znak = znaki.komputera;
            oceniajaca(GLEBIA, plansza, znak);
            plansza[wiersz][kolumna] = znak;
            wyswietl(plansza);
            ++zajete_pola;
            gra = czy_wygrana(plansza);
            sprawdz_wygranie(gra, zajete_pola);
        }
    }
}
