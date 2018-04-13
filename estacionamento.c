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

void entrada(){
  char c, *nome_do_cliente, placa_do_veiculo[3]; int tamanho_do_veiculo, horas, minutos;
  
  printf("Informe o nome do cliente: ");
  //while((c = getchar()) != "\n"){  //lê o nome do cliente e coloca um '\0' ao final da leitura
  //}
  printf("Informe o tamanho do veículo: ");
  scanf("%d", &tamanho_do_veiculo);
  if((tamanho_do_veiculo < 1) || (tamanho_de_veiculo > 4)){
    printf("Aceitamos apenas veículos de tamanhos 1, 2, 3 e 4.");
    return;
  }
  printf("Informe a placa do veículo:\t");

  //Se o formato da placa estiver incorreto (provavelmente seria bom ler como char e usar atoi depois):
  printf("A placa do veículo deve possuir exatamente 4 dígitos no formato:\t0000.");
  return;

  printf("Informe a hora de entrada do veículo no formato HH:mm:");

  //Se os dados forem exatamente iguais a outros:
  printf("Não foi possível estacionar o veículo. Aparentemente o veículo já está estacionado. Provavelmente ele foi clonado.");
  return;
  
  //Se der boa:
  printf("Veículo estacionado com sucesso.");
  return;
}
