#include "strings.h"

char* nova_string(){
  char* NOVA_STRING;
  MALLOC_char(NOVA_STRING, 40);

  return NOVA_STRING;
}

char* AUMENTA_string(char* STRING_pequena, int *TAMANHO){
  char* STRING_MAIOR;
  STRING_MAIOR = REALLOC_char(STRING_pequena, (*(TAMANHO)) * 2);
  (*(TAMANHO)) *= 2;

  return STRING_MAIOR;
}
