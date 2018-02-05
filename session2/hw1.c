#include <stdio.h>

int main (void) {
  float total;
  float average;
  float array[10] = { 1.0, 2.0, 3.0, 4.0, 3.0, 1.0, 3.0, 4.0, 5.0, 3.0};

  for(int i=0; i <= 10; i++) {
    total += array[i];
  }

  average = total / 10;

  printf("The adverage is: %f\n", average);

  return 0;

}
