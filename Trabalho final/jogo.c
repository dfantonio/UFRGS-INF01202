#include "funcoes.h"
#include "start.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  cls();
  Jogo jogo;

  setup(&jogo);
  rodaJogo(&jogo);
}