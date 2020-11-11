#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARTAS 52
#define NAIPES 4 // 1 = Copas, 2 = Ouros, 3 = Paus, 4 = Espadas
#define VALOR  13

typedef struct carta {
  int numero;
  int naipe;
} Carta;

typedef struct arquivo {
  int quantidade;
  Carta cartas[CARTAS];
} Arquivo;

void inicializa_baralho(Arquivo *payload) {
  for (int aux = 0; aux < CARTAS; aux++) {
    payload->cartas[aux].numero = (aux % VALOR) + 1;
    payload->cartas[aux].naipe = ((aux) / VALOR) + 1;
  }
}

void salva_estado(Arquivo payload, int quant) {
  FILE *arq;
  char nome[50];
  int teste;
  Carta deck[quant];
  Arquivo destino;
  printf("Digite o nome do arquivo: ");
  fgets(nome, 50, stdin);
  nome[strcspn(nome, "\n")] = 0;
  arq = fopen(nome, "wb");
  fwrite(&payload, sizeof(Arquivo), 1, arq);
  fclose(arq);
  arq = fopen(nome, "rb");
  fread(&destino, sizeof(Arquivo), 1, arq);
}

int main() {
  srand(time(NULL));
  system("cls");
  int quant;
  quant = CARTAS;
  Arquivo payload;
  payload.quantidade = CARTAS;
  inicializa_baralho(&payload);
  salva_estado(payload, quant);
}