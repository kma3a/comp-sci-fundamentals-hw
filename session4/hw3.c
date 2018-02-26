#include <stdio.h>
#include "hw2.c"
#define IS_DIGIT(x) ((x) >= '0' && (x) <= '9')
#define IS_SPECIAL(x) (!IS_ALPHABETIC (x) && !IS_DIGIT (x))

int main(void){

  printf("is x special? %i \n", IS_SPECIAL('x'));
  printf("is R special? %i \n", IS_SPECIAL('R'));
  printf("is $ special? %i \n", IS_SPECIAL('$'));
  printf("is P special? %i \n", IS_SPECIAL('P'));
  printf("is 0 special? %i \n", IS_SPECIAL('0'));

  return 0;

}
