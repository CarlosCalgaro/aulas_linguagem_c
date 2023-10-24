#include <stdlib.h>
#include <stdio.h>


int main(){
    int n;
    printf("Digite o numero N: \n");
    scanf("%d", &n);

    printf("%d", n);
    // O numero primo so eh divisivel por 1 e ele mesmo

    int achouPrimo = 0;
    int i;
    // 10 - 1 SIM 10- SIM 2 - SIM // NAO EH PRIMO#

    if( n == 1){ n+= 1; }
    if( n < 1){ printf("INVALIDO!"); }
    while(achouPrimo == 0){
        achouPrimo = 1;
        for(i = 2; i < n; i++){
            if(n % i == 0){ 
                achouPrimo = 0;
                i = n + 1;
            }
        }
        if(achouPrimo == 0){
            n++;
        }
    }
    printf("\n\nPRIMO: %d\n\n", n);
    return 0;
}