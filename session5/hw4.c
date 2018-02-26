#include <stdio.h>

/*
 * struct for the double link list
 */
struct link {
  int value;
  struct link *next;
  struct link *previous;
};

void insertEntry(struct link *prior_link, struct link *addition){

  addition->next = prior_link->next;
  addition->previous = prior_link;

  prior_link->next = addition;

}

void removeEntry(struct link *removal){
  if( removal->next != (struct link *) 0) {
    removal->previous->next = removal->next;
    removal->next->previous = removal->previous;
  } else {
    removal->previous->next = (struct link *) 0;
  }


}

int main(void){
  struct link one, two, three;
  struct link *list_pointer = &one;
  struct link new;

  one.value = 2;
  one.next = &two;

  two.previous = &one;
  two.value = 8;
  two.next = &three;

  three.previous = &two;
  three.value = 66;
  three.next = (struct link *) 0;

  //insertEntry(&two, );
  //removeEntry(&three);

  return 0;
}
