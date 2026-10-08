#include<stdio.h>

void FarenC(){

    float C, F;

    printf("Ingrese la temperatura en Farenheit:");
    scanf("%f", &F);

    C = (F-32)/1.8;

    printf("%3f Farenheit son %3f Celsius.",F,C);
}

void CelsiusF(){
     float F, C;

    printf("Ingrese la temperatura en Celsius:");
    scanf("%f", &C);

    F =(C*1.8)-32;

    printf("%3f Celsius son %3fFarenheit.",C,F);
}

void CelsiusK(){

    float C, K;

    printf("Ingrese la temperatura en Celsius:");
    scanf("%f", &C);

    K = C +273.15;

    printf("%3f Celsius son %3f Kelvin",C,K);
}

void KelvinC(){

    float K,C;

    printf("Ingrese la temperatura en Kelvin:");
    scanf("%f",K);

    C = K - 273.15;

    printf("%3f Kelvin son %3f", K,C);
}
   