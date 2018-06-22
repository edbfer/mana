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

  srand(time(nullptr));
  Population p(50);
  Point ini(0.0, 0.0);
  Point f(10.0, 10.0);

  p.generate(ini, f, 1500);
  p.printall();

  

  return 0;

}
