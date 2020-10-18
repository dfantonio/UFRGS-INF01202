#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menor2(int a, int b) {
  int menor;
  if (a < b) {
    menor = a;
  } else {
    menor = b;
  }
  return (menor);
}
int menor3(int menor, int c) {
  int menor1;
  if (menor < c) {
    menor1 = menor;
  } else {
    menor1 = c;
  }
  return (menor1);
}

int main() {
  int a, b, c, x, y; //x=menor2 | y=menor3
  printf("Digite o 1º número: ");
  scanf("%d", &a);
  printf("Digite o 2º número: ");
  scanf("%d", &b);
  printf("Digite o 3º número: ");
  scanf("%d", &c);

  x = menor2(a, b);
  y = menor3(x, c);
  printf("%d", y);
}
