#include "usable.t1.t2.h"

/*sterg spatiile sau tab.urile ramase */
char *clearContentChar(char *nume) {
  for (int i = 0; nume[i] != '\0'; i++) {
    if (nume[i] == '\n' || nume[i] == '\t' || nume[i] == ' ') {
      nume[i] = '\0';
    }
  }
  return nume;
}

/*verific daca un pointer este NULL*/
int checkIfIsNull(void *any_pointer) {
  if (any_pointer == NULL) {
    ERROR_1_MEM_ERROR/*afisez codul de eroare->definit in usable.t1.t2.h*/
    exit(1);
    return 1;
  } else {
    return 0;
  }
}
