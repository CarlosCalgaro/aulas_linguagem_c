/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define TAMANHO 5

void escreverMatriz(int matriz[TAMANHO][TAMANHO])
{
   int a;
   int linha, coluna;
   for (linha = 0; linha < TAMANHO; linha++)
   {
      for (coluna = 0; coluna < TAMANHO; coluna++)
      {
         printf("%d ", matriz[linha][coluna]);
      }
      printf("\n");
   }
}

void lerMatriz(int matriz[TAMANHO][TAMANHO])
{
   int linha, coluna;
   for (linha = 0; linha < TAMANHO; linha++)
   {
      for (coluna = 0; coluna < TAMANHO; coluna++)
      {
         printf("Digite numero: ");
         scanf("%d", &matriz[linha][coluna]);
      }
   }
}

int main()
{
   int matriz[TAMANHO][TAMANHO] = {
       {1, 2, 3, 4, 5},
       {-3, -4, 10, 11, 5},
       {4, 5, 6, 5, 6},
       {-5, 6, 7, 8, 9},
       {2, 6, 8, 9, 9}};

   escreverMatriz(matriz);
   printf("\n");

   int linha, i;
   int temTroca = 0;
   for (i = 0; i < TAMANHO; i++)
   {
      for (linha = 0; linha < TAMANHO - 1; linha++)
      {
         if (abs(matriz[linha][0]) < abs(matriz[linha + 1][0]))
         {
            temTroca = 1;
            int aux[TAMANHO];
            int j;
            for (j = 0; j < (TAMANHO); j++)
            {
               aux[j] = matriz[linha][j];
               matriz[linha][j] = matriz[linha + 1][j];
               matriz[linha + 1][j] = aux[j];
            }
         }
      }
      if (temTroca == 0)
      {
         i = 9999;
      }
   }

   escreverMatriz(matriz);
   return 0;
}