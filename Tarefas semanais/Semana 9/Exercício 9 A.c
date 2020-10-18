#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float decimal(int hr, int min, int seg)
{
  float res;
  if (hr > 23 || min > 59 || seg > 59)
  {
    res = -1;
  }
  else
  {
    res = (hr * 60) + min + (seg / 60);
  }
  return (res);
}

int main()
{
  int hr, min, seg;
  float res;
  printf("Digite hora: ");
  scanf("%d", &hr);
  printf("Digite min: ");
  scanf("%d", &min);
  printf("Digite seg: ");
  scanf("%d", &seg);
  res = decimal(hr, min, seg);
  if (res == -1)
  {
    printf("Horário inválido", res);
  }
  else
  {
    printf("%.2f", res);
  }
  return 0;
}