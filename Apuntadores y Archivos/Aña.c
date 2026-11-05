#include <stdio.h>
#include <string.h>

#define Mx 50

typedef struct{
    int  cuenta;
    char nombre[Mx];
    float balance;
}Cuentas;

int menu2(void);
int GCuenta();
void ReporteG(int tipo);
int ECuenta(int num); //evitar que se sobreescriba una misma cuenta
void TBalance(FILE *f, FILE *AR, int tipo, int *cuentasT, float *BalanceT);

//Archivo
#define ARCHIVO "cuentas.dat"
#define ARCHIVOR "Reporte.txt"

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
        GCuenta();
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
        printf("Saliendo del Programa.");
        return 0;
    default:
        printf("Opcion invalida\n");
        break;
    } }

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


int GCuenta(){
    Cuentas A;
    FILE *f;  //Declara el archivo

    printf("\n Numero de cuenta:");
    if (scanf("%d", &A.cuenta) !=1){
        while (getchar() != '\n');
        printf("Dato invalido.\n");
        return 0;
    }

    if (ECuenta(A.cuenta)){
        printf("Cuenta ya existencia");
        return 0;
    }

    printf("Nombre del titular:");
    scanf("%c",&A.nombre);

    printf("Ingrese el balance:");
    if (scanf("%d", &A.balance) !=1){
        while (getchar() != '\n');
        printf("Dato invalido.\n");
        return 0;
    }

    f = fopen(ARCHIVO, "ab"); //Abre el archivo
    if (f==NULL){
        printf("No se logro general el archivo.");
        return 0;
    }

    fwrite(&A, sizeof(Cuentas),1,f); //escribe en el archivo

    fclose(f);
    printf("Cuenta guardada.\n");
    return 1;
}

void TBalance(FILE *f, FILE *AR, int tipo, int *cuentasT, float *BalanceT){
    Cuentas A;

    if(fread(&A, sizeof(Cuentas), 1, f) != 1){
        return;
    }

    int incluir = 0;
    if(tipo == 1 && A.balance == 0) incluir = 1;
    else if(tipo == 2 &&A.balance < 0) incluir = 1;
    else if(tipo == 3 &&A.balance > 0) incluir = 1;
    else if(tipo == 4) incluir = 1;

    if (incluir){
         float BalanceT += A.balance;
        fprintf(AR, "%d \t %s\t %.2f\n", A.cuenta, A.nombre, A.balance);
        printf("%d \t %s\t %.2f\n", A.cuenta, A.nombre, A.balance);
    }
    
    TBalance(f,AR,tipo,cuentasT,BalanceT);
}

void ReporteG(int tipo){
    FILE *f = fopen(ARCHIVO, "rb");
    FILE *AR = fopen(ARCHIVOR, "w"); 
    int totalCuentas = 0;
    float balanceTotal = 0;

    if (f == NULL){
        printf("Error al abrir el archivo de cuentas (o esta vacio).\n");
        if (AR) fclose(AR);
        return;
    }
    if (AR == NULL){
        printf("Error al crear el archivo de reporte.\n");
        fclose(f);
        return;
    }

    switch(tipo){
        case 1:
            fprintf(AR, "Reporte de cuentas con balance 0\n");
            break;
        case 2:
            fprintf(AR, "Reporte de cuentas con balance de credito\n");
            break;
        case 3:
            fprintf(AR, "Reporte de cuentas con balance de debito\n");
            break;
        case 4:
            fprintf(AR, "Reporte general\n");
            break;
    }

    fprintf(AR, "No. cuenta \t Nombre \t Balance\n");
    fprintf(AR, "----------------------------------------\n");

  
    TBalance(f,AR, tipo,BalanceT);


    if (tipo == 2 || tipo == 3 || tipo == 4) {
        fprintf(AR, "Balance total: %.2f\n", balanceTotal);
    }

    fclose(f);
    fclose(AR);
    printf("\n[Reporte guardado exitosamente en '%s']\n\n", ARCHIVOR);
}