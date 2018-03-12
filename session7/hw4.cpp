/*
 * write a memeberfunction copy() that will copy a list
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
    slist(const char* c = "");
    void prepend(char c);
    void del();
    slistelem* first() const { return h;}
    void print() const;
    void release();
    int length();
    int count_c(char c);
    void append(slist &e);
    void copy(const slist &e);
  private:
    slistelem* h;
};

void slist::copy(const slist &e) {
  h = e.h;
};

void slist::print() const {
  slistelem* temp = h;
  while (temp !=0) {
    cout << temp -> data << endl;
    temp = temp -> next;
  }
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
  for (int i =0; c[i] != 0; c++) {
    slistelem* temp = new slistelem;
    temp -> data = c[i];
    temp -> next = 0;
    if (h == 0){
      h = temp;
    } else {
      temp -> next = h;
      h = temp;
    }
  }
};

//length returns the length of the slist
int slist::length() {
  int count = 0;
  slistelem* temp = h;
  while (temp != 0) {
    temp = temp -> next;
    count++;
  }

  return count;
};

//return number of elements whose data value is c
int slist::count_c(char c) {
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
  slist world;
  slist dlrow("Hello");

  cout << "copy" << endl;
  world.copy(dlrow);
  cout << "printing the copy" << endl;
  world.print();


  return 0;
}
