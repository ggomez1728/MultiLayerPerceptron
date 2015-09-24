/*
 * redMultiLabelPerceptron.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include "RedMultiCapaPerceptron.h"

RedMultiCapaPerceptron::RedMultiCapaPerceptron(int capas, int entradas, int ocultas, int salidas) {
  // TODO Auto-generated constructor stub
  learn_rate = 0.5;
  //Normalmente momentum debe ser un valor entre 0.1 y 0.9.
  momentum = 0.2;
  epochs = 3;
  numCapas=capas;
  //En CapaEntrada y CapasOculta se adiciona  una neurona para el bias
  Capa CapaEntrada(entradas,1,true);
  Capa CapasOculta(ocultas,entradas+1, true);
  Capa CapaSalida(salidas,ocultas+1, false);
  capaVector.push_back(CapaEntrada);
  if (capas>2)
    for (int i = 2; i< capas;i++ )
	  capaVector.push_back(CapasOculta);
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
  float errorPerEpoch=1;
  //iterado la cantidad de epocas definidas anteriormente
  for(int noEpoch=0; noEpoch<epochs; noEpoch++){
	//recorre todos los casos uno a uno
	cout<<"<<<<<EPOCA>>>>>: "<<noEpoch << endl;
    for(vector<Caso>::iterator cc=dataTrain->begin();cc!=dataTrain->end();cc++){
	  //Carga y Activacion primera capa en caso de que la entrada de cada neurona
	  //tenga una conexion Simple, <ultimaActivacion> tiene la salidas
	  feedForward(cc->entradasCaso);
	  imprimirSalidas();
	  backPropagation(cc->salidasCaso);
	  //calculamos el error en la epoca

	  //actualizamos los pesos
    }
    if (errorPerEpoch <= 0.01)break;
  }
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

void  RedMultiCapaPerceptron::backPropagation(vector<float> salidas){
  vector<Capa>::iterator capaSel;
  vector<float> deltasTemp;
  errorTotal=0;
  deltasTemp = capaVector[numCapas-1].calcularErrorCapa(salidas);
  imprimirError(deltasTemp);
  //calcular el error total cuadratico
  for (vector<float>::iterator errorSel=deltasTemp.begin();errorSel!=deltasTemp.end(); errorSel++){
	  errorTotal += pow(*errorSel, 2)/2;
  }
  cout << "Error Total:" << errorTotal<< endl;
  for (capaSel=capaVector.end();capaSel!=capaVector.begin();--capaSel){

  }
}
void RedMultiCapaPerceptron::imprimirError(vector<float> errores){
vector<float>::iterator errorSel;
int salida=0;
for(errorSel=errores.begin(); errorSel!=errores.end(); errorSel++){
  cout << "Error Salida("<< salida++<<")"<< *errorSel << endl;
}
}
void RedMultiCapaPerceptron::ajustarPesos(){

}

void RedMultiCapaPerceptron::imprimirPesos(){
  //impresion de pesos del modelo
  cout << "Impresion de pesos del sistema:" << endl;
  for(int noCapa = 0; noCapa < numCapas; noCapa++){
	cout << "Capa(" << noCapa <<")" << endl;
	for(int noNeurona = 0; noNeurona < capaVector[noCapa].Neuronas.size(); noNeurona++){
	  cout << "        Neurona(" << noNeurona << ")= " ;
	  for(int noPeso = 0; noPeso < capaVector[noCapa].Neuronas[noNeurona].pesos.size(); noPeso++){
		cout << capaVector[noCapa].Neuronas[noNeurona].pesos[noPeso] << " ";
	  }
	  if(capaVector[noCapa].Neuronas[noNeurona].esBias) cout << "(bias)";
	  cout << endl;
	}
  }
}

void RedMultiCapaPerceptron::imprimirSalidas(){
  //impresion de pesos del modelo
  cout << "Impresion de salidas del sistema:" << endl;
  for(int noNeurona = 0; noNeurona < capaVector[numCapas-1].Neuronas.size(); noNeurona++){
    cout << "Salida Neurona(" << noNeurona << ")= " ;
	cout << capaVector[numCapas-1].Neuronas[noNeurona].salida << " " << endl;
  }
}
