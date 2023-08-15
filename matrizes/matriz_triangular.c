/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
/**
Faça um algoritmo que leia uma matriz M[1..5,1..5] e escreva:
0 - Se a matriz é uma matriz diagonal;
1 - Se é triangular superior;
2- Se é triangular inferior;
3 - Se não é nenhuma das anteriores
*/
#define TAMANHO 5
int main()
{

   int matriz[TAMANHO][TAMANHO] = {
       {1, 2, 3, 4, 5},
       {4, 5, 6, 5, 6},
       {7, 8, 9, 6, 7},
       {7, 8, 9, 6, 7},
       {7, 8, 9, 6, 7}};
   int superiorNaoNulo = 0;
   int inferiorNaoNulo = 0;
   int centroNaoNulo = 0;
   int linha, coluna;
   for (linha = 0; linha < TAMANHO; linha++)
   {
      for (coluna = 0; coluna < TAMANHO; coluna++)
      {
         if (linha == coluna && matriz[linha][coluna] != 0)
         {
            centroNaoNulo = 1;
         }
         else if (linha > coluna && matriz[linha][coluna] != 0)
         {
            inferiorNaoNulo = 1;
         }
         else if (linha < coluna && matriz[linha][coluna] != 0)
         {
            superiorNaoNulo = 1;
         }
      }
   }
   if (centroNaoNulo == 1 && superiorNaoNulo == 0 && inferiorNaoNulo == 0)
   {
      /*
         E uma matriz é dita diagonal se os elementos não nulos ocorrem somente na diagonal principal.
      */
      printf("0 - Matriz Diagonal");
   }
   else if (centroNaoNulo == 1 && inferiorNaoNulo == 0 && superiorNaoNulo == 1)
   {
      /*
      Uma matriz é dita triangular superior se todos os elementos abaixo da diagonal principal
      são iguais a zero, e há pelo menos um elemento não nulo acima da diagonal principal.
      */
      printf("1 - Triangula Superior");
   }
   else if (centroNaoNulo == 1 && inferiorNaoNulo == 1 && superiorNaoNulo == 0)
   {
      /*
      uma matriz é dita triangular inferior se todos os elementos acima da diagonal
      principal são iguais a zero, e há pelo menos um elemento não nulo abaixo da diagonal principal.
      */
      printf("2 - Triangula Inferior");
   }
   else
   {
      printf("3 - Nenhuma das anteriores");
   }
   return 0;
}
