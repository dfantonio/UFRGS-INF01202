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