#include <stdio.h>
#include <stdlib.h>
#define QUANT 6

int separador(int num[QUANT], int tamanho, int pares) {
  if (num[tamanho] % 2 == 0) {
    pares++;
  }
  if (tamanho == 0) {
    return (pares);
  }
  separador(num, tamanho - 1, pares);
}

int main() {

  int num[QUANT], pares = 0;

  for (int i = 0; i < QUANT; i++) {
    printf("Digite o valor da %dº posição do vetor: ", i + 1);
    scanf("%d", &num[i]);
  }
  printf("O vetor possui %d números pares.", separador(num, QUANT - 1, pares));
}