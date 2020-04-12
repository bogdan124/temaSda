#include "alocmem.h"

/*functia de alocare pentru TREE*/
TREE *alocTree(int n) {

  TREE *charaloc;

  charaloc = (TREE *)malloc((n + 1) * sizeof(TREE));
  checkIfIsNull(charaloc);

  return charaloc;
}

/*functia de alocare pentru stackNode*/
stackNode *alocStackNode(int n) {

  stackNode *alocStack;

  alocStack = (stackNode *)malloc(n * sizeof(stackNode));
  checkIfIsNull(alocStack);
  return alocStack;
}

/*functia de alocare pentru int*/
int *alocInt(int n) {

  int *charaloc;

  charaloc = (int *)malloc((n + 1) * sizeof(int));
  checkIfIsNull(charaloc);

  return charaloc;
}

/*functia de alocare pentru Char*/
char *aloChar(int n) {

  char *charaloc;

  charaloc = (char *)malloc((n + 1) * sizeof(char));
  checkIfIsNull(charaloc);

  return charaloc;
}

/*functia de alocare pentru Player*/
Player *aloPlayer(int n) {

  Player *charaloc;

  charaloc = (Player *)malloc(n * sizeof(Player));
  checkIfIsNull(charaloc);

  return charaloc;
}

/*functia de alocare pentru Country*/
Country *aloCountry(int n) {

  Country *charaloc;

  charaloc = (Country *)malloc(n * sizeof(Country));
  checkIfIsNull(charaloc);

  return charaloc;
}

/*functia de alocare pentru index*/
INDEX *alocIndex(int n) {

  INDEX *charaloc;

  charaloc = (INDEX *)malloc(n * sizeof(INDEX));
  checkIfIsNull(charaloc);

  return charaloc;
}

Player *createPlayerStivInit(int numberOfplayers) {
  Player *playerCreate;
  playerCreate = (Player *)malloc(numberOfplayers * sizeof(Player));
  checkIfIsNull(playerCreate);
  return playerCreate;
}
