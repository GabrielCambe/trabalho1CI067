#include "estacionamento.h"




void inicializar(){
  int i, j;

  //esse for inicializa o historico , zerando a flag 'saiu' e inicializando cliente com NULL
  for(i = 0; i <= 100; i++){
    HISTORICO[i].saiu = 0;
    HISTORICO[i].cliente = NULL;
  }

  //inicialização da principal estrutura de dados, a matriz dos clientes
  for(i = 0; i <= 4; i++){
    for(j = 0; j <= 19; j++){
      CLIENTES[i][j].ocupado = 0;
      CLIENTES[i][j].nome_do_cliente = NULL;
    }
  }
  
  //inicialização de outras variáveis importantes
  arrecadacao = 0;
  carros = 0; carros_estacionados = 0;
  carros_tipo1 = 0; carros_tipo2 = 0;
  carros_tipo3 = 0; carros_tipo4 = 0;
}




void menu(){
  int escolha;
  CLRscr;
  printf("Menu:\n\t1 - Entrada de Veículo\n\t2 - Saída de Veículo\n\t3 - Informações Atuais do Estacionamento\n\t4 - \
Mapa do Estacionamento\n\t5 - Consulta de Histórico\n\t6 - Sair\n\nSua opção: ");

  scanf("%d", &escolha);
  printf("\n");
  
  switch(escolha){
  case 1:
    entrada();
    break;

  case 2:
    saida();
    break;

  case 3:
    informacoes();
    break;

  case 4:
    mapa();
    break;

  case 5:
    historico();
    break;

  case 6:
    finalizar();
    printf("Sistema encerrado.\n");
    exit(0);

  default:
    FLUSH_input;
    printf("Essa opção não é válida!\nAperte enter para retornar\n");
    while(getchar() != '\n');
  }
}




void entrada(){
  int e, j, i, tamanho; e = 0; j = 0; i = 0; tamanho = 50;
  char c, *nome_do_cliente, placa_do_veiculo[4]; nome_do_cliente = MALLOC_char(nome_do_cliente, tamanho);
  int tamanho_do_veiculo, horas, minutos;
  int entrou_um_carro; entrou_um_carro = 0;
  
  
  
  FLUSH_input;
  if(carros < MAX_CARROS){
    
    /////////////////// LEITURA DO NOME DO CLIENTE ///////////////////////
    printf("Informe o nome do cliente: ");
    //esse while lê o nome do cliente e depois é colocado um '\0' ao final da string
    while((c = (char) getchar()) != '\n'){
      nome_do_cliente[i++] = c;
      
      if(i == tamanho)
	nome_do_cliente = REALLOC_char(nome_do_cliente, (tamanho*=2));
    }nome_do_cliente[i] = '\0';
    //////////////////////////////////////////////////////////////////////
    


  
    //////////////// LEITURA DO TAMANHO DO VEICULO ///////////////////////
    printf("Informe o tamanho do veículo: ");
    scanf("%d", &tamanho_do_veiculo);
    FLUSH_input;
    //esse if testa se o tamanho do carro está correto
    if((tamanho_do_veiculo < 1) || (tamanho_do_veiculo > 4)){
      free(nome_do_cliente);
      
      printf("Aceitamos apenas veículos de tamanhos 1, 2, 3 e 4.\nAperte enter para retornar\n");
      ESPERE_newline_para_retornar;
    }
    //////////////////////////////////////////////////////////////////////
    
    

    
    //////////////////////// LEITURA DA PLACA ////////////////////////////
    printf("Informe a placa do veículo:\t"); i = 0;
    while((c = (char) getchar()) != '\n'){
      //testa se o usuário está tentando passar mais de 4 dígitos
      if(i == 4){
	free(nome_do_cliente);
      
	FLUSH_input;
	printf("A placa do veículo deve possuir exatamente 4 dígitos NUMÉRICOS no formato:\t0000.\nAperte enter para retornar\n");
	ESPERE_newline_para_retornar;
      }
      
      //testa se o usuário está passando apenas dígitos
      if(isdigit(c))
	placa_do_veiculo[i++] = c;
      else{
	free(nome_do_cliente);
      
	FLUSH_input;
	printf("A placa do veículo deve possuir exatamente 4 dígitos NUMÉRICOS no formato:\t0000.\nAperte enter para retornar\n");
	ESPERE_newline_para_retornar;
      }
    }placa_do_veiculo[i] = '\0';
    
    //testa se o usuário passou menos de 4 digitos
    if(i < 4){
      free(nome_do_cliente);
    
      printf("A placa do veículo deve possuir exatamente 4 dígitos NUMÉRICOS no formato:\t0000.\nAperte enter para retornar\n");
      ESPERE_newline_para_retornar;
    }
    //////////////////////////////////////////////////////////////////////

    


    ////////////////////// LEITURA DO HORARIO ////////////////////////////
    printf("Informe a hora de entrada do veículo no formato HH:mm: ");
    scanf("%d:%d", &horas, &minutos);
    //esse if testa se o horário é válido
    if((horas > 24 || horas < 0) || (minutos > 59 || minutos < 0)){
      free(nome_do_cliente);
      
      FLUSH_input;
      printf("O horário informado é invalido!\nAperte enter para retornar\n");
      ESPERE_newline_para_retornar;
    }
    //////////////////////////////////////////////////////////////////////

    
  

    ////////////////// TESTE DE VALIDADE DA ENTRADA //////////////////////
    // o trecho de código a seguir testa se o carro já está no estacionamento
    for(i = 0; i <= 4; i++){
      for(j = 0; j <= 19; j++){
	if(CLIENTES[i][j].ocupado){
	  if(strcmp(CLIENTES[i][j].nome_do_cliente, nome_do_cliente) == 0){
	    if(strncmp(CLIENTES[i][j].placa_do_veiculo, placa_do_veiculo, 4) == 0){
	      if(CLIENTES[i][j].tamanho_do_veiculo == tamanho_do_veiculo){
		if(CLIENTES[i][j].horas == horas){
		  if(CLIENTES[i][j].minutos == minutos){
		    free(nome_do_cliente);
		    
		    FLUSH_input;
		    printf("Não foi possível estacionar o veículo. Aparentemente o veículo já está estacionado. Provavelmente ele foi clonado.\nAperte enter para retornar\n");
		    ESPERE_newline_para_retornar;
		  }
		}
	      }
	    }
	  }
	}
      }
    }
    //////////////////////////////////////////////////////////////////////


    

    //////////////// ADIÇÃO DA ENTRADA À ESTRUTURA DE DADOS ////////////////
    //esses dois laços tentam estacionar o carro
    for(i = 0; i <= 4; i++){
      for(j = 0; j <= 19; j++){
	//nesse trecho o carro é estacionado
	if(((j + tamanho_do_veiculo - 1) <= 19) && (CLIENTES[i][j].ocupado == 0)){
	  for(e = 0; e < tamanho_do_veiculo; e++){
	    CLIENTES[i][j+e].nome_do_cliente = nome_do_cliente;
	    CLIENTES[i][j+e].placa_do_veiculo[0] = placa_do_veiculo[0];
	    CLIENTES[i][j+e].placa_do_veiculo[1] = placa_do_veiculo[1];
	    CLIENTES[i][j+e].placa_do_veiculo[2] = placa_do_veiculo[2];
	    CLIENTES[i][j+e].placa_do_veiculo[3] = placa_do_veiculo[3];
	    CLIENTES[i][j+e].tamanho_do_veiculo = tamanho_do_veiculo;
	    CLIENTES[i][j+e].horas = horas;
	    CLIENTES[i][j+e].minutos = minutos;
	    CLIENTES[i][j+e].ocupado = 1;
	  }
	  
	  //atualização do historico
	  HISTORICO[carros].placa[0] = placa_do_veiculo[0];
	  HISTORICO[carros].placa[1] = placa_do_veiculo[1];
	  HISTORICO[carros].placa[2] = placa_do_veiculo[2];
	  HISTORICO[carros].placa[3] = placa_do_veiculo[3];
	  HISTORICO[carros].cliente = nome_do_cliente;
	  HISTORICO[carros].tamanho = tamanho_do_veiculo;
	  HISTORICO[carros].entrada[0] = horas;
	  HISTORICO[carros].entrada[1] = minutos;
	  HISTORICO[carros].saiu = 0;
	  
	  //atualização das informações do sistema
	  ++carros; ++carros_estacionados;
	  switch(CLIENTES[i][j].tamanho_do_veiculo){
	  case 1:
	    ++carros_tipo1;
	    break;
	  case 2:
	    ++carros_tipo2;
	    break;
	  case 3:
	    ++carros_tipo3;
	    break;
	  case 4:
	    ++carros_tipo4;
	    break;
	  }
	  
	  //Entrada bem sucedida
	  entrou_um_carro = 1;
	  
	  FLUSH_input;
	  printf("\nVeículo estacionado com sucesso.\nAperte enter para retornar\n");
	  ESPERE_newline_para_retornar;
	}
      }
    }
    
    //se a flag não possuir um valou verdadeiro não foi possivel estacionar o carro
    if(!entrou_um_carro){
      free(nome_do_cliente);
      
      FLUSH_input;
      printf("O estacionamento não consegue comportará um veículo desse tamanho até que outros veículos saiam.\nAperte enter para retornar\n");
      ESPERE_newline_para_retornar;
    }
    //////////////////////////////////////////////////////////////////////

  }else{   
    FLUSH_input;
    printf("\nA cota diária foi excedida, não aceitaremos novos veículos no dia de hoje\nAperte enter para retornar\n");
    ESPERE_newline_para_retornar;
  }
}




void saida(){
  int horas_cobradas; horas_cobradas = 0;
  int total_cobrado; total_cobrado = 0;
  int e, j, i, tamanho; e = 0; j = 0; i = 0; tamanho = 50;
  char c, *nome_do_cliente, placa_do_veiculo[4]; nome_do_cliente = MALLOC_char(nome_do_cliente, tamanho);
  int horas, horas_passadas, minutos, minutos_passados;
  int hist_indx; int saiu_um_carro; saiu_um_carro = 0;

  
 
  /////////////////// LEITURA DO NOME DO CLIENTE ///////////////////////
  printf("Informe o nome do cliente: ");
  FLUSH_input;

  //esse while lê o nome do cliente e coloca um '\0' ao final da leitura
  while((c = (char) getchar()) != '\n'){
    nome_do_cliente[i++] = c;
    if(i == tamanho)
      nome_do_cliente = REALLOC_char(nome_do_cliente, (tamanho*=2));
  }nome_do_cliente[i] = '\0';
  //////////////////////////////////////////////////////////////////////


  

  ////////////////////// LEITURA DA PLACA //////////////////////////////
  printf("Informe a placa do veículo:\t"); i = 0;
  while((c = (char) getchar()) != '\n'){

    //testa se o usuário está tentando passar mais de 4 dígitos
    if(i == 4){
      free(nome_do_cliente);
      
      FLUSH_input;
      printf("\nA placa do veículo deve possuir exatamente 4 dígitos NUMÉRICOS no formato:\t0000.\nAperte enter para retornar\n");
      ESPERE_newline_para_retornar;
    }

    //testa se o usuário está passando apenas dígitos
    if(isdigit(c))
      placa_do_veiculo[i++] = c;
    else{
      free(nome_do_cliente);
      
      FLUSH_input;
      printf("\nA placa do veículo deve possuir exatamente 4 dígitos NUMÉRICOS no formato:\t0000.\nAperte enter para retornar\n");
      ESPERE_newline_para_retornar;
    }
  }placa_do_veiculo[i] = '\0';

  //testa se o usuário passou menos de 4 digitos
  if(i < 4){
    free(nome_do_cliente);

    FLUSH_input;
    printf("\nA placa do veículo deve possuir exatamente 4 dígitos NUMÉRICOS no formato:\t0000.\nAperte enter para retornar\n");
    ESPERE_newline_para_retornar;
  }
  //////////////////////////////////////////////////////////////////////
  


  
  /////////////////////// LEITURA DO HORARIO ///////////////////////////
  printf("Informe a hora de saída do veículo no formato HH:mm: ");
  scanf("%d:%d", &horas, &minutos);

  //esse if testa se o horário é válido
  if((horas > 24 || horas < 0) || (minutos > 59 || minutos < 0)){
    free(nome_do_cliente);

    FLUSH_input;
    printf("\nO horário informado é invalido!\nAperte enter para retornar\n");
    ESPERE_newline_para_retornar;
  }
  //////////////////////////////////////////////////////////////////////

  
  

  /////////////////////// RETIRADA DO CARRO ////////////////////////////
  //testa se o carro informado está estacionado e em caso afirmativo o retira do estacionamento
  for(i = 0; i <= 4; i++){
    for(j = 0; j <= 19; j++){
      if(CLIENTES[i][j].ocupado){
	if(strcmp(CLIENTES[i][j].nome_do_cliente, nome_do_cliente) == 0){
	  if(strncmp(CLIENTES[i][j].placa_do_veiculo, placa_do_veiculo, 4) == 0){

	    //esse if testa se a horario da saida é mais cedo que o da entrada
	    if((CLIENTES[i][j].horas > horas) || ((CLIENTES[i][j].horas == horas) && (CLIENTES[i][j].minutos > minutos))){
	      free(nome_do_cliente);
	      
	      FLUSH_input;
	      printf("\nA hora de saída não pode ser antes da hora de entrada.\nAperte enter para retornar\n");
	      ESPERE_newline_para_retornar;	      
	    }else{
	      
	      //esse trecho de código calcula as horas passadas desde a entrada do veículo
	      horas_passadas = horas - CLIENTES[i][j].horas;
	      minutos_passados = minutos - CLIENTES[i][j].minutos;
	      if(horas_passadas == 0){
		horas_cobradas = 1;
		if(minutos_passados < 0)
		  minutos_passados = 60 - CLIENTES[i][j].minutos;
	      }else{
		if(minutos_passados < 0){
		  minutos_passados = 60 - CLIENTES[i][j].minutos;
		  --horas_passadas;
		}

		//testa se o cliente extrapolou a carência de 15 min
		if(minutos_passados > 15){
		    horas_cobradas = horas_passadas + 1;
		}else{
		  if(horas_passadas <= 1)
		    horas_cobradas = 1;
		  else
		    horas_cobradas = horas_passadas - 1;
		}
	      }

	      //calculo do valor pago
	      switch((CLIENTES[i][j].tamanho_do_veiculo)){
	      case 1:
		total_cobrado = horas_cobradas * 5;
		--carros_tipo1;
		break;
	      case 2:
		total_cobrado = horas_cobradas * 7;
		--carros_tipo2;
		break;
	      case 3:
		total_cobrado = horas_cobradas * 10;
		--carros_tipo3;
		break;
	      case 4:
		total_cobrado = horas_cobradas * 14;
		--carros_tipo4;
		break;
	      }arrecadacao += total_cobrado; --carros_estacionados;

	      //atualização do histórico
	      hist_indx = 0;
	      for(hist_indx = 0; hist_indx <= 100; hist_indx++){
		if(strncmp(HISTORICO[hist_indx].placa, CLIENTES[i][j].placa_do_veiculo, 4) == 0){
		  if(strcmp(HISTORICO[hist_indx].cliente, CLIENTES[i][j].nome_do_cliente) == 0){
		    if(HISTORICO[hist_indx].tamanho == CLIENTES[i][j].tamanho_do_veiculo){
		      HISTORICO[hist_indx].saida[0] = horas;
		      HISTORICO[hist_indx].saida[1] = minutos;
		      HISTORICO[hist_indx].permanencia[0] = horas_passadas;
		      HISTORICO[hist_indx].permanencia[1] = minutos_passados;
		      HISTORICO[hist_indx].horas_cobradas = horas_cobradas;
		      HISTORICO[hist_indx].valor_pago = total_cobrado;
		      HISTORICO[hist_indx].saiu = 1;
		    }
		  }
		}
	      }    

	      //Saida bem sucedida
	      saiu_um_carro = 1;
	      
	      for(e = 0; e < CLIENTES[i][j].tamanho_do_veiculo; e++)
		CLIENTES[i][j+e].ocupado = 0;
	      free(nome_do_cliente);
	      
	      FLUSH_input;
	      printf("\nVeículo retirado com sucesso. O veículo ficou %dh%dm estacionado. Serão cobradas %d horas. Valor total é de R$ %d.00.\nAperte enter para retornar\n", horas_passadas, minutos_passados, horas_cobradas, total_cobrado);
	      ESPERE_newline_para_retornar;
	    }
	  }
	}
      }
    }
  }

  if(!saiu_um_carro){//o carro informado não estava estacionado
    free(nome_do_cliente);
    
    FLUSH_input;
    printf("\nNão foi posssível encontrar o veículo no estacionamento. Provavelmente foi roubado.\nAperte enter para retornar\n");
    ESPERE_newline_para_retornar;
  }
  //////////////////////////////////////////////////////////////////////
}




void informacoes(){
  int vagas_tamanho1, vagas_tamanho2, vagas_tamanho3, vagas_tamanho4, total_tipo1, total_tipo2, total_tipo3, total_tipo4, total_carros, vagas_livres;

  //calculo do número de vagas ocupadas
  total_tipo1 = carros_tipo1 * 1;
  total_tipo2 = carros_tipo2 * 2;
  total_tipo3 = carros_tipo3 * 3;
  total_tipo4 = carros_tipo4 * 4;
  
  total_carros = total_tipo1 + total_tipo2 + total_tipo3 + total_tipo4; 
  vagas_livres = 100 - total_carros;
  
  vagas_tamanho1 = vagas_livres / 1;
  vagas_tamanho2 = vagas_livres / 2;
  vagas_tamanho3 = vagas_livres / 3;
  vagas_tamanho4 = vagas_livres / 4;

  FLUSH_input;

  printf("Detalhes atuais do sistema:\n\nNúmero de carros estacionados até agora: %d.\nQuantidade de veículos estacionados no momento: %d.\nValor arrecadado até agora: R$ %d.00.\n\nQuantidade de vagas para:\n\tTamanho 1 - %d vagas;\n\tTamanho 2 - %d vagas;\n\tTamanho 3 - %d vagas;\n\tTamanho 4 - %d vagas;\n\nAperte enter para retornar\n", carros, carros_estacionados, arrecadacao, vagas_tamanho1, vagas_tamanho2, vagas_tamanho3, vagas_tamanho4);
  ESPERE_newline_para_retornar;
}




void mapa(){
  int i, j;
  
  //o campo 'coupado' da struct CLIENTE é usada para a impressão do mapa
  printf("Mapa do Sistema\n");
  for(i = 4; i >= 0; i--){
    printf("Andar %d:", (i+1));
    for(j = 0; j <= 19; j++){
      if(CLIENTES[i][j].ocupado == 1)
	printf(" *");
      else
	printf(" -");
    }
    printf("\n");
  }

  FLUSH_input;
  
  printf("\nAperte enter para retornar\n");
  ESPERE_newline_para_retornar;
}




void historico(){
  int i; i = 0;
  int j; j = 0;
  char c, placa_do_veiculo[5];
  int achou_a_placa; achou_a_placa = 0;

  
  FLUSH_input;

  //////////////////////// LEITURA DA PLACA //////////////////////////
  printf("Informe a placa do veículo:\t"); i = 0;
  while((c = (char) getchar()) != '\n'){
    //testa se o usuário está tentando passar mais de 4 dígitos
    if(i == 4){
      
      FLUSH_input;
      printf("\nA placa do veículo deve possuir exatamente 4 dígitos NUMÉRICOS no formato:\t0000.\nAperte enter para retornar\n");
      ESPERE_newline_para_retornar;
    }
    
    //testa se o usuário está passando apenas dígitos
    if(isdigit(c))
      placa_do_veiculo[i++] = c;
    else{
      
      FLUSH_input;
      printf("\nA placa do veículo deve possuir exatamente 4 dígitos NUMÉRICOS no formato:\t0000.\nAperte enter para retornar\n");
      ESPERE_newline_para_retornar;
    }
  }placa_do_veiculo[i] = '\0';
  
  //testa se o usuário passou menos de 4 digitos
  if(i < 4){
    
    printf("\nA placa do veículo deve possuir exatamente 4 dígitos NUMÉRICOS no formato:\t0000.\nAperte enter para retornar\n");
    ESPERE_newline_para_retornar;
  }
  //////////////////////////////////////////////////////////////////////

  


  ////////////////////// IMPRESSÃO DO HISTÓRICO ////////////////////////
  j = 1;
  for(i = 0; i <= 100; i++){
    if(strncmp(HISTORICO[i].placa, placa_do_veiculo, 4) == 0){
      achou_a_placa = 1;
      if(HISTORICO[i].saiu){
	printf("\nEntrada número %d do veículo:\t%s.\n\tEstacionado por %s.\n\tTamanho: %d.\n\tHorário de entrada: %02d:%02d.\n\tHorário de saída: %02d:%02d.\n\tTempo permanecido: %02dh:%02dm.\n\tHoras cobradas: %02d.\n\tValor pago: R$ %d.00.\n", j++, HISTORICO[i].placa, HISTORICO[i].cliente, HISTORICO[i].tamanho, HISTORICO[i].entrada[0], HISTORICO[i].entrada[1], HISTORICO[i].saida[0], HISTORICO[i].saida[1],  HISTORICO[i].permanencia[0], HISTORICO[i].permanencia[1], HISTORICO[i].horas_cobradas, HISTORICO[i].valor_pago);
      }else{
	printf("\nEntrada número %d do veículo:\t%s.\n\tEstacionado por %s.\n\tTamanho: %d.\n\tHorário de entrada: %02d:%02d.\n", j++, HISTORICO[i].placa, HISTORICO[i].cliente, HISTORICO[i].tamanho, HISTORICO[i].entrada[0], HISTORICO[i].entrada[1]);
      }
    }
  }
  if(!achou_a_placa){
      printf("\nO veículo não foi localizado no histórico do sistema.\nAperte enter para retornar\n");
      ESPERE_newline_para_retornar;
  }else{
    printf("\nAperte enter para retornar\n");
      ESPERE_newline_para_retornar;
  }
  //////////////////////////////////////////////////////////////////////
}




void finalizar(){
  int i, j;

  for(i = 0; i <= 4; ++i){
    for(j = 0; j <= 19; ++j){
      //////para evitar double free aqui, após liberar a string de um nome eu pulo os espaços ocupados pelo mesmo nome
      if((CLIENTES[i][j].ocupado) == 1){
	free(CLIENTES[i][j].nome_do_cliente);
	j+=CLIENTES[i][j].tamanho_do_veiculo;
      }
    }
  }
  
  //esse free libera as strings alocadas para os carros que saíram, que não puderam ser liberadas no loop acima
  for(i = 0; i <= 100; i++){
    if(HISTORICO[i].saiu){
      free(HISTORICO[i].cliente);
    }
  }
}
