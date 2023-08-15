//
// Created by Carlos Calgaro on 12/04/2023.
//
// 2) Faça um programa que leia os dados relativos a N pessoas (o valor de N é definido pela diretiva #define),
//    cada pessoa contendo as seguintes informações:
//
//    nome: até 50 caracteres;
//    peso em quilogramas (int)
//    altura em metros (float)
//    Após a entrada dos dados o programa deverá escrever o nome e o IMC das N pessoas, em ordem decrescente de IMC.
//    Para o cálculo do IMC basta dividir o peso pela altura ao quadrado.
//    Por exemplo, considerando um N=6 e para a entrada (nome,  peso e altura)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMERO_PESSOAS 6
typedef struct {
    char nome[50];
    int peso;
    float altura;
    float imc;
} Pessoa;

void lerDados(Pessoa ptr[]);
void escreverDados(Pessoa ptr[]);
void bubbleSort(Pessoa ptr[]);

int main(){
    Pessoa lista_pessoas[NUMERO_PESSOAS];
    lerDados(lista_pessoas);

    bubbleSort(lista_pessoas);
    escreverDados(lista_pessoas);

    return 0;
}

void escreverDados(Pessoa ptr[]){
    for(int i=0; i< NUMERO_PESSOAS; i++){
        printf("%s\n%f\n", ptr[i].nome, ptr[i].imc);
    }
}

void lerDados(Pessoa ptr[]){
    for(int i = 0; i < NUMERO_PESSOAS; i++){
        // Salvando o nome
        printf("Digite o nome da pessoa: ");
        fgets(ptr[i].nome, 50, stdin);
        ptr[i].nome[strlen(ptr[i].nome) - 1] = '\0'; // Removendo o ultimo espaco da string
        fflush(stdin);

        printf("Digite o peso:\n");
        scanf("%d", &ptr[i].peso);
        fflush(stdin);


        printf("Digite a altura:\n");
        scanf("%f", &ptr[i].altura);
        fflush(stdin);

        //calculando IMC
        ptr[i].imc = ptr[i].peso / (ptr[i].altura * ptr[i].altura);
    }
}

void bubbleSort(Pessoa ptr[]){
    for(int i=1; i < NUMERO_PESSOAS; i++){
        for(int j=0; j <= NUMERO_PESSOAS - 1; j++){
            if(ptr[j].imc < ptr[j+1].imc){
                Pessoa aux = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = aux;
            }
        }
    }
}