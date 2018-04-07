#include <iostream>
#include <assert.h>

template<class T>
class Queue : public LinearContainer<T> {
  public:
    void push(T c);
    containerElem<T>* pop();
  private:
    void copy();
};

template<class T>
void Queue<T>::push(T c) {
  if( this->is_full() ) {
    this->maxSize = this->maxSize *2;
    copy();
  }
  containerElem<T>* temp = new containerElem<T>(c);
  containerElem<T>* last = this->start;
  if (this->start == 0 ) {
    this->start = temp;
  } else {
    while ( last -> next != 0) {
      last = last -> next;
    }
    last -> next = temp;
  }
  this->currentCount++;
}


template <class T>
containerElem<T>* Queue<T>::pop() {
  assert( !this->is_empty());
  containerElem<T>* last = this->start;
  this->start = last->next;
  this->currentCount--;
  return last;
}

template<class T>
void Queue<T>::copy() {
  containerElem<T>* current = this ->start;
  containerElem<T>* newContainer = 0;
  containerElem<T>* prev = 0;
  while (current != 0) {
    containerElem<T>* temp = new containerElem<T>(current -> data);
    if(prev != 0) {
      prev -> next = temp;
    } else {
      newContainer = temp;
    }
    prev = temp;
    containerElem<T>* tempForDel = current;
    current = current -> next;
    delete tempForDel;
  }
  this -> start = newContainer;
}
