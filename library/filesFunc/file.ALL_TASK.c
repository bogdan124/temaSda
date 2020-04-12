
#include "file.ALL_TASK.h"

/*citesc din fisier*/
/*parametrii: cele trei fisiere date ca parametrii la executabil*/
/*returnez numarul de tari si santinela*/
RETURN_POINT_FLOAT readFromFile(char *filenameOne,
                                char *filenameTwo,
                                char *filenameThree) {
  /*fisierul din care citesc*/
  FILE *f;
  /*citeste numarul de tari primul numar din fisier*/
  int num_date;
  int i = 0;
  int j = 0;
  /*contorizeaza numarul de linii de la o tara la alta din fisier*/
  int count = 0;
  /*citim numarul de jucatori per tara*/
  int playersNumPerCountry;
  /*salvam numarul de jucatori per tara */
  int saveNumPlayersPerCountry;

  int initData = 0;
  /* stochez vectorul cu jucatori pentru o tara */
  Player *playerStiv;
  /* valoarea aceasta va fi returnata de catre functie*/
  RETURN_POINT_FLOAT returnHelp;
  /*stocam adresa de inceput*/
  C__NAMES__ *__storeStartAdress__;
  /*stocam adresa de sfarsit a listei*/
  C__NAMES__ *__storeFinishAdress__;
  /*aici se stocheaza ce se citeste din fisier*/
  char *bufferToStore = aloChar(300);
  /*stochez primul nume al jucatorului*/
  char *first_name;
  /*stochez al doilea nume al jucatorului*/
  char *second_name;
  /*stochez scorul jucatorului*/
  char *scorePlayer;
  /*
   * trebuie sa sterg continutul fisierului
   * rezultate.out in caz ca a fost scris
   * inainte
   * clearContentOfAFile()->se afla in filesFunc/file.ALL_TASK
   */
  clearContentOfAFile(filenameThree);
  /*
   * Practic imi extrage direct tarile din fisier sau jucatorii in functie de ce
   * vreau eu sa-mi extraga
   * asta fac cele 2 while-uri.
   * Cititul este vazut ca pe o matrice
   * astfel tara este linia iar jucatorii sunt colonele
   */
   /*
    * aici este definita lungimea buffer-ului
    * adica a lui bufferToStore
    */
  size_t buffer_size = 300;
  /* filenameTwo este date.in */
  f = fopen(filenameTwo, "r");
  /* verific daca f este NULL */
  checkIfIsNull(f);
  /* citeste numarul de tari din fisier */
  fscanf(f, "%d", &num_date);
  /*cat timp nu numarul de jucatori nu mai poate fi gasit*/
  while (playersNumPerCountry != EOF) {
    /*citim numarul de jucatori per tara*/
    fscanf(f, "%d", &playersNumPerCountry);
    /*salvam numarul de jucatori per tara */
    saveNumPlayersPerCountry = playersNumPerCountry;
    /*daca cumva se intampla ca numarul de jucatori sa fie negativ dam break*/
    if (playersNumPerCountry <= 0) {
      break;
    }
    /*+2 deoarece incepem sa citim de la numele tarii*/
    playersNumPerCountry = playersNumPerCountry + 2;
    /*
     * aici creez un vector de tip Player unde sunt toti jucatorii de la tara respectiva
     * apoi aceasta structura va fi "conectata" la tara
     * createPlayerStivInit()->se afla alocmem/alocmem
     */
    playerStiv = createPlayerStivInit(saveNumPlayersPerCountry);
    /*cat timp numarul de jucatori per tara nu a ajuns la 0*/
    while (playersNumPerCountry != 0) {
      /*aici citesc datele din fisier*/
      getline(&bufferToStore, &buffer_size, f);
      /*aici luam tarile*/
      if (count == 1) {
        /*
         * primul element ne va crea lista initData are rol de  boolean
         * initData ne spune daca am creat sau nu primul element din lista
         * adica daca este primul element din lista
         */
        if (initData == 0) {
          /* salvam primul elment din lista
           * initDoubleList()->se afla in Lists/createList.t1.t2
           */
          __storeStartAdress__ = initDoubleList();
          /* adresa de final este egala cu cea de start */
          __storeFinishAdress__ = __storeStartAdress__;
          /* initData este 1 deoarece a creat primul element din lista */
          initData = 1;
        } else {
          /* adaugam cate un nod la sfarsit addNodeDoubleListEnd/createList.t1.t2 */
          __storeFinishAdress__ = addNodeDoubleListEnd(&__storeFinishAdress__);
        }
        /* scriem in fisier ce am citit din buffer in rezultate.out pentru primul task1 */
        /* writeToFile->se afla filesFunc/file.ALL_TASK */
        writeToFile(filenameThree, bufferToStore);
        /*scrie datele in lista*/
        putDataIntoList(&__storeFinishAdress__, bufferToStore,
                        saveNumPlayersPerCountry);
        /*eliberez bufferToStore*/
        free(bufferToStore);
      } else {
        /*verific sa nu avem caractere "speciale" care sa-mi influenteze programul mai incolo */
        if (bufferToStore[0] != '\n' && bufferToStore[0] != '\t') {
          /*
           * extragem primul nume din bufferToStore,
           * bufferToStore este ceva de genul Ferrer David 24
           * aici extragem Ferrer
           */
          first_name = strtok(bufferToStore, " ");
          /* extragem David */
          second_name = strtok(NULL, " ");
          /* extragem 24 */
          scorePlayer = strtok(NULL, " ");
          /*
           *  punem in vectorul de la tara respectiva
           *  se afla in fisierul acesta
           */
          pushPlayerStiv(playerStiv, first_name, second_name, atoi(scorePlayer),
                         saveNumPlayersPerCountry);
        }
        /*eliberez memoria pentru bufferToStore*/
        free(bufferToStore);
      }
      /*aloca buffer to store*/
      bufferToStore = aloChar(300);
      /*crestem numarul de linii*/
      count++;
      /*scadem din jucatori cititi*/
      playersNumPerCountry--;
    }
    /*stochez toti jucatorii pe care i-am citit pentru o tara */
    __storeFinishAdress__->nameCountry->players = playerStiv;
    /*am ajuns la o noua tara*/
    count = 0;
  }
  /*
   * adaugam la finalul listei un nod
   * addNodeDoubleListEnd()->lists/createList.t1.t2
   */
  __storeFinishAdress__ = addNodeDoubleListEnd(&__storeFinishAdress__);
  /*
   * punem date in nodul adaugat
   * putDataIntoList()->lists/createList.t1.t2
   */
  putDataIntoList(&__storeFinishAdress__, bufferToStore,
                  saveNumPlayersPerCountry);
  /*
    Aici adaugam santinela care conecteaza nodul de inceput cu ea
    si cel de sfarsit tot cu ea
    addSentinel()->lists/createList.t1.t2
  */
  __storeFinishAdress__ =
      addSentinel(&__storeStartAdress__, &__storeFinishAdress__);
  /* inchide fisierul*/
  fclose(f);
  /*
   * punem in returnHelp ce ar trebuii sa returneze
   * nodul de sfarsit
   */
  returnHelp.nameCountry = __storeFinishAdress__;
  /*numarul de tari din fisier*/
  returnHelp.val = num_date;
  /*eliberez memoria pentru buffer*/
  free(bufferToStore);
  /*eliberez memoria pentru first_name*/
  free(first_name);
  /*returnez returnHelp*/
  return returnHelp;
}

/*aici imi scrie intr-un fisier un tip de date int*/
/*parametrii: numele fisierului, int.ul care vreau sa fi scris*/
void writeToFileIntValues(char *filenameToWrite, int whatToWrite) {
  FILE *f = NULL;

  f = fopen(filenameToWrite, "a");

  if (f == NULL) {
    printf("\nERROR:On writing in file.\n");
  }

  fprintf(f, "%d", whatToWrite);
  fclose(f);
}

/*aici imi scrie intr-un fisier un tip de date char*/
/*parametrii: numele fisierului, ce sa scriuin fisier*/
void *writeToFile(char *filenameToWrite, char *whatToWrite) {
  FILE *f = NULL;

  f = fopen(filenameToWrite, "a");

  if (f == NULL) {
    createFileToWrite(filenameToWrite, whatToWrite);
  }

  fprintf(f, "%s", whatToWrite);
  fclose(f);
}

/*aici imi genereaza fisierul*/
/*parametrii: numele fisierului , ce scriu in el*/
void createFileToWrite(char *filenameToWrite, char *whatToWrite) {
  FILE *g;
  g = fopen(filenameToWrite, "w");
  checkIfIsNull(g);
  fprintf(g, "%s", whatToWrite);
  fclose(g);
}

/*aici imi sterge tot continutul fisierului*/
/*parametrii: numele fisierului*/
void clearContentOfAFile(char *filename) {
  FILE *f;
  f = fopen(filename, "w");
  checkIfIsNull(f);
  fclose(f);
}

/*aici imi aloca spatiu pentru un player*/
void pushPlayerStiv(Player *stivPlayer, char *first_name, char *last_name,
                    int score_player, int numberOfplayers) {
  for (int i = 0; i < numberOfplayers; i++) {
    if (stivPlayer[i].first_name == NULL && stivPlayer[i].last_name == NULL) {
      stivPlayer[i].first_name = aloChar(strlen(first_name));
      stivPlayer[i].last_name = aloChar(strlen(last_name));
      strcpy(stivPlayer[i].first_name, first_name);
      strcpy(stivPlayer[i].last_name, last_name);
      stivPlayer[i].score = score_player;
      break;
    }
  }
}
