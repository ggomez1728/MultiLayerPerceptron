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

	//FeedForward(datai->entradasCaso);

  }
}

void RedMultiCapaPerceptron::FeedForward(vector<float> entradas){
  vector<float>::iterator ii;
  for (ii=entradas.begin();ii!=entradas.end(); ii++){

  }
}

void RedMultiCapaPerceptron::AjustarPesos(){

}

void RedMultiCapaPerceptron::calcularError(){

}

void  RedMultiCapaPerceptron::backPropagation(){

}


