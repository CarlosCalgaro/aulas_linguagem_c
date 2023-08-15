//
// Created by Carlos Calgaro on 12/04/2023.
// 3) Normalmente alguns poucos clientes representam a maior parte do faturamento de uma empresa. 
//    Assim, um administrador deseja determinar quantos clientes representam 50% do faturamento da sua empresa.  
//    Faça um programa que leia os dados de N clientes com as seguintes informações (o valor N é definido pela diretiva #define):
//
//      nome do cliente: até 50 caracteres
//      faturamento: float
//    Após, o programa deverá gerar como saída o total faturado e a quantidade mínima de clientes que representam 50% do faturamento. 
//    Além disso, o programa deverá escrever o nome dos clientes que representam a metade do total faturado.
//


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMERO_CLIENTES 8
typedef struct {
    char nome[50];
    float faturamento;
} Cliente;

void lerDados(Cliente ptr[], float *faturamento);
void bubbleSort(Cliente ptr[]);
int index50pcFaturamento(Cliente ptr[], float faturamento);

int main(){
    Cliente lista_pessoas[NUMERO_CLIENTES];
    float faturamento = 0;
    lerDados(lista_pessoas, &faturamento);

    bubbleSort(lista_pessoas);
    int index = index50pcFaturamento(lista_pessoas, faturamento);

    printf("Total Faturado: %f\n", faturamento);
    printf("Numero de clientes: %d\n", index);
    for(int i = 0; i < index; i++){
        printf("%s %f\n", lista_pessoas[i].nome, lista_pessoas[i].faturamento);
    }
    return 0;
}

int index50pcFaturamento(Cliente ptr[], float faturamento){
    int i = 0, total = 0;
    while(total < faturamento/2 && i < NUMERO_CLIENTES){
        total += ptr[i].faturamento;
        i+=1;
    }
    return i;
}

void lerDados(Cliente ptr[], float *faturamento){
    for(int i = 0; i < NUMERO_CLIENTES; i++){
        // Salvando o nome
        printf("Digite o nome do cliente: ");
        fgets(ptr[i].nome, 50, stdin);
        ptr[i].nome[strlen(ptr[i].nome) - 1] = '\0'; // Removendo o ultimo espaco da string
        fflush(stdin);

        printf("Digite o faturamento:\n");
        scanf("%f", &ptr[i].faturamento);
        fflush(stdin);
        *faturamento += ptr[i].faturamento ;
    }
}
void bubbleSort(Cliente ptr[]){
    for(int i=1; i < NUMERO_CLIENTES; i++){
        for(int j=0; j <= NUMERO_CLIENTES - 1; j++){
            if(ptr[j].faturamento < ptr[j+1].faturamento){
                Cliente aux = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = aux;
            }
        }
    }
}