#include "util.h"
#include "path.h"

double Lagrangian(double x, double xdot, double t)
{//oscilador harmonico
  return (1./2.)*xdot*xdot - (1./2.)*x*x;
}

double integrate(double dt, double (*Lagrangian) (double,double,double), Path* path)
{
  double integral, t, x, xdot, x1;
  int N = path->N;

  for(int i=1; i<N-1; i++)
  {
    t = (*path)[0].x + i*dt;
    x = (*Path)[i].y;
    x1 = (*Path)[i].y;
    xdot = (x1-x)/dt;
    integral = integral + Lagrangian(x,xdot,t)*dt;
  }

  return integral;
}
