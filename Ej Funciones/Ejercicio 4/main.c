#include "Coordenadas.h"

int main(){

    int c;

    do{
        printf("\n=================================");
        printf("\n    Conversion de Cordenadas     ");
        printf("\n=================================");
        printf("\na) Polares a Rectangulares: Presiona 1");
        printf("\nb) Rectanfulares a Polares: Presiona 2");
        printf("\ne) Salir: Presiona 3");
        printf("\nSeleccione una opcion: ");
        if (scanf("%i", &c) != 1){
            while (getchar() != '\n');
            c = 0;   
        }

        switch (c)
        {
        case 1:
            ConversionRec();
            break;
        case 2:
            ConversionPolares();
            break;
        case 3:
            printf("Saliendo del programa.");
            break;
        default:
            printf("Entrada invalida");
            break;
        }
        
    } while (c != 3);
    return 0;
}