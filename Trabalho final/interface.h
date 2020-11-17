// Arquivo destinado para as funções que lidam com a interface do jogo

#include "rlutil.h"
#include "struct.h"
#include "utils.h"
#include "validate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef INTERFACE_H
#define INTERFACE_H

#define TELA_INICIO      0
#define TELA_JOGO        1
#define TELA_LEADERBOARD 2
#define TELA_GET_DATA    3
#define TELA_PAUSE       4

#define Q_ES 218 // Quina esquerda superior
#define Q_EI 192 // Quina esquerda inferior
#define Q_DS 191 // Quina direita superior
#define Q_DI 217 // Quina direita inferior
#define T_HO 196 // Traço horizontal
#define T_VE 179 // Traço vertical

#define CIMA     'w'
#define BAIXO    's'
#define DIREITA  'd'
#define ESQUERDA 'a'

#define Y_INFORMACOES_JOGADOR 3
#define Y_CABECALHOS          6
#define Y_TABLEAU             9

void rodaJogo(Jogo *jogo) {
  while (1) {

    switch (jogo->telaAtual) {
    case TELA_INICIO:
      cls();
      printMainMenu(jogo);
      break;

    case TELA_GET_DATA:
      cls();
      renderizaGetData(jogo);
      break;

    case TELA_PAUSE:
      cls();
      renderizaPause(jogo);
      break;

    case TELA_JOGO:
      cls();
      criaInterfaceMesa(jogo);
      renderizaMesa(jogo);
      break;

    case TELA_LEADERBOARD:
      printf("to nos scores\n");
      break;

    default:
      break;
    }
  }
}

void renderizaPause(Jogo *jogo) {
  criaQuadrado(74, 30);
  printMenuOption("1 - Salvar e Sair", 25, 5);
  printMenuOption("2 - Sair", 30, 8);

  while (1) {
    if (kbhit()) {
      char k = getkey();
      switch (k) {
      case '1':
        cls();
        criaQuadrado(74, 30);
        gotoxy(25, 5);
        printf("Nome do arquivo do save: ");

        char arquivo[30];
        fflush(stdin);
        fgets(arquivo, 30, stdin);
        arquivo[strcspn(arquivo, "\n")] = 0;
        salvaJogo(jogo, arquivo);

        jogo->telaAtual = TELA_INICIO;
        return;

      case '2':
        jogo->telaAtual = TELA_INICIO;
        return;

      default:
        break;
      }
    }
  }
}

void renderizaGetData(Jogo *jogo) {
  criaQuadrado(74, 30);
  printMenuOption("1 - Novo Jogo", 25, 5);
  printMenuOption("2 - Carregar save", 23, 8);

  while (1) {
    if (kbhit()) {
      char k = getkey();
      switch (k) {
      case '1':
        setup(jogo);
        criaQuadrado(74, 30);
        gotoxy(25, 5);
        printf("Nome do jogador: ");
        fflush(stdin);
        fgets(jogo->jogador, 30, stdin);
        jogo->telaAtual = TELA_JOGO;
        return;

      case '2':
        cls();
        criaQuadrado(74, 30);
        gotoxy(25, 5);
        printf("Nome do arquivo do save: ");

        char arquivo[30];
        fflush(stdin);
        fgets(arquivo, 30, stdin);
        arquivo[strcspn(arquivo, "\n")] = 0;
        carregaJogo(jogo, arquivo);

        jogo->telaAtual = TELA_JOGO;
        return;

      default:
        break;
      }
    }
  }
}

void renderizaMesa(Jogo *jogo) {
  while (1) {
    if (kbhit()) {
      char k = getkey();
      switch (tolower(k)) {
      case 0:  // Código do ESC do cmd
      case 27: // Código ESC da tabela ASCII
        jogo->telaAtual = TELA_PAUSE;
        return;
      case ' ':
        trocaCartas(jogo);
        break;
      case DIREITA:
        movimentaCursor(jogo, 1, 0);
        break;
      case ESQUERDA:
        movimentaCursor(jogo, -1, 0);
        break;
      case CIMA:
        movimentaCursor(jogo, 0, -1);
        break;
      case BAIXO:
        movimentaCursor(jogo, 0, 1);
        break;

      default:
        break;
      }

      cls();
      criaInterfaceMesa(jogo);
    }
  }
}

void criaQuadrado(int x, int y) {
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
  gotoxy(4, Y_INFORMACOES_JOGADOR);
  printf("Jogador: %s", jogo->jogador);
  gotoxy(54, Y_INFORMACOES_JOGADOR);
  printf("Score: %d", jogo->score);

  gotoxy(4, Y_CABECALHOS - 1);
  printf("Estoque");
  gotoxy(14, Y_CABECALHOS - 1);
  printf("Descarte");
  gotoxy(34, Y_CABECALHOS - 1);
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
    // if (carta->numero < 10) printf(" "); // Pra deixar a largura igual com cartas de 1 ou 2 caracteres
    switch (carta->numero) {
    case (1):
      printf("  A %c  ", getNaipeCarta(carta->naipe));
      break;
    case (10):
      printf(" 10 %c  ", getNaipeCarta(carta->naipe));
      break;
    case (11):
      printf("  J %c  ", getNaipeCarta(carta->naipe));
      break;
    case (12):
      printf("  Q %c  ", getNaipeCarta(carta->naipe));
      break;
    case (13):
      printf("  K %c  ", getNaipeCarta(carta->naipe));
      break;
    default:
      printf("  %d %c  ", carta->numero, getNaipeCarta(carta->naipe));
      break;
    }

  } else {
    gotoxy(x, y);
    setColor(WHITE);
    setBackgroundColor(BLUE);
    printf(" -- -- ");
  }
  resetColor();
}

void renderizaTableau(Jogo *jogo) {
  for (int i = 0; i < TAM_TABLEAU_L; i++) {
    for (int j = 0; j < TAM_TABLEAU_C; j++) {
      if (jogo->tableau[i][j].numero != 0)
        renderizaCarta(&jogo->tableau[i][j], 4 + (10 * j), 9 + i);
    }
  }
}

void renderizaEstoque(Jogo *jogo) {
  int descarte = jogo->pos_estoque - 1;
  int ncartas = 0;
  int ultimaCarta = 0;
  for (int aux = 0; aux < 24; aux++) { // Conta quantas cartas existem no estoque/descarte
    if (jogo->estoque[aux].numero != 0) ncartas++;
  }
  for (int aux = 0; aux < 24; aux++) { // Encontra a posição da última carta
    if (jogo->estoque[aux].numero != 0) ultimaCarta = aux + 1;
  }

  while (jogo->estoque[descarte].numero == 0 && jogo->pos_estoque > 0 && jogo->pos_estoque <= 24) { // cartas removidas tem valor 0, e são puladas. menos a posição inicial que também é 0
    jogo->pos_estoque++;
    descarte++;
  }

  if (jogo->pos_estoque > 24) { // quando chega na posição 25 ou maior ele volta para o começo
    jogo->pos_estoque = 0;
    descarte = -1;
    somaScore(jogo, PONT_FLIP_ESTOQUE);
  }

  if (descarte >= 0) jogo->estoque[descarte].visivel = true; // Toda carta no descarte deve estar visível
  jogo->estoque[jogo->pos_estoque].visivel = false;

  if (jogo->pos_estoque != ultimaCarta && ncartas != 0) renderizaCarta(&jogo->estoque[jogo->pos_estoque], 4, 6); // renderiza o estoque atualizado
  if (descarte >= 0) renderizaCarta(&jogo->estoque[descarte], 14, 6);                                            // renderiza o descarte atualizado
}

void renderizaFundacao(Jogo *jogo) {
  int index;
  for (int col = 0; col < TAM_FUNDACAO_C; col++) {
    index = -1;
    for (int linha = 0; linha < TAM_FUNDACAO_L; linha++) {
      if (jogo->fundacao[linha][col].numero) {
        index = linha;
      };
    }
    if (index >= 0)
      renderizaCarta(&jogo->fundacao[index][col], 34 + (col * 10), Y_CABECALHOS);
    else {
      gotoxy(34 + (col * 10), Y_CABECALHOS);
      printf("-------");
    }
  }
}

void renderizaCursorTroca(int x, int y, int cor) {
  gotoxy(x, y);
  setColor(cor);
  printf(">");
  resetColor();
}

void renderizaCursor(Jogo *jogo) {
  int x = jogo->cursor.x;
  int y = jogo->cursor.y;
  if (y == 0) {
    switch (x) {
    case 0:
    case 1:
      renderizaCursorTroca(2 + 10 * x, Y_CABECALHOS, WHITE);

      break;
    default:
      renderizaCursorTroca(2 + 10 + 10 * x, Y_CABECALHOS, WHITE);
      break;
    }
  } else
    renderizaCursorTroca(2 + 10 * x, Y_TABLEAU + y - 1, WHITE);

  //renderiza cursor de troca
  if (jogo->pos_inicial.x || jogo->pos_inicial.y) {
    if (jogo->pos_inicial.y == 0) {
      switch (jogo->pos_inicial.x) {
      case 0:
      case 1:
        renderizaCursorTroca(2 + 10 * jogo->pos_inicial.x, Y_CABECALHOS, YELLOW);

        break;
      default:
        renderizaCursorTroca(2 + 10 + 10 * jogo->pos_inicial.x, Y_CABECALHOS, YELLOW);
        break;
      }
      return;
    } else
      renderizaCursorTroca(2 + 10 * jogo->pos_inicial.x, Y_TABLEAU + jogo->pos_inicial.y - 1, YELLOW);
  }
}

void criaInterfaceMesa(Jogo *jogo) {
  criaQuadrado(74, 30);
  renderizaEstoque(jogo);
  renderizaTableau(jogo);
  renderizaFundacao(jogo);
  renderizaCursor(jogo);
  aplicaLabels(jogo);
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
        cls();
        jogo->telaAtual = TELA_GET_DATA;
        return;

      case '2':
        cls();
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