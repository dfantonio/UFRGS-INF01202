#include "debug.h"
#include "funcoes.h"
#include "start.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Jogo jogo;

  jogo.score = 110;
  strcpy(jogo.jogador, "antonio");

  setup(&jogo);

  renderizaTableau(&jogo);
}