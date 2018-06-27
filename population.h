#ifndef _POPULATION_H
#define _POPULATION_H 1

#include "path.h"
#include "util.h"

#include <cstdlib>
#include <string>
#include <sstream>
#include <cmath>

//Boos

using namespace std;

class Population {
private:

  int dim;
  Path** pop;
  int id;

public:
  Population(int dim);
  ~Population();

  Path*& operator[](const int index);
  int getDimension();

  void generate(Point ini, Point f, int pathsize);
  void printall();
  void printAction();

  void setId(int id);

};

#endif //_POPULATION_H
