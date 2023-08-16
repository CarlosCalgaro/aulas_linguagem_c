
//
// Created by Carlos Calgaro on 16/08/2023.
//
/*
Uma matriz é dita Circulante cada elemento é igual ao elemento imediatamente acima à esquerda, 
e se o primeiro elemento de cada coluna é igual ao último elemento da coluna anterior. 
Assim, um exemplo de Matriz Circulante é:

1 9 7 8 2
2 1 9 7 8
8 2 1 9 7
7 8 2 1 9
9 7 8 2 1

Faça um algoritmo que leia uma matriz M[1..5,1..5] e verifique se é uma Matriz Circulante, 
escrevendo: 1 - Se é uma matriz Circulante; 
0 - Se não é uma matriz Circulante

*/
#include <stdio.h>

#define TAMANHO 5

int main()
{
    int matriz[TAMANHO][TAMANHO] = {
            {1, 9, 7, 8, 2},
            {2, 1, 9, 7, 8},
            {8, 2, 1, 9, 7},
            {7, 8, 2, 1, 9},
            {9, 7, 8, 2, 1}
    };
    int ehCircular = 1;
    int linha, coluna;
    for(linha = 0; linha < TAMANHO; linha ++){
        for(coluna = 0; coluna < TAMANHO; coluna ++){
            int linhaTeste = linha - 1;
            int colunaTeste = coluna - 1;
            if(linhaTeste < 0){ linhaTeste = TAMANHO - 1; }
            if(colunaTeste < 0){ colunaTeste = TAMANHO - 1; }

            if(matriz[linhaTeste][colunaTeste] != matriz[linha][coluna]){
                ehCircular = 0;
            }
        }
    }

    if(ehCircular){
        printf("CIRCULAR");
    }else{
        printf("NAO CIRCULAR");

    }
    return 0;
}