#include <stdio.h>
int getLength(char string[]) {
  int index = 0;
  while( string[index] != '\0') {
    ++index;
  }
  return index;
}

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

void removeString(char array[], int removeStart, int removeEnd){
  for(int i = 0; array[i] != '\0'; ++i) {
    if(array[i+removeEnd] == '\0'){
      array[i] = '\0';
      return;
    }
    if( i >= removeStart) {
      array[i] = array[i+removeEnd];
    }
  }


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


void replaceString(char text[], char string1[], char string2[]){
  int stringLength = getLength(string1);
  int index = findString(text, string1);
  printf("I ma the lenght: %d \n", stringLength);
  removeString(text, index, stringLength);
  insertString(text, string2, index);
}

int main(void){
  char text[] = "I am the 1 truth";
  replaceString(text, "1", "one");

  return 0;
}
