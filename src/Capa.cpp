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

void Capa::inicializarCapa(){
  vector<Neurona>::iterator neuronaSel;
  for(neuronaSel = Neuronas.begin(); neuronaSel!=Neuronas.end(); neuronaSel++){
	  neuronaSel->iniciarlizarNeurona();
  }
}

void Capa::cargarEntrada(vector<float> entradas){
  int numNeurona=0;
  vector<Neurona>::iterator neuronaSel;
  for(neuronaSel = Neuronas.begin(); neuronaSel!=Neuronas.end(); neuronaSel++){
	neuronaSel->salida = entradas[numNeurona] * neuronaSel->pesos[0] ;
    numNeurona++;
  }
}
