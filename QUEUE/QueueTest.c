#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"
#include <time.h>
#include "UnitC.h"

void newQueueTest(){
 clock_t start = clock();
  Queue* list = newQueue();
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  if(list == NULL)
    assertMessage(1,"create a new Queue",segs);
  else
    assertMessage(0,"create a new Queue",segs);
  destroy(list);
}

void destroyTest(){
  Queue* list = newQueue();
  clock_t start = clock();
  push(list,0);
  push(list,1);
  destroy(list); //if destroy did't work, the test would die, showing you an error
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"Destroy",segs); 
}

void isEmptyTest(){
  Queue* list = newQueue();
  clock_t start = clock();
  if(!isEmpty(list)){
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"isEmpty",segs);
    destroy(list);
    return;
  }
  push(list,1);
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


void pushTest(){
  Queue* list = newQueue();
  clock_t start = clock();
  push(list,0);
  push(list,1);
  push(list,2);

  if(list->top->element==0&&list->size==3){ 
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"push",segs);
  destroy(list);
  return;
  }
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(1,"push 2",segs);
  destroy(list);
}


void popTest(){ 
  Queue* queue = newQueue();
  clock_t start = clock();
  push(queue,1);
  push(queue,2);
  push(queue,3);
  push(queue,4);
  
  if(pop(queue)!=1){ 
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"pop",segs);
    destroy(queue);
    return;
  }	

  if(pop(queue)!=2){ 
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"pop",segs);
    destroy(queue);
    return;
  }	
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(0,"pop",segs);
    destroy(queue);
}


void topTest() {
  Queue* queue = newQueue();
  push(queue,1);
  push(queue,2);
  push(queue,3);
  clock_t start = clock();
  if(top(queue)!=1){
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"top",segs);
    destroy(queue);
    return;
  }
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"top",segs);
  destroy(queue);
} 


void efficiencyTests(){
  Queue* queue =  newQueue();
  //LIST WITH 10,000,000 ELEMENTS
  clock_t start = clock();
  int i = 0;
  for(i;i<10000000;i++)
    push(queue,i);
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  efficiencyMessage("INSERT 100,000,000 INTEGERS IN A QUEUE",segs);
  destroy(queue);

  Queue* lista2 =  newQueue();
  i = 0;
  start = clock();
  for(i;i<10000000;i++){ 
    int number = rand() % 1000000;
    push(lista2,number);
  }
  segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  efficiencyMessage("INSERT 100,000,000 RANDOM INTEGERS IN A QUEUE",segs);
  destroy(lista2);
  i=0;
  Queue* lista3 =  newQueue();
  for(i;i<100;i++){
    push(lista3,i);
  }
  while(!isEmpty(queue)){
    printf("%i ,",pop(lista3));
  }

  printf("\n");
} 

int main(){ 
  newQueueTest();
  destroyTest();
  isEmptyTest();
  pushTest();
  popTest();
  topTest();
  efficiencyAssert();
  efficiencyTests();

  return 0;

}
 
