#include<stdio.h>

int main(){

    int c;
    int n=0;
    int numP[100];

    for(c=1; c<=100; c++){

        if((c==2 ||c==3 || c==5 || c==7)||(c%2!=0 && c%3!=0 && c%5!=0 && c%7!=0)){
            numP[n] = c;
            c++;
        }

        printf("%d\t",numP[n]);
    }
return 0;    
}