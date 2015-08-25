/*
 * Caso.h
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */

#ifndef CASO_H_
#define CASO_H_
#include <vector>
using namespace std;
class Caso {

public:
  vector<float> entradasCaso;
  vector<float> salidasCaso;
  Caso();
  void cargarCaso(vector<float> entradas, vector<float> salidas);
};

#endif /* CASO_H_ */
