/*Este folosit in task-ul 3*/
#include "../structs/structs.h"
#include "../alocmem/alocmem.h"
#ifndef QUE_UE
#define QUE_UE
    Queue *createQueue();
    void enQueue(Queue *q, Player *v);
    int isEmpty(Queue *q);
    Player *deQueue(Queue *q);
    void deleteQueue(Queue *q);
#endif
