#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *arq;

  typedef struct info {
    int num;
    float numf;
    char letra;
  } Info;

  char nome[50], resultadoletra;
  int num, resultadoint;
  float resultadofloat;
  Info info;
  printf("Digite o nome do arquivo: ");
  fgets(nome, 50, stdin);
  nome[strcspn(nome, "\n")] = 0;
  if ((arq = fopen(nome, "rb")) == NULL) {
    fclose(arq);
    arq = fopen(nome, "wb");
    // grava os 3 valores
    printf("Digite um número inteiro: ");
    scanf("%d", &info.num);
    printf("Digite um float: ");
    scanf("%f", &info.numf);
    fflush(stdin);
    printf("Digite um caracter: ");
    scanf("%c", &info.letra);
    fwrite(&info, sizeof(Info), 1, arq);

  } else {
    fread(&info, sizeof(Info), 1, arq);
    printf("Resultado: %d\n", info.num);
    printf("Resultado: %.2f\n", info.numf);
    printf("Resultado: %c", info.letra);
    fclose(arq);
  }
}