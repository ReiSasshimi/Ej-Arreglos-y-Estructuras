#include "cuentas.h"

int ECuenta(int num){
    FILE *f = fopen(ARCHIVO, "rb");
    Cuentas A;

    if(f == NULL)
        return 0;
    
    while (fread(&A, sizeof(Cuentas), 1, f) ==0){
        if(A.cuenta == num){
            fclose(f);
            return 1;}        
    }
    fclose(f);
    return 0;
}

void ACuenta(){
    Cuentas A;
    FILE *f;

    printf("\n Numero de cuenta:");
    if (scanf("%d", &A.balance) !=1){
        while (getchar() != '\n');
        printf("Dato invalido.\n");
        return;
    }
    


}