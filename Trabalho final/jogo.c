#include "funcoes.h"
#include "start.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  cls();
  Jogo jogo;

  iniciaCartas(&jogo);

  setup();

  printMainMenu();

  while (1) {
    if (kbhit()) {
      char k = getkey();

      switch (k) {
      case '1':
        printf("\nJogo!");
        break;

      case '2':
        printf("\nScores:\nTonho - 1 milhão");
        break;

      case '3':
        exit(1);
        break;

      default:
        break;
      }
    }
  }
}