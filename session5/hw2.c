#include <stdio.h>
#include <stdlib.h>

int stringLength(char *string) {
  int index =1;
  while(string[index] != '\0') {
    index++;
  }

  return index;
}


char *insertString(char *oString, char *addString, int addIndex){
  char *finishedString = (char *) malloc(stringLength(oString) + stringLength(addString) );
  int index = 0, finishedIndex = 0;
  while (oString[index] != '\0' || index == addIndex) {
    if(index == addIndex) {
      int addStringIndex =0;
      while(addString[addStringIndex] != '\0') {
        finishedString[finishedIndex] = addString[addStringIndex];
        addStringIndex++;
        finishedIndex++;
      }
    }
    finishedString[finishedIndex] = oString[index];
    index++;
    finishedIndex++;
  }
  finishedString[finishedIndex] = '\0';
  return finishedString;

}

int main (void) {
  char *newString;
  newString = insertString("I am father", " the best", 4);
  printf(" %s \n", newString);
  free(newString);
  return 0;
}
