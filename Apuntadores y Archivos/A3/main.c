#include "Huracanes.h"

int main(){
    int C;

    do{
        printf("=====================\n");
        printf("      Huracanes      \n");
        printf("=====================\n");
        printf("\n");
        printf("1)   Ingresar Huracan\n");
        printf("2)          Modificar\n");
        printf("3)           Eliminar\n");
        printf("4)           Reportes\n");
        printf("5)              Salir\n");
        printf("\n");
        printf("Seleccione su opcion:");

        if (scanf("%d", &C) != 1) {
            while (getchar() != '\n'); 
            C = 0; }

        switch (C){
        case 1:
            IngresarH();
            break;
        case 2:
            ModificarH();
        
        default:
            break;
        }


    } while (C !=5);
    
}