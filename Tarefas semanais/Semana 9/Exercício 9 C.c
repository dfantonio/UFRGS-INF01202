#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int pares(int matriz[3][2])
{
  float verdade = 0;
  if (matriz[3][0] > matriz[1][0] && matriz[3][0] < matriz[2][0] && matriz[3][1] > matriz[1][1] && matriz[3][1] < matriz[2][1])
  {
    verdade += 1;
  }
  return (verdade);
}

int main()
{
  int pos[3][2];
  float vdd = 0;
  for (int linhas = 0; linhas < 3; linhas++)
  {
    printf("Digite o par ordenado do %dº ponto: ", linhas + 1);
    scanf("%d %d", &pos[linhas][0], &pos[linhas][1]);
  }
  vdd = pares(pos);
  if (vdd = 1)
  {
    printf("O 3º ponto está dentro do retângulo.");
  }
  else
  {
    printf("O 3º ponto não está dentro do retângulo.");
  }
}
