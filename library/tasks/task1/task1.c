
#include "task1.h"

/*returnez adresa santinelei si numarul tarilor din fisier*/
/*parametrii : numarul de tari*/
RETURN_POINT_FLOAT task1(char **files) {
  RETURN_POINT_FLOAT task1;
  /*readFromFile()->../filesFunc/file.ALL_TASK*/
  task1 = readFromFile(files[1], files[2], files[3]);
  return task1;
}
