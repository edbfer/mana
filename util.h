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

  friend Point operator* (double c, const Point& p);
  friend Point operator+ (const Point& p1, const Point& p2);
  Point operator= (const Point& p1);
};



#endif //_UTIL_H
