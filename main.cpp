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

int main(){

  int nmax;
  double dh = 0.05;

  srand(time(nullptr));
  Population pini(50);
  Point ini(0.0, 0.0);
  Point f(10.0, 10.0);

  pini.generate(ini, f, 1500);
  pini.printall();

  Population *p0 = &pini;

  Iteration i = new Iteration();

  for(int i = 0; i<nmax; i++)
  {
    Population *nextp = i.iterate(p0, 3, 0.05);
    nextp->setId(i);
    nextp->printall();
    p0 = nextp;
  }

  return 0;

}
