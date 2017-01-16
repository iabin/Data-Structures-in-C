#include <stdlib.h>
#include <stdio.h>
/* Basic Stack Implemetation
@author Alejandro Iabin Arteaga Hernandez
Data structures: STACK
*/
#ifndef __Stack_h
#define __Stack_h

/*YOU CAN MODIFY THE ELEMENT TYPE*/
typedef int ElementType;

typedef struct Node{
  ElementType element;
  struct Node* prev;
} Node;

typedef struct Stack{
  Node* top;
  int size;
} Stack;

Stack* newStack();
int destroyStack(Stack* stack);
int isEmpty(Stack* stack);
int push(Stack* stack,ElemetType element);
ElementType pop(Stack* stack);
ElementType top(Stack* stack);


#endif /*__Stack_h*/
