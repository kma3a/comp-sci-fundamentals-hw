#include <iostream>
#include <assert.h>

template<class T>
struct containerElem {
  containerElem(T d, containerElem<T>* n = 0) {
    data = d;
    next = n;
  }
  T data;
  containerElem<T>* next;
};

template<class T>
class LinearContainer {
  public:
    LinearContainer() : maxSize(10), currentCount(0), start(0) {}
    LinearContainer(int num);
    ~LinearContainer() { release();}
    void print();
    void push(T c);
    bool is_empty();
    bool is_full();
    void release();
    void del();
    containerElem<T>* pop();
  private:
    int maxSize;
    int currentCount;
    containerElem<T>* start;
};


template <class T>
LinearContainer<T>::LinearContainer(int num) {
  maxSize = num;
  start = 0;
  currentCount = 0;
}

template <class T>
void LinearContainer<T>::print() {
  assert(!is_empty());
  containerElem<T>* temp = start;
  while ( temp != 0) {
    std::cout << temp -> data << " -> ";
    temp = temp -> next;
  }
  std::cout << "n" << std::endl;
}

template <class T>
void LinearContainer<T>::push(T c) {
  assert( !is_full() );
  containerElem<T>* temp = new containerElem<T>(c);
  containerElem<T>* last = start;
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

template <class T>
containerElem<T>* LinearContainer<T>::pop() {
  assert( !is_empty());
  containerElem<T>* last = start;
  containerElem<T>* secondLast = 0;
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

template <class T>
bool LinearContainer<T>::is_empty() {
  return currentCount == 0;
}

template <class T>
bool LinearContainer<T>::is_full() {
  return currentCount == maxSize;
}

template <class T>
void LinearContainer<T>::release(){
  while (start != 0 ) {
    del();
  }
}

template <class T>
void LinearContainer<T>::del(){
  assert(start!=0);
  containerElem<T>* temp = start;
  start = start -> next;
  delete temp;
}


