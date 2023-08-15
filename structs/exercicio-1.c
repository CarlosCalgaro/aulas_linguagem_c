
/*
   1) Faça um programa que leia os dados relativos a N alunos (o valor N é definido pela diretiva #define), cada aluno contendo as seguintes informações:

   nome: até 50 caracteres
   nota1: float
   nota2: float
   nota3: float
   Após a entrada dos dados o programa deve escrever o nome e a média aritmética dos alunos.
   Os alunos devem estar organizados em ordem decrescente em relação a média final e se dois alunos tiverem a mesma  média eles deverão ser organizados em
   ordem alfabética. Por exemplo, considerando um valor de N=6 e para as entradas

   Fábio Cunha Lima 
   3.4 5.6 6.6
   Rafaela Azevedo Gomes 
   5.6 6.5 7.2
   Marina Goncalves Martins 
   6.5 7.5 8.5
   Murilo Pereira Correia 
   8.0 7.0 7.5
   Otávio Santos Souza 
   7.2 8.0 8.2
   Júlia Oliveira Correia 
   5.1 7.5 6.0

   o programa deve produzir a seguinte saída:

   Otávio Santos Souza 7.8
   Marina Goncalves Martins 7.5
   Murilo Pereira Correia 7.5
   Rafaela Azevedo Gomes 6.4
   Júlia Oliveira Correia 6.2
   Fábio Cunha Lima 5.2
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAMANHO_LISTA_ALUNOS 6

typedef struct {
   char nome[50];
   float nota1;
   float nota2;
   float nota3;
   float media;
} Alunos;

void lerAlunos(Alunos ptr[]);
void escreverAlunos(Alunos vetor_alunos[]);
void bubbleSort(Alunos vetor_alunos[]);

int main(){
    Alunos lista_alunos[TAMANHO_LISTA_ALUNOS];
    lerAlunos(lista_alunos);


    printf("Alunos: \n");
    escreverAlunos(lista_alunos);
    bubbleSort(lista_alunos);
    printf("Alunos Ordernados: \n");
    escreverAlunos(lista_alunos);

    return 0;
}

void lerAlunos(Alunos ptr[]){
    for(int i = 0; i < TAMANHO_LISTA_ALUNOS; i++){
        printf("Digite o nome do aluno: ");
        fgets(ptr[i].nome, 50, stdin);
        ptr[i].nome[strlen(ptr[i].nome) - 1] = '\0'; // Removendo o ultimo espaco da string
        fflush(stdin);
        printf("Digite as notas do aluno, separadas por espaco:\n");
        scanf("%f %f %f", &ptr[i].nota1, &ptr[i].nota2, &ptr[i].nota3);
        ptr[i].media = (ptr[i].nota1 + ptr[i].nota2 + ptr[i].nota3) / 3;
        fflush(stdin);
    }
}

void escreverAlunos(Alunos lista_alunos[]){
    for(int i=0; i< TAMANHO_LISTA_ALUNOS; i++){
        printf("Nome: %s, Nota 1: %f, Nota 2: %f, Nota 3: %f, Media: %f \n", lista_alunos[i].nome, lista_alunos[i].nota1, lista_alunos[i].nota2, lista_alunos[i].nota3, lista_alunos[i].media);
    }
}

void bubbleSort(Alunos vetor_alunos[]){
    for(int i=1; i < TAMANHO_LISTA_ALUNOS; i++){
        for(int j=0; j <= TAMANHO_LISTA_ALUNOS - 1; j++){
            if(vetor_alunos[j].media < vetor_alunos[j+1].media){
                Alunos aux = vetor_alunos[j];
                vetor_alunos[j] = vetor_alunos[j+1];
                vetor_alunos[j+1] = aux;
            }else if(vetor_alunos[j].media == vetor_alunos[j+1].media) {
                if(strcmp(vetor_alunos[j].nome, vetor_alunos[j+1].nome) > 0){
                    Alunos aux = vetor_alunos[j];
                    vetor_alunos[j] = vetor_alunos[j+1];
                    vetor_alunos[j+1] = aux;
                }
            }
        }
    }
}