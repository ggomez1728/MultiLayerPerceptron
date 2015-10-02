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
  epochs = 200;
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
	cout<< endl;
	cout<<"<<<<<EPOCA>>>>>: "<<noEpoch << endl;
    for(vector<Caso>::iterator cc=dataTrain->begin();cc!=dataTrain->end();cc++){
	  //Carga y Activacion primera capa en caso de que la entrada de cada neurona
	  //tenga una conexion Simple, <ultimaActivacion> tiene la salidas
      printinfo.printInOut(cc->entradasCaso, cc->salidasCaso);
      feedForward(cc->entradasCaso);
      printinfo.printModel(capaVector);
      //revisar sentido de activacion problema!
	  backPropagation(cc->salidasCaso);
	  //ajustarPesos();
	  //calculamos el error en la epoca

	  //actualizamos los pesos
    }
    if (errorPerEpoch <= 0.01)break;
  }
}

void RedMultiCapaPerceptron::feedForward(vector<float> entradas){
  //cargo las entradas del caso a la capa de entrada del multiCapa
  capaVector[0].cargarSimpleEntradas(entradas);
  ultimaActivacion=entradas;
  //activacion  de capas  siguientes hasta la salida
  for(int noCapa = 1; noCapa < numCapas; noCapa++){
	capaVector[noCapa].cargarMultiEntradas(ultimaActivacion);
	ultimaActivacion=capaVector[noCapa].ActivarCapa();
  }
}

void  RedMultiCapaPerceptron::backPropagation(vector<float> salidas){
  vector<float> errorParcial = salidas;
  errorTotal=0;
  //calculamos la diferencia entre la salida esperada y la salida calculada en el feedforward
  errorParcial = capaVector[numCapas-1].calcularErrorCapa(errorParcial);
  imprimirError(errorParcial);
  //calcular el error total cuadratico
  for (vector<float>::iterator errorSel = errorParcial.begin();
    errorSel!=errorParcial.end(); errorSel++){
  	errorTotal += pow(*errorSel, 2)/2;
  }
  cout << "Error Total:" << errorTotal<< endl;
  // The Backwards Pass
  // Aplicando regla de la cadena sabemos
  // Calculamos la derivada parcial del Error Total  con respecto a cada salida,
  // para actualizar los pesos de la capa de salida, este derivada esta representada por:
  // <-deltasTemp>
  // La derivada parcial de la función logística es la salida multiplicado por 1 menos la salida:
  // BackPorpagation capa salida, recorremos cada neurona de la capa

  cout << "Regla delta calculada" << endl;
  float deltaTemp=0;
  float deltaSum=1;
  for (int capaSel = numCapas-1; capaSel>0; --capaSel){
    //calculando los valores delta para la capa de salida
	for (int neuronaSel = 0; neuronaSel < capaVector[capaSel].Neuronas.size(); neuronaSel++){
	  if (capaSel == numCapas-1){
		  capaVector[capaSel].Neuronas[neuronaSel].valorDelta = -(errorParcial[neuronaSel])*
		  		(capaVector[capaSel].Neuronas[neuronaSel].salidaDerivada);
	  }else if ((capaSel == numCapas - 2) && (numCapas > 2)){
		deltaTemp=0;
		for (int neuronaDer = 0; neuronaDer < capaVector[capaSel + 1].Neuronas.size(); neuronaDer++){
			deltaTemp +=  capaVector[capaSel+1].Neuronas[neuronaDer].pesos[neuronaSel] *
					(capaVector[capaSel+1].Neuronas[neuronaDer].valorDelta);
		}
		capaVector[capaSel].Neuronas[neuronaSel].valorDelta =deltaTemp *
				capaVector[capaSel].Neuronas[neuronaSel].salidaDerivada;
	  }
      for(int pesoSel = 0;pesoSel < capaVector[capaSel].Neuronas[neuronaSel].pesos.size(); pesoSel++){
	    capaVector[capaSel].Neuronas[neuronaSel].pesos[pesoSel] =
		   capaVector[capaSel].Neuronas[neuronaSel].pesos[pesoSel] -
		  (learn_rate *(capaVector[capaSel].Neuronas[neuronaSel].valorDelta)*(capaVector[capaSel-1].Neuronas[neuronaSel].salida));
      }
	}
  }
}

void RedMultiCapaPerceptron::ajustarPesos(){
  //Actualizar pesos capa de salida
  for (int capaSel = numCapas-1; capaSel>=1; capaSel--){
	for(int neuronaSel = 0; neuronaSel < capaVector[capaSel].Neuronas.size(); neuronaSel++){
	  for(int pesoSel = 0; pesoSel < capaVector[capaSel].Neuronas[neuronaSel].pesos.size(); pesoSel++){
		  capaVector[capaSel].Neuronas[neuronaSel].pesos[pesoSel] =
		     capaVector[capaSel].Neuronas[neuronaSel].pesos[pesoSel] -
			 (learn_rate *(capaVector[capaSel].Neuronas[neuronaSel].valorDelta)* capaVector[capaSel].Neuronas[neuronaSel-1].salida);
	  }
	}
  }
}


void RedMultiCapaPerceptron::imprimirError(vector<float> errores){
  vector<float>::iterator errorSel;
  int salida=0;
  for(errorSel=errores.begin(); errorSel!=errores.end(); errorSel++){
    cout << "Error Salida("<< salida++<<")"<< *errorSel << endl;
  }
}
