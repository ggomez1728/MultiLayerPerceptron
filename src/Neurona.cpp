/*
 * Neurona.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */

#include "Neurona.h"

Neurona::Neurona(int entradas) {
  // TODO Auto-generated constructor stub
  salida = 0;
  for (int i = 0; i< entradas;i++ ){
    pesos.push_back(0.0);
  }
}

float Neurona::Activar(vector<float> entradas) const{
  float salidaFeedFwd = 0;

  return salidaFeedFwd;
}

void Neurona::iniciarNeurona(){
  float pesoAleatorio;
  vector<float>::iterator pesoSel;
  for (pesoSel=pesos.begin(); pesoSel!=pesos.end(); pesoSel++){
	  pesoAleatorio=((float) rand() / (RAND_MAX));
	  *pesoSel=pesoAleatorio;
  }

}
void Neurona::actualizarPesos(){

}

vector<float> Neurona::Actualizar_Pesos(vector<float> deltas){
  vector<float> pesos_backPro;

  return pesos_backPro;
}

Neurona::~Neurona() {
	// TODO Auto-generated destructor stub
}

