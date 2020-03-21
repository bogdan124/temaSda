#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

typedef struct countryNames{

    Country * nameCountry;
    struct countryNames * next;
    struct countryNames * prev;

}C__NAMES__;



Player * aloPlayer(int n);

/*aici am functiile cu pentru liste*/
C__NAMES__ * initDoubleList();
C__NAMES__ * addNodeDoubleListEnd(C__NAMES__ ** listEndNode);
C__NAMES__ * finishList(C__NAMES__ ** endList,C__NAMES__ ** startList);
C__NAMES__ * addSentinel(C__NAMES__ ** startList,C__NAMES__ ** finishList);
void lookInList(C__NAMES__ * start,C__NAMES__ * santinel);
void putDataIntoList(C__NAMES__ ** listEndNode,char * nameTara ,int nrPlayers);
Player * createPlayerStivInit(int numberOfplayers);
void pushPlayerStiv(Player * stivPlayer,char * first_name,char * last_name,int score_player,int numberOfplayers);


void clearContentOfAFile(char * filename);
int readFromFile(char * filenameOne,char * filenameTwo,char * filenameThree);//return number of country
void * writeToFile(char * filenameToWrite,char * whatToWrite);
void  createFileToWrite(char * filenameToWrite,char * whatToWrite);
int checkedIfFilesAreNamedProperly(char ** files);

Country * aloCountry(int n);
char * aloChar(int n);
int checkIfIsNull(void * any_pointer);


/*aici sunt task-urile*/
int task1(char ** files);
void task2();
void task3();
void whatTaskToSolve(char * filenameOne,char ** files);



int main(int num_items,char ** files){

  //if(checkedIfFilesAreNamedProperly(files)==0){

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
    FILE *f;
    f=fopen(filenameOne,"r");
    int i=0;
    int cerinteIn[5];
      while(i<5){
          fscanf(f, "%d", &cerinteIn[i]);
          i++;
      }
        fclose(f);
      if(cerinteIn[0]==1){
         task1(files);
         if(cerinteIn[1]==1){
           task2();
         }
      }
}

/*solve task 1*/
int task1(char ** files){
  int task1;

  task1= readFromFile(files[1],files[2],files[3]);
  return task1;
}
/*solve task 2*/
void task2(){

}




int readFromFile(char * filenameOne,char * filenameTwo,char * filenameThree){

  FILE *f;

  int num_date;
  int i=0;
  int j=0;

  int count=0;
  int saveNumPlayersPerCountry;
  int playersNumPerCountry;

  int initData=0;

  Player * playerStiv;

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

  if(strcmp("date.in",filenameTwo)==0)
  {
    f=fopen(filenameTwo,"r");
    fscanf(f, "%d", &num_date);
    printf("%d__ ",num_date);
    while(playersNumPerCountry!=EOF ){
        fscanf(f,"%d",&playersNumPerCountry);
        saveNumPlayersPerCountry=playersNumPerCountry;
        if(playersNumPerCountry<=0){
          break;
        }
        playersNumPerCountry=playersNumPerCountry+2;
         playerStiv=createPlayerStivInit(saveNumPlayersPerCountry);
        while(playersNumPerCountry!=0 ){
          fgets(bufferToStore,100,f);

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
        //   printf("--%s--",bufferToStore);
          // writeToFile(filenameThree,bufferToStore);
           /*
              write data to list
              here we write Country names ->bufferToStore
                            int number of players->saveNumPlayersPerCountry
           */
           putDataIntoList(&__storeFinishAdress__,bufferToStore,saveNumPlayersPerCountry);

         }else{
             if(bufferToStore[0]!='\n' && bufferToStore[0]!='\t'){
              //   printf("!!!%s",bufferToStore);
                 first_name=strtok(bufferToStore," ");


                 second_name=strtok(NULL," ");
                 scorePlayer=strtok(NULL," ");
                 pushPlayerStiv(playerStiv,first_name,second_name,atoi(scorePlayer),saveNumPlayersPerCountry);
            }
         }
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
  }



      fclose(f);
    lookInList(__storeStartAdress__,__storeFinishAdress__);
    return num_date;
}


void * writeToFile(char * filenameToWrite,char * whatToWrite){
  FILE * f;
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
  fprintf(g, "%s",whatToWrite);
  fclose(g);
}

void clearContentOfAFile(char * filename){
  FILE * f;
  f=fopen(filename,"w");
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
  alocNewNode->prev=(*startList);
  (*startList)->prev=alocNewNode;
  alocNewNode->next=(*finishList);
  (*finishList)->next=alocNewNode;

  return alocNewNode;
}

void delNodeDoubleListEnd(){


}

void lookInList(C__NAMES__ * start,C__NAMES__ * santinel){

  printf("___________________________________\n");
    C__NAMES__ * __saveStartAdress__;
    __saveStartAdress__=start;
    while(__saveStartAdress__->next!=santinel){
        printf("%s_____%d \n",__saveStartAdress__->nameCountry->name,__saveStartAdress__->nameCountry->nr_players);
        for(int i=0;i<__saveStartAdress__->nameCountry->nr_players;i++)
        {
            printf("%s__%s__%d\n",__saveStartAdress__->nameCountry->players[i].first_name,__saveStartAdress__->nameCountry->players[i].last_name,__saveStartAdress__->nameCountry->players[i].score );
        }
        __saveStartAdress__=__saveStartAdress__->next;
    }
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



char * aloChar(int n){

  char * charaloc;

  charaloc=(char *)malloc(n*sizeof(char));
  if(charaloc==NULL){
    exit(1);
  }

  return charaloc;
}

Player * aloPlayer(int n){

  Player * charaloc;

  charaloc=(Player *)malloc(n*sizeof(Player));
  if(charaloc==NULL){
    exit(1);
  }

  return charaloc;
}


Country * aloCountry(int n){

  Country * charaloc;

  charaloc=(Country *)malloc(n*sizeof(Country));
  if(charaloc==NULL){
    exit(1);
  }

  return charaloc;
}
