#ifndef _PATH_H
#define _PATH_H 1

#include <iostream>
#include <fstream>

using namespace std;

#include "util.h"

class Path
{
private:
  Point* path;
public:
  double fitness;
  int N;
  //amanha faço funçoes para isto
  Path(int N);

  Path(Point i, Point f, int N);

  Path (const Path& p);

  ~Path();

  double getFitness(double dt, double (*fitfunction) (double, double, double));

  void print(ostream& out);

  Point& operator[](const int index);
};

#endif //_PATH_H
