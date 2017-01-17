#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"
#include <time.h>
#include "UnitC.h"

void newStackTest(){
 clock_t start = clock();
  Stack* list = newStack();
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  if(list == NULL)
    assertMessage(1,"create a new Stack",segs);
  else
    assertMessage(0,"create a new Stack",segs);
  destroy(list);
}

void destroyTest(){
  Stack* list = newStack();
  clock_t start = clock();
  push(list,0);
  push(list,1);
  destroy(list); //if destroy did't work, the test would die, showing you an error
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"Destroy",segs); 
}

void isEmptyTest(){
  Stack* list = newStack();
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
  Stack* list = newStack();
  clock_t start = clock();
  push(list,0);
  push(list,1);
  push(list,2);

  if(list->top->element==2&&list->size==3){ 
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
  Stack* stack = newStack();
  clock_t start = clock();
  push(stack,1);
  push(stack,2);
  push(stack,3);
  push(stack,4);
  
  if(pop(stack)!=4){ 
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"pop",segs);
    destroy(stack);
    return;
  }	
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(0,"pop",segs);
    destroy(stack);
}


void topTest() {
  Stack* stack = newStack();
  push(stack,1);
  push(stack,2);
  push(stack,3);
  clock_t start = clock();
  if(top(stack)!=3){
    double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
    assertMessage(1,"top",segs);
    destroy(stack);
  }
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  assertMessage(0,"top",segs);
  destroy(stack);
} 


void efficiencyTests(){
  Stack* stack =  newStack();
  //LIST WITH 10,000,000 ELEMENTS
  clock_t start = clock();
  int i = 0;
  for(i;i<10000000;i++)
    push(stack,i);
  double segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  efficiencyMessage("INSERT 100,000,000 INTEGERS IN A STACK",segs);
  destroy(stack);

  Stack* lista2 =  newStack();
  i = 0;
  start = clock();
  for(i;i<10000000;i++){ 
    int number = rand() % 1000000;
    push(lista2,number);
  }
  segs = (double)(((double)clock() - start) / CLOCKS_PER_SEC);
  efficiencyMessage("INSERT 100,000,000 RANDOM INTEGERS IN A STACK",segs);
  destroy(lista2);
  i=0;
  Stack* lista3 =  newStack();
  for(i;i<100;i++){
    push(lista3,i);
  }
  while(!isEmpty(stack)){
    printf("%i ,",pop(lista3));
  }

  printf("\n");
} 

int main(){ 
  newStackTest();
  destroyTest();
  isEmptyTest();
  pushTest();
  popTest();
  topTest();
  efficiencyAssert();
  efficiencyTests();

  return 0;

}
 
