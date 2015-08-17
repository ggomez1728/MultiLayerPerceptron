//============================================================================
// Name        : PerceptronMultiCapa.cpp
// Author      : German Gomez
// Version     :
// Copyright   : intensivo
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <vector>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
//#include "cargar.h"
using namespace std;
#include "redMultiLabelPerceptron.h"
#include "Data.h"
#include "Caso.h"
int main() {
  vector<Caso> dataTrain;
  srand (time(NULL));
  Data data;
  dataTrain=data.leerData("data_train.txt");
  redMultiLabelPerceptron RNA(data.getCapasRNA(),data.getEntradasRNA(),data.getOcultasRNA(),data.getSalidasRNA());
  RNA.inicializarPesos();

	cout << "!!!Perceptron MultiCapa!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
