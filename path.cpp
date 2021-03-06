#include "path.h"
#include "iteration.h"

int Path::nextID;

Path::Path(int N = 200): N(N)
{
  id = nextID++;
  path = new Point[N];
}

Path::Path(Point i, Point f, int N = 200): N(N)
{
  id = nextID++;
  path = new Point[N];
  path[0] = i;
  path[N-1] = f;
}

Path::Path (const Path& p)
{
  id = nextID++;
  N = p.N;
  fitness = p.fitness;
  path = p.path;
}

Path::~Path()
{
  delete[] path;
}

double Path::getFitness(double dt, double (*fitfunction)(double, double, double))
{
  //this->fitness = integrate(dt, fitfunction, this);
  Path* path = this;
  double integral = 0., t = (*path)[0].x, x, xdot, x1, x2;
  int N = path->N;

  x = (*path)[0].y;
  x1 = (*path)[1].y;
  xdot = (x1 - x)/dt;
  integral += fitfunction(x, xdot, t)*dt;

  for(int i=1; i<N-1; i++)
  {
    t += dt;
    x1 = (*path)[i-1].y;
    x = (*path)[i].y;
    x2 = (*path)[i+1].y;
    xdot = (x2-x1)/(2.*dt);
    integral = integral + fitfunction(x,xdot,t)*dt;
  }

  t += dt;
  x = (*path)[N-1].y;
  x1 = (*path)[N-2].y;
  xdot = (x - x1)/dt;
  integral += fitfunction(x, xdot, t)*dt;

  this->fitness = integral;

  return integral;
}

void Path::print(ostream &out)
{
  for(int i = 0; i<N; i++)
  {
    out << path[i].x << "\t" << path[i].y << endl;
  }
}

Point& Path::operator[](const int index)
{
  return path[index];
}

void Path::setStartingID(int id)
{
  nextID = id;
}
