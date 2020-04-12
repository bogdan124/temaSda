#include "../structs/structs.h"
#include "../alocmem/alocmem.h"
#include "../lists/createList.t1.t2.h"
#ifndef FILES
#define FILES
  /*aici am functiile pentru lucrul cu fisiere cum ar golirea fisierului,citire,scriere,etc...*/
  /*imi sterge tot continutul unui fisier*/
  void clearContentOfAFile(char *filename);
  /*imi citeste datele de intrare din fisier date.in*/
  RETURN_POINT_FLOAT readFromFile(char *filenameOne,char *filenameTwo,char *filenameThree);
  /*scriu date de tip char intr-un fisier*/
  void *writeToFile(char *filenameToWrite, char *whatToWrite);
  /*scriu date de tip in intr-un fisier*/
  void writeToFileIntValues(char *filenameToWrite, int whatToWrite);
  /*creez un fisier si adaug ceva in el*/
  void createFileToWrite(char *filenameToWrite, char *whatToWrite);
  /**/
  void pushPlayerStiv(Player *stivPlayer, char *first_name, char *last_name,int score_player, int numberOfplayers);
#endif
