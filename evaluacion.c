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
int leertablero(char [][COLUMNAS]);
void mostrar_tab(char [][COLUMNAS]);
void ajuste_tablero(char[][COLUMNAS], int);
void borrar_fila(char [][COLUMNAS], int);

/*Funcion principal*/
int main(){
    char tablero[FILAS][COLUMNAS];
    int filas;
    filas = leertablero(tablero);
    mostrar_tab(tablero);
    return 0;
}

/*Funciones*/
int leertablero(char tab[FILAS][COLUMNAS]){
    int i = 0;
    while (i < FILAS){
        scanf("%s", tab[i]);
        i++;
    }
    i--;
    ajuste_tablero(tab, i);
    return i;
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

void ajuste_tablero(char tab[FILAS][COLUMNAS], int filas){
    int i, j, centro, contador;
    char espacio[FILAS];
    char proceso[FILAS][COLUMNAS];
    espacio[0] = ' ';
    centro = FILAS/ 2;
    strcpy(tab[centro], espacio);
    strcpy(proceso[0], tab[centro+1]);
    borrar_fila(tab, centro);
    strcpy(tab[centro], proceso[0]);
}

void borrar_fila(char tab[FILAS][COLUMNAS], int centro){
    int i, j;
    for (i = centro + 1; i < FILAS; i++){
        for ( j = 0; j < COLUMNAS; j++){
            tab[i][j] = '\0';
        }
    }
}