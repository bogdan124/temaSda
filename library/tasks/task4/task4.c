#include "task4.h"

/*Se rezolva task-ul 4*/
/*parametrii: cele 4 tari, cele 3 fisiere*/
TREE *task4(Country *savePlayersForTask4, char **files) {
  /*stocam jucatorul din root*/
  Player saveRootPlayer;
  /*root nod pentru BST*/
  TREE *root;
  /*rol de increment al lui j*/
  int j = 0;
  /*aflam jucatorul cu scorul minim*/
  int min_score = 0;
  /*stocheaza suma total a tuturor jucatorilor de cele 4 tari*/
  int numberOfplayers = 0;
  /*adresa root este null la inceput*/
  root = NULL;
  /*scrie in fisier filesFunc/file.ALL_TASK*/
  writeToFile(files[3], "\n====== CLASAMENT JUCATORI ======\n");
  /*afla totalul de playeri pentru cele 4 tari*/
  while (j != 4) {
    /*adunam toti jucatorii aici*/
    numberOfplayers += savePlayersForTask4[j].nr_players;
    /*incrementam j -ul*/
    j++;
  }
  /*la inceput jucatorul minim il punem pe primul*/
  min_score = savePlayersForTask4[0].players[0].score;
  /*primul jucator din BST adica cel pe care o sa-l punem in varf*/
  saveRootPlayer = savePlayersForTask4[0].players[0];
  /*parcurgem cele 4 tari*/
  for (int i = 0; i < 4; i++) {
    /*parcurgem jucatorii de la fiecare tara in spate*/
    for (int y = 0; y < savePlayersForTask4[i].nr_players; y++) {
      /*aflam scorul minim*/
      if (min_score > savePlayersForTask4[i].players[y].score) {
        /*stocam scorul minim in min_score*/
        min_score = savePlayersForTask4[i].players[y].score;
        /*si player-ul in saveRootPlayer*/
        saveRootPlayer = savePlayersForTask4[i].players[y];
        /*daca gasim un score egal cu minimul pe care il avem*/
      } else if (min_score == savePlayersForTask4[i].players[y].score) {
        /* aici se compar lexigrafic*/
        if (strcmp(savePlayersForTask4[i].players[y].last_name, saveRootPlayer.last_name) < 0) {
          /*inlocuim ce avem in saveRootPlayer cu noul root*/
          saveRootPlayer = savePlayersForTask4[i].players[y];
          /*aici verific cazul in care au acelasi last_name din punct de vedere lexigrafic*/
        } else if (strcmp(savePlayersForTask4[i].players[y].last_name, saveRootPlayer.last_name) == 0) {
          /*atunci compar first_name-ul lor */
          if (strcmp(savePlayersForTask4[i].players[y].first_name, saveRootPlayer.first_name) < 0) {
            /*si salvez in saveRootPlayer player-ul*/
            saveRootPlayer = savePlayersForTask4[i].players[y];
          }
        }
      }
    }
  }
  /*newNode()->tree/tree.t4.t5.c*/
  root = newNode(saveRootPlayer);
  /*parcurg cele 4 tari*/
  for (int i = 0; i < 4; i++) {
    /*parcurg jucatorii din cele 4 tari*/
    for (int y = 0; y < savePlayersForTask4[i].nr_players; y++) {
      /*
       * si ii pun in lista
       * insert()->tree/tree.t4.t5.c
       */
      root = insert(root, savePlayersForTask4[i].players[y]);
    }
  }
  /*inordine()->tree/tree.t4.t5.c*/
  inordine(root, files);

  return root;
}
