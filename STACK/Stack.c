#include <stdlib.h>
#include "Stack.h"


Node* newNode(ElementType* element) {
  Node* node = (Node*)malloc(sizeof(Node));
  if(node==NULL)
    return node;
  node->element = *element;
  node->prev = NULL;
 }
 
int destroyNode(Node* node){ 
  free(node);
}
 
Stack* newStack(){
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  if(stack==NULL)
    return stack;
  stack->top = NULL;
  stack->size = 0;
}

int destroy(Stack* stack){
   while(stack->top!=NULL){
    Node* node = stack->top;
    stack->top = stack->top->prev;
    destroyNode(node);
  }
  free(stack);
}

int isEmpty(Stack* stack){
  if(stack->size==0)
    return 1;
  return 0;
}

int push(Stack* stack,ElementType element){
  if(stack->top==NULL){
    Node* node = newNode(&element);
    stack->top = node;
    stack->size = 1;
    return 0;
  }
  Node* node = newNode(&element);
  node->prev = stack->top;
  stack->top = node;
  stack->size = stack->size+1;
  return 0;
}

ElementType pop(Stack* stack){
  if(stack->top==NULL)
    return -1;
  ElementType element = stack->top->element;
  Node* newTop = stack->top->prev; 
  Node* top = stack->top;
  stack->top = newTop;
  destroyNode(top);
  stack->size--;
  return element;
}
ElementType top(Stack* stack){ 
  return stack->top->element;
}
