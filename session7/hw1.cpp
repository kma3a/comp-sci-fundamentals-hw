/*
 * Use the slist type discussed in section 5.7, "Example: A singly Linked List," on page. 168, to code the following member functions:
 *
 * slist constructor whose initialiser is a char* string
 * slist::slist(const char* c);
 *
 * length returns the length of the slist
 * int slist::length();
 *
 * return number of elements whose data value is c
 * int slist::count_c(char c);
 */
#include <iostream>
#include <string>
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
    slistelem * first() const { return h;}
    void print() const;
    void release();
    int length();
    int count_c(char c);
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
  //assert(temp != 0);
  temp -> next = h;
  temp -> data = c;
  h = temp;
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
  cout << "\n##" << endl;
}

void slist::release() {
  while( h != 0) {
    del();
  }
}

int main (void) {
  slist world("hello");

  world.print();
  cout << "lenght " << world.length() << endl;
  cout << "number of l: " << world.count_c('l') << endl;

  return 0;
}
