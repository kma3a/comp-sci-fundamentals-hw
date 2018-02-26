#include <stdio.h>
#define IS_NEWLINE(x) ((x) == '\n') 


int getTwentyLines(FILE *file) {
  char line[128122];
  int c;
  char isq;
  int lineIndex = 0, lineCount = 1;

  while ( (c = getc (file)) != EOF) {
   if (IS_NEWLINE(c) && lineCount ==20){ 
     break;
   } else if(IS_NEWLINE(c)) {
      lineCount++;
    }
    line[lineIndex] = c;
    lineIndex++;
  }

  line[lineIndex] = '\0';
  printf("%s \n", line);
  if (c == EOF) {
    return 0;
  }
  scanf(" %c", &isq);
  if (isq == 'q') {
    return 0;
  } else {
    return getTwentyLines(file);
  }

}


int main(void){
  char inName[64];
  FILE *in;

  printf("Enter name of file to be read: ");
  scanf("%63s", inName);


  if( (in = fopen (inName, "r")) == NULL) {
    printf("can't open %s for reading. \n", inName);
    return 1;
  }

  getTwentyLines(in);

  fclose(in);
  return 0;

}
