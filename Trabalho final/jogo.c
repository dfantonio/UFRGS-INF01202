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

  renderizaTableau(&jogo);

  // rodaJogo(&jogo);
}