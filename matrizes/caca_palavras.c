#include <stdio.h>
#include <strings.h>
#define N 3
#define LINHA 4
#define COLUNA 4

/**
Direcao:
0 - Pra cima
1 - Pra baixo
2 - Esquerda
3 - Direita

retorno: 0 falso, 1 verdadeiro
*/
int procuraPalavra(char matriz[][4], char palavra[3], int pontoInicial[2],
                   int direcao) {
  int retorno = 1;
  int operadorLinha = 0;
  int operadorColuna = 0;
  int linha, coluna, i;
  linha = pontoInicial[0];
  coluna = pontoInicial[1];
  if (direcao == 0) {
    operadorLinha = -1;
  } else if (direcao == 1) {
    operadorLinha = 1;
  } else if (direcao == 2) {
    operadorColuna = -1;
  } else if (direcao == 3) {
    operadorColuna = 1;
  }

  for (i = 0; i < N; i++) {
    if ((linha < 0 || linha >= LINHA) || (coluna < 0 || coluna >= COLUNA)) {
      return 0;
    }
    if (palavra[i] != matriz[linha][coluna]) {
      return 0;
    }
    linha += operadorLinha;
    coluna += operadorColuna;
  }
  return 1;
};

int main() {
  char matriz[LINHA][COLUNA] = {
      {'v', 'i', 'i', 'j'},
      {'a', 'a', 'a', 'j'},
      {'a', 'v', 'a', 'j'},
      {'a', 'b', 'c', 'j'}
  };
  char palavra[N] = {'v', 'a', 'i'};
  int indiceLetra[2] = {0, 0};
  int pontoInicial[2];
  int i, j, direcao, retorno;
  j = indiceLetra[1];
  for (i = indiceLetra[0]; i < 4; i++) {
    while (j < 4) {
      pontoInicial[0] = i;
      pontoInicial[1] = j;
      for(direcao = 0; direcao < 4; direcao++){
        retorno = procuraPalavra(matriz, palavra, pontoInicial, direcao);
        if(retorno == 1){
          printf("Achou! em %d, %d - Direcao: %d", i, j, direcao);
          return 0;
        }
      }
      j++;
    }
    j = 0;
  }
  printf("Nao achou!");
}
