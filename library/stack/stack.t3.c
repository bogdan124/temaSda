
#include "stack.t3.h"

/* pushStack adaug stack elemnte de tip country*/
void pushStack(stackNode **stack, Country *valueToAdd) {
  stackNode *save;
  save = alocStackNode(1);
  save->content = valueToAdd;
  save->prev = (*stack);
  *stack = save;
}

/*verific daca este gol stack-ul*/
int emptyStack(stackNode *stack) {
  if (stack == NULL) {
    return 1;
  } else {
    return 0;
  }
}

/*scot elemente din stack*/
Country *popStack(stackNode **stack) {
  if (emptyStack(*stack) == 1) {
    return NULL;
  }
  stackNode *save;
  Country *saveNode;
  save = (*stack);
  saveNode = save->content;
  (*stack) = (*stack)->prev;

  free(save);
  return saveNode;
}
