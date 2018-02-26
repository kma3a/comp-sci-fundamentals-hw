#include <stdio.h>
#include <stdlib.h>

int stringLength(char *string) {
  int index =1;
  while(string[index] != '\0') {
    index++;
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


char *insertString(char *oString, char *addString, int addIndex){
  char *finishedString = (char *) malloc(stringLength(oString) + stringLength(addString) +1);
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
  finishedString[finishedIndex+1] = '\0';
  return finishedString;

}

char *removeString(char *string, int startIndex, int numRemoved){
  char *finishedString = (char *) malloc(stringLength(string));
  int index = 0, finishedIndex = 0;
  for(; string[index] != '\0'; index++) {
    if(index < startIndex || index > ( startIndex + numRemoved )) {
      finishedString[finishedIndex] = string[index];
      finishedIndex++;
    }
  }
  finishedString[finishedIndex + 1] = '\0';
  return finishedString;

}

char *replaceString(char *oString, char *replaceText, char *newText){
  char *newString = (char *) malloc(stringLength(oString) - stringLength(replaceText) + stringLength(newText) + 1);
  int replaceIndex = findString(oString, replaceText);
  if(replaceIndex >= 0 ) {
    newString = removeString(oString, replaceIndex, stringLength(replaceText));
    newString = insertString(newString, newText, replaceIndex);
  } else {
    newString = "Could not find string";
  }

  return newString;
}


int main (void) {
  char *newString;
  newString = replaceString("I am one cool", "one cool", "number one");
  printf("%s \n", newString);

  return 0;
}
