#include "debug.h"
#include "funcoes.h"
#include "start.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Jogo jogo;
  setup(&jogo);
  debugMode(&jogo);
  rodaJogo(&jogo);
}
