/*
 * redMultiLabelPerceptron.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */

#include "RedMultiCapaPerceptron.h"

RedMultiCapaPerceptron::RedMultiCapaPerceptron(int capas, int entradas, int ocultas, int salidas) {
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

void RedMultiCapaPerceptron::inicializarPesos(){
  vector<Capa>::iterator capaSel;
  vector<Neurona>::iterator neuronaSel;
  for (capaSel = capaVector.begin(); capaSel!=capaVector.end(); capaSel++ ){
	  capaSel->inicializarCapa();
  }
}
void RedMultiCapaPerceptron::activar(){
  vector<Caso>::iterator datai;
  for(datai=dataTrain->begin(); datai!=dataTrain->end();datai++){
    //FeedForward(datai->getEntradasCaso());

  }
}

void RedMultiCapaPerceptron::entrenar(){
  vector<Caso>::iterator cc;
  for(cc=dataTrain->begin();cc!=dataTrain->end();cc++){
	//Activacion primera capa
	ultimaActivacion = capaVector[0].cargarEntrada(cc->entradasCaso,false);
    //activacion  de capas  siguientes hasta la salida
	for(int noCapa = 1; noCapa < numCapas; noCapa++){
      ultimaActivacion = capaVector[noCapa].cargarEntrada(ultimaActivacion,true);
    }

  }
}

void RedMultiCapaPerceptron::ajustarPesos(){

}

void RedMultiCapaPerceptron::calcularError(){

}

void  RedMultiCapaPerceptron::backPropagation(){

}


void RedMultiCapaPerceptron::feedForward(vector<float> entradas){
  //cargo las entradas del caso a la capa de entrada del multiCapa
  int sizeEntrada = entradas.size();

}

