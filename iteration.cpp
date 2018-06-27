#include "iteration.h"
#include <iostream>

using namespace std;



void Iteration::bubble_sort(Population* pop)
{
  //cout << "\x1b[1:31mInicio Bubble Sort:" << endl << "\x1b[1:37mPopulação inicial:\x1b[0m" << endl;

  double sum=0.;
  int swap=1;
  Path *path_swap;

  for(int i = 0; i<pop->getDimension(); i++)
  {
    //cout << "PathID = " << (*pop)[i]->id << "; PathAction = " << (*pop)[i]->fitness << endl;
  }

  while(1)
  {
    swap=0;
    for(int i=0; i < dim-1; i++)
    {
        if((*pop)[i]->fitness > (*pop)[i+1]->fitness)
        {
          path_swap=(*pop)[i+1];
          (*pop)[i+1]=(*pop)[i];
          (*pop)[i]=path_swap;
          swap=1;
        }
    }
    if(swap==0)
      break;
  }

  max_fitness = (*pop)[0]->fitness;

  for(int i=0; i<dim; i++)
    sum = sum + (*pop)[i]->fitness;

  average_fitness = sum/((double)dim);

  //cout << "\x1b[1:37mPopulação Final:\x1b[0m" << endl;

  for(int i = 0; i<pop->getDimension(); i++)
  {
    //cout << "PathID = " << (*pop)[i]->id << "; PathAction = " << (*pop)[i]->fitness << endl;
  }

  //cout << "WinnerPathID = " << (*pop)[0]->id << endl;
  //cout << "AveragePathFitness = " << average_fitness << endl;
  //cout << "\x1b[1:31mFinal do Bubble Sort" << endl;
}

double Iteration::deviation(Population* pop)
{
  double s = 0, sum = 0;
  for(int i=0; i<dim; i++)
    sum = sum + pow((*pop)[i]->fitness - average_fitness,2);

  s = sum/(dim-1);
  return s;
}

double Iteration::gaussian(Path* path, double s)
{
  /*double f=0;
  f = (1/(sqrt(s*2.*M_PI)))*exp(-0.5*pow((path->fitness - max_fitness),2)/s);*/
  return /*f*/ max_fitness / path->fitness;
}

Population* Iteration::iterate(Population *pop, int N_combined, double dh, double dt)
{
  //cout << "Iteration::iterate(): Entry Point" << endl;
  int N=0, k=0, i=N_combined;
  double s=0.;

  bubble_sort(pop);
  //cout << "Iteration::iterate(): max_fitness -> " << max_fitness << endl;
  s = deviation(pop);
  //cout << "Iteration::iterate(): deviation() output -> " << s << endl;
  dim = pop->getDimension();

  Population* new_pop = new Population(dim);

  if(N_combined>dim)
    N_combined=dim;

  for(int r=0; r<N_combined; r++)
    (*new_pop)[r]=(*pop)[r];

  while(1)
  {
    for(k=0; k<N_combined; k++)
    {
      for(int h=(k+1); h<(N_combined-1); h++)
      {
        N = (*pop)[i]->N;
        double variation = (((double)rand())/((double)RAND_MAX))*2.*dh-dh;

        double t0 = (*((*pop)[k]))[0].x;
        Path* newp = new Path((*((*pop)[k]))[0], (*((*pop)[k]))[N-1], N);
        double c1 = gaussian((*pop)[k], s);
        double c2 = gaussian((*pop)[h], s);
        //cout << "Iteration::iterate() - gaussian() c1 output -> " << c1 << endl;
        //cout << "Iteration::iterate() - gaussian() c2 output -> " << c2 << endl;
        for(int j=1; j<N-1; j++)
        {

          Point p1 = (*((*pop)[k]))[j];
          Point p2 = (*((*pop)[h]))[j];
          Point f;

          f.x = t0 + j*dt;
          f.y = p1.y*c1 + p2.y*c2 + variation;

          //cout << "p1: (" << p1 << ") p2: (" << p2 << ")" << " c1: " << c1 << " c2: " << c2 << " endState: (" << f << ")" << endl;

          (*newp)[j] = f;
        }

        (*new_pop)[i] = newp;

        if(i < dim-1)
          i++;
        else
          return new_pop;
      }
    }
  }

  return new_pop;
}
