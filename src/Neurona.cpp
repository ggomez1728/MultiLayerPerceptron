/*
 * Neurona.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */

#include "Neurona.h"

Neurona::Neurona(int entradas) {
  // TODO Auto-generated constructor stub
  salida = 1;
  salidaDerivada=0;
  pesos.resize(entradas,0);
  esBias=false;
  esEntrada=false;
  valorDelta=0;

}

float Neurona::activarEntradas(vector<float> entradas) const{
  //salida=0;
  return salida;
}

void Neurona::iniciarlizarNeurona(){
  float pesoAleatorio;
  vector<float>::iterator pesoSel;
  if(esBias)pesos[0]=1;
  else{
    for (pesoSel=pesos.begin(); pesoSel!=pesos.end(); pesoSel++){
	  pesoAleatorio= 2 * ((float) rand() / (RAND_MAX)) - 1;
	  *pesoSel=pesoAleatorio;
    }
  }
}

void Neurona::cargarEntradas(vector<float> entradas){
  if (!esEntrada){
	salida=0;
	if(pesos.size() == entradas.size()){
	for(int selector = 0; selector < pesos.size(); selector++){
	  salida += pesos[selector] * entradas[selector];
	}
	salida=binary_sigmoidal(salida);
	salidaDerivada=salida*(1-salida);
	}
  }
  else{
	salida =entradas[0];
  }
}
void Neurona::calcularErrorNeurona(float valorDeseado){

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

