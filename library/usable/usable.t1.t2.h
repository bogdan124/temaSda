#include "../structs/structs.h"
#include "../alocmem/alocmem.h"
#include <stdio.h>
#ifndef USABLE
#define USABLE
#define ERROR_1_MEM_ERROR printf("\nERROR 1:Memory alocation problem\n");
#define NO_PROPERLY_FILENAME(x) \
  printf("\n ERROR 2:file %d doesn't have a specific name\n", x);
  /*sterg spatiile sau tab.urile ramase*/
  char *clearContentChar(char *nume);
  /*verific daca un pointer este NULL*/
  int checkIfIsNull(void *any_pointer);
#endif
