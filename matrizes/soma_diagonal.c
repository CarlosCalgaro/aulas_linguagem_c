/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{

   int matriz[3][3] = {
       {1, 2, 3},
       {4, 5, 6},
       {7, 8, 9}};
   int soma = 0;
   int linha, coluna;
   for (linha = 0; linha < 3; linha++)
   {
      soma = soma + matriz[linha][linha];
   }
   // for(linha = 0; linha < 3; linha++){
   //     for(coluna = 0; coluna < 3; coluna++){
   //         if(linha == coluna){
   //             soma = soma + matriz[linha][coluna];
   //         }
   //     }
   // }
   printf("%d", soma);
   return 0;
}
