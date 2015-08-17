/*
 * redMultiLabelPerceptron.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */

#include "redMultiLabelPerceptron.h"

redMultiLabelPerceptron::redMultiLabelPerceptron(int capas, int entradas, int ocultas, int salidas) {
  // TODO Auto-generated constructor stub
  numCapas=capas;
  Capa CapaEntrada(entradas,1);
  Capa CapasOculta(ocultas,entradas);
  Capa CapaSalida(salidas,ocultas);
  capaVector.push_back(CapaEntrada);
  if (capas>2)
	for (int i = 2; i< capas;i++ )
		capaVector.push_back(CapaSalida);
  capaVector.push_back(CapaSalida);
}

void redMultiLabelPerceptron::inicializarPesos(){
  vector<Capa>::iterator capaSel;
  vector<Neurona>::iterator neuronaSel;
  for (capaSel = capaVector.begin(); capaSel!=capaVector.end(); capaSel++ ){
	  capaSel->inicializarNeuronas();
  }
}

redMultiLabelPerceptron::~redMultiLabelPerceptron() {
	// TODO Auto-generated destructor stub
}

