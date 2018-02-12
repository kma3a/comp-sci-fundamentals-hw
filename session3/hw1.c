#include <stdio.h>

int findString(char array[], char searchString[]){
  int searchIndex = -1;
  int searchLetter = 0;
  for(int i = 0; array[i] != '\0' && searchString[searchLetter] != '\0'; ++i) {
    if ( array[i] == searchString[searchLetter]) {
      if(searchLetter == 0) {
        searchIndex = i;
      }
      searchLetter++;
    } else if(searchIndex >=0 && array[i] != searchString[searchLetter]){
      searchLetter = 0;
      searchIndex = -1;
    }
  }
  return searchIndex;
}

int main(void){

  int index;

  index = findString("a chatterbox", "hat");

  printf("I am the beginning index of dog: %i\n", index);

  index = findString("a chatterbox", "dog");
  
  printf("I am the beginning index of dog: %i\n", index);

  index = findString("a chatterbox", "boy");

  printf("I am the beginning index of boy: %i\n", index);
}
