#include<stdio.h>


typedef struct{
    int P[11];
    int gr;
    int PP[100];
} Polinomio;

int main(){

    Polinomio p1 = {0};

    printf("Ingrese el grado del primer polinomio:");
    scanf("%d", &p1.gr);

    for ( int i = p1.gr; i>=0 ; i--){
        printf("Ingrese el coeficiente de x^%d:\t",i);
        scanf("%d", &p1.P[i]);
    }

    Polinomio p2 = {0};

    printf("Ingrese el grado del segundo polinomio:\t");
    scanf("%d", &p2.gr);

    for ( int i = p2.gr; i>=0 ; i--){
        printf("Ingrese el coeficiente de x^%d:\t",i);
        scanf("%d", &p2.P[i]);
    }

    //Suma

    Polinomio ps = {0};

    for (int i = 10; i>=0; i--){
        ps.P[i]= p1.P[i] + p2.P[i];}

    printf("La suma de los polinomios es:\n");

    for (int i = 10; i>=0 ; i--){
        if (ps.P[i] != 0){
            printf("%d x^%d\t",ps.P[i],i );}
    }

    //Producto

    Polinomio pp = {0}; 

    for (int i = p1.gr; i >= 0; i--) {
        for (int j = p2.gr; j >= 0; j--) {10
            pp.PP[i + j] += p1.P[i] * p2.P[j];
        }
    }

    pp.gr = p1.gr + p2.gr;

    printf("\nEl producto de los polinomios es:\n");
    for (int k = pp.gr; k >= 0; k--) {
        if (pp.PP[k] != 0) {
            printf("%d x^%d\t", pp.PP[k], k);
        }
    }
    printf("\n");     
}