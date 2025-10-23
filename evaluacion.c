/*
Autores:
Fecha:
Tema:
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILAS 7
#define COLUMNAS 7

/*Prototipos*/
void leertablero(char [][COLUMNAS]);
void mostrar_tab(char [][COLUMNAS]);

/*Funcion principal*/
int main(){
    char tablero[FILAS][COLUMNAS];
    leertablero(tablero);
    mostrar_tab(tablero);
    return 0;
}

/*Funciones*/
void leertablero(char tab[FILAS][COLUMNAS]){
    int i, j;
    char salto;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            scanf("%c", &tab[i][j]);
        }
        scanf("%c", &salto);
    }
}

void mostrar_tab(char tab[FILAS][COLUMNAS]){
    int i, j;
    for(i = 0; i < FILAS; i++){
        for ( j = 0; j < COLUMNAS; j++){
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
}