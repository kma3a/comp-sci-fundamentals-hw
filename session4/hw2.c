#include <stdio.h>
#include "hw1.c"
#define IS_LOWER_CASE(x) ((x) >= 'a' && (x) <= 'z')
#define IS_ALPHABETIC(x) (IS_UPPER_CASE (x) || IS_LOWER_CASE (x))

/*
int main(void){

  printf("is x alphabetic? %i \n", IS_ALPHABETIC('x'));
  printf("is R alphabetic? %i \n", IS_ALPHABETIC('R'));
  printf("is $ alphabetic? %i \n", IS_ALPHABETIC('$'));
  printf("is P alphabetic? %i \n", IS_ALPHABETIC('P'));

  return 0;

}
*/
