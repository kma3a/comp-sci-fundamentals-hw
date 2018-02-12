#include <stdio.h>

int checkAcending(int val1, int val2, int isAcending){
  if(isAcending){
    return val1 > val2;
  }
  return val1 < val2;
}

void sort(int a[], int n, int isAcending) {
  int i,j, temp;

  for(i=0; i<n-1; ++i) {
    for (j=i+1; j<n; ++j){
      if(checkAcending(a[i], a[j], isAcending)){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
  }
}

int main (void) {
  int i;
  int array[16] = {34, -5, 6, 0, 12, 100,
                    56, 22, 44, -3, -9,
                    12, 17, 22, 6, 11};

  printf(" The array before the sort:\n");

  for(i=0; i<16; ++i){
    printf("%i ", array[i]);
  }

  printf("\n");

  sort(array, 16, 1);

  printf(" The array Acending:\n");

  for(i=0; i<16; ++i){
    printf("%i ", array[i]);
  }

  printf("\n");

  sort(array, 16, 0);

  printf(" The array Decending:\n");

  for(i=0; i<16; ++i){
    printf("%i ", array[i]);
  }


  printf("\n");


  

}
