#include <stdio.h>

/*
 * struct for the day
 */
struct link {
  int value;
  struct link *next;
  struct link *previous;
};



int main(void){
  struct link one, two, three;
  struct link *list_pointer = &one;

  one.value = 2;
  one.next = &two;

  two.previous = &one;
  two.value = 8;
  two.next = &three;

  three.previous = &two;
  three.value = 66;
  three.next = (struct link *) 0;

  while( list_pointer != (struct link *) 0) {
    printf("%i \n", list_pointer->value);
    list_pointer = list_pointer->next;
  }
  
  return 0;
}
