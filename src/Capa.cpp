/*
 * Capa.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */

#include "Capa.h"

Capa::Capa(int neuronas, int entradaXneurona) {
  // TODO Auto-generated constructor stub
  for (int i = 0; i< neuronas;i++ ){
	  Neuronas.push_back(entradaXneurona);
  }
}


void Capa::inicializarNeuronas(){
  vector<Neurona>::iterator neuronaSel;
  for(neuronaSel = Neuronas.begin(); neuronaSel!=Neuronas.end(); neuronaSel++){
	  neuronaSel->iniciarNeurona();
  }
}

Capa::~Capa() {
	// TODO Auto-generated destructor stub
}

