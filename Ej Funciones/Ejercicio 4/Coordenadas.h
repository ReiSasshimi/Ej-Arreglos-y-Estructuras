#ifndef Coordenadas_h
#define Coordenadas_h


#include <stdio.h>
#include <math.h>

typedef struct {
    float Coo[2];
    float angle;
    float r;
}Coordenadas;

void ConversionPolares();
void ConversionRec();

#endif