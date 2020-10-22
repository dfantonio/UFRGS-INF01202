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
      break;

    case TELA_LEADERBOARD:
      printf("to nos scores\n");
      break;

    default:
      break;
    }
  }
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