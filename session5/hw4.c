#include <stdio.h>
#include <stdlib.h>

/*
 * struct for the double link list
 */
struct link {
  int value;
  struct link *next;
  struct link *previous;
};

struct link *insertEntry(struct link *prior_link, int newValue){
  struct link *newLink;
  newLink = (struct link *)calloc( 1000,sizeof(struct link));
  newLink->value = newValue;
  newLink->previous = prior_link;
  newLink->next = prior_link->next;

  prior_link->next->previous = newLink;
  prior_link->next = newLink;

  return prior_link->next;
}

void removeEntry(struct link *removal){
  if( removal->next != (struct link *) 0) {
    removal->previous->next = removal->next;
    removal->next->previous = removal->previous;
  } else {
    removal->previous->next = (struct link *) 0;
  }

  free(removal);

}

void readDoubleLinks(struct link *list_pointer){
  int end =0;

  printf("\n forwards \n");
  while(!end) {
    printf("%i, ", list_pointer->value);
    if(list_pointer->next == (struct link *) 0){
      end = 1;
    } else {
      list_pointer = list_pointer->next;
    }
  }

  end = 0;
  printf("\n Backwards \n");

  while(!end) {
    printf("%i, ", list_pointer->value);
    if(list_pointer->previous == (struct link *) 0){
      end = 1;
    } else {
      list_pointer = list_pointer->previous;
    }
  }
}



int main(void){
  struct link one, two, three;
  struct link *list_pointer = &one;
  struct link *new;

  one.previous = (struct link *) 0;
  one.value = 2;
  one.next = &two;

  two.previous = &one;
  two.value = 8;
  two.next = &three;

  three.previous = &two;
  three.value = 66;
  three.next = (struct link *) 0;

  new = insertEntry(&two, 5);
  readDoubleLinks(list_pointer);
  removeEntry(new);
  readDoubleLinks(list_pointer);

  
  printf("\n done \n");
 
  return 0;
}
