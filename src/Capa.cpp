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

vector<float> Capa::cargarEntrada(vector<float> entradas, bool multiEntrada){
  vector<float> salidasCapa;
  int numNeurona=0;
  vector<Neurona>::iterator neuronaSel;
  for(neuronaSel = Neuronas.begin(); neuronaSel!=Neuronas.end(); neuronaSel++){
	if(multiEntrada){
	  numNeurona=0;
      vector<float>::iterator mm;
      for(mm = entradas.begin(); mm != entradas.end(); mm++){
        neuronaSel->salida += *mm * entradas[numNeurona];
        numNeurona++;
      }
	}
	else{
	  neuronaSel->salida = entradas[numNeurona] * neuronaSel->pesos[0] ;
	  numNeurona++;
	}
	salidasCapa.push_back(neuronaSel->salida);
  }
  return salidasCapa;
}
