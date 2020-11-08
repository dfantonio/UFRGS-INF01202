#include "debug.h"
#include "funcoes.h"
#include "start.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Jogo jogo;
  setup(&jogo);

  jogo.telaAtual = TELA_JOGO;
  //renderiza o estado inicial do jogo

  rodaJogo(&jogo);

  renderizaEstoque(&jogo);
  renderizaTableau(&jogo);
}
