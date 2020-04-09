#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <errno.h>
#define ERROR_1_MEM_ERROR printf("\nERROR 1:Memory alocation problem\n");
#define NO_PROPERLY_FILENAME(x) printf("\n ERROR 2:file %d doesn't have a specific name\n",x);





//structura jucator
typedef struct Player {
   char * last_name;
   char * first_name;
   int score;
} Player;


//Structura pentru tara
typedef struct Country {
   char * name;
   int nr_players;
   int global_score;
   Player * players;
} Country;

//pentru task-ul 1
typedef struct countryNames{

    Country * nameCountry;
    struct countryNames * next;
    struct countryNames * prev;

}C__NAMES__;


typedef struct stack{

    Country * content;
    struct stack * prev;

}stackNode;


/*
Aceasta structura o folosesc pentru a putea returna un int si un pointer din readFromFile
*/
typedef struct returnFromReadFile{

    C__NAMES__ * nameCountry;//valoarea santinelei
    int val;//numarul de tari din fisier

}RETURN_POINT_FLOAT;
/*
imi foloseste la task-ul 2
idee->pun toate adresele din lista aici si
 le aflu scorul minim o singura data.
Apoi elemin tarile din lista dublu inlantuita
De ce fac asta ?
Pai vreau sa limitez parcurgerea si calculul facut pe lista principala
Asa decat stochez adresele si scorul in memorie.
*/
typedef struct createIndex{

    C__NAMES__ * ctrName;
    float scoreMinim;

}INDEX;

typedef struct EL{

  Player * val;
  struct EL * next;
}COADA;

typedef struct Q{

  COADA *front,*rear;
}Queue;






/*stack functions*/
void pushStack(stackNode ** stack,Country  * valueToAdd);
Country * popStack(stackNode ** stack);
int emptyStack(stackNode * stack);

/*coada functii*/
Queue * createQueue();
void enQueue(Queue * q, Player * v);
int isEmpty(Queue *q);
Player * deQueue(Queue *q);
void deleteQueue(Queue *q);


Player * aloPlayer(int n);

/*aici am functiile cu pentru liste*/
C__NAMES__ * initDoubleList();
C__NAMES__ * addNodeDoubleListEnd(C__NAMES__ ** listEndNode);
C__NAMES__ * finishList(C__NAMES__ ** endList,C__NAMES__ ** startList);
C__NAMES__ * addSentinel(C__NAMES__ ** startList,C__NAMES__ ** finishList);
void delNodeDoubleListEnd(C__NAMES__ * listNodeToDelete);



void lookInList(C__NAMES__ * start);
void putDataIntoList(C__NAMES__ ** listEndNode,char * nameTara ,int nrPlayers);
Player * createPlayerStivInit(int numberOfplayers);
void pushPlayerStiv(Player * stivPlayer,char * first_name,char * last_name,int score_player,int numberOfplayers);

INDEX * buildIndexForSearch(RETURN_POINT_FLOAT getTask1);

void clearContentOfAFile(char * filename);
RETURN_POINT_FLOAT readFromFile(char * filenameOne,char * filenameTwo,char * filenameThree);//return number of country
void * writeToFile(char * filenameToWrite,char * whatToWrite);
void  createFileToWrite(char * filenameToWrite,char * whatToWrite);
int checkedIfFilesAreNamedProperly(char ** files);

/*aloc functions*/
Country * aloCountry(int n);
char * aloChar(int n);
INDEX * alocIndex(int n);
int * alocInt(int n);
int checkIfIsNull(void * any_pointer);
stackNode * alocStackNode(int n);

/*math functions*/
INDEX * sortFunc(INDEX * sir,int n);
int putereMica2(int n);

/*aici sunt task-urile*/
RETURN_POINT_FLOAT task1(char ** files);
void task2(int smallPow2,RETURN_POINT_FLOAT getTask1,char ** files);
void task3(RETURN_POINT_FLOAT getTask1,char ** files);
void whatTaskToSolve(char * filenameOne,char ** files);

/*functii task3*/
int * playMatch(Player * player1,Player * player2,FILE * fp);


char * clearContentChar(char * nume);

int main(int num_items,char ** files){

  //if(checkedIfFilesAreNamedProperly(files)==0){
      printf("%s",files[1]);
      whatTaskToSolve(files[1],files);
 //}


  return 0;
}

int checkedIfFilesAreNamedProperly(char ** files)
{

    if(strcmp(files[1],"cerinte.in")==0){
        printf("%s__%s__",files[1],"cerinte.in");
      NO_PROPERLY_FILENAME(1)
      return 1;
    }else if(strcmp(files[2],"date.in")==0){
      NO_PROPERLY_FILENAME(2)
      return 1;
    }else if(strcmp(files[3],"rezultate.out")==0){
      NO_PROPERLY_FILENAME(3)
      return 1;
    }

  return 0;
}

void whatTaskToSolve(char * filenameOne,char ** files){
    int i=0;
    int cerinteIn[5];

    FILE *f;

    RETURN_POINT_FLOAT getTask1;

    f=fopen(filenameOne,"r");
    checkIfIsNull(f);
      while(i<5){
          fscanf(f, "%d", &cerinteIn[i]);
          i++;
      }
        fclose(f);
      if(cerinteIn[0]==1){
         getTask1=task1(files);

         if(cerinteIn[1]==1){
           clearContentOfAFile(files[3]);
           task2(putereMica2(getTask1.val),getTask1,files);
         }
         if(cerinteIn[2]==1){
           task3(getTask1,files);
         }
      }
}




void task3(RETURN_POINT_FLOAT getTask1,char ** files){

  C__NAMES__ * saveAdress;

  Country * country1;
  Country * country2;

  Player * player1;
  Player * player2;
  Player * maxPlayer1;
  Player * maxPlayer2;

  stackNode * createStack;
  Queue * q;
  stackNode * WINNER;

  FILE * fp;

  int k=1;
  int count=0;
  int * storeLocalScore;
  int local_score_tara_1;
  int local_score_tara_2;


  createStack=NULL;
  WINNER=NULL;


  q=createQueue();
  storeLocalScore=alocInt(2);

  saveAdress=getTask1.nameCountry->next;
  while(saveAdress->nameCountry!=getTask1.nameCountry->nameCountry){

          pushStack(&createStack,saveAdress->nameCountry);

    saveAdress=saveAdress->next;
  }

  popStack(&createStack);
  fp=fopen(files[3],"a");
  while(1){

    fprintf(fp,"\n====== ETAPA %d ======\n",k);
    while(!emptyStack(createStack)){
      //printf("pop");
      country1=popStack(&createStack);
      country2=popStack(&createStack);
    //  printf("%d ",country1->global_score);
      /*verific daca am un \n la sfarsit */
      country1->name=clearContentChar(country1->name);
      country2->name=clearContentChar(country2->name);


      fprintf(fp,"\n%s %d ----- %s %d\n",country1->name,country1->global_score,country2->name,country2->global_score);

      for(int i=0;i<country1->nr_players;i++){
        for(int j=0;j<country2->nr_players;j++){
          player1=&(country1->players[i]);
          enQueue(q,player1);
          player2=&(country2->players[j]);
          enQueue(q,player2);
        }
      }
      local_score_tara_1=0;
      local_score_tara_2=0;
      maxPlayer1=NULL;
      maxPlayer2=NULL;
      while(!isEmpty(q)){
        player1=deQueue(q);
        player2=deQueue(q);
        if(maxPlayer1==NULL || maxPlayer2==NULL){
          maxPlayer1=player1;
          maxPlayer2=player2;
        }
        if(player1->score > maxPlayer1->score){
            maxPlayer1=player1;
        }
         if(player2->score>maxPlayer2->score){
            maxPlayer2=player2;
        }
        storeLocalScore = playMatch(player1,player2,fp);
        local_score_tara_1+=storeLocalScore[0];
        local_score_tara_2+=storeLocalScore[1];

      }
      country1->global_score+=local_score_tara_1;
      country2->global_score+=local_score_tara_2;
      if(local_score_tara_1>local_score_tara_2){
        pushStack(&WINNER,country1);
      }else if(local_score_tara_2>local_score_tara_1){
        pushStack(&WINNER,country2);
      }else if(local_score_tara_2==local_score_tara_1){
        if(maxPlayer1->score > maxPlayer2->score){
          pushStack(&WINNER,country1);
          printf("%s %d %s %d 1\n",country1->name,maxPlayer1->score,country2->name,maxPlayer2->score);
        }else if(maxPlayer1->score<maxPlayer2->score){
          pushStack(&WINNER,country2);
          printf("%s %s 2",country1->name,country2->name);
        }else if(maxPlayer1->score==maxPlayer2->score){
          pushStack(&WINNER,country2);
          printf("%s %s 3",country1->name,country2->name);
        }


      }

    }


    fprintf(fp,"\n=== WINNER ===\n");

    count=0;
    while(!emptyStack(WINNER)){
        country1=popStack(&WINNER);
        count++;
        fprintf(fp,"%s --- %d\n",country1->name,country1->global_score);
        pushStack(&createStack,country1);
    }

    if(count==1){
      break;
    }

    k++;
  }
  //country2=popStack(&createStack);
  //pushStack(&WINNER,country1);

  fclose(fp);


}


/*meciurile dintre aceste doua tari*/
/*returneaza un array format din scorul local al tarilor dupa meci */
int * playMatch(Player * player1,Player * player2,FILE * fp){

   int local_score_tara_1=0;
   int local_score_tara_2=0;

   int * scoreReturn;

   scoreReturn=alocInt(2);
   fprintf(fp, "%s %s %d vs %s %s %d\n",player1->first_name,player1->last_name,player1->score,player2->first_name,player2->last_name,player2->score);

   if(player1->score>player2->score){
     player1->score+=5;
     local_score_tara_1+=3;
   }else if(player2->score>player1->score){
     player2->score+=5;
     local_score_tara_2+=3;
   }else if(player2->score==player1->score){
      player1->score+=2;
      player2->score+=2;
      local_score_tara_1+=1;
      local_score_tara_2+=1;
   }
  // printf("%d %s %d %s\n",player1->score,player1->last_name,player2->score,player2->last_name);
   scoreReturn[0]=local_score_tara_1;
   scoreReturn[1]=local_score_tara_2;

   return scoreReturn;


}



/*solve task 1*/
RETURN_POINT_FLOAT task1(char ** files){
  RETURN_POINT_FLOAT task1;

  task1 = readFromFile(files[1],files[2],files[3]);
  return task1;
}
/*solve task 2*/
void task2(int smallPow2,RETURN_POINT_FLOAT getTask1,char ** files){

  INDEX * indexSantinelaSearch;
  int j=0;

  /*ma ajuta sa caut mai usor fara sa calculez valorile minime de mai multe ori*/
  indexSantinelaSearch=buildIndexForSearch(getTask1);
  while(indexSantinelaSearch[j].scoreMinim < indexSantinelaSearch[getTask1.val-smallPow2].scoreMinim){

      delNodeDoubleListEnd(indexSantinelaSearch[j].ctrName);

      j++;
  }




printf("\n");
C__NAMES__ * __saveStartAdress__;
__saveStartAdress__=getTask1.nameCountry->next;

while(__saveStartAdress__->nameCountry!=NULL){
  for(int i=getTask1.val-smallPow2;i<getTask1.val;i++){

    if(strcmp(__saveStartAdress__->nameCountry->name,indexSantinelaSearch[i].ctrName->nameCountry->name)==0){


        //printf("_%s_ __%s__\n",indexSantinelaSearch[i].ctrName->nameCountry->name,__saveStartAdress__->nameCountry->name);
        //printf("%s--",__saveStartAdress__->nameCountry->name);
        writeToFile(files[3],__saveStartAdress__->nameCountry->name);
    }


  }

  __saveStartAdress__=__saveStartAdress__->next;
}

//  lookInList(getTask1.nameCountry);

}

INDEX * buildIndexForSearch(RETURN_POINT_FLOAT getTask1){

  INDEX * indexSantinelaSearch;
  C__NAMES__ * __saveStartAdress__;
  int j=0;

  indexSantinelaSearch=alocIndex(getTask1.val+1);
  //printf("\n%p",getTask1.nameCountry);

  __saveStartAdress__=getTask1.nameCountry->next;

  while(__saveStartAdress__->nameCountry!=NULL){
      indexSantinelaSearch[j].ctrName=__saveStartAdress__;
      indexSantinelaSearch[j].scoreMinim=0;
      for(int i=0;i<__saveStartAdress__->nameCountry->nr_players;i++)
      {
          indexSantinelaSearch[j].scoreMinim+=__saveStartAdress__->nameCountry->players[i].score;
      }
      indexSantinelaSearch[j].scoreMinim=(indexSantinelaSearch[j].scoreMinim)/(__saveStartAdress__->nameCountry->nr_players);
      __saveStartAdress__=__saveStartAdress__->next;
      j++;
  }
  free(__saveStartAdress__);
  indexSantinelaSearch=sortFunc(indexSantinelaSearch,getTask1.val);
  return indexSantinelaSearch;
}

INDEX * sortFunc(INDEX * sir,int n){

    INDEX aux;

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(sir[i].scoreMinim<sir[j].scoreMinim){
          aux=sir[i];
          sir[i]=sir[j];
          sir[j]=aux;
        }
      }
    }

    return sir;
}



/*returnez numarul de tari si santinela*/
RETURN_POINT_FLOAT readFromFile(char * filenameOne,char * filenameTwo,char * filenameThree){

  FILE *f;

  int num_date;
  int i=0;
  int j=0;

  int count=0;
  int saveNumPlayersPerCountry;
  int playersNumPerCountry;

  int initData=0;

  Player * playerStiv;
  RETURN_POINT_FLOAT returnHelp;//valoarea aceasta va fi returnata de catre functie

  C__NAMES__ * __storeStartAdress__;
  C__NAMES__ * __storeFinishAdress__;

  char * bufferToStore=aloChar(300);
  char * first_name;
  char * second_name;
  char * scorePlayer;
  /*
  trebuie sa sterg continutul fisierului
  rezultate.out in caz ca a fost scris
  inainte
  */
  clearContentOfAFile(filenameThree);

  /*
    stiu ca m-am complicat cu citirea datelor pentru task1
    dar o sa ma ajute la task-urile urmatoare deoarece pot sa parcurg mai usor sirul
    practic imi extrage direct tarile din fisier sau jucatorii in functie de ce vreau eu sa-mi extraga
    asta fac cele 2 while-uri
  */

  //if(strcmp("date.in",filenameTwo)==0)
  //{
   size_t buffer_size = 300;
    f=fopen(filenameTwo,"r");
    checkIfIsNull(f);
    fscanf(f, "%d", &num_date);
    //printf("%d__ ",num_date);
    while(playersNumPerCountry!=EOF ){
        fscanf(f,"%d",&playersNumPerCountry);
        saveNumPlayersPerCountry=playersNumPerCountry;
        if(playersNumPerCountry<=0){
          break;
        }
        playersNumPerCountry=playersNumPerCountry+2;//+2 deaorece incepem sa citim de la numele tarii
         playerStiv=createPlayerStivInit(saveNumPlayersPerCountry);
        while(playersNumPerCountry!=0 ){
        //  fgets(bufferToStore,300,f);
          getline(&bufferToStore, &buffer_size, f);
        //  printf("%s\n",bufferToStore );
          //aici luam tarile
          if(count==1){
            /*primul element ne va crea lista initData are rol de  boolean*/
            if(initData==0){
                  __storeStartAdress__=initDoubleList();
                  __storeFinishAdress__=__storeStartAdress__;

                  initData=1;
            }else{
                  __storeFinishAdress__=addNodeDoubleListEnd(&__storeFinishAdress__);
            }


             writeToFile(filenameThree,bufferToStore);
           /*
              write data to list
              here we write Country names ->bufferToStore
                            int number of players->saveNumPlayersPerCountry
           */
           putDataIntoList(&__storeFinishAdress__,bufferToStore,saveNumPlayersPerCountry);
           free(bufferToStore);
         }else{
             if(bufferToStore[0]!='\n' && bufferToStore[0]!='\t'){
              //   printf("!!!%s",bufferToStore);
                 first_name=strtok(bufferToStore," ");


                 second_name=strtok(NULL," ");
                 scorePlayer=strtok(NULL," ");
                 pushPlayerStiv(playerStiv,first_name,second_name,atoi(scorePlayer),saveNumPlayersPerCountry);
            }
            free(bufferToStore);
         }
        bufferToStore=aloChar(300);
        count++;
        playersNumPerCountry--;


        }
        __storeFinishAdress__->nameCountry->players=playerStiv;
        count=0;
      }
      /*
          Here we do again the same thing for the last country
         write data to list
         here we write Country names ->bufferToStore
                       int number of players->saveNumPlayersPerCountry
      */
      __storeFinishAdress__=addNodeDoubleListEnd(&__storeFinishAdress__);

      putDataIntoList(&__storeFinishAdress__,bufferToStore,saveNumPlayersPerCountry);
      /*
        Aici adaugam santinela care conecteaza nodul de inceput cu ea
        si cel de sfarsit tot cu ea
      */
      __storeFinishAdress__=addSentinel(&__storeStartAdress__,&__storeFinishAdress__);
  //}

  fclose(f);
  returnHelp.nameCountry=__storeFinishAdress__;
  returnHelp.val=num_date;
//  free( __storeStartAdress__);
  //free( __storeFinishAdress__);

  free(bufferToStore);
  free(first_name);
  //free(second_name);
  //free(scorePlayer);

    return returnHelp;
}


void * writeToFile(char * filenameToWrite,char * whatToWrite){
  FILE * f=NULL;

  f=fopen(filenameToWrite,"a");

  if(f==NULL){

    createFileToWrite(filenameToWrite,whatToWrite);
  }

  fprintf(f,"%s",whatToWrite);
  fclose(f);

}

void  createFileToWrite(char * filenameToWrite,char * whatToWrite){
  FILE * g;
  g=fopen(filenameToWrite,"w");
  checkIfIsNull(g);
  fprintf(g, "%s",whatToWrite);
  fclose(g);

}

void clearContentOfAFile(char * filename){
  FILE * f;
  f=fopen(filename,"w");
  checkIfIsNull(f);
  fclose(f);

}


C__NAMES__ * initDoubleList(){


    C__NAMES__ * start;
    start=(C__NAMES__ *) malloc(1*sizeof(C__NAMES__));
    checkIfIsNull(start);
    start->prev=start;
    start->next=start;

    return start;

}


void putDataIntoList(C__NAMES__ ** listEndNode,char * nameTara ,int nrPlayers){
  (*listEndNode)->nameCountry=aloCountry(1);
  (*listEndNode)->nameCountry->global_score=0;
  (*listEndNode)->nameCountry->name=aloChar(strlen(nameTara));
  (*listEndNode)->nameCountry->nr_players=nrPlayers;
  strcpy((*listEndNode)->nameCountry->name,nameTara);

}


Player * createPlayerStivInit(int numberOfplayers){

        Player * playerCreate;
        playerCreate=(Player *)malloc(numberOfplayers*sizeof(Player));
        checkIfIsNull(playerCreate);
        return playerCreate;
}

void pushPlayerStiv(Player * stivPlayer,char * first_name,char * last_name,int score_player,int numberOfplayers){

      for(int i=0;i<numberOfplayers;i++){
        if(stivPlayer[i].first_name==NULL && stivPlayer[i].last_name==NULL){
          stivPlayer[i].first_name=aloChar(strlen(first_name));
          stivPlayer[i].last_name=aloChar(strlen(last_name));
          strcpy(stivPlayer[i].first_name,first_name);
          strcpy(stivPlayer[i].last_name,last_name);
          stivPlayer[i].score=score_player;
          break;
        }
      }

}




C__NAMES__ * addNodeDoubleListEnd(C__NAMES__ ** listEndNode) {

    C__NAMES__ * alocNewNode;
    alocNewNode = (C__NAMES__ *) malloc(1*sizeof(C__NAMES__));
    checkIfIsNull(alocNewNode);
    (*listEndNode)->next=alocNewNode;
    alocNewNode->prev=(*listEndNode);
    alocNewNode->next=alocNewNode;

    return alocNewNode;
}

C__NAMES__ * finishList(C__NAMES__ ** endList,C__NAMES__ ** startList){

  (*startList)->prev=(*endList);
  (*endList)->next=(*startList);


}

C__NAMES__ * addSentinel(C__NAMES__ ** startList,C__NAMES__ ** finishList){

  C__NAMES__ * alocNewNode;
  alocNewNode = (C__NAMES__ *) malloc(1*sizeof(C__NAMES__));
  checkIfIsNull(alocNewNode);
  alocNewNode->nameCountry=NULL;
  (*startList)->prev=alocNewNode;
  alocNewNode->next=(*startList);

  (*finishList)->next=alocNewNode;
  alocNewNode->prev=(*finishList);

  return alocNewNode;
}

void delNodeDoubleListEnd(C__NAMES__ * listNodeToDelete){

    /*daca nu a ajuns la santinela*/
    if(listNodeToDelete->next->nameCountry!=NULL && listNodeToDelete->prev->nameCountry!=NULL){/*daca se afla la mijloc*/
        (listNodeToDelete->prev)->next=listNodeToDelete->next;
        (listNodeToDelete->next)->prev=listNodeToDelete->prev;
    }else if(listNodeToDelete->prev->nameCountry==NULL){/*daca este primul nodde*/
          (listNodeToDelete->prev)->next=(listNodeToDelete->next);
          (listNodeToDelete->next)->prev=(listNodeToDelete->prev);
    }else if(listNodeToDelete->next->nameCountry==NULL){/*daca este ultimul node*/
    /*daca a ajuns la santinela*/
      (listNodeToDelete->next)->prev=(listNodeToDelete->prev);
      (listNodeToDelete->prev)->prev=(listNodeToDelete->next);
    }
    free(listNodeToDelete);

}

void lookInList(C__NAMES__ * start){

//writeToFile("rezultate.out","\n____________________\n");
/*
    C__NAMES__ * __saveStartAdress__;
    __saveStartAdress__=start->next;
    printf("%s %s",__saveStartAdress__->nameCountry->name,__saveStartAdress__->prev->nameCountry->name);
    writeToFile("rezultate.out","\n____________________\n");
    while(__saveStartAdress__->next->nameCountry!=NULL){
        printf("%s",__saveStartAdress__->nameCountry->name);//,__saveStartAdress__->nameCountry->nr_players
         //writeToFile("rezultate.out",__saveStartAdress__->nameCountry->name);
        for(int i=0;i<__saveStartAdress__->nameCountry->nr_players;i++)
        {
            printf("%s__%s__%d\n",__saveStartAdress__->nameCountry->players[i].first_name,__saveStartAdress__->nameCountry->players[i].last_name,__saveStartAdress__->nameCountry->players[i].score );
        }
        __saveStartAdress__=__saveStartAdress__->next;
    }
    */
}



int checkIfIsNull(void * any_pointer){

    if (any_pointer==NULL){
        ERROR_1_MEM_ERROR
        exit(1);
        return 1;
    }else{
      return 0;
    }

}

/*calculeaza cea mai mica putere a lui 2*/
int putereMica2(int n){

  int i=0;
  int mic=0;

  while(mic<n){

    mic=pow(2,i);
    i++;
  }

  return (pow(2,i-2));
}




void pushStack(stackNode ** stack,Country *  valueToAdd){

    stackNode * save;
    save=alocStackNode(1);
    save->content=valueToAdd;
    save->prev=(*stack);
    *stack=save;

}
int emptyStack(stackNode * stack){

    if(stack==NULL){
      return 1;
    }else{
      return 0;
    }

}

Country * popStack(stackNode ** stack){



    if(emptyStack(*stack)==1){
        return NULL;
    }
    stackNode * save;
    Country * saveNode;


    save=(*stack);
    saveNode=save->content;
    //  printf("%s",(*stack)->content->name);
    (*stack)=(*stack)->prev;

    free(save);
    return saveNode;
}




Queue * createQueue()
{
  Queue *q;
  q=(Queue *)malloc(sizeof(Queue));
  if (q==NULL)
    return NULL;
  q->front=q->rear=NULL;
  return q;
}

void enQueue(Queue * q, Player * v){
  COADA * newNode=(COADA*)malloc(sizeof(COADA));
  newNode->val=v;
  newNode->next=NULL;
  if (q->rear==NULL)
   q->rear=newNode;
   else{
     (q->rear)->next=newNode;
     (q->rear)=newNode;
   }
   if (q->front==NULL)
   q->front=q->rear;
 }


int isEmpty(Queue *q){
  return (q->front==NULL);
}
 Player * deQueue(Queue *q) {
   COADA* aux;
    Player * d;
  //  if (isEmpty(q))
    //return {0};
    aux =q->front;
    d= aux->val;
    q->front=(q->front)->next;
    free(aux);
    return d;
  }

void deleteQueue(Queue *q){
  COADA* aux;
  while (!isEmpty(q)){
    aux=q->front;
    q->front=q->front->next;
    free(aux);
  }
  free(q);
}


/*sterg spatiile sau tab.urile ramase */
char * clearContentChar(char * nume){

      for(int i=0;nume[i]!='\0';i++){
        if(nume[i]=='\n' || nume[i]=='\t' || nume[i]==' '){
            nume[i]='\0';
        }
      }
      return nume;
}



stackNode * alocStackNode(int n)
{
  stackNode * alocStack;

  alocStack=(stackNode*)malloc(n*sizeof(stackNode));
  checkIfIsNull(alocStack);
  return alocStack;
}


int * alocInt(int n){
  int * charaloc;

  charaloc=(int *)malloc((n+1)*sizeof(int));
  checkIfIsNull(charaloc);

  return charaloc;
}

/*functia de alocare pentru Char.uri*/
char * aloChar(int n){

  char * charaloc;

  charaloc=(char *)malloc((n+1)*sizeof(char));
  checkIfIsNull(charaloc);

  return charaloc;
}
/*functia de alocare pentru Player*/
Player * aloPlayer(int n){

  Player * charaloc;

  charaloc=(Player *)malloc(n*sizeof(Player));
  checkIfIsNull(charaloc);

  return charaloc;
}

/*functia de alocare pentru Country*/
Country * aloCountry(int n){

  Country * charaloc;

  charaloc=(Country *)malloc(n*sizeof(Country));
  checkIfIsNull(charaloc);

  return charaloc;
}

/*functia de alocare pentru index*/
INDEX * alocIndex(int n){

    INDEX * charaloc;

    charaloc=(INDEX *)malloc(n*sizeof(INDEX));
    checkIfIsNull(charaloc);

    return charaloc;

}
