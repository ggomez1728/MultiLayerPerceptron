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
  if (!esBias){
  	for (pesoSel=pesos.begin(); pesoSel!=pesos.end(); pesoSel++){
	  pesoAleatorio=((float) rand() / (RAND_MAX));
	  *pesoSel=pesoAleatorio;
  	}
  }
  else{
	  pesos[0]=1;
  }
}

void Neurona::cargarEntradas(vector<float> entradas){
  vector<float>::iterator pesoSel, entradaSel;
  if(!esBias){
	for(pesoSel=pesos.begin(), entradaSel=entradas.begin();
	    pesoSel!=pesos.end(); pesoSel++, entradaSel++){
	  salida+=(*pesoSel)*(*entradaSel);
    }
	salida=bipolar_sigmoidal(salida);
  }
  else salida = pesos[0];
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

