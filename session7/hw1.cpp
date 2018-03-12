/*
 * Use the slist type discussed in section 5.7, "Example: A singly Linked List," on page. 168, to code the following member functions:
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
    slist(const char* c);
    ~slist() { release();}
    void prepend(char c);
    void del();
    slistelem* first() const { return h;}
    void print();
    void release();
    int length() const;
    int count_c(char c) const;
  private:
    slistelem* h;
};

//slist constructor whose initializer is a char* string
slist::slist(const char* c) {
  h = 0;
  for (int i =0; c[i] != '\0'; i++) {
    prepend(c[i]);
  }
};


void slist::prepend(char c) {
  slistelem* temp = new slistelem;
  //assert( temp !=0);
  temp -> next = h;
  temp -> data = c;
  h = temp;
}

//length returns the length of the slist
int slist::length() const {
  int count = 0;
  slistelem* temp = h;
  while (temp != 0) {
    temp = temp -> next;
    count++;
  }

  return count;
};

//return number of elements whose data value is c
int slist::count_c(char c) const {
  int count = 0;
  slistelem* temp = h;
  while (temp != 0) {
    if(temp->data == c) {
      count++;
    }
    temp = temp -> next;
  }

  return count;
};

void slist::print() {
  slistelem* temp = h;
  while( temp != 0) {
    cout << temp->next << endl;
    temp = temp->next;
  }
}

void slist::release() {
  while (h!=0) {
    del();
  }
};

void slist::del() {
  slistelem* temp = h;
  h = h -> next;
  delete temp;
};

int main (void) {
  slist world("Hello");
  int lng = 5;

  cout << "length" << endl;
  cout << lng << endl;
  cout << "number" << endl;
  cout << world.count_c('l') << endl;

  return 0;
}

