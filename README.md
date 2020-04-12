In caz de ceva mai exista o copie aici care nu mai este modificata
https://github.com/bogdan124/temaSda/tree/master

Structura proiectului :

  -fiecare folder este format dintr-un fisier c si header-ul respectiv fisierului
        -astfel anumite fisiere se numesc ex.t1.t2.c
              - .t1.t2 sunt corespunzatoare task1,task2 (unde predomina codul respectiv)
              - ALL_TASK in toate task-urile(doar in filesFunc)
  -Foldere:
  NOTE:am eliminat stelutele de la pointeri deoarece imi inclina text-ul
  dar a trebuii sa fie de ajuns cat sa indice locatia functiei
  <div style="color:red;font-size:40px;">
           -library->|<br/>
                     |->alocmem->|
                                 |-alocmem.c(functiile pentru alocare de memorie pentru  char,int,INDEX,Country..etc)
                                 |-alocmem.h(headerele respective lui alocmem si functiile de care alocmem.c are nevoie sa ruleze)
                     |->filesFunc->|
                                   |-file.ALL_TASK.c(predomina lucrul cu fisiere folosit in toate task-urile)            
                                   |-file.ALL_TASK.h(headerele corespunzatoare lui .c)
                     |->lists->|
                               |-createList.t1.t2.c
                               |-createList.t1.t2.h
                     |->math->|
                              |-math.t2.t3.c
                              |-math.t2.t3.h                               
                     |->queue->|
                               |-queue.t3.c
                               |-queue.t3.h
                     |->stack->|
                               |-stack.t3.c
                               |-stack.t3.h
                     |->structs->|
                                 |-structs.h(toate structurile folosite)  
                     |->tasks->|  (mai jos sunt functiile corespunzatoare fiecarui task in parte)     
                               |->task1->|
                                         |task1.c
                                         |task1.h
                               |->task2->|
                                         |task2.c
                                         |task2.h
                               |->task3->|
                                         |task3.c
                                         |task3.h
                               |->task4->|
                                         |task4.c
                                         |task4.h
                               |->task5->|
                                         |task5.c
                                         |task5.h->
                                                 ->
                    |->tree->|(aici am functiile corespunzatore pentru BST)
                             |tree.t4.t5.c
                             |tree.t4.t5.h->    TREE insert(TREE node, Player key);
                                          ->    TREE newNode(Player data);
                                          ->    void inordine(TREE root, char files);
                    |->usable->|(aici sunt functii care sunt folosite in toate task-urile)
                               |usable.t1.t2.c
                               |usable.t1.t2.h->char clearContentChar(char nume);
                                              ->int checkIfIsNull(void any_pointer);
         -main.c
         -makefile                     
</div>
