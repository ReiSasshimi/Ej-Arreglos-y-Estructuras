#include "Huracanes.h"

void IngresarH(){
    FILE *AB ;
    Huracan A;

    if ((AB = fopen(ARCHIVO, "ab")) == NULL){
        printf("ERROR no se pudo abrir el archivo.");
        return;}
    
    printf("\n======Ingresa el huracan====== \n");

    printf("Ingrese la categoria (1 a 5): ");
    scanf("%d", &A.categoria);

    printf("Ingrese la fecha de clasificacion: ");
    scanf(" %[^\n]", A.fecha);

    printf("Ingrese el tamano (radio en grados latitud o km): ");
    scanf("%f", &A.tamaño);

    printf("Ingrese el origen (coordenadas geograficas): ");
    scanf(" %[^\n]", A.origen);

    printf("Ingrese la velocidad maxima: ");
    scanf("%f", &A.velocidad_max);

    printf("Ingrese el nombre del huracan: ");
    scanf(" %[^\n]", A.nombre);

    fwrite(&A, sizeof(Huracan), 1, AB);

    if (ferror(AB)) {
        printf("ERROR: Ocurrio un problema al guardar los datos en el archivo.\n");}
    else {
        printf("¡Huracan guardado con exito en el archivo!\n"); }

    fclose(AB);
}
    
void ModificarH(){
    FILE *AB;
    Huracan A;

    char NombreB[50];
    int Encontrado;

    if ((AB = fopen(ARCHIVO, "r+b")) == NULL){
        printf("ERROR no se pudo abrir el archivo.");
        return;}

    printf("\n=======Modificar datos del huracan======\n");

    printf("Ingrese el Nombre del Huracan a modificar:");
    scanf(" %[^\n]", NombreB);

    while (fread(&A, sizeof(Huracan),1, AB) == 1){
        if (strcmp(NombreB, A.nombre) == 0){ // Strcmp compara dos cadeanas
            
            printf("Nueva categoria");
            scanf("%d",A.categoria);

            printf("Ingrese la fecha de clasificacion: ");
            scanf(" %[^\n]", A.fecha);

            printf("Ingrese el tamano (radio en grados latitud o km): ");
            scanf("%f", &A.tamaño);

            printf("Ingrese el origen (coordenadas geograficas): ");
            scanf(" %[^\n]", A.origen);

            printf("Ingrese la velocidad maxima: ");
            scanf("%f", &A.velocidad_max);

            printf("Ingrese el nombre del huracan: ");
            scanf(" %[^\n]", A.nombre);

            fseek(AB, -sizeof(Huracan), SEEK_CUR); //Puntero del archivo, tamaño, donde mover el puntero "seek_cur" dejara el puntero en su posocion actual

            fwrite(&A, sizeof(Huracan), 1, AB);

            Encontrado = 1;
            printf("Datos del huracan modificado");
        break;
        } 
    }
    
    if(!Encontrado)
    printf("Huracan no encontrado.");

    fclose(AB);
}

void EliminarH(){
    FILE *AB;
    Huracan A;

    int HuracanE;

    if (AB = fopen(ARCHIVO,"r+b") == NULL){
        printf("ERROR  no se pudo abiri el archivo.");
        return;}

    printf("Ingresa el nombre del Huracan a eliminar:");
    scanf("%[^\n]",&HuracanE);

    while (fread(&A, sizeof(Huracan), 1, AB) == 1){
        if (strcmp(HuracanE, A.nombre) == 0){
            
            Huracan A[] = 0;
        }
        
    }
    
    

}
