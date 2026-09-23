#include<stdio.h>

int main(){

    int num[100];
    int n;
    int c=0;

    for(n=1; n<=100; n++){

        if(n%2!=0 && n%7==0){
            num[c] = n;
            printf("%d\t", num[c]);
            c++;
        }
    }

    printf("\nTotal: %d\n", c);

    return 0;
}