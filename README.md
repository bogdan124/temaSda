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
  <pre>
  <h5 style="color:red;font-size:12px;">
           -library->|<br/>
                     |->alocmem->|<br/>
                                 |-alocmem.c(functiile pentru alocare de memorie pentru  char,int,INDEX,Country..etc)<br/>
                                 |-alocmem.h -> Country *aloCountry(int n);<br/>
                                             ->char *aloChar(int n);<br/>
                                             ->INDEX *alocIndex(int n);<br/>
                                             ->int *alocInt(int n);<br/>
                                             ->stackNode *alocStackNode(int n);<br/>
                                             ->TREE *alocTree(int n);<br/>
                                             ->Player *createPlayerStivInit(int numberOfplayers);<br/>
                                             ->int checkIfIsNull(void *any_pointer);<br/>
                     |->filesFunc->|<br/>
                                   |-file.ALL_TASK.c(predomina lucrul cu fisiere folosit in toate task-urile)<br/>            
                                   |-file.ALL_TASK.h ->void clearContentOfAFile(char *filename);<br/>                            
                                                     ->RETURN_POINT_FLOAT readFromFile(char *filenameOne,char *filenameTwo,char *filenameThree); <br/>                                    
                                                     ->void *writeToFile(char *filenameToWrite, char *whatToWrite);<br/>                                  
                                                     ->void writeToFileIntValues(char *filenameToWrite, int whatToWrite);  <br/>                              
                                                     ->void createFileToWrite(char *filenameToWrite, char *whatToWrite); <br/>                           
                                                     ->void pushPlayerStiv(Player *stivPlayer, char *first_name, char *last_name,int score_player, int numberOfplayers);<br/>
                     |->lists->|<br/>
                               |-createList.t1.t2.c<br/>
                               |-createList.t1.t2.h->C__NAMES__ *initDoubleList();<br/>
                                                   ->C__NAMES__ *addNodeDoubleListEnd(C__NAMES__ **listEndNode);<br/>
                                                   ->C__NAMES__ *finishList(C__NAMES__ **endList, C__NAMES__ **startList);<br/>
                                                   ->C__NAMES__ *addSentinel(C__NAMES__ **startList, C__NAMES__ **finishList);<br/>
                                                   ->void delNodeDoubleListEnd(C__NAMES__ *listNodeToDelete);<br/>
                                                   ->void putDataIntoList(C__NAMES__ **listEndNode, char *nameTara, int nrPlayers);<br/>
                     |->math->|<br/>
                              |-math.t2.t3.c<br/>
                              |-math.t2.t3.h-> INDEX *sortFunc(INDEX *sir, int n);<br/>
                                            -> int putereMica2(int n); <br/>                              
                     |->queue->|<br/>
                               |-queue.t3.c<br/>
                               |-queue.t3.h->    Queue *createQueue();<br/>
                                           ->    void enQueue(Queue *q, Player *v);<br/>
                                           ->    int isEmpty(Queue *q);<br/>
                                           ->    Player *deQueue(Queue *q);<br/>
                                           ->    void deleteQueue(Queue *q);<br/>
                     |->stack->|<br/>
                               |-stack.t3.c<br/>
                               |-stack.t3.h->      void pushStack(stackNode **stack, Country *valueToAdd);<br/>
                                           ->      Country *popStack(stackNode **stack);<br/>
                                           ->      int emptyStack(stackNode *stack);<br/>
                     |->structs->|<br/>
                                 |-structs.h(toate structurile folosite)<br/>  
                     |->tasks->|  (mai jos sunt functiile corespunzatoare fiecarui task in parte)<br/>     
                               |->task1->|<br/>
                                         |task1.c<br/>
                                         |task1.h->RETURN_POINT_FLOAT task1(char **files);<br/>
                               |->task2->|<br/>
                                         |task2.c<br/>
                                         |task2.h->  void task2(int smallPow2, RETURN_POINT_FLOAT getTask1, char **files);<br/>
                                                 ->INDEX *buildIndexForSearch(RETURN_POINT_FLOAT getTask1);<br/>
                               |->task3->|<br/>
                                         |task3.c<br/>
                                         |task3.h->  Country *task3(RETURN_POINT_FLOAT getTask1, char **files);<br/>
                                                 ->   int *playMatch(Player *player1, Player *player2, FILE *fp);<br/>
                               |->task4->|<br/>
                                         |task4.c<br/>
                                         |task4.h->TREE *task4(Country *savePlayersForTask4, char **files);<br/>
                               |->task5->|<br/>
                                         |task5.c<br/>
                                         |task5.h->void task5(TREE *root, char **files, Player player1, Player player2,int *number, int *isOK1, int *isOK2);<br/>                                       
                    |->tree->|(aici am functiile corespunzatore pentru BST)<br/>
                             |tree.t4.t5.c<br/>
                             |tree.t4.t5.h-> TREE *insert(TREE *node, Player key);<br/>
                                          -> TREE *newNode(Player data);<br/>
                                          -> void inordine(TREE *root, char **files);<br/>
                    |->usable->|(aici sunt functii care sunt folosite in toate task-urile)<br/>
                               |usable.t1.t2.c<br/>
                               |usable.t1.t2.h->char *clearContentChar(char *nume);<br/>
                                              ->int checkIfIsNull(void *any_pointer);<br/>
         -main.c<br/>
         -makefile <br/>                    
           
</h1><br/>
</pre>
