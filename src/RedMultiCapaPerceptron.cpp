/*
 * redMultiLabelPerceptron.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include "RedMultiCapaPerceptron.h"
#include <math.h>

#include "printInfo.h"
RedMultiCapaPerceptron::RedMultiCapaPerceptron(int numberLayers, int numberInputNeurons, int numberHidenNeurons, int numberOutputNeurons) {
  // TODO Auto-generated constructor stub
  learn_rate = 0.5;
  //Normalmente momentum debe ser un valor entre 0.1 y 0.9.
  momentum = 0.2;
  epochs = 10;
  numCapas=numberLayers;
  //En CapaEntrada y CapasOculta se adiciona  una neurona para el bias
  Layer inputLayer(numberInputNeurons+1,1);
  layerVector.push_back(inputLayer);
  if (numberLayers>2){
	  Layer hiddenLayer(numberHidenNeurons+1,numberInputNeurons+1);
	  for (int i = 2; i< numberLayers;i++ ){
		  layerVector.push_back(hiddenLayer);
    }
	Layer outputLayer(numberOutputNeurons,numberHidenNeurons+1);
	layerVector.push_back(outputLayer);
  }
  else{
	  Layer outputLayer(numberOutputNeurons,numberInputNeurons+1);
	  layerVector.push_back(outputLayer);
  }

}

void RedMultiCapaPerceptron::setData(std::vector<Case> *dataIn){
	dataTrain = dataIn;
}

void RedMultiCapaPerceptron::randomWeights(){
  std::vector<Layer>::iterator layerSelect;
  for (layerSelect = layerVector.begin(); layerSelect!=layerVector.end(); layerSelect++ ){
	  layerSelect->initializeLayer();
  }
}

void RedMultiCapaPerceptron::activar(){
	std::vector<Case>::iterator datai;
  for(datai=dataTrain->begin(); datai!=dataTrain->end();datai++){
    //FeedForward(datai->getEntradasCaso());
  }
}

void RedMultiCapaPerceptron::trainingNeuralNetwork(){
  for(int noEpoch=0; noEpoch<epochs; noEpoch++){
    for(vector<Case>::iterator cc =dataTrain->begin();cc!=dataTrain->end();cc++){
	  printInfo::InputOutput(cc->inputsCase, cc->outputsCase);
      feedForward(cc->inputsCase);
      backPropagation(cc->outputsCase);
	  printInfo::Model(layerVector);
	  ajustarPesos();
    }
    //if (errorPerEpoch <= 0.01)break;
  }
}

void RedMultiCapaPerceptron::feedForward(std::vector<double> inputTest){
  layerVector[0].loadImputsForInputLayer(inputTest);
  lastActivation=inputTest;
  for(int layerSelector = 1; layerSelector < numCapas-1; layerSelector++){
	  layerVector[layerSelector].loadImputsForHiddenLayer(lastActivation);
	  lastActivation=layerVector[layerSelector].ActivarCapa();
  }
  layerVector[numCapas-1].loadImputsForOutputLayer(lastActivation);
  lastActivation=layerVector[numCapas-1].ActivarCapa();
}

void  RedMultiCapaPerceptron::backPropagation(std::vector<double> salidas){
	std::vector<double> errorParcial = salidas;
  errorTotal=0;
  //calculamos la diferencia entre la salida esperada y la salida calculada en el feedforward
  errorParcial = layerVector[numCapas-1].calcularErrorCapa(errorParcial);
  imprimirError(errorParcial);
  //calcular el error total cuadratico
  for (vector<double>::iterator errorSel = errorParcial.begin();
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
  double deltaTemp=0;
  double deltaSum=1;
  for (int capaSel = numCapas-1; capaSel>0; --capaSel){
    //calculando los valores delta para la capa de salida
	for (int neuronSel = 0; neuronSel < layerVector[capaSel].Neurons.size(); neuronSel++){
	  if (capaSel == numCapas-1){
		  layerVector[capaSel].Neurons[neuronSel].deltaValue = -(errorParcial[neuronSel])*
		  		(layerVector[capaSel].Neurons[neuronSel].getOutNeuronDerivate());
	  }else if ((capaSel == numCapas - 2) && (numCapas > 2)){
		deltaTemp=0;
		for (int neuronDer = 0; neuronDer < layerVector[capaSel + 1].Neurons.size(); neuronDer++){
			deltaTemp +=  layerVector[capaSel+1].Neurons[neuronDer].weights[neuronSel] *
					(layerVector[capaSel+1].Neurons[neuronDer].getDeltaValue());
		}
		layerVector[capaSel].Neurons[neuronSel].deltaValue =deltaTemp *
				layerVector[capaSel].Neurons[neuronSel].getOutNeuronDerivate();
	  }
	}
  }
}

void RedMultiCapaPerceptron::ajustarPesos(){
  //Actualizar pesos capa de salida
  for (int capaSel = numCapas-1; capaSel>0; capaSel--){
	for(int neuronSel = 0; neuronSel < layerVector[capaSel].Neurons.size(); neuronSel++){
	  for(int pesoSel = 0; pesoSel < layerVector[capaSel].Neurons[neuronSel].weights.size(); pesoSel++){
		  layerVector[capaSel].Neurons[neuronSel].weights[pesoSel] =
				layerVector[capaSel].Neurons[neuronSel].weights[pesoSel] -
		   (learn_rate *(layerVector[capaSel].Neurons[neuronSel].getDeltaValue())* layerVector[capaSel].Neurons[neuronSel-1].getOutNeuron());
	  }
	}
  }
}


void RedMultiCapaPerceptron::imprimirError(std::vector<double> errores){
	std::vector<double>::iterator errorSel;
  int salida=0;
  for(errorSel=errores.begin(); errorSel!=errores.end(); errorSel++){
    cout << "Error Salida("<< salida++<<")"<< *errorSel << endl;
  }
}
