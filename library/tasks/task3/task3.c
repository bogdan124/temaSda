#include "task3.h"

/*rezolv task-ul 3*/
/*parametrii: santinela si numarul de tari, fisierele cele 3*/
/*return: ulltimele 4 tari pentru task4*/
Country *task3(RETURN_POINT_FLOAT getTask1, char **files) {

  C__NAMES__ *saveAdress;
  /*tarile de jos sunt practic cele 2 tari care au meci */
  /*salvez tara 1 */
  Country *country1;
  /*salvez tara 2*/
  Country *country2;
  /*alocam spatiul pentru cele 4 tari*/
  Country *savePlayersForTask4;
  /*jucatorul 1 care are meci cu jucatorul 2 */
  /*adresa jucator 1*/
  Player *player1;
  /*adresa jucator 2*/
  Player *player2;
  /*salvez adresa max player per echipa 1 */
  Player *maxPlayer1;
  /*salvez adresa max player per echipa 2 */
  Player *maxPlayer2;
  /*stack-ul pentru task-ul 3 unde pun tarile*/
  stackNode *createStack;
  /*stack-ul pentru tarile castigatoare*/
  stackNode *WINNER;
  /*deschid fisierul pentru rezultate*/
  FILE *fp;
  /*coada cu jucatori*/
  Queue *q;
  /*rol de increment*/
  int k = 1;
  /*urmareste meciurile care se joaca*/
  int count = 0;
  int *storeLocalScore;
  /*scorul local per tara (aici este tara 1)*/
  int local_score_tara_1;
  /*scorul local per tara (aici este tara 2)*/
  int local_score_tara_2;
  /*numaram cate tari punem in stack*/
  int len_queque = 0;
  /*rol de increment*/
  int increment = 0;
  /*aici initializez stack-ul cu null*/
  createStack = NULL;
  /*aici initializez stack-ul cu null*/
  WINNER = NULL;
  /*aloc memorie pentru savePlayersForTask4 cu 4 elemente de tip country*/
  savePlayersForTask4 = aloCountry(4);
  /*creez coada*/
  q = createQueue();
  /*salvez scorul local al celor 2 tari*/
  storeLocalScore = alocInt(2);
  /*trec la primul element din lista*/
  saveAdress = getTask1.nameCountry->next;
  /*parcurg lista*/
  while (saveAdress->nameCountry != getTask1.nameCountry->nameCountry) {
    /*pun in stack tarile*/
    pushStack(&createStack, saveAdress->nameCountry);
    /*numaram cate tari punem in stack*/
    len_queque++;
    /*mergem la urmatorul element din lista*/
    saveAdress = saveAdress->next;
  }
  /*dau afara un element din stack (este un element null acolo)*/
  popStack(&createStack);
  /*si scad numarul tarilor cu una*/
  len_queque = len_queque - 1;
  /*acum deschid fisierul*/
  fp = fopen(files[3], "a");
  /*un loop infinit care o sa fie oprit de conditia break*/
  while (1) {
    /*numarul de tari se injumatateste cu fiecare etapa*/
    len_queque = len_queque / 2;
    /*scriu numarul etapei*/
    fprintf(fp, "\n====== ETAPA %d ======\n", k);
    /*cat stiva nu sa golit*/
    while (!emptyStack(createStack)) {
      /*salvez prima tara in country1*/
      country1 = popStack(&createStack);
      /*salvez tara 2 in country2*/
      country2 = popStack(&createStack);
      /*cat timp tarile sunt intre [1,2]*/
      if (len_queque <= 2 && len_queque >= 1) {
        /*pun tara 1 in ce trebuie sa returnez*/
        savePlayersForTask4[increment] = *(country1);
        /*incrementez variabila*/
        increment++;
        /*pun tara 2 in ce trebuie sa returnez*/
        savePlayersForTask4[increment] = *(country2);
        /*incrementez variabila*/
        increment++;
      }
      /*scriu in fisier numele tarii si scorul*/
      fprintf(fp, "\n%s %d ----- %s %d\n", country1->name,
              country1->global_score, country2->name, country2->global_score);
      /*pun meciurile in coada*/
      for (int i = 0; i < country1->nr_players; i++) {
        for (int j = 0; j < country2->nr_players; j++) {
          /*adaug jucatorul 1 in coada*/
          player1 = &(country1->players[i]);
          enQueue(q, player1);
          /*adaug oponentul jucatorului 1 in coada*/
          player2 = &(country2->players[j]);
          enQueue(q, player2);
        }
      }
      /*setez scorul local la tara 1*/
      local_score_tara_1 = 0;
      /*setez scorul local la tara 2*/
      local_score_tara_2 = 0;
      /*player-ul cu scorul cel mai mare din echipa 1 il setez NULL*/
      maxPlayer1 = NULL;
      /*player-ul cu scorul cel mai mare din echipa 2 il setez NULL*/
      maxPlayer2 = NULL;
      /*cat timp coada nu se goleste*/
      while (!isEmpty(q)) {
        /*scotem jucatorul 1*/
        player1 = deQueue(q);
        /*scoatem oponentul lui 1*/
        player2 = deQueue(q);
        /*daca cei 2 sunt null*/
        if (maxPlayer1 == NULL || maxPlayer2 == NULL) {
          /*jucatorii cu cel mai mare scor este primul*/
          maxPlayer1 = player1;
          /*si al doilea*/
          maxPlayer2 = player2;
        }
        /*compar scorul  jucatorilor din prima echipa pentru a afla care este maxim*/
        if (player1->score > maxPlayer1->score) {
          maxPlayer1 = player1;
        }
        /*compar scorul jucatorilor din a doua echipa pentru a afla care este maxim*/
        if (player2->score > maxPlayer2->score) {
          maxPlayer2 = player2;
        }
        /*acum cei 2 jucatori au meci*/
        storeLocalScore = playMatch(player1, player2, fp);
        /*adaugam la scorul local 1 */
        local_score_tara_1 += storeLocalScore[0];
        /*adaugam la scorul local 2 */
        local_score_tara_2 += storeLocalScore[1];
      }
      /*adaugam la scorul local la cel global la tara 1*/
      country1->global_score += local_score_tara_1;
      /*adaugam la scorul local la cel global la tara 2*/
      country2->global_score += local_score_tara_2;
      /*compar scorurile sa vad ce tara castiga*/
      if (local_score_tara_1 > local_score_tara_2) {
        /*adaug in stiva tara 1 ca fiind cea castigatoare*/
        pushStack(&WINNER, country1);
        /*poate a castigat tara 2*/
      } else if (local_score_tara_2 > local_score_tara_1) {
        /*adaug in stiva tara 2 ca fiind cea castigatoare*/
        pushStack(&WINNER, country2);
        /*poate cele 2 tari au scorul local egal*/
      } else if (local_score_tara_2 == local_score_tara_1) {
        /*atunci le compar scorul tarilor maxime(scor maxim)*/
        if (maxPlayer1->score > maxPlayer2->score) {
          /*pun in stiva winner tara 1 ca fiind cea castigatoare*/
          pushStack(&WINNER, country1);
          /*apoi compar invers sa verific daca a castigat tara 2*/
        } else if (maxPlayer1->score < maxPlayer2->score) {
          /*pun in stiva tara2*/
          pushStack(&WINNER, country2);
          /*poate cele 2 tari au scorul egal*/
        } else if (maxPlayer1->score == maxPlayer2->score) {
          /*atunci o pun pe prima scoasa din stiva*/
          pushStack(&WINNER, country1);
        }
      }
    }
    /*aici afisez tarile care au castigat*/
    fprintf(fp, "\n=== WINNER ===\n");
    /*rol de increment il setez la 0*/
    count = 0;
    /*cat timp stiva winner nu este goala*/
    while (!emptyStack(WINNER)) {
      /*scoatem toate tarile si le scriem in fisier*/
      country1 = popStack(&WINNER);
      /*incrementez*/
      count++;
      /*scriu in fisier*/
      fprintf(fp, "%s --- %d\n", country1->name, country1->global_score);
      /*adaug in stack tara1 deaoare exista posibilitatea sa mai avem meciuri in urmatoarele etape*/
      pushStack(&createStack, country1);
    }
    /*daca count este 1 atunci am terminat meciurile*/
    if (count == 1) {
      break;
    }
    /*incrementez k-ul*/
    k++;
  }
  /*inchidem fisierul*/
  fclose(fp);
  /*stergem din memorie coada*/
  deleteQueue(q);
  /*returnez cele 4 tari pentru task-ul 4*/
  return savePlayersForTask4;
}

/*meciurile dintre aceste doua tari*/
/*parametrii: jucatorul1 din cerinte , jucatorul2 din cerinte, fisierul in care scriu*/
/*returneaza un array format din scorul local al tarilor dupa meci */
int *playMatch(Player *player1, Player *player2, FILE *fp) {
  /*scorul local pentru tara 1*/
  int local_score_tara_1 = 0;
  /*scorul local pentru tara 1*/
  int local_score_tara_2 = 0;
  /*scorul local per meci*/
  int *scoreReturn;
  /*aloc memmorie pentru cele 2 tari*/
  scoreReturn = alocInt(2);
  /*scriu in fisier meciul care a avut loc*/
  fprintf(fp, "%s %s %d vs %s %s %d\n", player1->first_name, player1->last_name,
          player1->score, player2->first_name, player2->last_name,
          player2->score);
  /*compar scroul dintre jucatori*/
  if (player1->score > player2->score) {
    /*castiga primul ii dam 5 puncte*/
    player1->score += 5;
    /*castiga tara 1 ii dam 3 puncte*/
    local_score_tara_1 += 3;
  /*dar poate jucatorul 2 castiga */
  } else if (player2->score > player1->score) {
    /*atunci ii dam 5 puncte*/
    player2->score += 5;
    /*si tara primeste 3 puncte*/
    local_score_tara_2 += 3;
  /*daca exista egalitate*/
  } else if (player2->score == player1->score) {
    /*atunci jucatorul 1 primeste 2 puncte*/
    player1->score += 2;
    /*atunci jucatorul 2 primeste 2 puncte*/
    player2->score += 2;
    /*atunci tara 1 primeste 1 puncte*/
    local_score_tara_1 += 1;
    /*atunci tara 2 primeste 1 puncte*/
    local_score_tara_2 += 1;
  }
  /*pun scorul local la prima tara in ce trebuie sa returnez*/
  scoreReturn[0] = local_score_tara_1;
  /*pun scorul local de la a doua tara in ce trebuie sa returnez*/
  scoreReturn[1] = local_score_tara_2;
  /*o returnez*/
  return scoreReturn;
}
