#include<stdio.h>

int main(){

    int A[10], B[10];
    int i, j;

    printf("Elementos del primer conjunto:\n");
    for(i=0; i<10; i++) scanf("%d", &A[i]);

    printf("Elementos del segundo conjunto:\n");
    for(i=0; i<10; i++) scanf("%d", &B[i]);

    printf("\nElementos en comun:\n");
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(A[i] == B[j]){
                printf("%d\t", A[i]);
                break;
            }
        }
    }
    printf("\n");

    return 0;
}