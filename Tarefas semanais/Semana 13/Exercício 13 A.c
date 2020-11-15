#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *arq;

  char nome[50], palavra[50], testea[50];
  int linha = 1, contador = 0;
  printf("Digite o nome do arquivo: ");
  fgets(nome, 50, stdin);
  nome[strcspn(nome, "\n")] = 0;
  printf("Digite a palavra que deseja procurar no arquivo: ");
  fgets(palavra, 50, stdin);
  palavra[strcspn(palavra, "\n")] = 0;
  arq = fopen(nome, "r");
  while (fgets(testea, 50, arq)) {
    testea[strcspn(testea, "\n")] = 0;
    if ((strcmp(testea, palavra)) == 0) {
      printf("%d\n", linha);
      contador++;
    }
    linha++;
  }
  if (contador == 0) {
    printf("Não tem nenhuma ocorrência.");
  }
}