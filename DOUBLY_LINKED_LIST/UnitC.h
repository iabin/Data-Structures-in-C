/* Unit test framework that I made specially to test data Structures 
I shall do them better next, but meanwhile is enough to test Doubly linked lists
*/
#include <stdio.h>
#include <time.h>
#include <string.h>
int tests_run = 0;
double totalTime = 0;
int tests_right = 0;

/*prints an error message in standard err or a 0k futhermore, prints the time in mlseg*/
void assertMessage(int assert,char *testDescrip,double tiempo) {
  totalTime = totalTime + tiempo;
  tests_run++;
  int i = 0;
  if(!assert){ 
    printf("%s",testDescrip);
    for(i;i<(50-strlen(testDescrip));i++)
      printf(".");
    printf("0k %lf seg\n",tiempo);
    tests_right++;
  } 
  else{ 
    fprintf(stderr," %s", testDescrip);
    for(i;i<(50-strlen(testDescrip));i++)
      printf(".");
    printf("HAS FAILED %lf seg\n",tiempo);
  } 
}

/*Prints total time and tests passed*/
void endTests(){
  printf("\n%i right tests, from %i\n",tests_run,tests_right);
  printf("Total time: %lf\n ",totalTime);
} 

/*Reboots the time and runs*/
void efficiencyAssert(){
  printf("\n************************EFFICIENCY_TESTS*************************\n");
  tests_run = 0;
  totalTime = 0;
}

/*Prints an algorithm time and a little descripcion of it*/
void efficiencyMessage(char *testDescrip,double tiempo){
  totalTime = totalTime + tiempo;
  tests_run++;
  int i = 0;
  printf("%s",testDescrip);
  for(i;i<(50-strlen(testDescrip));i++)
    printf(".");
  printf("%lf seg\n",tiempo);
  tests_right++;
    

}
 
