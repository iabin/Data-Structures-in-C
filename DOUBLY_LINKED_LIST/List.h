#include <stdlib.h>
#include <stdio.h>
/* Basic List Implemetation
@author Alejandro Iabin Arteaga Hernandez
Data structures:DOUBLY LINKED LIST
*/
#ifndef __List_h
#define __List_h

/*YOU CAN MODIFY THE ELEMENT TYPE*/
typedef int ElementType;

/*internal node*/
typedef struct Node{
  ElementType element;
  struct Node* next;
  struct Node* prev;
} Node;

/*This shall be the external structure, all the list methods were made to work externaly,
but you should not modify the internal atributes */
typedef struct List{
  Node* head;
  Node* tail;
  int size;
} List;

/* NODE METHODS ONLY FOR INTERNAL WORKING
Node* newNode(ElementType* element);
int destroyNode(Node* nodo);
the methods are private
/*

/*List methods,you can use all*/
List* newList();
int destroy(List* list);
int insert(List* list,ElementType element);
int insertFirst(List* list,ElementType element);
int delete(List* list,ElementType element);
int deleteFirst(List* list,ElementType element);
int isEmpty(List* list);
int size(List* list);
int isHere(List* list,ElementType element);
Node* find(List* list,ElementType element);
List* reverse(List* list);


#endif /*__List_h*/



