#include <stdio.h>
#define IS_NEWLINE(x) ((x) == '\n') 
#define IS_EVEN(x) ((x) % 2 == 0)


int getOneLine(char line[], FILE *file, int startIndex) {
  int c, currentIndex = startIndex;

  while ( (c = getc (file)) != EOF) {
    line[currentIndex] = c;
    if(IS_NEWLINE(c)) {
      break;
    }
    currentIndex++;
  }

  line[currentIndex] = '\n';
  if (c == EOF) {
    return -1;
  }

  return currentIndex + 1;
}



int main(void){
  char inNameOne[64], inNameTwo[64];
  char final[128];
  FILE *inOne, *inTwo;
  int index = 0, lineCount = 1, total;

  printf("Enter name of file to be merged: ");
  scanf("%63s", inNameOne);
  printf("Enter name of file to be merged: ");
  scanf("%63s", inNameTwo);

  if( (inOne = fopen (inNameOne, "r")) == NULL) {
    printf("can't open %s for reading. \n", inNameOne);
    return 1;
  }
  if( (inTwo = fopen (inNameTwo, "r")) == NULL) {
    printf("can't open %s for reading. \n", inNameTwo);
    return 1;
  }

  while (index >=0) {
    total = index;
    if(IS_EVEN(lineCount)) {
      index = getOneLine(final, inTwo, index);
    } else {
      index = getOneLine(final, inOne, index);
    }
    lineCount++;
  }

  while (total >=0) {
    if(IS_EVEN(lineCount)) {
      total = getOneLine(final, inTwo, total);
    } else {
      total = getOneLine(final, inOne, total);
    }
  }

  fclose(inOne);
  fclose(inTwo);
  fprintf(stdout, "%s \n", final);
  return 0;

}
