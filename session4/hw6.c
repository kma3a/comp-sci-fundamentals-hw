#include <stdio.h>
#define IS_NEWLINE(x) ((x) == '\n') 
#define IS_EVEN(x) ((x) % 2 == 0)


int getOneLine(char line[], FILE *file, int index, int startIndex, int endIndex) {
  int c, currentIndex = index;
  int lineIndex = 0;


  while ( (c = getc (file)) != EOF) {
    if(IS_NEWLINE(c)) {
      break;
    }
    if(lineIndex >= startIndex && lineIndex <= endIndex) {
      line[currentIndex] = c;
      currentIndex++;
    }

    lineIndex++;
  }

  line[currentIndex] = '\n';
  if (c == EOF) {
    return -1;
  }

  return currentIndex + 1;
}



int main(void){
  char inName[64];
  char final[128];
  FILE *in;
  int index = 0, lineCount = 1;
  int startValue, endValue;

  printf("Enter name of file to be read: ");
  scanf("%63s", inName);
  printf("Enter the start value: ");
  scanf("%d", &startValue);
  printf("Enter the end value: ");
  scanf("%d", &endValue);


  if( (in = fopen (inName, "r")) == NULL) {
    printf("can't open %s for reading. \n", inName);
    return 1;
  }

  while (index >=0) {
    index =  getOneLine(final, in, index, startValue, endValue);
    lineCount++;
  }

  fclose(in);
  fprintf(stdout, "%s \n", final);
  return 0;

}
