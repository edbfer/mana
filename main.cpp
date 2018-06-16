#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
//C Headers para criar um pipe para o gnuplot
#include <stdio.h>
#include <unistd.h>

#include "path.h"
#include "population.h"
#include "util.h"
#include "iteration.h"
using namespace std;

int main(){

  //PIPE PARA O gnuplot
  FILE* gnupipe = popen("gnuplot -persist", "w");
  fprintf(gnupipe, "\n");

  srand(time(nullptr));
  Population p(50);
  Point ini(0.0, 0.0);
  Point f(10.0, 10.0);
  for(int i = 0; i<20; i++)
  {
    p.generate(ini, f, 200);
    p.printall();
    fprintf(gnupipe, "call gnuplot.gp\n");
    fflush(gnupipe);
    sleep(1000);
  }

  fclose(gnupipe);

  return 0;

}
