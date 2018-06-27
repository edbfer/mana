#include "util.h"
#include "path.h"

using namespace std;

Point operator*(double c, const Point& p)
{
  Point newP(c*p.x, c*p.y);
  return newP;
}

Point operator+ (const Point& p1, const Point& p2)
{
  Point newP(p1.x+p2.x, p1.y+p2.y);
  return newP;
}

Point Point::operator=(const Point &p1)
{
  this->x = p1.x;
  this->y = p1.y;
}

/*ostream& operator<< (ostream& o, const Point& p)
{
  o << "x: " << p.x << " y: " << p.y;
  return o;
}*/
