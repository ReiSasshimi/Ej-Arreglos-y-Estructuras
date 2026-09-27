#include<stdio.h>

#define CL 5
#define CU 3 
#define Nul -1

typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int A;
    char editorial[100];
    int pag;
    int dis;
    int preA;
}Libro;

typedef struct {
    int id;
    char Nom[100];
    char direc[100];
    char Tel[15];
    int edad;
    int prestamos;
    int libros[3];
}Usuario;

void Datos(Libro libros[], Usuario usuarios[]);
void ConLibros(Libro libros[]);
void ConUsuarios(Usuario usuarios[], Libro libros[]);
void Prestamo(Libro libros[], Usuario usuarios[]);
void Devolucion(Libro libros[], Usuario usuarios[]);

int main(){

    int C;
    Libro Libros [CL];
    Usuario Usuarios[CU];

    Datos(Libros, Usuarios);

    do {
        printf("\n=================================");
        printf("\n    SISTEMA DE BIBLIOTECA");
        printf("\n=================================");
        printf("\na) Prestamo: Presiona 1");
        printf("\nb) Devolucion: Presiona 2");
        printf("\nc) Consulta de libros: Presiona 3");
        printf("\nd) Consulta de usuarios: Presiona 4");
        printf("\ne) Salir: Presiona 5");
        printf("\nSeleccione una opcion: ");
        if (scanf("%d", &C) != 1) {
            while (getchar() != '\n'); 
            C = 0; 
        }
        switch (C) {
            case 1:
                Prestamo(Libros, Usuarios);
                break;
            case 2:
                Devolucion(Libros, Usuarios);
                break;
            case 3:
                ConLibros(Libros);
                break;
            case 4:
                ConUsuarios(Usuarios, Libros);
                break;
            case 5:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion no valida. Intente de nuevo.\n");
        }
    } while (C != 5);

    return 0;
}

void Datos(Libro libros[], Usuario usuarios[]){

    Libro L_datos [CL] = {
        {100,"Crimen y Castigo", "Fiodor Dostoyevski", 1866, "Editores Mexicanos Unidos", 633, 0, 2},
        {101,"El Mito del Sísifo", "Albert Camus", 1942, "Random House", 137, 0, 1 },
        {102,"No tengo boca y debo gritar", "Harlan Ellison", 1967, "Editorial Producciones Editoriales", 154,1, Nul},
        {103,"El psicoanalista", "John Katzenbach", 2002, "Ediciones B", 464, 0, 1 },
        {104,"La guía del ligue", "Gabriel Montiel", 2015, "Penguin Random House", 160, 0, 2}
    };

    Usuario U_datos [CU] = {
        {1, "Diana Carina Vargas Cruz", "Apaxco", "56 5704 3118", 20, 2, {103, 101, Nul}},
        {2, "Jose Torres", "Michoacán", "55 5409 3885", 35, 1, {100, Nul, Nul}},
        {3, "El Fedelobo", "CDMX", "55 8442 1217", 34,1, {104, Nul, Nul }},
    };

    for (int i = 0; i <CL; i++){
        libros[i] = L_datos[i];}

    for (int i = 0; i < CU; i++){
        usuarios[i] = U_datos[i];}       

}

void Prestamo(Libro libros[],Usuario usuarios[]){


    printf("\n=======================================================\n");
    printf("                       PRESTAMOS                         \n");
    printf("=======================================================\n");

    int ID;
    int ID2;

    printf("ingrese su ID:");
    scanf("%d", &ID);

    for (int i = 0; i < CU; i++){
        if (usuarios[i].id == ID){
            if (usuarios[i].prestamos < 3){

                printf("Ingrese el ID del libro solicitado:");
                scanf("%d", &ID2);

                for (int k = 0; k < CL; k++){
                    if (libros[k].id == ID2){
                        if (libros[k].dis == 1){
                            
                            libros[k].dis=0;
                            usuarios[i].prestamos ++;
                            libros[k].preA = usuarios[i].id;

                            for (int j = 0; j < 3; j++){
                                if (usuarios[i].libros[j] == Nul){
                                    usuarios[i].libros[j] = libros[k].id;

                                    printf("Solicitud aceptada. c;\n\n");

                                    break;} 
                            }
                            
                        }else{printf("Libro no disponible\n\n");}
                    }   
                }   
            }else{printf("Limite de prestamos alcanzados\n\n");}   
        }   
    }
}

void Devolucion(Libro libros[], Usuario usuarios[]){

    printf("\n=======================================================\n");
    printf("                       Devolucion                        \n");
    printf("=======================================================\n");

    int ID;
    int devuelto = 0;

    printf("Ingrese el ID del libro a regresar:");
    scanf("%d", &ID);

    for (int i = 0; i < CU; i++){
        for (int k = 0; k < 3; k++){
            if (usuarios[i].libros[k] == ID){
                
                usuarios[i].libros[k] = Nul;
                usuarios[i].prestamos--;
                
                for (int j = 0; j < CL; j++){
                    if (libros[j].id == ID){
                        
                        libros[j].preA = Nul;
                        libros[j].dis = 1;

                        printf("El libro fue devuelto con exito. c;");
                        break;
                    } 
                }

                devuelto = 1;
                break;
            }
        }
        if (devuelto) break;
    }
    if (!devuelto) {                                 
        printf("\nError: El libro con ID %d no se encuentra registrado como prestado.\n", ID);}
}

void ConLibros(Libro libros[]){

    printf("\n=======================================================\n");
    printf("                   CONSULTA DE LIBROS                    \n");
    printf("=======================================================\n");

    for (int i = 0; i < CL; i++) {
        printf("Libro\t %d:\n", i + 1);
        printf("ID:\t  %d\n", libros[i].id);
        printf("Titulo:\t  %s\n", libros[i].titulo);
        printf("Autor:\t  %s\n", libros[i].autor);
        printf("Año:\t  %d\n", libros[i].A);
        printf("Editorial:\t  %s\n", libros[i].editorial);
        printf("Paginas:\t  %d\n", libros[i].pag);
        
        if (libros[i].dis == 1) {
            printf("Disponibilidad: DISPONIBLE (1)\n");
        } else {
            printf("Disponibilidad: PRESTADO (0)\n");
            printf("Prestado a:     Usuario ID %d\n", libros[i].preA);
        }
        
        printf("\n\n");
    }
}


void ConUsuarios(Usuario usuarios[], Libro libros[]){

    int ID;

     printf("\n=======================================================\n");
    printf("                    CONSULTA DE USUARIOS                  \n");
    printf("=======================================================\n");

    printf("Ingrese su ID:");
    scanf("%d", &ID);

    for (int i = 0; i < CU; i++) {
        if (usuarios[i].id == ID) {
            printf("ID:\t  %d\n", usuarios[i].id);
            printf("Nombre:\t  %s\n", usuarios[i].Nom);
            
            if (usuarios[i].prestamos > 0) {
                printf("Usuario con prestamo de:\n");

                for (int n = 0; n < 3; n++) {
                    int id_libro = usuarios[i].libros[n];
                    if (id_libro != Nul) {
                        for (int k = 0; k < CL; k++) {
                            if (libros[k].id == id_libro) {
                                printf(" ID: %d\t  Titulo: \"%s\"\n", libros[k].id, libros[k].titulo);
                                break;  
                            }
                        }
                    }
                }
            } else {printf("El usuario no tiene prestamos vigentes.\n");}

            return; // Finaliza la búsqueda al encontrar al usuario
        }
    }
}