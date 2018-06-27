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
  return t*t;//sqrt(1 + xdot*xdot);
}

//ha aqui uma merda muito grande a acontecer
//isto gera quase sempre os mesmos valores
//e de acordo com o printf da so uma iteração
//devemos estar a foder bem a memória nalgum lado
//isto vai envolver umas boas sessões com o valgrind

int main(){

  //FILE* gp = popen("gnuplot -persist", "w");

  Path::setStartingID(0);

  int nmax = 20;
  int dim = 10;
  double dh = 0.05;
  double pathsize = 5000;

  unsigned int seed = time(nullptr);

  cout << "Seed = " << seed << endl;
  srand(seed);

  Population pini(dim);
  Point ini(0.0, 0.0);
  Point f(10.0, 10.0);

  double dt = (f.x - ini.x)/pathsize;
  cout << "dt: " << dt << endl;

  pini.generate(ini, f, pathsize);
  for(int j = 0; j<dim; j++)
  {
    pini[j]->getFitness(dt, &Lagrangian);
  }
  pini.printAction();
  pini.setId(0);
  pini.printall();

  Population *p0 = &pini;

  Iteration it(dim);

  //fprintf(gp, "set multiplot layout 5, 10 rowsfirst\n");
  //fprintf(gp, "plot 'iteration_0/teste_%d.dat' using 1:2 with lines\n)

  for(int i = 0; i<nmax; i++)
  {
    for(int j = 0; j<dim; j++)
    {
      (*p0)[j]->getFitness(dt, &Lagrangian);
    }
    Population *nextp = it.iterate(p0, 3, 0.5, dt);
    nextp->setId(i+1);
    nextp->printall();
    int nlines = dim % 5;
    cout << "Iteration: " << i << endl;
    /*for (int k = 0; k<dim; k++)
    {
      if(k % 5 == 0)
        cout << endl;
      cout << "Pos:" << k << " ID:" << (*nextp)[k]->id << " FN:" << (*nextp)[k]->fitness << "\t";

    }*/
    cout << endl << endl;
    p0 = nextp;
  }

  //pclose(gp);

  return 0;

}
