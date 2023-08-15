/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
// Somar duas matrizes 2x2  (inteiros) e guardar em resultado escrever na tela;

void escreverMatriz(int matriz[3][3])
{
   int i, j;
   for (i = 0; i < 3; i++)
   {
      for (j = 0; j < 3; j++)
      {
         printf("%d ", matriz[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

int main()
{
   int matriz[3][3] = {
       {0, 1, 2},
       {3, 4, 5},
       {6, 7, 8}};
   int corteInicial[2] = {1, 1};
   int corteFinal[2] = {2, 1};
   int i, j, k, l;
   int soma = 0;
   for (i = corteInicial[0]; i <= corteFinal[0]; i++)
   {
      l = 0;
      k = 2;
      if (i == corteInicial[0])
      {
         l = corteInicial[1];
      }
      if (i == corteFinal[0])
      {
         k = corteFinal[1];
      }
      for (j = l; j <= k; j++)
      {
         soma = soma + matriz[i][j];
      }
   }
   escreverMatriz(matriz);
   printf("%d", soma);
   return 0;
}
