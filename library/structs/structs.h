
#ifndef STRUCTS
#define STRUCTS

    /* structura jucator */
    typedef struct Player {
      char *last_name;
      char *first_name;
      int score;
    } Player;

    /* Structura pentru tara */
    typedef struct Country {
      char *name;
      int nr_players;
      int global_score;
      Player *players;
    } Country;

    /*
     * pentru task-ul 1
     * lista dublu inlantuita
     */
    typedef struct countryNames {
      Country *nameCountry;
      struct countryNames *next;
      struct countryNames *prev;

    } C__NAMES__;

    /*
     *  lista pentru stack
     */
    typedef struct stack {
      Country *content;
      struct stack *prev;

    } stackNode;

    /*
    Aceasta structura o folosesc pentru a putea returna un int si un pointer din
    readFromFile
    */
    typedef struct returnFromReadFile {
      C__NAMES__ *nameCountry;  // valoarea santinelei
      int val;  // numarul de tari din fisier

    } RETURN_POINT_FLOAT;
    /*
    imi foloseste la task-ul 2
    idee->pun toate adresele din lista aici si
     le aflu scorul minim o singura data.
    Apoi elemin tarile din lista dublu inlantuita
    De ce fac asta ?
    Pai vreau sa limitez parcurgerea si calculul facut pe lista principala
    Asa decat stochez adresele si scorul in memorie.
    */
    typedef struct createIndex {
      C__NAMES__ *ctrName;
      float scoreMinim;

    } INDEX;

    /*structura pentru coada cu valori de tip player*/
    typedef struct EL {
      Player *val;
      struct EL *next;
    } COADA;

    /*structura care tine adresa de inceput si sfarsit*/
    typedef struct Q {
       COADA *front, *rear;
     } Queue;

     /*BST-ul cu valori de tip player*/
    typedef struct TREE {
      Player val;
      struct TREE *left, *right;

    } TREE;

#endif
