#include "Matrices.h"

int main(){

    int C;

    do {
        printf("\n=================================");
        printf("\n    Operaciones Matriciales      ");
        printf("\n=================================");
        printf("\na) Suma de Matrices: Presiona 1");
        printf("\nb) Producto de matrices: Presiona 2");
        printf("\nc) Suma de elementos de Matrices: Presiona 3");
        printf("\ne) Salir: Presiona 5");
        printf("\nSeleccione una opcion: ");
        if (scanf("%d", &C) != 1) {
            while (getchar() != '\n'); 
            C = 0; 
        }
        switch (C) {
            case 1:
                SMatrices();
                break;
            case 2:
                PMatrices();
                break;
            case 3:
                SEMatrices();
                break;
            case 5:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion no valida. Intente de nuevo.\n");
        }
    } while (C != 5);
    return 0;
}