#include <stdio.h>

int findString(char array[], char searchString[]){
  int searchIndex = 0;
  int searchLetter = 0;
  for(int i = 0; array[i] != '\0' && searchString[searchLetter] != '\0'; ++i) {
    if ( array[i] == searchString[searchLetter]) {
      if(searchLetter == 0) {
        searchIndex = i;
      }
      searchLetter++;
    }
  }
  return searchIndex;
}

int main(void){

  int index;

  index = findString("a chatterbox", "hat");

  printf("I am the beginning index of hat: %i\n", index);
  
}
