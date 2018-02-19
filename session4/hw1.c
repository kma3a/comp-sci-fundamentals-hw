#include <stdio.h>
#define IS_UPPER_CASE(x) ((x) >= 'A' && (x) <= 'Z')

int main(void){

  printf("is x uppercase? %i \n", IS_UPPER_CASE('x'));
  printf("is R uppercase? %i \n", IS_UPPER_CASE('R'));
  printf("is $ uppercase? %i \n", IS_UPPER_CASE('$'));
  printf("is P uppercase? %i \n", IS_UPPER_CASE('P'));

  return 0;

}
