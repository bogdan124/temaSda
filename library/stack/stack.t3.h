#include "../structs/structs.h"
#include "../alocmem/alocmem.h"

#ifndef STACK
#define STACK
  /*stack functions*/
  void pushStack(stackNode **stack, Country *valueToAdd);
  Country *popStack(stackNode **stack);
  int emptyStack(stackNode *stack);
#endif
