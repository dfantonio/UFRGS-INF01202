#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

// Função para debug que printa todo o tableau
void printaTableau(Jogo *jogo) {
  for (int i = 0; i < 7; i++) {
    for (int col = 0; col < 7; col++) {
      if (i > col) printf("\t");
      else
        printf("%02d\t", jogo->tableau[i][col].numero);
    }
    printf("\n");
  }
}