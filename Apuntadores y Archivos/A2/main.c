#include "cuentas.h"

int main(){

    int c, opReporte;

    do{
        printf("================================\n");
        printf("   \n");
        printf("================================\n");
        printf("Agregar Cuenta   presione 1\n");
        printf("Reportes         presione 2\n");
        printf("Salir            presione 3\n");
    } while (c != 3);
    scanf("%d",&c);

    switch (c){
    case 1:

        break;
    case 2:
           do {
                opReporte = menu2();
 
                if (opReporte >= 1 && opReporte <= 4)
                       ReporteG(opReporte);
                else if (opReporte != 5)
                        printf("Opcion invalida.\n");
 
           } while (opReporte != 5);   
         break;

    case 3:
        return 0;
    default:
        printf("Opcion invalida\n");
        break;
    } 
}

int menu2(){

    int op;
    printf("===========\n");
    printf(" REPORTES\n");
    printf("============\n");
    printf("\n");
    printf("1) Cuentas con balance 0\n");
    printf("2) Cuentas con balance de credito (balance < 0)\n");
    printf("3) Cuentas con balance de debito (balance > 0)\n");
    printf("4) Reporte general\n");
    printf("5) Salir\n");
    printf("Opcion: ");
    if (scanf("%d", &op) != 1) {
        while (getchar() != '\n');
        return 0;
    }
    return op;
}
