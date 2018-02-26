#include <stdio.h>

int stringLength(char *string) {
  int index =1;
  while(string[index] != '\0') {
    index++;
  }

  return index;
}

void removeString(char *string, int startIndex, int numRemoved){
  char finishedString[stringLength(string) - numRemoved];
  int index = 0, finishedIndex = 0;
  for(; string[index] != '\0'; index++) {
    if(index < startIndex || index > ( startIndex + numRemoved )) {
      finishedString[finishedIndex] = string[index];
      finishedIndex++;
    }
  }
  finishedString[finishedIndex] = '\0';
  printf("%s \n", finishedString);

}

int main (void) {
  removeString("I am your father", 4, 4);
  return 0;
}
