/******************************************************************************
exercicio 6 da lista 2 de string:

Faça programa em C que recebe um string de até 1000 caracteres contendo um texto
no qual as palavras são separadas pelo caractere '#' que é seguido por um valor
que identifica o número de espaços em brancos a serem inseridos pela função. O
programa deverá substituir o caractere '#' e o valor pelos número de espaços
definidos. Por exemplo, se o string original contém:

Isto#4é#5uma#6pequena#1frase.
após a chamada o string ficará:

Isto    é      uma      pequena frase.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 1000
/*----------------------------------------------------------------------------*/
void separa(char frase[N], char str[N]) {
  int i, j, k;
  int num;
  k = 0;
  for(i = 0; frase[i] != '\0';){
    if(frase[i] == '#'){
      i++;
      num = 0;
      while(frase[i] >= '0' && frase[i] <='9'){
        num = num * 10 + (frase[i] - '0');
        i++;
      }
      for(j = 0; j < num; j++){
        str[k] = ' ';
        k++;
      }
    }else{
      str[k] = frase[i];
      k++;
      i++;
    }
  }
  str[k]= '\0';
}
/*----------------------------------------------------------------------------*/
int main() {
  char frase[N] = "Isto#4é#5uma#6pequena#1frase";
  char frase2[N];

  separa(frase, frase2);

  printf("Separado: %s", frase2);

  return 0;
}