/*
Autores:
Fecha:
Tema:
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ESPACIO 49 

/*Prototipos*/
void leertablero(char []);
void mostrar_tab(char []);

/*Funcion principal*/
int main(){
    char tablero[ESPACIO];
    leertablero(tablero);
    mostrar_tab(tablero);
    return 0;
}

/*Funciones*/
void leertablero(char tab[]){
    int i = 0, j = 0;
    while (scanf("%s", tab) != EOF) {
        printf("%s", tab);
        i++;
        if (i == 1){
            printf("\n");
            i = 0;
        }
    }
}

void mostrar_tab(char tab[]){
    int i, j;
    for(i = 0; i < ESPACIO -1; i++){
        printf("%2s", tab[i]);
    }
}
