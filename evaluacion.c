/*
Autores:
Fecha:
Tema:
*/
#include <stdio.h>
#include <string.h>
#define FILAS 7
#define COLUMNAS 7

typedef struct orden{      /*Guardar datos futuros, ya que el orden saldra invertido*/
    int origen_x[31];
    int origen_y[31];
    int salta_x[31];
    int salta_y[31];
} ORDEN;

/*Prototipos*/
void leertablero(char [][COLUMNAS]);
void mostrar(int , ORDEN );
int fichas_actuales(char [][COLUMNAS]);
int resolver(char [][COLUMNAS], int *, ORDEN *);
void respaldo(char [][COLUMNAS], char [][COLUMNAS]);
void guardar(int *, int, int, int, int, ORDEN *);

/*Funcion principal*/
int main(){
    ORDEN real;
    char tablero[FILAS][COLUMNAS];
    int contador = 0;
    leertablero(tablero);
    resolver(tablero, &contador, &real);
    mostrar(contador, real);
    return 0;
}

/*Funciones*/
void leertablero(char tab[FILAS][COLUMNAS]){
    int i, j;
    char salto;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            scanf("%c", &tab[i][j]); /*Usa la entrada estandar*/
        }
        scanf("%c", &salto);
    }
}

void mostrar(int paso, ORDEN real){  /*des: abreviacion de "desde"; has: hasta*/
    int i, j = 1;
    printf("En 31 movimientos se encontro la solucion\n");
    for (i = paso; i > 0; i--){
        printf("%d: posicion <%d,%d> a posicion <%d,%d>\n", j, real.origen_x[i], real.origen_y[i], real.salta_x[i], real.salta_y[i]); /*Consideramos la casilla 0 como 1*/
        j++;
    }
}

int fichas_actuales(char tab[FILAS][COLUMNAS]){ 
    int c = 0;
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){ /*Cuenta las X en el tablero actual*/
            if(tab[i][j]=='X'){
                c++;
            }
        }
    }
    return c;
}

int resolver(char tab[FILAS][COLUMNAS], int *contador, ORDEN *real){
    int centro_f, centro_c;
    char clon[FILAS][COLUMNAS];
    int x, y, movimientos, i, j;
    int salto_x, salto_y;
    int movy[4] = {1, 0, -1, 0}; /*En un plano cartesiano de suma, resta o mantiene los movimientos en x y lo mismo para y*/
    int movx[4] = {0, 1, 0, -1};
    centro_c = (COLUMNAS /2);
    centro_f = (FILAS / 2);
    if(fichas_actuales(tab) == 1 && tab[centro_f][centro_c]=='X'){
        return 1;
    }
    for (i = 0; i < FILAS; i++){
        for ( j = 0; j < COLUMNAS; j++){
            if(tab[i][j] == 'X'){
                for (movimientos = 0; movimientos < 4; movimientos++){
                    x = i + movx[movimientos];
                    y = j + movy[movimientos];
                    salto_x = i + 2 * movx[movimientos];
                    salto_y = j + 2 * movy[movimientos];
                    if(salto_x >= 0 && salto_x < FILAS && salto_y >= 0 && salto_y < COLUMNAS && tab[x][y] == 'X' && tab[salto_x][salto_y] == ' '){
                        respaldo(tab, clon);
                        clon[i][j] = ' ';
                        clon[x][y] = ' ';
                        clon[salto_x][salto_y] = 'X';
                        if(resolver(clon, contador, real)){
                            (*contador)++;
                            guardar(contador, i, j, salto_x, salto_y, real);
                            return 1;
                        }
                    }
                }
            }
        } 
    }
    return 0;
}

void respaldo(char original[FILAS][COLUMNAS], char clon[FILAS][COLUMNAS]){
    int i, j;
    for ( i = 0; i < FILAS; i++){
        for ( j = 0; j < COLUMNAS; j++){
            clon[i][j] = original[i][j];
        }
    }
}

void guardar(int *paso, int des_x, int des_y, int salto_x, int salto_y, ORDEN *real){
    real->origen_x[*paso] = des_x + 1;
    real->origen_y[*paso] = des_y + 1;
    real->salta_x[*paso] = salto_x + 1;
    real->salta_y[*paso] = salto_y + 1;
}