
#include "task2.h"

/*rezolva task-ul 2*/
/*Parametrii: numarul de corespunzator pentru cea mai mica putere a lui 2
 *| adresa santinelei si numarul de tari | fisierele cele 3
 */
void task2(int smallPow2, RETURN_POINT_FLOAT getTask1, char **files) {
  /*am un vector cu adresele din lista si scorul lor*/
  INDEX *indexSantinelaSearch;
  int j = 0;

  /* ma ajuta sa caut mai usor fara sa calculez valorile minime de mai multe ori */
  indexSantinelaSearch = buildIndexForSearch(getTask1);
  /*parcurgem sirul pentru a elimina tarile din lista */
  while (indexSantinelaSearch[j].scoreMinim <
         indexSantinelaSearch[getTask1.val - smallPow2].scoreMinim) {
    /*sterg element din lista delNodeDoubleListEnd()->lists/createList.t1.t2*/
    delNodeDoubleListEnd(indexSantinelaSearch[j].ctrName);

    j++;
  }
  /*salvez adresa de inceput*/
  C__NAMES__ *__saveStartAdress__;
  __saveStartAdress__ = getTask1.nameCountry->next;
  /*parcurg lista inlantuita*/
  while (__saveStartAdress__->nameCountry != NULL) {
    /*parcurg vectorul cu elemnte de tip INDEX*/
    for (int i = getTask1.val - smallPow2; i < getTask1.val; i++) {
      /*verific daca se gasesc elemetele din vector in lista*/
      if (strcmp(__saveStartAdress__->nameCountry->name,
                 indexSantinelaSearch[i].ctrName->nameCountry->name) == 0) {
        /*scriu in fisier writeToFile()->filesFunc/file.ALL_TASK*/
        writeToFile(files[3], __saveStartAdress__->nameCountry->name);
        writeToFile(files[3], "\n");
      }
    }
    /*merg la urmatorul element din lista*/
    __saveStartAdress__ = __saveStartAdress__->next;
  }
}

/*creez vectorul cu elemente de tip INDEX*/
INDEX *buildIndexForSearch(RETURN_POINT_FLOAT getTask1) {
  /*tin adresa de inceput la vectorul cu elemente de tip INDEX*/
  INDEX *indexSantinelaSearch;
  C__NAMES__ *__saveStartAdress__;
  /*j-ul il folosesc pentru a incrementa*/
  int j = 0;
  /*ii aloc memorie alocIndex()->alocmem*/
  indexSantinelaSearch = alocIndex(getTask1.val + 1);
  /*ma mut pe prima pozite din lista*/
  __saveStartAdress__ = getTask1.nameCountry->next;
  /*parcurg lista cat timp nu a ajuns la santinela*/
  while (__saveStartAdress__->nameCountry != NULL) {
    indexSantinelaSearch[j].ctrName = __saveStartAdress__;
    indexSantinelaSearch[j].scoreMinim = 0;
    /*parcurg jucatorii de la tara*/
    for (int i = 0; i < __saveStartAdress__->nameCountry->nr_players; i++) {
      /*pun scorul lor in vectorul INDEX*/
      indexSantinelaSearch[j].scoreMinim +=
          __saveStartAdress__->nameCountry->players[i].score;
    }
    /*si il impart la numarul de jucatori pentru tara respectiva*/
    indexSantinelaSearch[j].scoreMinim =
        (indexSantinelaSearch[j].scoreMinim) /
        (__saveStartAdress__->nameCountry->nr_players);
    /*ma mut la urmatorul element din lista*/
    __saveStartAdress__ = __saveStartAdress__->next;
    j++;
  }
  /*eliberez __saveStartAdress__*/
  free(__saveStartAdress__);
  /*sortez vectorul cu elemente de tip INDEX*/
  indexSantinelaSearch = sortFunc(indexSantinelaSearch, getTask1.val);
  /*returnez index-ul*/
  return indexSantinelaSearch;
}
