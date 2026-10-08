#include "Coordenadas.h"

void ConversionRec(){

   Coordenadas Punto;
   Coordenadas Polares;

   printf("Ingrese la magnitud del vector:\n");
   scanf("%f", &Polares.r);
   printf("Ingrese el angulo del vector:\n");
   scanf("%f", &Polares.angle);

    Punto.Coo[0] = Polares.r*sinf(Polares.angle);
    Punto.Coo[1] = Polares.r*cosf(Polares.angle);
   
    printf("El Vector en coordenadas rectangulares es: (%f,%f)\n\n", Punto.Coo[0], Punto.Coo[1]);

}

void ConversionPolares(){

    Coordenadas Punto;
    Coordenadas Polares;

    printf("Ingrese el vector (x y):");
    scanf("%f %f", &Punto.Coo[0], &Punto.Coo[1]);

    Polares.r = sqrt(pow(Punto.Coo[0],2) + pow(Punto.Coo[1],2));
    Polares.angle = atan (Punto.Coo[0]/Punto.Coo[1]);

    printf("El vector en polares es r = %2f, angulo = %2f\n\n",Polares.r, Polares.angle);
}