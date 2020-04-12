#include "../structs/structs.h"
#include "../alocmem/alocmem.h"
#include "../filesFunc/file.ALL_TASK.h"
#ifndef TREE_S
#define TREE_S
  TREE *insert(TREE *node, Player key);
  TREE *newNode(Player data);
  void inordine(TREE *root, char **files);
#endif
