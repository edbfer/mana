#ifndef _POPULATION_H
#define _POPULATION_H 1

#include "path.h"
#include "util.h"

#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class Population {
private:

  int dim;
  Path* pop;

public:
  Population(int dim = 50): dim(dim)
  {
    pop = new Path[dim];
  }

  ~Population()
  {
    delete[] pop;
  }

  generate(Point i, Point f, int pathsize)
  {
    for(int i = 0; i<dim; i++)
    {
      double length = sqrt(pow(i.x-f.x, 2) + pow(i.y-f.y, 2));
      Path p(i, f, pathsize);
      for(int j = 1; j<pathsize-1; j++)
      {
        double x = (rand()/RAND_MAX)*length;
        double y = (rand()/RAND_MAX)*length;
        Point t(x, y);
        p.path[j] = t;
      }
    }
  }

  printall()
  {
    for(int i = 0; i<dim; i++)
  }
};

#endif //_POPULATION_H
