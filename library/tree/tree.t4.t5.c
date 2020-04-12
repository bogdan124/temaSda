
#include "tree.t4.t5.h"

/*creez un nod*/
TREE *newNode(Player data) {
  TREE *node = (TREE *)malloc(sizeof(TREE));
  node->val = data;
  node->left = node->right = NULL;
  return node;
}

/*adaug elemente in BST*/
TREE *insert(TREE *node, Player key) {
  if (node == NULL) {
    return newNode(key);
  }
  if (key.score < node->val.score) {
    node->left = insert(node->left, key);
  } else if (key.score > node->val.score) {
    node->right = insert(node->right, key);
  } else if (key.score == node->val.score) {
    if (strcmp(key.first_name, node->val.first_name) < 0) {
      node->val = key;
    } else if (strcmp(key.last_name, node->val.last_name) == 0) {
      if (strcmp(key.last_name, node->val.last_name) < 0) {
        node->val = key;
      }
    }
  }
  return node;
}

/*parcurg BST-ul*/
/*parametrii : adresa si fisierele cele 3*/
void inordine(TREE *root, char **files) {
  if (root) {
    inordine(root->right, files);
    /*scriu valorile din BST in fiser*/
    writeToFile(files[3], root->val.first_name);
    writeToFile(files[3], " ");
    writeToFile(files[3], root->val.last_name);
    writeToFile(files[3], " ");
    writeToFileIntValues(files[3], root->val.score);
    writeToFile(files[3], "\n");
    inordine(root->left, files);
  }
}
