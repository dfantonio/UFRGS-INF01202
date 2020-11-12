#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARTAS 52
#define VALOR  13

typedef struct carta {
  int numero;
  int naipe;
} Carta;

void inicializa_baralho(Carta cartas[CARTAS]) {
  for (int aux = 0; aux < CARTAS; aux++) {
    cartas[aux].numero = (aux % VALOR) + 1;
    cartas[aux].naipe = ((aux) / VALOR) + 1;
  }
}

int salva_estado(Carta cartas[CARTAS], int tamanho) {
  FILE *arq;
  char nome[50];
  Carta resultado[tamanho];
  printf("Digite o nome do arquivo: ");
  fgets(nome, 50, stdin);
  nome[strcspn(nome, "\n")] = 0;
  arq = fopen(nome, "wb");
  fwrite(&tamanho, sizeof(int), 1, arq);
  fwrite(cartas, sizeof(Carta) * 52, 1, arq);
  fclose(arq);
}
int main() {
  system("cls");
  Carta cartas[CARTAS];
  inicializa_baralho(cartas);
  salva_estado(cartas, CARTAS);
}
