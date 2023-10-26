#include <stdio.h>
#include <stdlib.h>

int main() {
    int contadorPrimos = 0; // Variável para contar o número de números primos encontrados
    int achaPrimo = 0; // Variável usada para verificar se um número é primo
    int n = 2; // Começamos com o número 2, que é o primeiro número primo
    int i;

    while (contadorPrimos < 50) { // Loop para encontrar os primeiros 50 números primos
        while (achaPrimo == 0) { // Loop para verificar se "n" é primo
            achaPrimo = 1; // Assumimos que "n" é primo até que a prova contrária seja encontrada

            // Testamos a divisão de "n" por todos os números de 2 até "n-1"
            // Se algum número for divisível por "n", então "n" não é primo
            for (i = 2; i < n; i++) {
                if (n % i == 0) {
                    achaPrimo = 0; // Se "n" for divisível por algum número, ele não é primo
                    i = n + 1; // Forçar saída do loop
                }
            }

            if (achaPrimo == 0) {
                n++; // Se "n" não for primo, passamos para o próximo número
            }
        }

        printf("Achou Primo: %d\n", n); // Imprime o número primo encontrado
        contadorPrimos += 1; // Incrementa o contador de números primos encontrados
        achaPrimo = 0; // Redefine a variável achaPrimo para 0
        n++; // Passamos para o próximo número para verificar se ele é primo
    }

    return 0;
}