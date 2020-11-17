#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef UTILS_H // Esses dois ifs servem pra permitir que esse aquivo seja importa múltiplas vezes
#define UTILS_H

#define ARQ_SAVE          "jogo.save"
#define PONT_DESC_TABLEAU 5
#define PONT_FLIP_TABLEAU 5
#define PONT_TO_FUND      10
#define PONT_FUND_TABLEAU -15
#define PONT_FLIP_ESTOQUE -50
#define PONT_WIN          300

void salvaJogo(Jogo *jogo) {
  FILE *arq;
  arq = fopen(ARQ_SAVE, "wb");
  fwrite(jogo, sizeof(Jogo), 1, arq);
  fclose(arq);
}

int carregaJogo(Jogo *jogo, char nome[30]) {
  FILE *arq;
  arq = fopen(ARQ_SAVE, "rb");
  if (arq == NULL) {
    fclose(arq);
    return 0;
  }
  fread(jogo, sizeof(Jogo), 1, arq);
  fclose(arq);
}

void somaScore(Jogo *jogo, int pontuacao) {
  if ((jogo->score + pontuacao) < 0) jogo->score = 0;
  else
    jogo->score += pontuacao;
}

#endif
