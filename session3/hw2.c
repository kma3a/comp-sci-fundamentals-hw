#include <stdio.h>

void removeString(char array[], int removeStart, int removeEnd){
  char newArray[20];
  int currentIndex = 0;

  for(int i = 0; array[i] != '\0'; ++i) {
    if( i < removeStart || i > removeStart + removeEnd -1) {
      newArray[currentIndex] = array[i];
      ++currentIndex;
    }
  }

  newArray[currentIndex] = '\0';

  printf("%s", newArray);

}

int main(void){

  removeString("the wrong son", 4, 6);
  
}
