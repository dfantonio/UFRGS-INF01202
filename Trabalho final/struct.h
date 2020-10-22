#include <stdbool.h>
#ifndef STRUCT_C // Esses dois ifs servem pra permitir que esse aquivo seja importa múltiplas vezes
#define STRUCT_C

/**
 * Por definição quando o número da carta for 0 significa que aquela posição 
 * está vazia e deve ser ignorada
 */
typedef struct carta {
  int numero; // 1 - Às até 13 - Rei;
  int naipe;  // 1 - Copas, 2 - Paus...
  bool visivel;
} Carta;

typedef struct jogo {
  Carta estoque[52];
  Carta descarte[24];
  Carta tableau[19][7];
  Carta funcadao[13][4];
  char jogador[30];
  int score;
  int telaAtual;
} Jogo;
#endif
