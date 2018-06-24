#ifndef iteration_h
#define iteration_h

#include "path.h"
#include "population.h"
#include "util.h"

#include <cmath>

class Iteration{

private:

  double max_fitness, average_fitness;
  int dim;

public:
  Iteration(int dim): dim(dim){}
  void bubble_sort(Population* pop);
  double deviation(Population* pop);
  double gaussian(Path* path, double s);
  Population* iterate(Population* pop, int N_combined, double dh, double dt);//N_combined= numero de caminhos com menor ação que vão ser combinados

};

#endif
