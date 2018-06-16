#ifndef _POPULATION_H
#define _POPULATION_H 1

#include "path.h"
#include "util.h"

#include <cstdlib>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Population {
private:

  int dim;
  Path** pop;

public:
  Population(int dim = 50): dim(dim)
  {
    pop = new Path*[dim];
  }

  ~Population()
  {
    for(int i = 0; i<dim; i++)
    {
      delete pop[i];
    }
    delete[] pop;
  }

  Path*& operator[](const int index)
  {
    return pop[i];
  }

  void generate(Point ini, Point f, int pathsize)
  {
    for(int i = 0; i<dim; i++)
    {
      double length = sqrt(pow(ini.x-f.x, 2.0) + pow(ini.y-f.y, 2.0));
      Path *p = new Path(ini, f, pathsize);
      for(int j = 1; j<pathsize-1; j++)
      {
        double x = (((double)rand())/((double)RAND_MAX))*length;
        double y = (((double)rand())/((double)RAND_MAX))*length;
        Point t(x, y);
        (*p)[j] = t;
      }
      pop[i] = p;
    }
  }

  void printall()
  {
    ostringstream fnstream;
    for(int i = 0; i<dim; i++)
    {
      fnstream << "teste_" << i << ".dat";
      ofstream out(fnstream.str().c_str());
      pop[i]->print(out);
      fnstream.str("");
      out.close();
    }
  }
};

#endif //_POPULATION_H
