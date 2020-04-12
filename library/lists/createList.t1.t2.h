#include "../structs/structs.h"
#include "../alocmem/alocmem.h"
#include "../usable/usable.t1.t2.h"
#include <string.h>
#ifndef LIST
#define LIST
  /*aici am functiile pentru liste*/
  C__NAMES__ *initDoubleList();
  C__NAMES__ *addNodeDoubleListEnd(C__NAMES__ **listEndNode);
  C__NAMES__ *finishList(C__NAMES__ **endList, C__NAMES__ **startList);
  C__NAMES__ *addSentinel(C__NAMES__ **startList, C__NAMES__ **finishList);
  void delNodeDoubleListEnd(C__NAMES__ *listNodeToDelete);
  void putDataIntoList(C__NAMES__ **listEndNode, char *nameTara, int nrPlayers);
#endif
