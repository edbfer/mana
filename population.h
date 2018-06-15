#ifndef _POPULATION_H
#define _POPULATION_H 1

#include "path.h"
#include "util.h"

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
      Path p()
      for(int j = 1; j<pathsize-1; j++)
    }
  }
}

#endif //_POPULATION_H
