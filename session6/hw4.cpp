/* 
 * The following decartaions do not compile correctly Explain what is wrong
 *
 *struct borther {
  char name[20];
  int age;
  struct sister sib;
} a;

struct sister {
  char name[20];
  int age;
  struct brother sib;
} a;


Answer:
The a is not needed so thtat is the first to go, The second is that before a struct can be used it needs to be decalinred so you can't have something with con dependencies be declainred at the same time.  You also don't need the struct in the declaration.
 */

#include <iostream>
#include <string>

struct brother {
  char name[20];
  int age;
  sister sib;
};

struct sister {
  char name[20];
  int age;
  brother sib;
};


int main()
{
  return 0;
}
