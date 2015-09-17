/*
 * Capa.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */

#include "Capa.h"

Capa::Capa(int neuronas, int entradaXneurona) {
  // TODO Auto-generated constructor stub
	Neuronas.resize(neuronas,entradaXneurona);
}

void Capa::inicializarCapa(){
  vector<Neurona>::iterator neuronaSel;
  for(neuronaSel = Neuronas.begin(); neuronaSel!=Neuronas.end(); neuronaSel++){
	neuronaSel->iniciarlizarNeurona();
  }
}
vector<float> Capa::calcularErrorCapa(vector<float> salidaEsperada){
  vector<float> deltas;
  for(int neuronSel=0; neuronSel < salidaEsperada.size();neuronSel++){

  }
  return deltas;
}
void Capa::agregarBias(){
  Neuronas.end()->esBias=true;
  Neuronas.end()->pesos.resize(1);
  Neuronas.end()->pesos[0]=1;
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
	  neuronaSel->salida = entradas[numNeurona] * neuronaSel->pesos[0];
	  numNeurona++;
	}
	salidasCapa.push_back(neuronaSel->salida);
  }
  return salidasCapa;
}

void Capa::cargarSimpleEntradas(vector<float> entradas){
  vector<Neurona>::iterator neuronaSel;
  vector<float>::iterator entradaSel;
  vector<float> entradaSimple(1);
  for(neuronaSel = Neuronas.begin(), entradaSel = entradas.begin();
	neuronaSel!=Neuronas.end(), entradaSel != entradas.end(); neuronaSel++, entradaSel++){
    //cargar capa de entrada
	entradaSimple[0]=*entradaSel;
	neuronaSel->cargarEntradas(entradaSimple);
  }
}

void Capa::cargarMultiEntradas(vector<float> entradas){
  vector<Neurona>::iterator neuronaSel;
  for(neuronaSel = Neuronas.begin(); neuronaSel!=Neuronas.end(); neuronaSel++){
	//cargar capa de entrada
	if(!neuronaSel->esBias)
	  neuronaSel->cargarEntradas(entradas);
  }
}

vector<float> Capa::ActivarCapa(){
  vector<float> salidasCapa;
  vector<Neurona>::iterator neuronaSel;
  vector<float>::iterator pesosSel;
  salidasCapa.resize(Neuronas.size());
  int salidaSelect=0;
  for(neuronaSel = Neuronas.begin(); neuronaSel!=Neuronas.end(); neuronaSel++){
	salidasCapa[salidaSelect]=neuronaSel->salida;
	++salidaSelect;
  }
  return salidasCapa;
}
