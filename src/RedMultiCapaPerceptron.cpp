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

void RedMultiCapaPerceptron::feedForward(vector<float> entradas){
  //cargo las entradas del caso a la capa de entrada del multiCapa
  /*vector<float>::iterator ii;
  for (ii=entradas.begin();ii!=entradas.end(); ii++){

  }*/
  int sizeEntrada = entradas.size();

}

void RedMultiCapaPerceptron::entrenar(){
  vector<Caso>::iterator cc;

  for(cc=dataTrain->begin();cc!=dataTrain->end();cc++){
	/*int noNeurona = 0;
	//cargar entradas de entrenamiento
	vector<float>::iterator nn;
	for(nn=cc->entradasCaso.begin(); nn!=cc->entradasCaso.end(); nn++){
	  capaVector[0].Neuronas[noNeurona].salida =
			  *nn * (capaVector[0].Neuronas[noNeurona].pesos[0]);
	  noNeurona++;
	}
*/
    capaVector[0].cargarEntrada(cc->entradasCaso);

  }
}

void RedMultiCapaPerceptron::ajustarPesos(){

}

void RedMultiCapaPerceptron::calcularError(){

}

void  RedMultiCapaPerceptron::backPropagation(){

}


