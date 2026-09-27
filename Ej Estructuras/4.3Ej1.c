#include <stdio.h>
#include <math.h>

typedef struct{
  float X;
  float Y;
  }Punto;
  
int main(){

  Punto x1;
  Punto y1;
  
  printf("Ingrese el primer punto (x y):");
  scanf("%f %f",&x1.X,&y1.Y);
  
  Punto x2;
  Punto y2;
  
  printf("Ingrese el segundo punto (x y):");
  scanf("%f %f", &x2.X, &y2.Y);
  
  float dx = x2.X - x1.X;
  float dy = y2.Y - y2.Y;
  
  float dis = sqrt( pow(dx,2) + pow (dy,2));
  
  printf("La distancia entre los puntos (%f %f) y (%f %f) es: %2f", x1.X, y1.Y, x2.X, y2.Y, dis);
  
return 0;
}