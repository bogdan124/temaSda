<pre>In caz de ceva mai exista o copie aici care nu mai este modificata
NOTE:exista posibilitatea sa nu se vada foarte bine structura in cazul acesta pe github readme-ul se vede bine
am folosit tag-uri de html si arata mai bine
https://github.com/bogdan124/temaSda/tree/master

NOTE: In cazul in care ceva nu este bine explicat aici in cod sigur este explicat mai bine.

Logica din spate:
  -Task1:lista dublu inlantuita cu santinela este facuta in felul urmatorul
        ->nodul predecesor este conectat la urmatorul iar urmatorul la el si asta se tot repeta
        ->santinela conecteaza cu next partea din fata a listei si cu prev partea din spate iar valoarea ei este nula
  -Task2:aici mi-am creat un vector cu adresele elementelor din liste si scorul lor
        ->apoi am sortat crescator si am inceput sa elimin elementele(din lista le elimin) care au cea mai mare putere a lui 2 posibila
  -Task3:am creat o stiva de tip structura in care am pus tarile ramasein turneu
        ->am scos succesiv cate 2 tari apoi am parcurs jucatorii de la ele si i-am adaugat in coada
        ->apoi am inceput sa fac meciurile dintre jucatori (in coada sunt elementele juc 1 juc 2 ,juc 1 juc 3)(practic meciurile efectiv care au loc)
        ->i-am comparat si le-am dat punctaj
        ->in stiva winner am pus tara castigatoare apoi am reinceput comparatiile pana in winner ramane doar o tara care este castigatoare
  -Task4:de la task-ul 3 am preluat cele 4 tari si le-am pus jucatorii in BST
        -apoi am inceput sa fac comparatii cand puneam jucatorii sa vad ce se afla in arbore
  -Task5:mai intai verific existenta lor apoi caut si numar toti jucatorii cuprinsi intre cele 2 valori

Structura proiectului :
  -toate functiile sunt mai bune explicate in fisierele lor sau in headere
  -fiecare folder este format dintr-un fisier c si header-ul respectiv fisierului
        -astfel anumite fisiere se numesc ex.t1.t2.c
              - .t1.t2 sunt corespunzatoare task1,task2 (unde predomina codul respectiv)
              - ALL_TASK in toate task-urile(doar in filesFunc)
  -Foldere:
    </pre>
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
