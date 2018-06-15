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

  
};

#endif //_UTIL_H
