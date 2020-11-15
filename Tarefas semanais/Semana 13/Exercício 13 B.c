#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *arq, *imp, *par;

  char nome[50], numeros[50];
  printf("Digite o nome do arquivo: ");
  fgets(nome, 50, stdin);
  nome[strcspn(nome, "\n")] = 0;
  arq = fopen(nome, "r");
  par = fopen("pares.txt", "w");
  imp = fopen("impares.txt", "w");
  fclose(par);
  fclose(imp);
  while (fgets(numeros, 50, arq)) {
    numeros[strcspn(numeros, "\n")] = 0;
    if ((atoi(numeros) % 2) == 0) {
      fopen("pares.txt", "a+");
      fprintf(par, "%s\n", &numeros);
    } else {
      fopen("impares.txt", "a+");
      fprintf(imp, "%s\n", &numeros);
    }
  }
}