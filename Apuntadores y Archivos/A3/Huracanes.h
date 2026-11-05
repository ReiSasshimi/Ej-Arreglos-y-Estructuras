#ifndef Huracanes_h
#define Huracanes_h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char nombre[50];
    int categoria;
    char fecha[30];
    float tamaño;          
    char origen[50];  
    float velocidad_max;
}Huracan;

void IngresarH();
void ModificarH();
void EliminarH();
void Reportes();

#define ARCHIVO "Huracanes.bin"
#define ARCHIVORH "Reportes.txt"

#endif