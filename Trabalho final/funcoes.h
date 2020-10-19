#include "rlutil.h"

int teste() {
  return 10;
}

#define Q_ES 218 // Quina esquerda superior
#define Q_EI 192 // Quina esquerda inferior
#define Q_DS 191 // Quina direita superior
#define Q_DI 217 // Quina direita inferior
#define T_HO 196 // Traço horizontal
#define T_VE 179 // Traço vertical

void setup() {
  hidecursor();
  saveDefaultColor();
  setBackgroundColor(2);
  // system("color c2"); //Pode ser uma alternativa para colorir todo o fundo
}

void printOption(char *texto, int startX, int startY) {
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

void printMainMenu() {
  printf(" _______                 _    _                     _          \n");
  printf("|_   __ \\               (_)  / \\                   (_)         \n");
  printf("  | |__) |,--.   .---.  __  .---.  _ .--.   .---.  __   ,--.   \n");
  printf("  |  ___/`'_\\ : / /'`\\][  |/ /__\\\\[ `.-. | / /'`\\][  | `'_\\ :  \n");
  printf(" _| |_   // | |,| \\__.  | || \\__., | | | | | \\__.  | | // | |, \n");
  printf("|_____|  \\'-;__/'.___.'[___]'.__.'[___||__]'.___.'[___]\\'-;__/ \n\n\n");
  printOption("(1) Jogar", 16, 10);
  printOption("(2) Recordes", 32, 10);
  printOption("(3) Sair", 25, 13);
}