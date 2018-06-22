#ifndef _UTIL_H
#define _UTIL_H 1

struct Point
{
  double x;
  double y;

  Point(): x(0), y(0)
  {}

  Point(double x, double y): x(x), y(y)
  {}

  Point(const Point& p): x(p.x), y(p.y)
  {}

  friend Point operator* (double c, const Point& p)
  {
    Point newP(c*p.x, c*p.y);
    return newP;
  }

  friend Point operator+ (const Point& p1, const Point& p2)
  {
    Point newP(p1.x+p2.x, p1.y+p2.y);
    return newP;
  }

  Point operator= (const Point& p1)
  {
    this->x = p1.x;
    this->y = p1.y;
  }
};

#endif //_UTIL_H
