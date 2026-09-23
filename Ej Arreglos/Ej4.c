#include<stdio.h>

int main(){

    int num[10];
    int i, posMay=0, posMen=0;
    int may, men, suma, resta, mult;

    for(i=0; i<10; i++){
        printf("Ingrese numero %d: ", i+1);
        scanf("%d", &num[i]);
    }

    may = men = suma = resta = mult = num[0];

    for(i=1; i<10; i++){
        if(num[i] > may){ may = num[i]; posMay = i; }
        if(num[i] < men){ men = num[i]; posMen = i; }
        suma += num[i];
        resta -= num[i];
        mult *= num[i];
    }

    printf("\nMayor: %d (Posicion: %d)\n", may, posMay);
    printf("Menor: %d (Posicion: %d)\n", men, posMen);
    printf("Suma: %d\nResta: %d\nMultiplicacion: %d\n", suma, resta, mult);

    return 0;
}