/*bibliotecile cu task-uri*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/*fisierele cu task-uri*/
#include "library/tasks/task1/task1.h"
#include "library/tasks/task2/task2.h"
#include "library/tasks/task3/task3.h"
#include "library/tasks/task4/task4.h"
#include "library/tasks/task5/task5.h"


/*functia alege ce task sa rezolve*/
void whatTaskToSolve( char **files);

/*functia main*/
int main(int num_items, char **files) {
  /*apelez functia whatTaskToSolve pentru a citi dincerinte si a hotara ce trebuie rezolvat*/
  whatTaskToSolve(files);

  return 0;
}


/*
 * alege task-ul care trebuie executat
 * parametrii : parametrii lui tenis->cele 3 fisiere
 */
void whatTaskToSolve(char **files) {

  /*rol de increment pentru un  vectorul cerinteIn*/
  int i = 0;
  /*vector alocat dinamic imi salveaza cele 5 numere din cerinte*/
  int *cerinteIn;
  /*isOk1 imi spune daca exista primul jucator in cerinte dar si in BST */
  int isOk1 = 0;
  /*isOk2 imi spune daca exista al doilea jucator in cerinte dar si in BST */
  int isOk2 = 0;
  /*imi returneaza numarul de jucatori de la task.ul 5*/
  int numberOfplayersTask5 = 0;
  /*pentru a citi din fisierul cerinte*/
  FILE *f;
  /*jucatorul 1 din cerinte pentru task-ul 5*/
  Player player1;
  /*jucatorul 2 din cerinte pentru task-ul 5*/
  Player player2;
  /* salveaza adresa la santinela si numarul de tari din fisier */
  RETURN_POINT_FLOAT getTask1;
  /*salvez cele 4 tari pentru task-ul 5*/
  Country *savePlayersForTask4;
  /*tine adresa root de la BST*/
  TREE *rootBinaryTree;
  /*aloc vectorul cu cerinte alocInt()->alocmem/alocmem*/
  cerinteIn = alocInt(5);
  /*deschid fisierul 1*/
  f = fopen(files[1], "r");
  /*verific daca a putut fi deschis*/
  checkIfIsNull(f);
  /*parcurg primele 5 numere sa vad ce se afla in ele*/
  while (i < 5) {
    /*citesc primele 5 int-uri din fisier*/
    fscanf(f, "%d", &cerinteIn[i]);
    /*incrementez i-ul*/
    i++;
  }

  /*verifica daca face task-ul 1*/
  if (cerinteIn[0] == 1) {
    /*incarca task-ul 1 si ce returneaza duce in getTask1*/
    getTask1 = task1(files);
    /* verifica daca face task-ul 2*/
    if (cerinteIn[1] == 1) {
      /*goleste fisierul clearContentOfAFile()->filesFunc/file.ALL_TASK*/
      clearContentOfAFile(files[3]);
      /*incarca task-ul 2*/
      task2(putereMica2(getTask1.val), getTask1, files);
    }
    /*verifica daca face task-ul 3*/
    if (cerinteIn[2] == 1) {
      /*incarca task-ul 3*/
      savePlayersForTask4 = task3(getTask1, files);
      /*verifica daca incepe task-ul 4*/
      if (cerinteIn[3] == 1) {
        /*salvez adresa BST dupa ce este creat si incarca task-ul 4*/
        rootBinaryTree = task4(savePlayersForTask4, files);
        /*incarca task-ul 5*/
        if (cerinteIn[4] == 1) {
          /*aloc memorie pentru first_name din player1*/
          player1.first_name = aloChar(100);
          /*aloc memorie pentru first_name din player2*/
          player2.first_name = aloChar(100);
          /*aloc memorie pentru last_name din player1*/
          player1.last_name = aloChar(100);
          /*aloc memorie pentru last_name din player2*/
          player2.last_name = aloChar(100);
          /*citeste din cerinte player1 first_name*/
          fscanf(f, "%s", player1.first_name);
          /*citeste din cerinte player1 last_name*/
          fscanf(f, "%s", player1.last_name);
          /*citeste din cerinte player1 score*/
          fscanf(f, "%d", &player1.score);
          /*citeste din cerinte player2 first_name*/
          fscanf(f, "%s", player2.first_name);
          /*citeste din cerinte player2 last_name*/
          fscanf(f, "%s", player2.last_name);
          /*citeste din cerinte player2 score*/
          fscanf(f, "%d", &player2.score);
          /*compar scorul celor 2 jucatori ca sa stiu care este mai mic sa-l pun in BST*/
          if (player2.score < player1.score) {
            /*incarc task5() si pun player2 ca fiind cel mic*/
            task5(rootBinaryTree, files, player2, player1,
                  &numberOfplayersTask5, &isOk1, &isOk2);
          } else {
            /*incarc task5() si pun player1 ca fiind ce mic*/
            task5(rootBinaryTree, files, player1, player2,
                  &numberOfplayersTask5, &isOk1, &isOk2);
          }
          /*scriu in rezultate un \n*/
          writeToFile(files[3], "\n");
          /*isOk are rol de boolean si imi spune daca exista primul jucator*/
          if (isOk1 == 0) {
            /*daca nu exista scriu in fisier(rezultate.out) ca nu exista*/
            writeToFile(files[3], player1.first_name);
            writeToFile(files[3], " ");
            writeToFile(files[3], player1.last_name);
            writeToFile(files[3], " nu poate fi identificat!");
          }
          /*daca exista ambii jucatori scriem in fisier rezultate.out*/
          if (isOk1 == 1 && isOk2 == 1) {
            /*writeToFileIntValues()->filesFunc/file.ALL_TASK*/
            /*numarul de jucatori pentru task-ul 5*/
            writeToFileIntValues(files[3], numberOfplayersTask5);
          }
          /*daca nu exista al doilea jucator imi spune ca nu este identificat*/
          if (isOk2 == 0) {
            writeToFile(files[3], player2.first_name);
            writeToFile(files[3], " ");
            writeToFile(files[3], player2.last_name);
            writeToFile(files[3], " nu poate fi identificat!");
          }
        }
      }
    }
  }
  /*inchid fisierul*/
  fclose(f);
  /*eliberez memoria*/
  free(cerinteIn);
  free(savePlayersForTask4);
}
