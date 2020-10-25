#include "funcoes.h"
#include "start.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  cls();
  Jogo jogo;

  jogo.score = 110;
  strcpy(jogo.jogador, "antonio");

  printf("Jogador: %s", jogo.jogador);
  setup(&jogo);
  criaInterfaceMesa(&jogo);

  Carta carta;
  carta.numero = 13;
  carta.naipe = 1;
  carta.visivel = true;
  renderizaCarta(&carta, 4, 15);

  carta.numero = 2;
  renderizaCarta(&carta, 4, 17);
  // rodaJogo(&jogo);
}