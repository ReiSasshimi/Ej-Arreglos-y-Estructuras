#include<stdio.h>

int main(){

    int num[10];
    int i, j, aux;

    for(i=0; i<10; i++){
        printf("Ingrese numero %d: ", i+1);
        scanf("%d", &num[i]);
    }

    for(i=0; i<9; i++){
        for(j=i+1; j<10; j++){
            if(num[i] > num[j]){
                aux = num[i];
                num[i] = num[j];
                num[j] = aux;
            }
        }
    }

    printf("\nOrden ascendente:\n");
    for(i=0; i<10; i++){
        printf("%d\t", num[i]);
    }
    printf("\n");

    return 0;
}