#include <stdbool.h>
#ifndef STRUCT_H // Esses dois ifs servem pra permitir que esse aquivo seja importa múltiplas vezes
#define STRUCT_H

#define COPAS   1
#define PAUS    2
#define OUROS   3
#define ESPADAS 4

#define TAM_ESTOQUE    52
#define TAM_DESCARTE   25
#define TAM_TABLEAU_L  19
#define TAM_TABLEAU_C  7
#define TAM_FUNDACAO_L 13
#define TAM_FUNDACAO_C 4
#define TAM_JOGADOR    30

/**
 * Por definição quando o número da carta for 0 significa que aquela posição 
 * está vazia e deve ser ignorada
 */
typedef struct carta {
  int numero; // 1 - Às até 13 - Rei;
  int naipe;  // 1 - Copas, 2 - Paus, 3 - Ouros, 4 -Espadas
  bool visivel;
} Carta;

typedef struct cursor {
  int x;
  int y;
} Cursor;

typedef struct jogo {
  Carta estoque[TAM_ESTOQUE];
  Carta descarte[TAM_DESCARTE];
  Carta tableau[TAM_TABLEAU_L][TAM_TABLEAU_C];
  Carta fundacao[TAM_FUNDACAO_L][TAM_FUNDACAO_C];
  Cursor cursor;
  Cursor pos_inicial;
  char jogador[TAM_JOGADOR];
  int score;
  int telaAtual;
  int pos_estoque; // posição do estoque
} Jogo;
#endif
