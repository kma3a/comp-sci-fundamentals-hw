/* 
 * write a structure poin that has three coordinates x,y, and z.
 *
 * How can you access the individual coordinates?
 */

#include <iostream>
#include <string>
using namespace std;

struct coord
{
  int x;
  int y;
  int z;
};

int main()
{
  coord point;

  point.x = 12;
  point.y = 32;
  point.z = 211;

  cout << "x: " << point.x << " y: " << point.y << " z: " << point.z << endl;
  return 0;
}
