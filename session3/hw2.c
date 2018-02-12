#include <stdio.h>

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

int main(void){
  char text[] = "the wrong son";

  removeString(text, 4, 6);
  printf("%s", text);
  
  return 0;
}
