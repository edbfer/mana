#include "population.h"
#include <omp.h>
#include <cmath>
#include <cstdlib>

using namespace std;

Population::Population(int dim = 50): dim(dim)
{
  pop = new Path*[dim];
}

Population::~Population()
{
  for(int i = 0; i<dim; i++)
  {
    delete pop[i];
  }
  delete[] pop;
}

int Population::getDimension()
{
  return dim;
}

void Population::generate(Point ini, Point f, int pathsize)
{
  //for(int i = 0; i<dim; i++)
  /*int i = 0;
  while(1)
  {
    double length = sqrt(pow(ini.x-f.x, 2.0) + pow(ini.y-f.y, 2.0));
    Path *p = new Path(ini, f, pathsize);
    Point x0 = ini;
    #pragma omp parallel for
    for(int j = 1; j<pathsize-1; j++)
    {
      double x = (2.0*(((double)rand())/((double)RAND_MAX))-1.0)*length*0.01;
      double y = (2.0*(((double)rand())/((double)RAND_MAX))-1.0)*length*0.01;
      Point t(x0.x+x, x0.y+y);
      (*p)[j] = t;
      x0 = t;
    }
    double l = sqrt(pow(x0.x-f.x, 2.0) + pow(x0.y-f.y, 2.0));
    cout << l << endl;
    if (l > length*0.1)
    {
      continue;
      delete[] p;
    }
    else
    {
      pop[i] = p;
      i++;
      if(i == 50)
        break;
    }
  }*/
  double deltat = f.x - ini.x;
  double deltax = f.y - ini.y;
  double dt = deltat/pathsize;
  int i = 0;
  while(1)
  {
    Path* p = new Path(ini, f, pathsize);
    Point x0 = ini;
    for(int t = 0; t<pathsize-1; t++)
    {
      double y = (2.0*(((double)rand())/((double)RAND_MAX))-1.0)*deltax*0.1;
      Point tmp(ini.x+t*dt, x0.y+y);
      (*p)[t] = tmp;
      x0 = tmp;
    }
    if(fabs(x0.y-f.y) > deltax*0.1)
    {
      delete p;
      continue;
    }
    else
    {
      pop[i] = p;
      i++;
      if(i == dim)
        return;
    }
  }
}

Path*& Population::operator[](const int index)
{
  return pop[index];
}

void Population::printall()
{
  ostringstream fnstream;
  ostringstream dirs;
  dirs << "mkdir ./iteration_" << id;
  system(dirs.str().c_str());
  for(int i = 0; i<dim; i++)
  {
    fnstream << "iteration_" << id << "/teste_" << i << ".dat";
    ofstream out(fnstream.str().c_str());
    pop[i]->print(out);
    fnstream.str("");
    out.close();
  }
}

void Population::setId(int id)
{
  this->id = id;
}
