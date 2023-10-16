/**
 * 1) Faça um programa que leia um valor n e crie dinamicamente uma matriz de n 
 * elementos e passe esse vetor para uma função que vai ler os elementos 
 * desse vetor. 
 * Depois, no programa principal, o vetor preenchido deve ser impresso. 
 * Além disso, antes de finalizar o programa, 
 * deve-se liberar a área de memória alocada.  
 **/
 #include <stdio.h>
 #include <stdlib.h>

void lerValor(int ** matriz, int linhas, int colunas){
    int i, j;
    int valorLido;
    for(i=0; i < linhas; i++){
      for(j=0; j < colunas; j++){
        printf("Escreva o valor de matriz[%d][%d]", i, j);
        scanf("%d", &valorLido);
        matriz[i][j] = valorLido;
      }  
    }
}

int main(){
    
  int linhas; // Tamanho das linhas e colunas;
  int colunas;
  printf("Digite o numero de linhas: \n");
  scanf("%d", &linhas);
  printf("Digite o numero de colunas: \n");
  scanf("%d", &colunas);
  
  int** matriz = (int**)calloc(linhas, sizeof(int*));
  int i = 0;
  
  for(i = 0; i < colunas; i++){
    matriz[i] = (int*) calloc(colunas, sizeof(int));
  }
  
  lerValor(matriz, linhas, colunas);
  
  int j;
   for(i=0; i < linhas; i++){
      for(j=0; j < colunas; j++){
       printf("%d - ", matriz[i][j]);
      }
      printf("\n");
    }
}