#include <stdio.h>

void insertString(char array[], char insertChar[], int insertStart){
  char newArray[20];
  int currentIndex =0;

  for(int i =0; array[i] != '\0'; ++i){

    if(i == insertStart) {
      for(int j=0; insertChar[j] != '\0'; ++j){
        newArray[currentIndex] = insertChar[j];
        ++currentIndex;
      }
    }
    newArray[currentIndex] = array[i];
    ++currentIndex;
  }

  newArray[currentIndex] = '\0';

  printf("%s", newArray);
}

int main(void) {
  insertString("the wrong son", "per", 10);
  return 0;
}
