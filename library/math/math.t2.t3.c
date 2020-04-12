#include "math.t2.t3.h"

/*functie de sortare pentru score */
/*
 * INDEX contine adresa tarii si scorul
 * astfel avem un sir din aceste de tip INDEX
 */
INDEX *sortFunc(INDEX *sir, int n) {
  INDEX aux;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (sir[i].scoreMinim < sir[j].scoreMinim) {
        aux = sir[i];
        sir[i] = sir[j];
        sir[j] = aux;
      }
    }
  }

  return sir;
}

/*calculeaza cea mai mica putere a lui 2 pentru n*/
int putereMica2(int n) {
  int i = 0;
  int mic = 0;

  while (mic < n) {
    mic = pow(2, i);
    i++;
  }

  return (pow(2, i - 2));
}
