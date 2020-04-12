#include "createList.t1.t2.h"

/*adaug nod la sfarsitul listei*/
C__NAMES__ *addNodeDoubleListEnd(C__NAMES__ **listEndNode) {
  /*aloc un nod nou*/
  C__NAMES__ *alocNewNode;
  alocNewNode = (C__NAMES__ *)malloc(1 * sizeof(C__NAMES__));
  /*verific daca ce am alocat este null*/
  checkIfIsNull(alocNewNode);
  /*aici atribui nodul la lista*/
  (*listEndNode)->next = alocNewNode;
  alocNewNode->prev = (*listEndNode);
  alocNewNode->next = alocNewNode;
  /*returnez nodul*/
  return alocNewNode;
}
/*termin lista inlantuita si unesc cele 2 capete ale ei*/
C__NAMES__ *finishList(C__NAMES__ **endList, C__NAMES__ **startList) {
  (*startList)->prev = (*endList);
  (*endList)->next = (*startList);
}
/*adaug santinela la inceput si sfarsit*/
C__NAMES__ *addSentinel(C__NAMES__ **startList, C__NAMES__ **finishList) {
  C__NAMES__ *alocNewNode;
  /*aloc nod*/
  alocNewNode = (C__NAMES__ *)malloc(1 * sizeof(C__NAMES__));
  /*verific daca este null*/
  checkIfIsNull(alocNewNode);
  /*valoarea santinelei este null*/
  alocNewNode->nameCountry = NULL;
  /*ii atribui incetul si sfarsitul listei la santinela*/
  (*startList)->prev = alocNewNode;
  alocNewNode->next = (*startList);
  (*finishList)->next = alocNewNode;
  alocNewNode->prev = (*finishList);
  /*returnez santinela*/
  return alocNewNode;
}

void delNodeDoubleListEnd(C__NAMES__ *listNodeToDelete) {
  /*daca nu a ajuns la santinela*/
  if (listNodeToDelete->next->nameCountry != NULL &&
      listNodeToDelete->prev->nameCountry != NULL) { /*daca se afla la mijloc*/
    (listNodeToDelete->prev)->next = listNodeToDelete->next;
    (listNodeToDelete->next)->prev = listNodeToDelete->prev;
  } else if (listNodeToDelete->prev->nameCountry == NULL) { /*daca este primul nodde*/
    (listNodeToDelete->prev)->next = (listNodeToDelete->next);
    (listNodeToDelete->next)->prev = (listNodeToDelete->prev);
  } else if (listNodeToDelete->next->nameCountry == NULL) { /*daca este ultimul node*/
    /*daca a ajuns la santinela*/
    (listNodeToDelete->next)->prev = (listNodeToDelete->prev);
    (listNodeToDelete->prev)->prev = (listNodeToDelete->next);
  }
  /*eliberez memoria*/
  free(listNodeToDelete);
}
/*initializez lista*/
C__NAMES__ *initDoubleList() {
  C__NAMES__ *start;
  /*aloc memoria*/
  start = (C__NAMES__ *)malloc(1 * sizeof(C__NAMES__));
  /*verific daca este null*/
  checkIfIsNull(start);
  start->prev = start;
  start->next = start;
  /*returnez adresa de start*/
  return start;
}
/*punem datele in lista*/
void putDataIntoList(C__NAMES__ **listEndNode, char *nameTara, int nrPlayers) {
  /*aloca o tara*/
  (*listEndNode)->nameCountry = aloCountry(1);
  /*initializez scorul global cu 0*/
  (*listEndNode)->nameCountry->global_score = 0;
  /*aloc numele tarii*/
  (*listEndNode)->nameCountry->name = aloChar(strlen(nameTara));
  /*adaug numarul de players*/
  (*listEndNode)->nameCountry->nr_players = nrPlayers;
  nameTara = clearContentChar(nameTara);
  strcpy((*listEndNode)->nameCountry->name, nameTara);
}
