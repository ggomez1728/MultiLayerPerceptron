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
  //En CapaEntrada y CapasOculta se adiciona  una neurona para el bias
  Capa CapaEntrada(entradas+1,1);
  CapaEntrada.agregarBias();
  Capa CapasOculta(ocultas+1,entradas+1);
  CapasOculta.agregarBias();
  Capa CapaSalida(salidas,ocultas+1);
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
	//Carga y Activacion primera capa en caso de que la entrada de cada neurona
	//tenga una conexion Simple, <ultimaActivacion> tiene la salidas
	feedForward(cc->entradasCaso);
	backPropagation(cc->salidasCaso);

  }
}

void RedMultiCapaPerceptron::ajustarPesos(){

}

void RedMultiCapaPerceptron::calcularError(){

}

void  RedMultiCapaPerceptron::backPropagation(vector<float> salidas){

}


void RedMultiCapaPerceptron::feedForward(vector<float> entradas){
  //cargo las entradas del caso a la capa de entrada del multiCapa
  entradas.push_back(1);
  capaVector[0].cargarSimpleEntradas(entradas);
  ultimaActivacion=capaVector[0].ActivarCapa();
  //activacion  de capas  siguientes hasta la salida
  for(int noCapa = 1; noCapa < numCapas; noCapa++){
	capaVector[noCapa].cargarMultiEntradas(ultimaActivacion);
	ultimaActivacion=capaVector[noCapa].ActivarCapa();
  }

}

