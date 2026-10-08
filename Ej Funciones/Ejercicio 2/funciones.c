#include "Matrices.h"

void SMatrices(){

    Matriz A;
    Matriz B;
    Matriz C;

    //Verificar operacion
    printf("Ingrese el tamaño de la matriz A (n m):" );
    scanf("%i %i",&A.fil, &A.col);

    printf("Ingrese el tamaño de la matriz B (n m):");
    scanf("%i %i",&B.fil, &B.col);

    if (A.col > Max || B.col > Max || A.fil > Max || B.fil >Max ){
        printf("Tamaño de Matriz mayor al limite");
        return ;}

    if (A.col != B.col || A.fil != B.fil){
        printf("Operación invalida Matrices de tamaño diferentes");
        return ;}

    //Guardar Matrices
    printf("Ingrese los %d elementos de A:\n", A.fil * A.col);
    for (int i = 0; i < A.fil; i++) {
        for (int j = 0; j < A.col; j++) {
            scanf("%d", &A.Matriz[i][j]);}
    }

    printf("Ingrese los %d elementos de B:\n", B.fil * B.col);
    for (int i = 0; i < B.fil; i++) {
        for (int j = 0; j < B.col; j++) {
            scanf("%d", &B.Matriz[i][j]);}
    }
    
    //Operacion de suma
    C.col = A.col;
    C.fil = A.fil;

     for (int i = 0; i < C.fil; i++) {
        for (int j = 0; j < C.col; j++) {
            C.Matriz[i][j] = A.Matriz[i][j] + B.Matriz[i][j];}
    }

    printf("\n--- Matriz C (Resultado A + B) ---\n");
    for (int i = 0; i < C.fil; i++) {
        for (int j = 0; j < C.col; j++) {
            printf("%4d ", C.Matriz[i][j]);}
        printf("\n");
    }
}

void PMatrices(){
    
    Matriz A;
    Matriz B;
    Matriz C;

    //Verificar operacion
    printf("Ingrese el tamaño de la matriz A (n m):" );
    scanf("%i %i",&A.fil, &A.col);

    printf("Ingrese el tamaño de la matriz B (n m):");
    scanf("%i %i",&B.fil, &B.col);

    if (A.col > Max || B.col > Max || A.fil > Max || B.fil >Max ){
        printf("Tamaño de Matriz mayor al limite");
        return ;}

    if (A.col != B.fil ){
        printf("Operación invalida Matrices Col A != Fil B");
        return ;}

     //Guardar Matrices
    printf("Ingrese los %d elementos de A:\n", A.fil * A.col);
    for (int i = 0; i < A.fil; i++) {
        for (int j = 0; j < A.col; j++) {
            scanf("%d", &A.Matriz[i][j]);}
    }

    printf("Ingrese los %d elementos de B:\n", B.fil * B.col);
    for (int i = 0; i < B.fil; i++) {
        for (int j = 0; j < B.col; j++) {
            scanf("%d", &B.Matriz[i][j]);}
    }

    //Operacion de producto
    C.fil = A.fil;
    C.col = B.col;

    for (int i = 0; i < C.fil; i++) {
        for (int j = 0; j < C.col; j++) {
            C.Matriz[i][j] = 0;
            for (int k = 0; k < A.col; k++) {
                C.Matriz[i][j] += A.Matriz[i][k] * B.Matriz[k][j];}
        }
    }

    printf("\n--- Matriz C (Resultado A * B) [%dx%d] ---\n", C.fil, C.col);
    for (int i = 0; i < C.fil; i++) {
        for (int j = 0; j < C.col; j++) {
            printf("%4d ", C.Matriz[i][j]);}
        printf("\n");
    }
}

void SEMatrices(){
    Matriz A;
    int suma = 0;

    //Verificar operacion
    printf("Ingrese el tamaño de la matriz A (n m):");
    scanf("%i %i",&A.fil, &A.col);

    if (A.col > Max || A.fil > Max){
        printf("Tamaño de Matriz mayor al limite");
        return ;}

    //Guardar Matriz
    printf("Ingrese los %d elementos de A:\n", A.fil * A.col);
    for (int i = 0; i < A.fil; i++) {
        for (int j = 0; j < A.col; j++) {
            scanf("%d", &A.Matriz[i][j]);}
    }

    //Operacion de suma de elementos
    for (int i = 0; i < A.fil; i++) {
        for (int j = 0; j < A.col; j++) {
            suma += A.Matriz[i][j];}
    }

    printf("\n--- Suma de elementos de la Matriz A ---\n");
    printf("La suma total de los elementos es: %d\n", suma);
}