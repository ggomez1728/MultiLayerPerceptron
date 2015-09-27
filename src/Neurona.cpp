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
  pesos.resize(entradas,0);
  esBias=false;
  valorDelta=0;
}

float Neurona::activarEntradas(vector<float> entradas) const{
  //salida=0;

  return salida;
}

void Neurona::iniciarlizarNeurona(){
  float pesoAleatorio;
  vector<float>::iterator pesoSel;
  for (pesoSel=pesos.begin(); pesoSel!=pesos.end(); pesoSel++){
	pesoAleatorio=((float) rand() / (RAND_MAX));
	*pesoSel=pesoAleatorio;
  }
}

void Neurona::cargarEntradas(vector<float> entradas){
  vector<float>::iterator pesoSel, entradaSel;
  salida=0;
  if(!esBias){
	for(pesoSel=pesos.begin(), entradaSel=entradas.begin();
	    pesoSel!=pesos.end(); pesoSel++, entradaSel++){
	  salida+=(*pesoSel)*(*entradaSel);
    }
  }
  else salida = pesos[0];
  //utiliza la funcion de activacion
  salida=binary_sigmoidal(salida);
}
void Neurona::calcularErrorNeurona(float valorDeseado){

}
void Neurona::actualizarPesos(){

}

vector<float> Neurona::actualizarPesos(vector<float> deltas){
  vector<float> pesos_backPro;
  return pesos_backPro;
}

float  Neurona::binary_sigmoidal(float in_value){
	return (float)1/(1+exp(-in_value));
}

float  Neurona::bipolar_sigmoidal( float in_value){
	return ((float)2/(1+exp(-in_value))) - 1;
}

