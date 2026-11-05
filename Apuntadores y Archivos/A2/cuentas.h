#ifndef cuentas_h
#define cuentas_h

#include <stdio.h>
#include <string.h>

#define Mx 50

typedef struct{
    int  cuenta;
    char nombre[Mx];
    float balance;
}Cuentas;

int menu2(void);
void GCuenta();
void ReporteG(int tipo);
int ECuenta(int num); //evitar que se sobreescriba una misma cuenta

//Archivo
#define ARCHIVO "cuentas.dat"

#endif