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
    LinearContainer() : maxSize(10), currentCount(0), start(0) {}
    LinearContainer(int num);
    void print();
    void push(char c);
    bool is_empty();
    bool is_full();
    containerElem* pop();
  private:
    int maxSize;
    int currentCount;
    containerElem* start;
};

LinearContainer::LinearContainer(int num) {
  maxSize = num;
  start = 0;
  currentCount = 0;
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
  assert( !is_full() );
  containerElem* temp = new containerElem(c);
  containerElem* last = start;
  if (start == 0 ) {
    start = temp;
  } else {
    while ( last -> next != 0) {
      last = last -> next;
    }
    last -> next = temp;
  }
  currentCount++;
}

containerElem* LinearContainer::pop() {
  assert( !is_empty());
  containerElem* last = start;
  containerElem* secondLast = 0;
  while ( last -> next != 0) {
    secondLast = last;
    last = last -> next;
  }
  if(secondLast == 0) {
    start = 0;
    currentCount = 0;
    return last;
  }
  secondLast -> next = 0;
  currentCount--;
  return last;
}

bool LinearContainer::is_empty() {
  return currentCount == 0;
}

bool LinearContainer::is_full() {
  return currentCount == maxSize;
}

int main (void) {
  LinearContainer list;

  list.push('h');
  list.push('e');
  list.push('l');
  list.push('l');
  list.push('o');
  list.push(' ');
  list.push('y');
  list.push('o');
  list.push('u');
  cout << "full 1 " << list.is_full()  << endl;
  list.push('!');
  cout << "full 2 " << list.is_full()  << endl;
  list.print();
  containerElem* popElem = list.pop();
  cout << popElem -> data << endl;
  list.print();
  bool empty = list.is_empty();
  cout << "empty 1 " << empty  << endl;
  list.pop();
  empty = list.is_empty();
  cout << "empty 2 " << empty  << endl;

}

