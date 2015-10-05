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
  epochs = 100;
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
  double errorPerEpoch;
  for(int noEpoch=0; noEpoch<epochs; noEpoch++){
	errorPerEpoch=0;
    for(vector<Case>::iterator cc =dataTrain->begin();cc!=dataTrain->end();cc++){
	  printInfo::InputOutput(cc->inputsCase, cc->outputsCase);
      feedForward(cc->inputsCase);
      backPropagation(cc->outputsCase);
      errorPerEpoch+=errorTotal;
	  printInfo::Model(layerVector);
	  ajustarPesos();
    }
    if (errorPerEpoch <= 0.01)break;
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
  errorParcial = layerVector[numCapas-1].calcularErrorCapa(errorParcial);
  printInfo::errors(errorParcial);
  for (vector<double>::iterator errorSelect = errorParcial.begin();
		  errorSelect!=errorParcial.end(); errorSelect++){
  	errorTotal += pow(*errorSelect, 2)/2;
  }
  cout << "Regla delta calculada" << endl;
  double deltaTemp=0;
  double deltaSum=0;
  bool hasBias = false;
  for (int layerSelect = numCapas-1; layerSelect>0; layerSelect--){
	  if (layerSelect == numCapas-1)hasBias = false;
	  else hasBias = true;
    //calculando los valores delta para la capa de salida
	for (int neuronSel = 0; neuronSel < layerVector[layerSelect].Neurons.size(); neuronSel++){
	  if (hasBias && neuronSel == layerVector[layerSelect].Neurons.size()-1)
		  break;
	  if (layerSelect == (numCapas-1)){
		  deltaTemp = -(errorParcial[neuronSel]) * (layerVector[layerSelect][neuronSel].getOutNeuronDerivate());
	  }else if ((layerSelect == numCapas - 2) && (numCapas > 2)){
		  deltaSum=0;
		  for (int neuronDer = 0; neuronDer < layerVector[layerSelect + 1].Neurons.size(); neuronDer++){
			  deltaSum +=  layerVector[layerSelect+1][neuronDer][neuronSel] * (layerVector[layerSelect+1][neuronDer].getDeltaValue());
		  }
		  deltaTemp = deltaSum * layerVector[layerSelect].Neurons[neuronSel].getOutNeuronDerivate();
	  }
	  layerVector[layerSelect][neuronSel].setDeltaValue(deltaTemp);
	}
  }
}

void RedMultiCapaPerceptron::ajustarPesos(){
  //Actualizar pesos capa de salida
	double learnValue;
  for (int layerSelect = numCapas-1; layerSelect>0; layerSelect--){
	for(int neuronSelect = 0; neuronSelect < layerVector[layerSelect].Neurons.size(); neuronSelect++){
	  for(int pesoSel = 0; pesoSel < layerVector[layerSelect][neuronSelect].weights.size(); pesoSel++){
		  learnValue = (learn_rate * (layerVector[layerSelect][neuronSelect].getDeltaValue()) * layerVector[layerSelect-1][neuronSelect].getOutNeuron());
		  layerVector[layerSelect][neuronSelect].SubtractWeight(pesoSel,learnValue);
	  }
	}
  }
}
