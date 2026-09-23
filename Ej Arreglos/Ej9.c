#include<stdio.h>

int main(){

    int num[10];
    int i=0, j, val, rep;

    while(i<10){
        printf("Ingrese numero %d: ", i+1);
        scanf("%d", &val);

        rep = 0;
        for(j=0; j<i; j++){
            if(num[j] == val){
                rep = 1;
                break;
            }
        }

        if(rep){
            printf("El valor ya existe en el arreglo, intente de nuevo.\n");
        }else{
            num[i] = val;
            i++;
        }
    }

    printf("\nArreglo final:\n");
    for(i=0; i<10; i++) printf("%d\t", num[i]);
    printf("\n");

    return 0;
}