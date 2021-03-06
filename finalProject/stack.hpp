#include <iostream>
#include <assert.h>
#include "debug.hpp"
#include "linearContainer.hpp"
#ifndef STACK_HPP
#define STACK_HPP

template<class T>
class Stack : public LinearContainer<T> {
  public:
    void push(T c);
  private:
    void copy();
};

template<class T>
void Stack<T>::push(T c) {
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
  log("count");
  log(this->currentCount);
}

template<class T>
void Stack<T>::copy() {
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

#endif //STACK_HPP
