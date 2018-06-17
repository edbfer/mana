#ifndef iteration_h
#define iteration_h

#include "path.h"
#include "population.h"

#include <cmath>

class Iteration{

private:

  double max_fitness, average_fitness;
  int dim;
public:

void bubble_sort(Population pop)
{
  double sum=0.;
  int swap=1;
  Path *path_swap;

  while(1)
  {
    swap=0;
    for(int i=0; i < dim-1; i++)
    {
        if(pop[i]->fitness > pop[i+1]->fitness)
        {
          path_swap=pop[i+1];
          pop[i+1]=pop[i];
          pop[i]=path_swap;
          swap=1;
        }
    }
    if(swap==0)
      break;
  }

  max_fitness = pop[0]->fitness;

  for(int i=0; i<dim; i++)
    sum = sum + pop[i]->fitness;
  average_fitness = sum/(dim);
}


double deviation(Population pop)
{
  double s = 0, sum = 0;
  for(int i=0; i<dim; i++)
    sum = sum + pow(pop[i]->fitness - average_fitness,2);

  s = sum/(dim-1);
  return s;
}
double gaussian(Path path, Population pop)
{
  double f=0, s=0;
  s = deviation(pop);
  f = (1/(s*sqrt(2.*M_PI)))*exp(-0.5*pow((path.fitness - max_fitness)/s,2));
  return f;
}

Population iteration(Population pop, int N_combined, double dx)//N_combined= numero de caminhos com menor ação que vão ser combinados
{
  bubble_sort(pop);
  int N=0, cont=0, k=0;
  double variation;
  dim = getDimension();
  Population new_pop(dim);


    while(cont < dim)
    {
      for(k=0; k<N_combined; k++)
      {
        for(int h=(k+1); h<(N_combined-1); h++)
          {
            for(int i=0; i<dim; i++)
            {
              N = pop[i]->N;
              variation = (((double)rand())/((double)RAND_MAX))*2*dx-dx;
              for(int j=0; j<N; j++)
              {
                new_pop[i][j] = gaussian(pop[k][j],pop)*pop[k][j] + gaussian(pop[h][j],pop)*pop[h][j] + variation;
                cont+=cont;
              }
            }
          }
        }
      }
  return new_pop;
}




};

#endif
