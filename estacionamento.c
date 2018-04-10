#include "estacionamento.h"

void menu(){
  int escolha;
  CLRscr;
  printf("Menu:\n\t1 - Entrada de Veículo\n\t2 - Saída de Veículo\n\t3 - InformaçõesAtuais do Estacionamento\n\t4 - \
Mapa do Estacionamento\n\t5 - Consulta de Histórico\n\t6 - Sair\n\nSua opção: ");
  scanf("%d", &escolha);
  printf("\n");
  switch(escolha){
  case 1:
    //entrada();
    break;
  case 2:
    //saida();
    break;
  case 3:
    //informacoes();
    break;
  case 4:
    //mapa();
    break;
  case 5:
    //historico();
    break;
  case 6:
    exit(0);
    break;
  default:
    printf("Essa opção não é válida!");
    CLRscr;
  }
}
