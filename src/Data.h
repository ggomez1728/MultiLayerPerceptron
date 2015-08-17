/*
 * CargarData.h
 *
 *  Created on: 16 de ago. de 2015
 *      Author: german
 */

#ifndef DATA_H_
#define DATA_H_
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include "Caso.h"
using namespace std;

class Data {
  int capasRNA, entradasRNA, ocultasRNA, salidasRNA;
  vector<Caso> dataFormat;
public:
	Data();
	int getCapasRNA();
	int getEntradasRNA();
	int getOcultasRNA();
	int getSalidasRNA();
	vector<Caso> leerData(string archivo);
	virtual ~Data();
};

#endif /* CARGARDATA_H_ */
