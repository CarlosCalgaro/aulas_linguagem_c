#include <stdio.h>

void verificadores(long int cpf, int *d1, int *d2) {
  *d1 = cpf % 100;
  *d2 = *d1 % 10;
  *d1 = *d1 / 10;
}

int main() {
  long int cpf;
  int d1, d2;

  printf("Digite os 9 primeiros valores do cpf:\n");
  scanf("%d", &cpf);

  verificadores(cpf, &d1, &d2);

  printf("D1= %d e D2= %d\n", d1, d2);
}