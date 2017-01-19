#include <stdlib.h>
#include "Queue.h"


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
 
Queue* newQueue(){
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  if(queue==NULL)
    return queue;
  queue->top = NULL;
  queue->bot = NULL;
  queue->size = 0;
}

int destroy(Queue* queue){
  while(queue->top!=NULL){
    Node* node = queue->top;
    queue->top = queue->top->prev;
    destroyNode(node);
  }
  free(queue);
}

int isEmpty(Queue* queue){
  if(queue->size==0)
    return 1;
  return 0;
}

int push(Queue* queue,ElementType element){
  if(queue->top==NULL){
    Node* node = newNode(&element);
    queue->top = node;
    queue->bot = node;
    queue->size = 1;
    return 0;
  }
  Node* node = newNode(&element);
  queue->bot->prev = node;
  queue->bot = node;
  queue->size = queue->size+1;
  return 0;
}

ElementType pop(Queue* queue){
  if(queue->top==NULL)
    return -1;
  ElementType element = queue->top->element;
  Node* newTop = queue->top->prev; 
  Node* top = queue->top;
  queue->top = newTop;
  destroyNode(top);
  queue->size--;
  return element;
}
ElementType top(Queue* queue){ 
  return queue->top->element;
}
