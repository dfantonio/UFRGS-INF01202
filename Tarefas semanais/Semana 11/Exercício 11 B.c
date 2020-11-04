#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARTAS 52
#define NAIPES 4
#define VALOR  13

typedef struct carta {
  int numero;
  int naipe;
} Carta;

void inicializa_baralho(Carta baralho[CARTAS]) {
  for (int aux = 0; aux < CARTAS; aux++) {
    baralho[aux].numero = (aux % VALOR) + 1;
    baralho[aux].naipe = ((aux) / VALOR) + 1;
  }
}

void imprime_baralho(Carta baralho[CARTAS], int quant) {
  printf("Cartas: ");
  for (int i = 0; i < quant; i++) {
    printf("\n%d ", baralho[rand() % (CARTAS + 1)].numero);
    switch (baralho[i].naipe) {
    case 1:
      printf("de Copas");
      break;
    case 2:
      printf("de Ouros");
      break;
    case 3:
      printf("de Paus");
      break;
    case 4:
      printf("de Espadas");
      break;
    }
  }
}

int main() {
  srand(time(NULL));
  Carta baralho[52];
  int quant;
  quant = rand() % (CARTAS + 1);
  inicializa_baralho(baralho);
  imprime_baralho(baralho, quant);
}