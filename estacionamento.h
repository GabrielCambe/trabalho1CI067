#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ESPERE_newline_para_retornar while(getchar() != '\n'); return
#define FLUSH_input while(getchar() != '\n')
#define CLRscr (void) system("clear")
#define MAX_CARROS 100
#define TRUE (1==1)

#define MALLOC_char(nome, tamanho) nome = ((char*) malloc((sizeof(char) * tamanho))); if(nome == NULL) abort()
#define REALLOC_char(nome, tamanho) ((char*) realloc(nome, (sizeof(char) * tamanho))); if(nome == NULL) abort()

typedef struct{
  char placa[5];
  char *cliente;
  int tamanho;
  int entrada[3];
  int saida[3];
  int permanencia[3];
  int horas_cobradas;
  int valor_pago;
  int saiu;
}HISTORICO_t;

typedef struct{
  char *nome_do_cliente;
  
  char placa_do_veiculo[4];
  int tamanho_do_veiculo, horas, minutos;

  int ocupado;
}CLIENTE_t;

HISTORICO_t HISTORICO[120];
CLIENTE_t CLIENTES[5][20]; //fiz uma matriz de structs para representar o estacionamento pois isso facilitou a lógica do problema
int arrecadacao;//coloquei int pois a somaa dos valores cobrados sempre será inteira, visto que é cobrado por hora e o valor pra cada carro também é inteiro
int carros_estacionados, carros, carros_tipo1, carros_tipo2, carros_tipo3, carros_tipo4;

void inicializar();
void menu();
void entrada();
void saida();
void informacoes();
void mapa();
void historico();   
void finalizar();
