#include <stdio.h>

int getLength(char string[]) {
  int index = 0;
  while( string[index] != '\0') {
    ++index;
  }
  return index;
}

void insertString(char array[], char insertChar[], int insertStart){
  int length = getLength(array);
  int insertLength = getLength(insertChar);
  char newArray[length + insertLength + 1];
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

  printf("%s \n", newArray);
}

int main(void) {
  char text[] = "the wrong son";
  insertString(text, "per", 10);
  return 0;
}
