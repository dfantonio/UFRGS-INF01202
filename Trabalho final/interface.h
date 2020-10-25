// Arquivo destinado para as funções que lidam com a interface do jogo

#include "rlutil.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef INTERFACE_H
#define INTERFACE_H

#define TELA_INICIO      0
#define TELA_JOGO        1
#define TELA_LEADERBOARD 2

#define Q_ES 218 // Quina esquerda superior
#define Q_EI 192 // Quina esquerda inferior
#define Q_DS 191 // Quina direita superior
#define Q_DI 217 // Quina direita inferior
#define T_HO 196 // Traço horizontal
#define T_VE 179 // Traço vertical

// Exemplo de função que muda de acordo com o sistema operacional
static void _interface_limpa_tela(void) {
#ifdef OS_Windows
  /* Windows code */
  system("cls");
#else
  /* GNU/Linux code */
  system("clear");
#endif
  puts("");
}

void rodaJogo(Jogo *jogo) {
  while (1) {

    switch (jogo->telaAtual) {
    case TELA_INICIO:
      printMainMenu(jogo);
      break;

    case TELA_JOGO:
      printf("to no jogo\n");
      criaInterfaceMesa(jogo);
      break;

    case TELA_LEADERBOARD:
      printf("to nos scores\n");
      break;

    default:
      break;
    }
  }
}

void criaQuadrado(int x, int y) {
  cls();
  printf("%c", Q_ES);
  for (int i = 0; i < (x - 2); i++)
    printf("%c", T_HO);
  printf("%c", Q_DS);
  for (int i = 2; i < y; i++) {
    gotoxy(1, i);
    printf("%c", T_VE);
    gotoxy(x, i);
    printf("%c\n", T_VE);
  }

  printf("%c", Q_EI);
  for (int i = 0; i < (x - 2); i++)
    printf("%c", T_HO);
  printf("%c", Q_DI);
}

void aplicaLabels(Jogo *jogo) {
  gotoxy(4, 3);
  printf("Jogador: %s", jogo->jogador);
  gotoxy(55, 3);
  printf("Score: %d", jogo->score);

  gotoxy(4, 5);
  printf("Estoque");
  gotoxy(15, 5);
  printf("Descarte");
  gotoxy(35, 5);
  printf("Fundacao");

  gotoxy(4, 8);
  printf("Tableau");
}

int getCorCarta(int naipe) {
  return naipe % 2 ? RED : BLACK;
}

char getNaipeCarta(int naipe) {
  switch (naipe) {
  case COPAS:
    return 3;

  case PAUS:
    return 5;

  case OUROS:
    return 4;

  case ESPADAS:
    return 6;
  }
}

void renderizaCarta(Carta *carta, int x, int y) {
  if (carta->visivel) {
    gotoxy(x, y);
    setColor(getCorCarta(carta->naipe));
    setBackgroundColor(WHITE);
    if (carta->numero < 10) printf(" "); // Pra deixar a largura igual com cartas de 1 ou 2 caracteres
    printf(" %d %c  ", carta->numero, getNaipeCarta(carta->naipe));
  } else {
    gotoxy(x, y);
    setColor(WHITE);
    setBackgroundColor(BLUE);
    printf(" -- -- ");
  }
  resetColor();
}

void renderizaTableau(Jogo *jogo) {
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 7; j++) {
      if (jogo->tableau[i][j].numero != 0)
        renderizaCarta(&jogo->tableau[i][j], 4 + (9 * j), 9 + i);
    }
  }
}

void criaInterfaceMesa(Jogo *jogo) {
  criaQuadrado(70, 30);
  aplicaLabels(jogo);
  renderizaTableau(jogo);
}

void printMenuOption(char *texto, int startX, int startY) {
  int tamanho = strlen(texto) + 4;
  for (int linha = 0; linha < tamanho; linha++) {
    switch (linha) {
    case 0:
      gotoxy(startX, startY);
      printf("%c", Q_ES);
      for (int i = 0; i < tamanho - 2; i++) {
        printf("%c", T_HO);
      }
      printf("%c", Q_DS);
      break;

    case 1:
      gotoxy(startX, startY + 1);
      printf("%c %s %c", T_VE, texto, T_VE);
      break;

    case 2:
      gotoxy(startX, startY + 2);
      printf("%c", Q_EI);
      for (int i = 0; i < tamanho - 2; i++) {
        printf("%c", T_HO);
      }
      printf("%c", Q_DI);
      break;

    default:
      break;
    }
  }
}

void printMainMenu(Jogo *jogo) {
  printf(" _______                 _    _                     _          \n");
  printf("|_   __ \\               (_)  / \\                   (_)         \n");
  printf("  | |__) |,--.   .---.  __  .---.  _ .--.   .---.  __   ,--.   \n");
  printf("  |  ___/`'_\\ : / /'`\\][  |/ /__\\\\[ `.-. | / /'`\\][  | `'_\\ :  \n");
  printf(" _| |_   // | |,| \\__.  | || \\__., | | | | | \\__.  | | // | |, \n");
  printf("|_____|  \\'-;__/'.___.'[___]'.__.'[___||__]'.___.'[___]\\'-;__/ \n\n\n");
  printMenuOption("(1) Jogar", 16, 10);
  printMenuOption("(2) Recordes", 32, 10);
  printMenuOption("(3) Sair", 25, 13);

  while (1) {
    if (kbhit()) {
      char k = getkey();
      switch (k) {
      case '1':
        jogo->telaAtual = TELA_JOGO;
        return;

      case '2':
        jogo->telaAtual = TELA_LEADERBOARD;
        return;

      case '3':
        exit(1);

      default:
        break;
      }
    }
  }
}

#endif