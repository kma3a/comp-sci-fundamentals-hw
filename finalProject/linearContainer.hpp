#include <iostream>
#include <assert.h>

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
    ~LinearContainer() { release();}
    void print();
    void push(char c);
    bool is_empty();
    bool is_full();
    void release();
    void del();
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
  assert(!is_empty());
  containerElem* temp = start;
  while ( temp != 0) {
    std::cout << temp -> data << " -> ";
    temp = temp -> next;
  }
  std::cout << "n" << std::endl;
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
  } else {
    secondLast -> next = 0;
  }
  currentCount--;
  return last;
}

bool LinearContainer::is_empty() {
  return currentCount == 0;
}

bool LinearContainer::is_full() {
  return currentCount == maxSize;
}

void LinearContainer::release(){
  while (start != 0 ) {
    del();
  }
}

void LinearContainer::del(){
  assert(start!=0);
  containerElem* temp = start;
  start = start -> next;
  delete temp;
}


