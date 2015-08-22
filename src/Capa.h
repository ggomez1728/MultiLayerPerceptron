/*
 * Capa.h
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#include <vector>
#include "Neurona.h"
#ifndef CAPA_H_
#define CAPA_H_
using namespace std;
class Capa {
  vector<Neurona> Neuronas;
public:
	Capa(int neuronas,  int entradaXneurona);
	void inicializarCapa();
};

#endif /* CAPA_H_ */
