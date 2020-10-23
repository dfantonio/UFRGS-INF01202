#include "interface.h"
#include "rlutil.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setup(Jogo *jogo) {
  jogo->telaAtual = TELA_INICIO;
  hidecursor();
  saveDefaultColor();
  iniciaCartas(&jogo);
  // setBackgroundColor(2);
  // system("color c2"); //Pode ser uma alternativa para colorir todo o fundo
}
