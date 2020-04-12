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
  <h5 style="color:red;font-size:12px;">
           -library->|<br />
                     |->alocmem->|<br/>
                                 |-alocmem.c(functiile pentru alocare de memorie pentru  char,int,INDEX,Country..etc)<br/>
                                 |-alocmem.h<br/>
                     |->filesFunc->|<br/>
                                   |-file.ALL_TASK.c(predomina lucrul cu fisiere folosit in toate task-urile)   <br/>         
                                   |-file.ALL_TASK.h(headerele corespunzatoare lui .c)<br/>
                     |->lists->|<br/>
                               |-createList.t1.t2.c<br/>
                               |-createList.t1.t2.h<br/>
                     |->math->|<br/>
                              |-math.t2.t3.c<br/>
                              |-math.t2.t3.h<br/>                            
                     |->queue->|<br/>
                               |-queue.t3.c<br/>
                               |-queue.t3.h<br/>
                     |->stack->|<br/>
                               |-stack.t3.c<br/>
                               |-stack.t3.h<br/>
                     |->structs->|<br/>
                                 |-structs.h(toate structurile folosite)  <br/>
                     |->tasks->|  (mai jos sunt functiile corespunzatoare fiecarui task in parte)<br/>     
                               |->task1->|<br/>
                                         |task1.c<br/>
                                         |task1.h<br/>
                               |->task2->|<br/>
                                         |task2.c<br/>
                                         |task2.h<br/>
                               |->task3->|<br/>
                                         |task3.c<br/>
                                         |task3.h<br/>
                               |->task4->|<br/>
                                         |task4.c<br/>
                                         |task4.h<br/>
                               |->task5->|<br/>
                                         |task5.c<br/>
                                         |task5.h-><br/>
                                                 -><br/>
                    |->tree->|(aici am functiile corespunzatore pentru BST)<br/>
                             |tree.t4.t5.c<br/>
                             |tree.t4.t5.h->    TREE insert(TREE node, Player key);<br/>
                                          ->    TREE newNode(Player data);<br/>
                                          ->    void inordine(TREE root, char files);<br/>
                    |->usable->|(aici sunt functii care sunt folosite in toate task-urile)<br/>
                               |usable.t1.t2.c<br/>
                               |usable.t1.t2.h->char clearContentChar(char nume);<br/>
                                              ->int checkIfIsNull(void any_pointer);<br/>
         -main.c<br/>
         -makefile  <br/>                   
</h1><br/>
