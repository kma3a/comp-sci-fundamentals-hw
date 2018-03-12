/* 
 * Recode as a class the data type deque, which is a double-ended queue that allowes pushing and popping at both ends.
 *class deque {
  public:
    void reset() { top=bottom = max_length/2; top--;}
  private:
    char s[max_len];
    int bottom, top;
};

  Declair and implement 
  + push_t()
      push on top 
  + pop_t()
      pop on top 
  + push_b()
      push on bottom
  + pop_b()
      pop on button
  + print_stack()
      output the stach from bottom to top
  - top_of()
  - bottom_of()
  + empty()
      denoted by having the top fall below the bottom.
  + full()


 */

#include <iostream>
#include <string>
using namespace std;

class deque {
  public:
    void reset() { top = bottom = 20/2; top--;}
    int full() { return top == 20-1 && bottom == 0;}
    void push_t(char a) {if(!full()){top++; s[top] = a;}}
    void push_b(char b) { if(!full()){bottom--; s[bottom] = b;}}
    char pop_t() { return s[top--];}
    char pop_b() { return s[bottom++];}
    void print_stack() { if(!empty()) { int i = bottom; do{ cout << s[i] << endl; i++;}while(i<=top);}}
    int empty() {return top < bottom;}
  private:
    char s[20];
    int bottom, top;
};

int main()
{
  deque a;

  a.reset();

  cout << "Empty? " << endl;
  cout << a.empty() << endl;

  cout << "full? " << endl;
  cout << a.full() << endl;

  a.push_t('a');

  a.print_stack();

  cout << "next " << endl;

  a.push_b('b');
  a.print_stack();

  cout << " pop top "<< endl;

  cout << a.pop_t() << endl;

  cout << " pop bottom "<< endl;
  cout << a.pop_b() << endl;

  cout << "Empty? " << endl;
  cout << a.empty() << endl;

  return 0;
}
