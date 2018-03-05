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
  - push_t()
      push on top 
  - pop_t()
      pop on top 
  - push_b()
      push on bottom
  - pop_b()
      pop on button
  - print_stack()
      output the stach from bottom to top
  - top_of()
  - bottom_of()
  - empty()
      denoted by having the top fall below the bottom.
  - full()


 */

#include <iostream>
#include <string>

class deque {
  public:
    void reset() { top=bottom = max_length/2; top--;}
  private:
    char s[max_len];
    int bottom, top;
};

int main()
{
  return 0;
}
