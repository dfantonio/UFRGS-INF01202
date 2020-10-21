#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void embaralha(Jogo *jogo) {
  srand(time(NULL));
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
  }
}

void iniciaCartas(Jogo *jogo) {
  criaBaralho(jogo);
  embaralha(jogo);
}