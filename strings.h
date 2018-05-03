#include <string.h>
#include <stdlib.h>

#define MALLOC_char(nome, tamanho) nome = ((char*) malloc(sizeof(char) * tamanho)); if(nome == NULL) abort()
#define REALLOC_char(nome, tamanho) ((char*) realloc(nome, sizeof(char) * tamanho)); if(nome == NULL) abort()


char* nova_string();
char* AUMENTA_string(char* STRING_pequena, int *TAMANHO);
