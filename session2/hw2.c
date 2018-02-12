#include <stdio.h>

int gcd(int u , int v) {
    int temp;

    while (v != 0){
      temp = u % v;
      u = v;
      v = temp;
    }

    return u;
}

int lcm ( int int1, int int2){

  return int1 * int2 / gcd( int1, int2);

}


int main (void) {

  printf(" the lcd if 15 and 10 is %d \n", lcm(15, 10));
}
