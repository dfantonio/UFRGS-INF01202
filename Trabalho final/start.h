#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void embaralha(Jogo *jogo) {
  // srand(time(NULL));
  srand(0);
  int random;
  for (int i = 0; i < 52; i++) {
    random = (rand() % 52);
    Carta t = jogo->estoque[random];
    jogo->estoque[random] = jogo->estoque[i];
    jogo->estoque[i] = t;
  }
}

void criaBaralho(Jogo *jogo) {
  for (int i = 0; i < 52; i++) {
    jogo->estoque[i].numero = (i % 13) + 1;
    jogo->estoque[i].naipe = ((i) / 13) + 1;
    jogo->estoque[i].visivel = false;
  }
}

void distribuiTableau(Jogo *jogo) {
  //Inicializa todas as posições como inválidas
  for (int row = 0; row < 19; row++) {
    for (int col = 0; col < 7; col++) {
      jogo->tableau[row][col].numero = 0;
      jogo->tableau[row][col].visivel = true;
      jogo->tableau[row][col].naipe = 0;
    }
  }

  int col = 0, linha = 0;
  for (int i = 24; i < 52; i++, linha++) {
    if (linha == (col + 1)) {
      jogo->tableau[linha - 1][col].visivel = true;
      col++;
      linha = 0;
    }
    jogo->tableau[linha][col] = jogo->estoque[i];
    jogo->estoque[i].numero = 0;
  }
  jogo->tableau[6][6].visivel = true;
}

void zeraFundacao(Jogo *jogo) {
  Carta carta;
  carta.numero = 0;
  for (int col = 0; col < TAM_FUNDACAO_C; col++) {
    for (int linha = 0; linha < TAM_FUNDACAO_L; linha++) {
      jogo->fundacao[linha][col] = carta;
    }
  }
}

void iniciaCartas(Jogo *jogo) {
  criaBaralho(jogo);
  embaralha(jogo);
  distribuiTableau(jogo);
  zeraFundacao(jogo);
}