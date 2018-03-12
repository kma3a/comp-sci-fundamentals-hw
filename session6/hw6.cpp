/* 
 *  Extend the data type deque by adding a member function relocate(), 
 *
 *  If deque is full relocate() is called, and the contents of the deque are moved to balance empty storage around the center max_len/2 of array s. its function declaration deader is
 */


#include <iostream>
#include <string>
using namespace std;

class deque {
  public:
    void reset() { top = bottom = max_length/2; top--;}
    bool full() { return top == max_length-1 && bottom == 0;}
    void push_t(char a) {if(!full()){top++; s[top] = a;}}
    void push_b(char b) { if(!full()){bottom--; s[bottom] = b;}}
    char pop_t() { return s[top--];}
    char pop_b() { return s[bottom++];}
    char bottom_of() { return s[bottom];}
    char top_of() { return s[top];}
    void print_stack() { if(!empty()) { int i = bottom; do{ cout << s[i] << endl; i++;}while(i<=top);}}
    bool empty() {return top < bottom;}
  private:
    enum { max_length = 100;}
    char s[max_length];
    int bottom, top;
};

//returns true if it succeeds, false if it fails
bool deque::relocate() { }

int main()
{
  return 0;
}
