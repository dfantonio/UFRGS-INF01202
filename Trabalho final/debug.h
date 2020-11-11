#include "interface.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

// Função para debug que printa todo o tableau
void printaTableau(Jogo *jogo) {
  for (int row = 0; row < 19; row++) {
    for (int col = 0; col < 7; col++) {
      printf("%d %d %d\t", jogo->tableau[row][col].numero, jogo->tableau[row][col].naipe, jogo->tableau[row][col].visivel);
    }
    printf("\n");
  }
}

void debugMode(Jogo *jogo) {
  jogo->telaAtual = TELA_JOGO;
  strcpy(jogo->jogador, "Beta");
  // jogo->fundacao[0][0] = jogo->estoque[0];
  // jogo->fundacao[0][0].numero--;
  // jogo->fundacao[0][0].visivel = true;
  // jogo->fundacao[0][1] = jogo->estoque[1];
  // jogo->fundacao[0][1].visivel = true;
}