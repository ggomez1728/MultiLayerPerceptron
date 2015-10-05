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

#include "Case.h"


class Data {
  int capasRNA, entradasRNA, ocultasRNA, salidasRNA;
  std::vector<Case> dataFormat;
public:
	Data();
	int getCapasRNA();
	int getEntradasRNA();
	int getOcultasRNA();
	int getSalidasRNA();
	std::vector<Case> leerData(std::string archivo);
};

#endif /* CARGARDATA_H_ */
