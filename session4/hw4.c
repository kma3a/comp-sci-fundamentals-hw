#include <stdio.h>
#define IS_LOWER_CASE(x) ((x) >= 'a' && (x) <= 'z')
#define TO_UPPER(x) (IS_LOWER_CASE (x) ? (x) - 'a' + 'A' : (x))

int main(void){
  char inName[64], outName[64];
  FILE *in, *out;
  int c;


  printf("Enter name of file to be copied: ");
  scanf("%63s", inName);
  printf("Enter name of output file: ");
  scanf("%63s", outName);

  if( (in = fopen (inName, "r")) == NULL) {
    printf("can't open %s for reading. \n", inName);
    return 1;
  }
  if( (out = fopen (outName, "w")) == NULL) {
    printf("can't open %s for writing. \n", outName);
    return 1;
  }

  while ( (c = getc (in)) != EOF) {
    c = TO_UPPER(c);
    putc(c,out);
  }

  fclose(in);
  fclose(out);
  printf("File has been copied");
  return 0;

}
