#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stringLength(char *string) {
  int index =1;
  while(string[index] != '\0') {
    index++;
  }

  return index;
}

char *removeString(char *string, int startIndex, int numRemoved){
  char *finishedString = (char *) malloc(stringLength(string) - numRemoved);
  int index = 0, finishedIndex = 0;
  for(; string[index] != '\0'; index++) {
    if(index < startIndex || index > ( startIndex + numRemoved )) {
      finishedString[finishedIndex] = string[index];
      finishedIndex++;
    }
  }
  finishedString[finishedIndex] = '\0';
  return finishedString;

}

int main (void) {
  char *newString;
  newString = removeString("I am your father", 4, 4);
  printf("%s \n", newString);

  return 0;
}
