#ifndef Matrices_h
#define Matrices_h

#include <stdio.h>

#define Max 200

typedef struct {
    int fil;
    int col;
    int Matriz[Max][Max];
}Matriz;

//Funciones de operaciones 
void SMatrices();
void PMatrices();
void SEMatrices();

#endif