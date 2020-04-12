/*Este folosit in task-ul 3*/


#include "queue.t3.h"

/*o creez*/
Queue *createQueue() {
  Queue *q;
  q = (Queue *)malloc(sizeof(Queue));
  if (q == NULL) return NULL;
  q->front = q->rear = NULL;
  return q;
}

/*adaug elemente in ea*/
void enQueue(Queue *q, Player *v) {
  COADA *newNode = (COADA *)malloc(sizeof(COADA));
  newNode->val = v;
  newNode->next = NULL;
  if (q->rear == NULL)
    q->rear = newNode;
  else {
    (q->rear)->next = newNode;
    (q->rear) = newNode;
  }
  if (q->front == NULL) q->front = q->rear;
}

/*verific daca este goala*/
int isEmpty(Queue *q) { return (q->front == NULL); }
Player *deQueue(Queue *q) {
  COADA *aux;
  Player *d;
  aux = q->front;
  d = aux->val;
  q->front = (q->front)->next;
  free(aux);
  return d;
}

/*sterg coada*/
void deleteQueue(Queue *q) {
  COADA *aux;
  while (!isEmpty(q)) {
    aux = q->front;
    q->front = q->front->next;
    free(aux);
  }
  free(q);
}
