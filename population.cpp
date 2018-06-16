#include "population.h"

Population::Population(int dim = 50): dim(dim)
{}

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

Path*& Population::operator[](const int index)
{
  return pop[index];
}

void Population::printall()
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
