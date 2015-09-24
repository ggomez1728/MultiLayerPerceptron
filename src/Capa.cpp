/*
 * Capa.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: German Gomez
 */

#include "Capa.h"

Capa::Capa(int neuronas, int entradaXneurona, bool isBias) {
  // TODO Auto-generated constructor stub
	Neuronas.resize(neuronas,entradaXneurona);
	if(isBias)agregarBias();
}

void Capa::inicializarCapa(){
  vector<Neurona>::iterator neuronaSel;
  for(neuronaSel = Neuronas.begin(); neuronaSel!=Neuronas.end(); neuronaSel++){
	neuronaSel->iniciarlizarNeurona();
  }
}
vector<float> Capa::calcularErrorCapa(vector<float> salidaEsperada){
  vector<float> deltas;
  deltas.resize(salidaEsperada.size());
  if (salidaEsperada.size() == Neuronas.size()){
	for(int neuronSel=0; neuronSel < salidaEsperada.size(); neuronSel++){
      deltas[neuronSel] = salidaEsperada[neuronSel]-Neuronas[neuronSel].salida;
    }
  }
  return deltas;
}
void Capa::agregarBias(){
  Neurona neuronaBias(1);
  neuronaBias.esBias = true;
  Neuronas.push_back(neuronaBias);
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
  int entradaSel=0;
  vector<float> entradaSimple(1);
  for(neuronaSel = Neuronas.begin(); neuronaSel!=Neuronas.end(); neuronaSel++){
    //cargar capa de entrada
	entradaSimple[0]=entradas[entradaSel];
	neuronaSel->cargarEntradas(entradaSimple);
	if(!neuronaSel->esBias)
	  entradaSel++;
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
