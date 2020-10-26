#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define L 2
#define C 4

float semnome(int m_in[L][C], float *m_out[L][C], int l, int c) {
  int soma = 0;
  for (l = 0; l < L; l++) {
    for (c = 0; c < C; c++) {
      soma += m_in[l][c];
    }
  }
  m_out[0][0] = 2.0;
  printf("soma %d\n", soma);
  float teste = 2;

  // for (l = 0; l < L; l++) {
  //   for (c = 0; c < C; c++) {
  //     m_out[l][c] = teste;
  //     // *(m_out[l][c]) = ((float)m_in[l][c] / soma);
  //   }
  // }
}
int main() {

  int m_in[L][C] = {
      {0, 33, 2, 15},
      {33, 0, 60, 32},
  };
  float *m_out[L][C];

  // for (int l = 0; l < L; l++) {
  //   for (int c = 0; c < C; c++) {
  //     printf("Preencha a %dº coluna.", c + 1);
  //     scanf("%d", &m_in[l][c]);
  //   }
  // }

  semnome(m_in, &m_out, L, C);

  printf("TESTE: %d", m_out[0][0]);

  // for (int l = 0; l < L; l++) {
  //   for (int c = 0; c < C; c++) {
  //     printf("%.2f\t", m_out[l][c]);
  //   }
  // }
}