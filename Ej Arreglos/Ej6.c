#include<stdio.h>

int main(){

    int num[10];
    int i, busqueda, enco=0;

    for(i=0; i<10; i++){
        printf("Ingrese numero %d: ", i+1);
        scanf("%d", &num[i]);
    }

    printf("\nNumero a buscar: ");
    scanf("%d", &busqueda);

    for(i=0; i<10; i++){
        if(num[i] == busqueda){
            printf("El numero %d esta en la posicion %d\n", busqueda, i);
            enco = 1;
        }
    }

    if(!enco){
        printf("El numero no se encuentra en el arreglo.\n");
    }

    return 0;
}