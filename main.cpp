#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
//C Headers para criar um pipe para o gnuplot
#include <stdio.h>
#include <unistd.h>

#include "path.h"
#include "population.h"
#include "util.h"
#include "iteration.h"
using namespace std;

double Lagrangian(double x, double xdot, double t)
{//oscilador harmonico
  return sqrt(1 + xdot*xdot);
}

int main(){

  int nmax = 100;
  int dim = 50;
  double dh = 0.05;

  srand(time(nullptr));
  Population pini(50);
  Point ini(0.0, 0.0);
  Point f(10.0, 10.0);

  double dt = (f.x - ini.x)/1500.0;

  pini.generate(ini, f, 1500);
  pini.setId(0);
  pini.printall();


  Population *p0 = &pini;

  Iteration it(50);

  for(int i = 0; i<nmax; i++)
  {
    for(int j = 0; j<dim; j++)
    {
      (*p0)[j]->getFitness(dt, &Lagrangian);
    }
    Population *nextp = it.iterate(p0, 3, 0.05, dt);
    nextp->setId(i+1);
    nextp->printall();
    p0 = nextp;
  }

  return 0;

}
