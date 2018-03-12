/*
 * write a memeberfunction append() that will add a list to the end of the implicit list argument;
 * then clear the appebded slist by zeroing the head;
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
    void print() const;
    void release();
    int length() const;
    int count_c(char c) const;
    void append(slist &e);
  private:
    slistelem* h;
};

//appends a new list to the current one
void slist::append(slist &e) {
  slistelem* temp = h;
  while (temp->next !=0) {
    temp = temp -> next;
  }
  temp -> next = e.h;
  e.h = 0;
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
  slist world("olleH");
  slist dlrow("Hello");

  cout << "append" << endl;
  world.append(dlrow);
  //cout << world.length() << endl;
  cout << dlrow.length() << endl;


  return 0;
}
