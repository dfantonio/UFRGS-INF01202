#include "interface.h"
#include "rlutil.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setup(Jogo *jogo) {
  jogo->telaAtual = TELA_INICIO;
  jogo->pos_estoque = 0; // posição do estoque começa em 0
  jogo->cursor.x = 0;
  jogo->cursor.y = 0;
  jogo->score = 0;
  jogo->pos_inicial.x = 0;
  jogo->pos_inicial.y = 0;
  jogo->vitoria = false;
  cls();
  hidecursor();
  saveDefaultColor();
  iniciaCartas(jogo);
}
