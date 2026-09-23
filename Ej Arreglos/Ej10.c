#include<stdio.h>
#include<string.h>

int main(){

    int op, val, i, j, dec=0, len, p;
    char hex[20];
    int arr[32];

    printf("1. Dec a Bin\n2. Bin a Dec\n3. Dec a Oct\n4. Oct a Dec\n5. Dec a Hex\n6. Hex a Dec\nOpcion: ");
    scanf("%d", &op);

    if(op==1 || op==3 || op==5){
        printf("Numero decimal: ");
        scanf("%d", &val);
        int base = (op==1)? 2 : (op==3)? 8 : 16;
        i = 0;
        if(val==0) printf("0\n");
        while(val>0){
            arr[i++] = val % base;
            val /= base;
        }
        printf("Resultado: ");
        for(j=i-1; j>=0; j--){
            if(arr[j]<10) printf("%d", arr[j]);
            else printf("%c", 'A' + arr[j] - 10);
        }
        printf("\n");
    }else if(op==2 || op==4){
        printf("Numero (Bin/Oct): ");
        scanf("%d", &val);
        int base = (op==2)? 2 : 8;
        p = 1;
        while(val>0){
            dec += (val%10)*p;
            val /= 10;
            p *= base;
        }
        printf("Resultado decimal: %d\n", dec);
    }else if(op==6){
        printf("Numero hexadecimal: ");
        scanf("%s", hex);
        len = strlen(hex);
        p = 1;
        for(i=len-1; i>=0; i--){
            if(hex[i]>='0' && hex[i]<='9') dec += (hex[i]-'0')*p;
            else if(hex[i]>='A' && hex[i]<='F') dec += (hex[i]-'A'+10)*p;
            else if(hex[i]>='a' && hex[i]<='f') dec += (hex[i]-'a'+10)*p;
            p *= 16;
        }
        printf("Resultado decimal: %d\n", dec);
    }

    return 0;
}