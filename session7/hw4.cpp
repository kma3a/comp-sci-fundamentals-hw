/*
 * As written, slist::del() expect a nonempty list. what goes wrong if it is passed
 * an empty list?
 * you get a  segmentation fault
 *
 * see the effect on your system. Modify this routine to test for this condition and continue.
 * Note that this can be tested as an assertion but will then abort on the empty list.
 */
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

struct slistelem {
  char data;
  slistelem* next;
};

class slist {
  public:
    slist() : h(0) {}
    slist(const char* c);
    ~slist() { release();}
    void prepend(char c);
    void del();
    slistelem* first() const { return h;}
    void print() const;
    void release();
    int length();
    int count_c(char c);
    void append(slist& e);
    void copy(const slist &e);
  private:
    slistelem* h;
};

slist::slist(const char* c) {
  h = 0;
  for(int i = 0; c[i] != 0; i++){
    prepend(c[i]);
  }
}

int slist::length() {
  slistelem* temp = h;
  int length = 1;
  while (temp != 0) {
    length++;
    temp = temp -> next;
  }
  return length;
}


int slist::count_c(char c) {
  slistelem* temp = h;
  int length = 0;
  while (temp != 0) {
    if(temp-> data == c) {
      length++;
    }
    temp = temp -> next;
  }
  return length;

}


void slist::prepend(char c) {
  slistelem* temp = new slistelem;
  assert(temp != 0);
  temp -> next = h;
  temp -> data = c;
  h = temp;
}

void slist::append(slist& e) {
  slistelem* last = h;
  while (last -> next != 0) {
    last = last -> next;
  }

  cout << "last data " << last -> data << endl;
  cout << "e first " << e.first() << endl;
  last -> next = e.h;
  e.h = 0;
}

void slist::copy(const slist &e) {
  release();
  slistelem* current = e.h;
  slistelem* prev = 0;
  while (current != 0) {
    slistelem* temp = new slistelem;
    temp -> data = current -> data;
    temp -> next = 0;
    if(prev != 0) {
      prev -> next = temp;
    } else {
      h = temp;
    }
    prev = temp;
    current = current -> next;
  }
}

void slist::del() {
  assert(h != 0);
  slistelem* temp = h;
  h = h -> next;
  delete temp;
}

void slist::print() const {
  slistelem* temp = h;
  while (temp != 0) {
    cout << temp -> data << " -> ";
    temp = temp -> next; 
  }
  cout << "\n" << endl;
}

void slist::release() {
  while( h != 0) {
    del();
  }
}

int main (void) {
  slist test("HELLO");
  test.print();
  test.del();

  test.print();
  test.release();
  cout << "after release" << endl;
  test.del();

  return 0;
}
