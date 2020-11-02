#include "debug.h"
#include "funcoes.h"
#include "start.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Jogo jogo;
  system("cls");
  setup(&jogo);

  jogo.telaAtual = TELA_JOGO;
  //renderiza o estado inicial do jogo
  renderizaEstoque(&jogo);
  renderizaTableau(&jogo);

  // simulação do jogo
  while (jogo.telaAtual == TELA_JOGO) {
    for (int i = 0; i < 24; i++)
      printf("%d ", jogo.estoque[i].numero); // print para ver se a sequencia esta correta
    char teste_estoque = getkey();
    switch (teste_estoque) {
    case 'e':             // 'e' = condição do cursor clicar no estoque
      jogo.pos_estoque++; // inteiro que muda aa posição do estoque a ser renderizado
      break;
    case 't':                                    // para testar se a função pula um ou uma sequencia de 0s
      jogo.estoque[jogo.pos_estoque].numero = 0; // remove a carta que está no topo do estoque (numero = 0)
      jogo.descarte[(jogo.pos_estoque) + 1].numero = 0;
      break;
    default: // sai do while
      jogo.telaAtual = 0;
      break;
    }
    //renderiza o estado atualizado do jogo
    renderizaEstoque(&jogo);
    renderizaTableau(&jogo);
  }
}
