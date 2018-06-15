#ifndef _PATH_H
#define _PATH_H 1

#include <iostream>
#include <fstream>

#include "util.h"

class Path{
private:

  Point* path;
  int N;
  double fitness;

public:
  Path(int N = 200): N(N)
  {
    path = new Point[N];
  }

  Path(Point i, Point f, int N = 200): N(N)
  {
    path = new Point[N];
    path[0] = i;
    path[N-1] = f;
  }

  ~Path()
  {
    delete[] path;
  }

  double getFitness(double (fitfunction*) (Path&))
  {
    this->fitness = fitfunction(*this);
    return fitness;
  }

  void print(ostream& out)
  {
    for(int i = 0; i<N; i++)
    {
      out << path[i].x << "\t" << path[i].y << "\n";
    }
  }

}

#endif //_PATH_H
