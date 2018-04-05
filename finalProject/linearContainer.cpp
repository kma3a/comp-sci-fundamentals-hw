#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

struct containerElem {
  containerElem(char d, containerElem* n = 0) {
    data = d;
    next = n;
  }
  char data;
  containerElem* next;
};

class LinearContainer {
  public:
    LinearContainer() : currentCount(0), maxSize(100), start(0) {}
    LinearContainer(int num, char c);
    void print();
    void push(char c);
    bool is_empty();
    containerElem* pop();
  private:
    int maxSize;
    int currentCount;
    containerElem* start;
};

LinearContainer::LinearContainer(int num, char c) {
  containerElem* temp = new containerElem(c);
  maxSize = num;
  start = temp;
  currentCount = 1;
}

void LinearContainer::print() {
  containerElem* temp = start;
  while ( temp != 0) {
    cout << temp -> data << " -> ";
    temp = temp -> next;
  }
  cout << "\n" << endl;
}

void LinearContainer::push(char c) {
  assert( currentCount != maxSize );
  containerElem* temp = new containerElem(c);
  containerElem* last = start;
  while ( last -> next != 0) {
    last = last -> next;
  }
  last -> next = temp;
  currentCount++;
}

containerElem* LinearContainer::pop() {
  containerElem* last = start;
  containerElem* secondLast = 0;
  while ( last -> next != 0) {
    secondLast = last;
    last = last -> next;
  }

  secondLast -> next = 0;
  currentCount--;
  return last;
}

int main (void) {
  LinearContainer list(3, 'h');

  list.push('e');
  list.print();
  containerElem* popElem = list.pop();
  cout << popElem -> data << endl;
  list.print();

}

