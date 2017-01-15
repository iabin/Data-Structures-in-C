#include <stdlib.h>
#include <stdio.h>
#include "List.h"
/*Internal method
It creates a new node*/
Node* newNode(ElementType* element){
  Node*  node = (Node*)malloc(sizeof(Node));
  if(node==NULL)
    return node;
  node->element = *element;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

/* list destructor*/
int destroy(List* list){
  free(list);
    return 0;
}

/*Node destructor*/
int destroyNode(Node* nodo){
  free(nodo);
  return 0;
}

/*Like a constructor, makes a new list*/
List* newList() {
  List* list = (List*)malloc(sizeof(List));
  if(list == NULL)
    return list;
  
  list->head = NULL;
  list->tail = NULL;
  list->size = 0; 
  return list;
}

/*Insert an element at the end of the list*/
int insert(List* list,ElementType element) {
  if(list->head==NULL) {
    list->head = newNode(&element);
    list->tail = list->head;
    list->size = 1;
    return 0;
  }
  Node* nodo = newNode(&element);
  list->tail->next = nodo;
  nodo->prev = list->tail;
  list->tail = nodo;
  list->size++;
}

/*Insert an element at the begin of the list*/
int insertFirst(List* list,ElementType element){
 if(list->head==NULL) {
    list->head = newNode(&element);
    list->tail = list->head;
    list->size = 1;
    return 0;
  }
 
  Node* nodo = newNode(&element);
  list->head->prev = nodo;
  nodo->next = list->head;
  list->head = nodo;
  list->size++;

}

/*Searches an element and deletes it*/
int delete(List* list,ElementType element){ 
  Node* del = find(list,element);
  if(del == NULL)
    return 1;
  if(del==list->head){ 
    deleteFirst(list,element);
    return 0;
  } 
  if(del==list->tail){
    del->prev->next = NULL;
    list->tail = NULL;
    destroyNode(del);
    return 0;
  }
  
  del->prev->next = del->next;
  del->next->prev = del->prev;
  destroyNode(del);
  return 0;
  } 

/*delete the list head*/
int deleteFirst(List* list,ElementType element){
  if(list->size==0)
    return 1;
  if(list->size==1){
    destroyNode(list->head);
    list->head == NULL;
  } 
  Node* newHead =  list->head->next;
  newHead->prev = NULL;
  destroyNode(list->head);
  list->head == newHead; 
} 

/*returns an int
1 if is empty
0 if not
*/
int isEmpty(List* list) {
  if(list->size==0)
    return 1;
  return 0;
}

/*Returns the list size*/
int size(List* list){
  return list->size;
}

/*returns an int
1 if the element is in the list
0 if not
*/
int isHere(List* list,ElementType element) {
  if(find(list,element)!=NULL)
    return 1;
  return 0;
}

/*finds an element, return null if is not in the list*/
Node* find(List* list,ElementType element) {
  if(list->head==NULL)
    return NULL;
  Node* node = list->head; 
  while(node!=NULL){
    if(node->element == element)
      return node;
    node = node->next;
  }
  return NULL;
}


/*Returns the reverse version of the list*/
List* reverse(List* list){
 Node* node = list->head;
 List* list2 = newList();
  while(node!=NULL){
    insertFirst(list2,node->element);
    node = node->next;
  }
  return list2;
}




