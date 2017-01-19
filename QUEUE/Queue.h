#include <stdlib.h>
#include <stdio.h>
/* Basic Queue Implemetation
@author Alejandro Iabin Arteaga Hernandez
Data structures: STACK
*/
#ifndef __Queue_h
#define __Queue_h

/*YOU CAN MODIFY THE ELEMENT TYPE*/
typedef int ElementType;

typedef struct Node{
  ElementType element;
  struct Node* prev;
} Node;

typedef struct Queue{
  Node* top;
  Node* bot;
  int size;
} Queue;

Queue* newQueue();
int destroy(Queue* queue);
int isEmpty(Queue* queue);
int push(Queue* queue,ElementType element);
ElementType pop(Queue* queue);
ElementType top(Queue* queue);


#endif /*__Queue_h*/
