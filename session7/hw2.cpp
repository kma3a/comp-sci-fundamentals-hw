/*
 * write a memeberfunction append() that will add a list to the end of the implicit list argument;
 * then clear the appended slist by zeroing the head;
 * void slist::append(slist& e);
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

void slist::del() {
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
  slist world("olleH");
  slist dlrow("Hello");

  cout << "append" << endl;
  world.append(dlrow);
  world.print();
  dlrow.print();


  return 0;
}
