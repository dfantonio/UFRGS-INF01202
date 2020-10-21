
typedef struct carta {
  int numero; // 1 - Às até 13 - Rei;
  int naipe;  // 1 - Copas, 2 - Paus...
} Carta;

typedef struct jogo {
  Carta estoque[52];
  Carta descarte[28];
  Carta tableau[19][7];
  Carta funcadao[13][4];
  char jogador[30];
  int score;
} Jogo;
