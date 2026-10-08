#include<stdio.h>

void CelsiusF();
void FarenC();
void CelsiusK();
void KelvinC();

int main(){

    int c;

    do
    {
        printf("\n============================");
        printf("\n  Conversion de temperatura ");
        printf("\n============================");
        printf("\na) Celsius a Farenheit: Presiona 1");
        printf("\nb) Farenheit a Celsius: Presiona 2");
        printf("\nc) Celsius a Kelvin: Presiona 3");
        printf("\nd) Kelvin a Celsius: Presiona 4");
        printf("\ne) Salir: Presiona 5\n");

        if (scanf("%d", &c) != 1) {
            while (getchar() != '\n'); 
            c = 0; }

        switch (c){
        case 1:
            CelsiusF();
            break;
        case 2:
            FarenC();
            break;
        case 3:
            CelsiusK();
            break;
        case 4:
            KelvinC();
            break;
        case 5:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("\nOpcion invalida. Intente de nuevo");
            break;
        }
    } while (c != 5);
return 0;
}
