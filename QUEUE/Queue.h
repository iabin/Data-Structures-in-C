#include <stdlib.h>
#include <stdio.h>
/* Basic Queue Implemetation
@author Alejandro Iabin Arteaga Hernandez
Data structures: Queue
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
  int size;
} Queue;

Queue* newQueue();
int destroyQueue(Queue* queue);
int isEmpty(Queue* queue);
int push(Queue* queue,ElemetType element);
ElementType pop(Queue* queue);
ElementType top(Queue* queue);


#endif /*__Queue_h*/
