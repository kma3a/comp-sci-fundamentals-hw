#include <stdio.h>

//will take a number and translate it into words
//ex. 1234 >> one two three four
int main (void) {
  int input, right_number, reversed;
  printf("What number would you like me to translate into words?\n");
  scanf("%i", &input);
  reversed = 0;

  do {
    right_number = input % 10;
    reversed = reversed * 10 + right_number;
    input /= 10;
  }
  while (input != 0);
  
  do {
    right_number = reversed % 10;
    reversed /= 10;
    switch (right_number)
    {
      case 0:
        printf("zero ");
        break;
      case 1:
        printf("one ");
        break;
      case 2:
        printf("two ");
        break;
      case 3:
        printf("three ");
        break;
      case 4:
        printf("four ");
        break;
      case 5:
        printf("five ");
        break;
      case 6:
        printf("six ");
        break;
      case 7:
        printf("seven ");
        break;
      case 8:
        printf("eight ");
        break;
      case 9:
        printf("nine ");
        break;
      default:
        printf("must be a number.\n");
        break;
    }
  }
  while (reversed != 0);

  printf("\n");

  return 0;
}
