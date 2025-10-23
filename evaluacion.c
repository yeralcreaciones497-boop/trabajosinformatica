/*
Autores:
Fecha:
Tema:
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILAS 8
#define COLUMNAS 7

/*Prototipos*/
void leertablero(char [][COLUMNAS]);
void mostrar_tab(char [][COLUMNAS]);

/*Funcion principal*/
int main(){
    char tablero[FILAS][COLUMNAS];
    leertablero(tablero);
    return 0;
}

/*Funciones*/
void leertablero(char tab[FILAS][COLUMNAS]){
    int i = 0;
    for ( i = 0; i < FILAS; i++){
        scanf("%s", tab[i]);
        printf("%c\n", tab[i][1]);
    }
}

void mostrar_tab(char tab[FILAS][COLUMNAS]){
    int i, j;
    for(i = 0; i < FILAS; i++){
        printf("%s", tab[i]);
    }
}
