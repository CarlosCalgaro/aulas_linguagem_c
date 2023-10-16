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

void lerValor(int *vetor, int n)
{

    int i;
    for (i = 0; i < n; i++)
    {
        printf("Escreva o valor de vetor[%d]", i);
        scanf("%d", &vetor[i]);
    }
}

int main()
{

    int n; // Tamanho do vetor
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    int *vetor = (int *)calloc(n, sizeof(int));
    lerValor(vetor, n);

    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d - ", vetor[i]);
    }
}