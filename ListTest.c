#include "UnitC.h"
#include "List.h"
#include <time.h>
/*Proves newList method*/
void newListTest(){
  clock_t start = clock();
  List* list = newList();
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  if(list == NULL)
    assertMessage(1,"create a new List",segs);
  else
    assertMessage(0,"create a new List",segs);
  destroy(list);
}

/*Proves insert method*/
void insertTest(){
  List* list = newList();
  int i = 0;
  clock_t start = clock();
  for(i;i<1000;i++){
    insert(list,i);
  }
  if(list->head->element==0&&list->tail->element==999&&list->size==1000){ 
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"insert elements",segs);
  destroy(list);
  return;
  }
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(1,"insert elements",segs);
  destroy(list);
}

/*Proves destroy method*/
void destroyTest(){
  List* list = newList();
  clock_t start = clock();
  insert(list,0);
  insert(list,1);
  destroy(list); //if destroy did't work, the test would die, showing you an error
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"Destroy",segs); 
}

/*Proves insertFirst method*/
void insertFirstTest() {
  List* list = newList();
  int i = 0;
  clock_t start = clock();
  for(i;i<1000;i++){
    insertFirst(list,i);
  }
  if(list->head->element==999&&list->tail->element==0&&list->size==1000){ 
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"insert elements",segs);
  destroy(list);
  return;
  }
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(1,"insert elements",segs);
  destroy(list);
}

/*Proves delete method*/
void deleteTest() {
  List* list = newList();
  int  i = 0;
  for(i;i<1000;i++){ 
    insert(list,i);
  }
  clock_t start = clock();
  for(i;i<1000;i++){ 
    delete(list,i);
    
  if(!list->size==(1000-i-1)) {
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(1,"delete",segs);
  destroy(list);
  return;
  } 
  }
  destroy(list);
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"delete",segs);
} 



/*Proves deleteFirst method*/
void deleteFirstTest(){
  List* list = newList();
  int i = 0;
  for(i;i>1000;i++){
    insert(list,i);
  }
  i = 0;
  clock_t start = clock();
  for(i;i>1000;i++){
    if(!list->head == i) {
      double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
      assertMessage(1,"deleteFirst",segs);
      destroy(list);
      return;
    }
    
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(0,"deleteFirst",segs);
    destroy(list);
    return;
  }
}

/*Proves isEmpty method*/
void isEmptyTest(){
  List* list = newList();
  clock_t start = clock();
  if(!isEmpty(list)){
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"isEmpty",segs);
    destroy(list);
    return;
  }
  insert(list,1);
  if(isEmpty(list)){
     double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"isEmpty",segs);
    destroy(list);
    return;
  }
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"isEmpty",segs);
  destroy(list);
  return;
}

/*Proves size method*/
void sizeTest(){
  List* list = newList();
  clock_t start = clock();
  if(size(list)!=0){
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"Size: Empty size must be 0",segs);
    destroy(list);
    return;
  }
  int  i = 0;
  for(i;i<10000;i++){ 
      insert(list,i);
    } 
  if(size(list)!=10000){
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"size",segs);
    destroy(list);
    return;
  }
   double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
   assertMessage(0,"size",segs);
   destroy(list);
   return;
}

/*Proves isHere  method*/
void isHereTest() {
  List* list = newList();
  clock_t start = clock();
  if(isHere(list,1)){
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"isHere",segs);
    destroy(list);
    return;
  }
  insert(list,8);
  if(!isHere(list,8)){ 
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"isEmpty",segs);
    destroy(list);
    return;
  }
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"isEmpty",segs);
  destroy(list);
  return;
}

/*Proves find method*/
void findTest(){
  clock_t start = clock();
  List* list = newList();
  if(find(list,8)!=NULL){
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"findTest",segs);
    destroy(list);
    return;
  }
  insert(list,8);
  if(find(list,8)->element==list->head->element){
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(0,"findTest",segs);
    destroy(list);
    return;
  }
  int i = 100;
  for(i;i>0;i--){
    insert(list,i);
  }
   if(find(list,2)->element==list->tail->prev->element){
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(0,"findTest",segs);
    destroy(list);
    return;
  }
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"findTest",segs);
    destroy(list);
    return;
}

/*Proves reverse method*/
void reverseTest(){
  List* list = newList();
  int i = 1000;
  for(i;i>0;i--){
    insert(list,i);
  }
  clock_t start = clock();
  List* lista = reverse(list);
  i = 1;
  Node* node = list->head;
  while(node != NULL){
    if(!node->element==i){
      double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
      assertMessage(1,"reverse",segs);
      destroy(list);
      return;
    }
    node = node->next;
  } 
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"reverse",segs);
  destroy(list);
  return;
}

/*execute all the tests*/
void allTests(){
  printf("\n");
  newListTest();
  insertTest();
  destroyTest();
  insertFirstTest();
  deleteTest();
  deleteFirstTest();
  isEmptyTest();
  sizeTest();
  isHereTest();
  findTest();
  reverseTest();
  endTests();
}

/*efficiency tests, excecute hard test to prove the List*/
void efficiencyTests(){
  List* lista =  newList();
  //LIST WITH 10,000,000 ELEMENTS
  clock_t start = clock();
  int i = 0;
  for(i;i<10000000;i++)
    insert(lista,i);
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  efficiencyMessage("INSERT 100,000,000 INTEGERS IN A LIST",segs);
  destroy(lista);

  List* lista2 =  newList();
  i = 0;
  start = clock();
  for(i;i<10000000;i++){ 
    int number = rand() % 1000000;
    insert(lista2,number);
  }
  segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  efficiencyMessage("INSERT 100,000,000 RANDOM INTEGERS IN A LIST",segs);
  destroy(lista2);
  i=0;
  List* lista3 =  newList();
  for(i;i<100;i++){
    insert(lista3,i);
  }
  lista3 = reverse(lista3); 
  Node* node = lista3->head;
  while(node!=NULL){
    printf("%i ,",node->element);
    node = node->next;
  }

  printf("\n");
  printf("%i ",size(lista3));
  printf("\n");
} 

/*Main method*/
int main(){
  allTests();
  efficiencyAssert();
  efficiencyTests();
  return 0;
} 

