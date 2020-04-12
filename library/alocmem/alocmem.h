#include "../structs/structs.h"
#include <stdlib.h>
#ifndef MATHLIB
#define MATHLIB
  /*aici sunt functiile pentru alocare*/
  /*aloc n elemente de tip Country*/
  Country *aloCountry(int n);
  /*aloc n elemente de tip Char*/
  char *aloChar(int n);
  /*aloc n elemente de tip INDEX*/
  INDEX *alocIndex(int n);
  /*aloc n elemente de tip int*/
  int *alocInt(int n);
  /*aloc n elemente de tip stackNode*/
  stackNode *alocStackNode(int n);
  /*aloc n elemente de tip TREE*/
  TREE *alocTree(int n);
  Player *createPlayerStivInit(int numberOfplayers);
  /*verific daca este NULL un pointer de mai sus*/
  int checkIfIsNull(void *any_pointer);
#endif
