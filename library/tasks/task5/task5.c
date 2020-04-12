#include "task5.h"

/* Parametrii: adresa root,fisierele,jucatorul 1 din cerinte,jucatorul2 din cerinte,
 * numarul care trebuie afisat pentru task-ul 5,isOk1 verific existenta jucatorului 1,
 * verific existenta jucatorului 2
 */
void task5(TREE *root, char **files, Player player1, Player player2,
           int *number, int *isOK1, int *isOK2) {
  if (root) {
    /*parcurgem partea dreapta mai intai*/
    task5(root->right, files, player1, player2, number, isOK1, isOK2);
    /*verificam exsiteta jucatorului 1*/
    if (strcmp(root->val.last_name, player1.last_name) == 0 &&
        strcmp(root->val.first_name, player1.first_name) == 0) {
      (*isOK1)++;
    }
    /*verificam existenta jucatorului 2*/
    if (strcmp(root->val.last_name, player2.last_name) == 0 &&
        strcmp(root->val.first_name, player2.first_name) == 0) {
      (*isOK2)++;
    }
    /*gasesc jucatorii cu valorile cuprinse intre cele 2 valori in BST*/
    if (player1.score < root->val.score && root->val.score < player2.score) {
      (*number) += 1;
    }
    /*parcurg partea stanga */
    task5(root->left, files, player1, player2, number, isOK1, isOK2);
  }
}
